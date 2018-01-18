#include "node.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "value/value.h"
#include "env/env.h"


struct node { 
	int type; 
	void **list; 
};


void varcpy(char **orj)
{
	char *var = malloc((strlen(*orj) + 1) * sizeof(char));
	strcpy(var, *orj);
	*orj = var;
}


void * newNode(int type, ...)
{
	struct node *n = malloc(sizeof(struct node));
	n->type = type;
	int argN = GET_N(type);
	if (argN) n->list = malloc(sizeof(void *) * argN);
	else n->list = NULL;

	va_list args;
	va_start(args, type);

	for (int i=0; i<argN; i++) n->list[i] = va_arg(args, void *);
	
	switch (n->type)
	{
		case FUNC_DEF_S:		varcpy((char **) &(n->list[0])); break;
		case ASSIGN_EXP:		varcpy((char **) &(n->list[0])); break;
		case VAR_EXP:			varcpy((char **) &(n->list[0])); break;
		case VAR_CALL_EXP:		varcpy((char **) &(n->list[0])); break;
		case VAR_ARRAY_GET_EXP:	varcpy((char **) &(n->list[0])); break;
		case VAR_ARRAY_SET_EXP:	varcpy((char **) &(n->list[0])); break;
		case ONE_ASSIGN_AL:		varcpy((char **) &(n->list[0])); break;
		case MUL_ASSIGN_AL:		varcpy((char **) &(n->list[0])); break;
		case ONE_VAR_VL:		varcpy((char **) &(n->list[0])); break;
		case MUL_VAR_VL:		varcpy((char **) &(n->list[0])); break;
	}
	
	va_end(args);
	
	return n;
}


void deleteNode(void *_n)
{
	struct node *n = _n;

	switch (n->type)
	{
		case FUNC_DEF_S:		free(n->list[0]); break;
		case ASSIGN_EXP:		free(n->list[0]); break;
		case VAR_EXP:			free(n->list[0]); break;
		case VAR_CALL_EXP:		free(n->list[0]); break;
		case VAR_ARRAY_GET_EXP:	free(n->list[0]); break;
		case VAR_ARRAY_SET_EXP:	free(n->list[0]); break;
		case ONE_ASSIGN_AL:		free(n->list[0]); break;
		case MUL_ASSIGN_AL:		free(n->list[0]); break;
		case ONE_VAR_VL:		free(n->list[0]); break;
		case MUL_VAR_VL:		free(n->list[0]); break;
	}

	if (n->list) free(n->list);
	free(n);
}


void deleteNodeRec(void *_n)
{
	// TODO
}


int level = 0;
void printSpace()
{
	for (int i=0; i<level; i++) { printf("    "); }
}

void *printNode(struct node *n, char *name)
{
	printSpace(); printf("%s\n", name); level++;
	for (int i=0; i<GET_N(n->type); i++) 
	{
		evaluate(n->list[i], NULL);
	}
	level--;
	return NULL;
}

