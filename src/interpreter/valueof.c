#include "node.h"
#include "nodei.h"
#include "tryCatch.h"
#include "value/value.h"
#include "env/env.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




static void *applyVarDef(struct node *n, void *env)
{
	switch (n->type)
	{
		case ONE_VAR_VL:	if (!extendFrame(env, n->list[0], NULL)) {
								kissError(n->line, "Redefinition of variable \"%s\"", (char *) n->list[0]);
								raise(3);
							}
							break;
		case MUL_VAR_VL:	if (!extendFrame(env, n->list[0], NULL)) {
								kissError(n->line, "Redefinition of variable \"%s\"", (char *) n->list[0]);
								raise(3);
							}
							applyVarDef(n->list[1], env);
							break;
	}
	return NULL;
}


static void extendEnvWithArgList(void *newEnv, void *env, struct node *varList, struct node *argList)
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

	kissError(argList->line, "'call expression' argument number does not match");
	raise(3);
}


static void *applyProcedure(void *proc, struct node *argList)
{
	void *env = ProcVal_GetEnv(proc);
	void *newEnv = emptyFrame(env);
	extendEnvWithArgList(newEnv, env, ProcVal_GetBVarList(proc), argList);
	void *val = valueof(ProcVal_GetBody(proc), newEnv);
	return val;
}


static void *valueofNumberOp(struct node *n, void *env)
{
	void *n1 = valueof(n->list[0], env);
	void *n2 = valueof(n->list[1], env);
	if (checkValueType(IntVal, n1)) {
		if (checkValueType(IntVal, n2)) {
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
		} else {
			kissError(n->line, "Number binary operation second operand is not an Integer value");
			raise(3);
		}
	} else {
		kissError(n->line, "Number binary operation first operand is not an Integer value");
		raise(3);
	}

	return NULL;
}


