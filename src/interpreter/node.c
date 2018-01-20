#include "node.h"
#include "nodei.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "env/value/value.h"
#include "env/env.h"



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
		case ASSIGN_EXP:		varcpy((char **) &(n->list[0])); break;
		case VAR_EXP:			varcpy((char **) &(n->list[0])); break;
		case ONE_ASSIGN_AL:		varcpy((char **) &(n->list[0])); break;
		case MUL_ASSIGN_AL:		varcpy((char **) &(n->list[0])); break;
		case ONE_VAR_VL:		varcpy((char **) &(n->list[0])); break;
		case MUL_VAR_VL:		varcpy((char **) &(n->list[0])); break;
		case INTEGER_CONST:		varcpy((char **) &(n->list[0])); break;
		case BOOLEAN_CONST:		{char *b = malloc(sizeof(char));
								*b = *((char *) n->list[0]);
								n->list[0] = b;
								break;}
	}
	
	va_end(args);
	
	return n;
}


void deleteNode(void *_n)
{
	struct node *n = _n;

	switch (n->type)
	{
		case ASSIGN_EXP:		free(n->list[0]); break;
		case VAR_EXP:			free(n->list[0]); break;
		case ONE_ASSIGN_AL:		free(n->list[0]); break;
		case MUL_ASSIGN_AL:		free(n->list[0]); break;
		case ONE_VAR_VL:		free(n->list[0]); break;
		case MUL_VAR_VL:		free(n->list[0]); break;
		case INTEGER_CONST:		free(n->list[0]); break;
		case BOOLEAN_CONST:		free(n->list[0]); break;
	}

	if (n->list) free(n->list);
	free(n);
}


void deleteNodeRec(void *_n)
{
	// TODO
}


void kissError(char *str)
{
	printf("KISS ERROR: %s\n", str);
	exit(1);
}

void kissWarning(char *str)
{
	printf("KISS WARNING: %s\n", str);
}