void *printAST(void *_n, void *env)
{
	if (!_n) return NULL;
	
	struct node *n = _n;
	switch (n->type)
	{
		case A_PROGRAM:				return printNode(n, "a-program");
		case EMPTY_PROGRAM:			return printNode(n, "empty-program");

		case ONE_STATEMENT_SL:		return printNode(n, "one-statement-sl");
		case MUL_STATEMENT_SL:		return printNode(n, "mul-statement-sl");

		case EXPRESSION_S:			return printNode(n, "expression-s");
		case COMPOUND_S:			return printNode(n, "compound-s");
		case VAR_DEF_INIT_S:		return printNode(n, "var-def-init-s");
		case VAR_DEF_S:				return printNode(n, "var-def-s");
		case FUNC_DEF_S:			printSpace(); printf("func-def-s\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									evaluate(n->list[1], NULL);
									evaluate(n->list[2], NULL);
									level--;
									return NULL;
		case IF_S:					return printNode(n, "if-s");
		case IF_ELSE_S:				return printNode(n, "if-else-s");
		case WHILE_S:				return printNode(n, "while-s");
		case PRINT_S:				return printNode(n, "print-s");

		case ASSIGN_EXP:			printSpace(); printf("assign-exp\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									evaluate(n->list[1], NULL);
									level--;
									return NULL;
		case CONSTANT_EXP:			return printNode(n, "constant-exp");
		case VAR_EXP:				printSpace(); printf("var-exp\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									level--;
									return NULL;
		case PROC_EXP:				return printNode(n, "proc-exp");
		case VAR_CALL_EXP:			printSpace(); printf("var-call-exp\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									evaluate(n->list[1], NULL);
									level--;
									return NULL;
		case EXP_CALL_EXP:			return printNode(n, "exp-call-exp");
		case ARRAY_EXP:				return printNode(n, "array-exp");
		case VAR_ARRAY_GET_EXP:		printSpace(); printf("var-array-get-exp\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									evaluate(n->list[1], NULL);
									level--;
									return NULL;
		case EXP_ARRAY_GET_EXP:		return printNode(n, "exp-array-get--exp");
		case VAR_ARRAY_SET_EXP:		printSpace(); printf("var-array-set-exp\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									evaluate(n->list[1], NULL);
									level--;
									return NULL;
		case EXP_ARRAY_SET_EXP:		return printNode(n, "exp-array-set-exp");
		case IF_EXP:				return printNode(n, "if-exp");
		case IF_ELSE_EXP:			return printNode(n, "if-else-exp");
		case ADD_EXP:				return printNode(n, "add-exp");
		case SUB_EXP:				return printNode(n, "sub-exp");
		case MUL_EXP:				return printNode(n, "mul-exp");
		case DIV_EXP:				return printNode(n, "div-exp");
		case REM_EXP:				return printNode(n, "rem-exp");
		case MIN_EXP:				return printNode(n, "min-exp");
		case EQ_EXP:				return printNode(n, "eq-exp");
		case NEQ_EXP:				return printNode(n, "neq-exp");
		case L_EXP:					return printNode(n, "l-exp");
		case G_EXP:					return printNode(n, "g-exp");
		case GEQ_EXP:				return printNode(n, "geq-exp");
		case LEQ_EXP:				return printNode(n, "leq-exp");
		case AND_EXP:				return printNode(n, "and-exp");
		case OR_EXP:				return printNode(n, "or-exp");
		case NOT_EXP:				return printNode(n, "not-exp");

		case ONE_ASSIGN_AL:			printSpace(); printf("one-assign-al\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									evaluate(n->list[1], NULL);
									level--;
									return NULL;
		case MUL_ASSIGN_AL:			printSpace(); printf("mul-assign-al\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									evaluate(n->list[1], NULL);
									evaluate(n->list[2], NULL);
									level--;
									return NULL;

		case NEMPTY_ARG_LIST:		return printNode(n, "nempty-arg-list");
		case EMPTY_ARG_LIST:		return printNode(n, "empty-arg-list");
		case ONE_ARG_AL:			return printNode(n, "one-arg-al");
		case MUL_ARG_AL:			return printNode(n, "mul-arg-al");

		case NEMPTY_VAR_LIST:		return printNode(n, "nempty-var-list");
		case EMPTY_VAR_LIST:		return printNode(n, "empty-var-list");
		case ONE_VAR_VL:			printSpace(); printf("one-var-vl\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									level--;
									return NULL;
		case MUL_VAR_VL:			printSpace(); printf("mul-var-vl\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									evaluate(n->list[1], NULL);
									level--;
									return NULL;

		case INTEGER_CONST:			printSpace(); printf("integer-const\n"); level++;
									printSpace(); printValue(n->list[0]);
									level--;
									return NULL;
		case BOOLEAN_CONST:			printSpace(); printf("boolean-const\n"); level++;
									printSpace(); printValue(n->list[0]);
									level--;
									return NULL;
	}

	return NULL;
}


void *evaluate(void *n, void *env)
{
	return printAST(n, env);
}
