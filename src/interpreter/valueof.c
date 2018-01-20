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
							{
								char str[128];
								sprintf(str, "Redefinition of variable %s", (char *) n->list[0]);
								kissError(str);
							}
							break;
		case MUL_VAR_VL:	if (!extendFrame(env, n->list[0], NULL))
							{
								char str[128];
								sprintf(str, "Redefinition of variable %s", (char *) n->list[0]);
								kissError(str);
							}
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
	//deleteFrame(newEnv);
	return val;
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
									//deleteFrame(newEnv);
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
		case WHILE_S:				{void *pred = valueof(n->list[0], env);
									if (!checkValueType(BoolVal, pred)) kissError("while statement predicate: Expected Boolean value");
									if (!BoolVal_GetVal(pred)) return NULL;
									else
									{
										valueof(n->list[1], env);
										return valueof(n, env);
									}}
		case PRINT_S:				{void *val = valueof(n->list[0], env);
									if (val == NULL) 
									{
										kissWarning("This expresson does not produce a printable value");
										return NULL;
									}
									else {
										printValue(val);
										return val;
									}
									return NULL;}

		case ASSIGN_EXP:			{void *val = valueof(n->list[1], env);
									if (setEnv(env, n->list[0], val)) return val;
									else {
										char str[128];
										sprintf(str, "Variable %s does not exist", (char *) n->list[0]);
										kissError(str);
									}}
		case CONSTANT_EXP:			return valueof(n->list[0], env);
		case VAR_EXP:				{void *val = NULL;
									if (applyEnv(env, n->list[0], &val)) return val;
									else {
										char str[128];
										sprintf(str, "Variable %s does not exist", (char *) n->list[0]);
										kissError(str);
									}}
		case PROC_EXP:				return newValue(ProcVal, n->list[0], n->list[1], env);
		case CALL_EXP:				{void *proc = valueof(n->list[0], env);
									if (checkValueType(ProcVal, proc))
										return applyProcedure(proc, n->list[1]);
									else
										kissError("call expression: procedure does not evaluate to a procedure value");}
		case ARRAY_EXP:				break;
		case ARRAY_GET_EXP:			break;
		case ARRAY_SET_EXP:			break;
		case IF_EXP:				break;
		case IF_ELSE_EXP:			break;
		case ADD_EXP:				break;
		case SUB_EXP:				break;
		case MUL_EXP:				break;
		case DIV_EXP:				break;
		case REM_EXP:				break;
		case MIN_EXP:				break;
		case EQ_EXP:				break;
		case NEQ_EXP:				break;
		case L_EXP:					break;
		case G_EXP:					break;
		case GEQ_EXP:				break;
		case LEQ_EXP:				break;
		case AND_EXP:				break;
		case OR_EXP:				break;
		case NOT_EXP:				break;

		case ONE_ASSIGN_AL:			if (!extendFrame(env, n->list[0], valueof(n->list[1], env)))
									{
										char str[128];
										sprintf(str, "Redefinition of variable %s", (char *) n->list[0]);
										kissError(str);
									}
									return NULL;
		case MUL_ASSIGN_AL:			if (!extendFrame(env, n->list[0], valueof(n->list[1], env)))
									{
										char str[128];
										sprintf(str, "Redefinition of variable %s", (char *) n->list[0]);
										kissError(str);
									}
									return valueof(n->list[2], env);

		case NEMPTY_ARG_LIST:		break;
		case EMPTY_ARG_LIST:		break;
		case ONE_ARG_AL:			break;
		case MUL_ARG_AL:			break;

		case NEMPTY_VAR_LIST:		break;
		case EMPTY_VAR_LIST:		break;
		case ONE_VAR_VL:			break;
		case MUL_VAR_VL:			break;

		case INTEGER_CONST:			return IntVal_FromString(n->list[0]);
		case BOOLEAN_CONST:			return newValue(BoolVal, *(char *) n->list[0]);
	}

	return NULL;
}

