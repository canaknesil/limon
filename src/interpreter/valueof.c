#include "node.h"
#include "nodei.h"
#include "env/value/value.h"
#include "env/env.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




void *applyVarDef(struct node *n, void *env)
{
	switch (n->type)
	{
		case ONE_VAR_VL:	if (!extendFrame(env, n->list[0], NULL))
								kissError("Redefinition of variable %s", (char *) n->list[0]);
							break;
		case MUL_VAR_VL:	if (!extendFrame(env, n->list[0], NULL))
								kissError("Redefinition of variable %s", (char *) n->list[0]);
							applyVarDef(n->list[1], env);
							break;
	}
	return NULL;
}


void extendEnvWithArgList(void *newEnv, void *env, struct node *varList, struct node *argList)
{
	if (varList->type == EMPTY_VAR_LIST && argList->type == EMPTY_ARG_LIST)
		return;

	if (varList->type == NEMPTY_VAR_LIST && argList->type == NEMPTY_ARG_LIST)
	{
		extendEnvWithArgList(newEnv, env, varList->list[0], argList->list[0]);
		return;
	}

	if (varList->type == ONE_VAR_VL && argList->type == ONE_ARG_AL)
	{
		extendFrame(newEnv, varList->list[0], valueof(argList->list[0], env));
		return;
	}

	if (varList->type == MUL_VAR_VL && argList->type == MUL_ARG_AL)
	{
		extendFrame(newEnv, varList->list[0], valueof(argList->list[0], env));
		extendEnvWithArgList(newEnv, env, varList->list[1], argList->list[1]);
		return;
	}

	kissError("Argument number does not match");
}


void *applyProcedure(void *proc, struct node *argList)
{
	void *env = ProcVal_GetEnv(proc);
	void *newEnv = emptyFrame(env);
	extendEnvWithArgList(newEnv, env, ProcVal_GetBVarList(proc), argList);
	void *val = valueof(ProcVal_GetBody(proc), newEnv);
	deleteFrame(newEnv);
	return val;
}


void *valueofNumberOp(struct node *n, void *env)
{
	void *n1 = valueof(n->list[0], env);
	void *n2 = valueof(n->list[1], env);
	if (checkValueType(IntVal, n1) && checkValueType(IntVal, n2))
	{
		switch (n->type)
		{
			case ADD_EXP:				return IntVal_Add(n1, n2);
			case SUB_EXP:				return IntVal_Sub(n1, n2);
			case MUL_EXP:				return IntVal_Mul(n1, n2);
			case DIV_EXP:				return IntVal_Div(n1, n2);
			case REM_EXP:				return IntVal_Rem(n1, n2);
			case EQ_EXP:				return newValue(BoolVal, IntVal_Eq(n1, n2));
			case NEQ_EXP:				return newValue(BoolVal, IntVal_Neq(n1, n2));
			case L_EXP:					return newValue(BoolVal, IntVal_L(n1, n2));
			case G_EXP:					return newValue(BoolVal, IntVal_G(n1, n2));
			case GEQ_EXP:				return newValue(BoolVal, IntVal_Geq(n1, n2));
			case LEQ_EXP:				return newValue(BoolVal, IntVal_Leq(n1, n2));
		}
	}
	else
		kissError("Other value for number operation operands other than a number value");

	return NULL;
}


void *valueofBoolOp(struct node *n, void *env)
{
	void *b1 = valueof(n->list[0], env);
	void *b2 = valueof(n->list[1], env);
	if (checkValueType(BoolVal, b1) && checkValueType(BoolVal, b2))
	{
		switch (n->type)
		{
			case AND_EXP:				return BoolVal_And(b1, b2);
			case OR_EXP:				return BoolVal_Or(b1, b2);
		}
	}
	else
		kissError("Other value for number operation operands other than a number value");

	return NULL;
}


