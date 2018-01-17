#include "node.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "value/value.h"


struct node { 
	int type; 
	void **list; 
};



void * newNode(int type, ...)
{
	struct node *n = malloc(sizeof(struct node));
	n->type = type;
	int argN = GET_N(type);
	if (argN) n->list = malloc(sizeof(void *) * argN);
	else n->list = NULL;

	va_list args;
	va_start(args, type);
	for (int i = 0; i < argN; i++) n->list[i] = va_arg(args, void *);
	va_end(args);
	
	return n;
}


void deleteNode(void *_n)
{
	struct node *n = _n;
	if (n->list) free(n->list);
	free(n);
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

		case ONE_STATEMENT_SL:		return printNode(n, "a-statement");
		case MUL_STATEMENT_SL:		return printNode(n, "statement-list");

		case EXPRESSION_S:			return printNode(n, "an-expression");
		case COMPOUND_S:			return printNode(n, "compound-statement");
		case VAR_DEF_INIT_S:		return printNode(n, "var-def-init");
		case VAR_DEF_S:				return printNode(n, "var-def");
		case FUNC_DEF_S:			return printNode(n, "func-def");
		case IF_S:					return printNode(n, "if-statement");
		case IF_ELSE_S:				return printNode(n, "if-else-statement");
		case WHILE_S:				return printNode(n, "while-statement");
		case PRINT_S:				return printNode(n, "print-statement");

		case ASSIGN_EXP:			return printNode(n, "assign-exp");
		case CONSTANT_EXP:			return printNode(n, "constant-exp");
		case VAR_EXP:				return printNode(n, "var-exp");
		case PROC_EXP:				return printNode(n, "proc-exp");
		case VAR_CALL_EXP:			return printNode(n, "var-call-exp");
		case EXP_CALL_EXP:			return printNode(n, "exp-call-exp");
		case ARRAY_EXP:				return printNode(n, "array-exp");
		case VAR_ARRAY_GET_EXP:		return printNode(n, "var-array-get-exp");
		case EXP_ARRAY_GET_EXP:		return printNode(n, "exp-array-get--exp");
		case VAR_ARRAY_SET_EXP:		return printNode(n, "var-array-set-exp");
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

		case INTEGER_CONST:			printSpace(); printValue(n->list[0]);
	}

	return NULL;
}


void *evaluate(void *n, void *env)
{
	return printAST(n, env);
}