static void *valueofBoolOp(struct node *n, void *env)
{
	void *b1 = valueof(n->list[0], env);
	void *b2 = valueof(n->list[1], env);
	if (checkValueType(BoolVal, b1)) {
		if (checkValueType(BoolVal, b2)) {
			switch (n->type)
			{
				case AND_EXP:				return BoolVal_And(b1, b2);
				case OR_EXP:				return BoolVal_Or(b1, b2);
			}
		} else {
			kissError(n->line, "Boolean binary operation second operand is not a Boolean value");
			raise(3);
		}
	} else {
		kissError(n->line, "Boolean binary operation first operand is not a Boolean value");
		raise(3);
	}

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
									return val;}
		case VAR_DEF_INIT_S:		return valueof(n->list[0], env);
		case VAR_DEF_S:				return applyVarDef(n->list[0], env);
		case IF_S:					{void *pred = valueof(n->list[0], env);
									if (!checkValueType(BoolVal, pred)) {
										kissError(n->line, "'if statement' predicate is not a Boolean value");
										raise(3);
									}
									char b = BoolVal_GetVal(pred);
									if (b) return valueof(n->list[1], env);
									else return NULL;}
		case IF_ELSE_S:				{void *pred = valueof(n->list[0], env);
									if (!checkValueType(BoolVal, pred)) {
										kissError(n->line, "'if-else statement' predicate is not a Boolean value");
										raise(3);
									}
									char b = BoolVal_GetVal(pred);
									if (b) return valueof(n->list[1], env);
									else return valueof(n->list[2], env);}
		case WHILE_S:				while (1)
									{
										void *pred = valueof(n->list[0], env);
										if (!checkValueType(BoolVal, pred)) {
											kissError(n->line, "'while statement' predicate is not a Boolean value");
											raise(3);
										}
										char b = BoolVal_GetVal(pred);
										if (!b) return NULL;
										else valueof(n->list[1], env);
									}
		case PRINT_S:				{void *val = valueof(n->list[0], env);
									printValue(val);
									return val;}

		case ASSIGN_EXP:			{void *val = valueof(n->list[1], env);
									if (setEnv(env, n->list[0], val)) return val;
									else {
										kissError(n->line, "Variable \"%s\" does not exist", (char *) n->list[0]);
										raise(3);
									}}
		case CONSTANT_EXP:			return valueof(n->list[0], env);
		case VAR_EXP:				{void *val = NULL;
									if (applyEnv(env, n->list[0], &val)) return val;
									else {
										kissError(n->line, "Variable \"%s\" does not exist", (char *) n->list[0]);
										raise(3);
									}}
		case PROC_EXP:				return newValue(ProcVal, n->list[0], n->list[1], env);
		case CALL_EXP:				{void *proc = valueof(n->list[0], env);
									if (checkValueType(ProcVal, proc))
										return applyProcedure(proc, n->list[1]);
									else {
										kissError(n->line, "'call expression' operator is not a procedure value");
										raise(3);
									}}
		case ARRAY_EXP:				{void *val = valueof(n->list[0], env);
									if (!checkValueType(IntVal, val)) {
										kissError(n->line, "'array expression' size is not an Integer value");
										raise(3);
									}
									return newValue(ArrayVal, IntVal_GetCInt(val));}
		case ARRAY_GET_EXP:			{void *arr = valueof(n->list[0], env);
									if (!checkValueType(ArrayVal, arr)) {
										kissError(n->line, "'array get expression' array is not an array value");
										raise(3);
									}
									void *i = valueof(n->list[1], env);
									if (!checkValueType(IntVal, i)) {
										kissError(n->line, "'array get expression' index is not an Integer value");
										raise(3);
									}
									void *val;
									if (ArrayVal_Get(arr, IntVal_GetCInt(i), &val)) return val;
									else {
										kissError(n->line, "'array get expression' index is not in range");
										raise(3);
									}}
		case ARRAY_SET_EXP:			{void *arr = valueof(n->list[0], env);
									if (!checkValueType(ArrayVal, arr)) {
										kissError(n->line, "'array set expression' array is not an array value");
										raise(3);
									}
									void *i = valueof(n->list[1], env);
									if (!checkValueType(IntVal, i)) {
										kissError(n->line, "'array set expression' index is not an Integer value");
										raise(3);
									}
									void *val = valueof(n->list[2], env);
									if (ArrayVal_Set(arr, IntVal_GetCInt(i), val)) return val;
									else {
										kissError(n->line, "'array set expression' index is not in range");
										raise(3);
									}}
		case IF_ELSE_EXP:			{void *pred = valueof(n->list[0], env);
									if (!checkValueType(BoolVal, pred)) {
										kissError(n->line, "'if-else expression' predicate is not a Boolean value");
										raise(3);
									}
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
									else {
										kissError(n->line, "Number unary operation operand is not an Integer value");
										raise(3);
									}}
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
									else {
										kissError(n->line, "Boolean unary operation operand is not a Boolean value");
										raise(3);
									}}

		case ONE_ASSIGN_AL:			{void *val = valueof(n->list[1], env);
									if (!extendFrame(env, n->list[0], val)) {
										kissError(n->line, "Redefinition of variable \"%s\"", (char *) n->list[0]);
										raise(3);
									}
									return val;}
		case MUL_ASSIGN_AL:			{void *val = valueof(n->list[1], env);
									if (!extendFrame(env, n->list[0], val)) {
										kissError(n->line, "Redefinition of variable \"%s\"", (char *) n->list[0]);
										raise(3);
									}
									return valueof(n->list[2], env);}

		case INTEGER_CONST:			return IntVal_FromString(n->list[0]);
		case BOOLEAN_CONST:			return newValue(BoolVal, *(char *) n->list[0]);
		case STRING_CONST:			return StringVal_FromRaw(n->list[0]);
		case CHARACTER_CONST:		return CharVal_FromRaw(n->list[0]);
	}

	return NULL;
}

