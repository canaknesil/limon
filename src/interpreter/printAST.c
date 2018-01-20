#include "node.h"
#include "nodei.h"
#include "env/value/value.h"
#include "env/env.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



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
		printAST(n->list[i], NULL);
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
		case IF_S:					return printNode(n, "if-s");
		case IF_ELSE_S:				return printNode(n, "if-else-s");
		case WHILE_S:				return printNode(n, "while-s");
		case PRINT_S:				return printNode(n, "print-s");

		case ASSIGN_EXP:			printSpace(); printf("assign-exp\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									printAST(n->list[1], NULL);
									level--;
									return NULL;
		case CONSTANT_EXP:			return printNode(n, "constant-exp");
		case VAR_EXP:				printSpace(); printf("var-exp\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									level--;
									return NULL;
		case PROC_EXP:				return printNode(n, "proc-exp");
		case CALL_EXP:				return printNode(n, "call-exp");
		case ARRAY_EXP:				return printNode(n, "array-exp");
		case ARRAY_GET_EXP:			return printNode(n, "array-get-exp");
		case ARRAY_SET_EXP:			return printNode(n, "array-set-exp");
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
									printAST(n->list[1], NULL);
									level--;
									return NULL;
		case MUL_ASSIGN_AL:			printSpace(); printf("mul-assign-al\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									printAST(n->list[1], NULL);
									printAST(n->list[2], NULL);
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
									printAST(n->list[1], NULL);
									level--;
									return NULL;

		case INTEGER_CONST:			printSpace(); printf("integer-const\n"); level++;
									printSpace(); printf("%s\n", (char *) n->list[0]);
									level--;
									return NULL;
		case BOOLEAN_CONST:			printSpace(); printf("boolean-const\n"); level++;
									printSpace(); printf("%d\n", *(char *) n->list[0]);
									level--;
									return NULL;
	}

	return NULL;
}