void *valueof(void *_n, void *env)
{
	if (!_n) return NULL;
	
	struct node *n = _n;
	switch (n->type)
	{
		case A_PROGRAM:				return valueof(n->list[0], env);
		case EMPTY_PROGRAM:			return NULL;

		case ONE_STATEMENT_SL:		return valueof(n->list[0], env);
		case MUL_STATEMENT_SL:		valueof(n->list[0], env);
									return valueof(n->list[1], env);

		case EXPRESSION_S:			return valueof(n->list[0], env);
		case COMPOUND_S:			{void *newEnv = emptyFrame(env);
									void *val = valueof(n->list[0], newEnv);
									deleteFrame(newEnv);
									return val;}
		case VAR_DEF_INIT_S:		return valueof(n->list[0], env);
		case VAR_DEF_S:				return applyVarDef(n->list[0], env);
		case IF_S:					{void *pred = valueof(n->list[0], env);
									if (!checkValueType(BoolVal, pred)) kissError("if statement predicate: Expected Boolean value");
									if (BoolVal_GetVal(pred)) return valueof(n->list[1], env);
									else return NULL;}
		case IF_ELSE_S:				{void *pred = valueof(n->list[0], env);
									if (!checkValueType(BoolVal, pred)) kissError("if-else statement predicate: Expected Boolean value");
									if (BoolVal_GetVal(pred)) return valueof(n->list[1], env);
									else return valueof(n->list[2], env);}
		case WHILE_S:				while (1)
									{
										void *pred = valueof(n->list[0], env);
										if (!checkValueType(BoolVal, pred)) kissError("while statement predicate: Expected Boolean value");
										char b = BoolVal_GetVal(pred);
										deleteValue(pred);
										if (!b) return NULL;
										else valueof(n->list[1], env);
									}
		case PRINT_S:				{void *val = valueof(n->list[0], env);
									printValue(val);
									return val;}

		case ASSIGN_EXP:			{void *val = valueof(n->list[1], env);
									if (setEnv(env, n->list[0], val)) return val;
									else kissError("Variable %s does not exist", (char *) n->list[0]);}
		case CONSTANT_EXP:			return valueof(n->list[0], env);
		case VAR_EXP:				{void *val = NULL;
									if (applyEnv(env, n->list[0], &val)) return val;
									else kissError("Variable %s does not exist", (char *) n->list[0]);}
		case PROC_EXP:				return newValue(ProcVal, n->list[0], n->list[1], env);
		case CALL_EXP:				{void *proc = valueof(n->list[0], env);
									if (checkValueType(ProcVal, proc))
										return applyProcedure(proc, n->list[1]);
									else
										kissError("call expression: procedure does not evaluate to a procedure value");}
		case ARRAY_EXP:				{void *val = valueof(n->list[0], env);
									if (!checkValueType(IntVal, val)) kissError("Array expression: Expected number value");
									return newValue(ArrayVal, IntVal_GetCInt(val));}
		case ARRAY_GET_EXP:			{void *arr = valueof(n->list[0], env);
									if (!checkValueType(ArrayVal, arr)) kissError("Array get expression: Expected array value");
									void *i = valueof(n->list[1], env);
									if (!checkValueType(IntVal, i)) kissError("Array get expression: Expected integer value");
									void *val;
									if (ArrayVal_Get(arr, IntVal_GetCInt(i), &val)) return val;
									else kissError("Array index greater than array size");}
		case ARRAY_SET_EXP:			{void *arr = valueof(n->list[0], env);
									if (!checkValueType(ArrayVal, arr)) kissError("Array get expression: Expected array value");
									void *i = valueof(n->list[1], env);
									if (!checkValueType(IntVal, i)) kissError("Array get expression: Expected integer value");
									void *val = valueof(n->list[2], env);
									if (ArrayVal_Set(arr, IntVal_GetCInt(i), val)) return val;
									else kissError("Array index greater than array size");}
		case IF_ELSE_EXP:			{void *pred = valueof(n->list[0], env);
									if (!checkValueType(BoolVal, pred)) kissError("if-else expression predicate: Expected Boolean value");
									if (BoolVal_GetVal(pred)) return valueof(n->list[1], env);
									else return valueof(n->list[2], env);}
		case ADD_EXP:				return valueofNumberOp(n, env);
		case SUB_EXP:				return valueofNumberOp(n, env);
		case MUL_EXP:				return valueofNumberOp(n, env);
		case DIV_EXP:				return valueofNumberOp(n, env);
		case REM_EXP:				return valueofNumberOp(n, env);
		case MIN_EXP:				{void *num = valueof(n->list[0], env);
									if (checkValueType(IntVal, num))
										return IntVal_Neg(num);
									else
										kissError("Other value for number operation operands other than a number value");}
		case EQ_EXP:				return valueofNumberOp(n, env);
		case NEQ_EXP:				return valueofNumberOp(n, env);
		case L_EXP:					return valueofNumberOp(n, env);
		case G_EXP:					return valueofNumberOp(n, env);
		case GEQ_EXP:				return valueofNumberOp(n, env);
		case LEQ_EXP:				return valueofNumberOp(n, env);
		case AND_EXP:				return valueofBoolOp(n, env);
		case OR_EXP:				return valueofBoolOp(n, env);
		case NOT_EXP:				{void *b = valueof(n->list[0], env);
									if (checkValueType(BoolVal, b))
										return BoolVal_Not(b);
									else
										kissError("Other value for number operation operands other than a number value");}

		case ONE_ASSIGN_AL:			{void *val = valueof(n->list[1], env);
									if (!extendFrame(env, n->list[0], val))
										kissError("Redefinition of variable %s", (char *) n->list[0]);
									return val;}
		case MUL_ASSIGN_AL:			if (!extendFrame(env, n->list[0], valueof(n->list[1], env)))
										kissError("Redefinition of variable %s", (char *) n->list[0]);
									return valueof(n->list[2], env);

		/*case NEMPTY_ARG_LIST:		break;
		case EMPTY_ARG_LIST:		break;
		case ONE_ARG_AL:			break;
		case MUL_ARG_AL:			break;

		case NEMPTY_VAR_LIST:		break;
		case EMPTY_VAR_LIST:		break;
		case ONE_VAR_VL:			break;
		case MUL_VAR_VL:			break;*/

		case INTEGER_CONST:			return IntVal_FromString(n->list[0]);
		case BOOLEAN_CONST:			return newValue(BoolVal, *(char *) n->list[0]);
		case STRING_CONST:			return StringVal_FromRaw(n->list[0]);
		case CHARACTER_CONST:		return CharVal_FromRaw(n->list[0]);
	}

	return NULL;
}

