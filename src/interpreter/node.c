#include "node.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


struct node { 
	int type; 
	void **list; 
};


int getArgN(int type)
{
	return type & 0xFF;
}


void * newNode(int type, ...)
{
	struct node *n = malloc(sizeof(struct node));
	n->type = type;
	int argN = getArgN(type);
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



void *evaluate(void *_n, void *env)
{
	if (!_n) return NULL;
	
	struct node *n = _n;
	switch (n->type)
	{
		case A_PROGRAM:			return evaluate(n->list[0], env);
		case EMPTY_PROGRAM:		return NULL;
	}

	return NULL;
}