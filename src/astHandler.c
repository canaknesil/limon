#include "astHandler.h"
#include "interpreter/node.h"
#include "interpreter/env/env.h"
#include "interpreter/value/value.h"
#include <stddef.h>
#include <stdio.h>


void handleAST(void *p)
{
	if (p == NULL) {
		printf("Empty program\n");
		return;
	}

	void *initEnv = emptyFrame(NULL);

	printAST(p, NULL);				  
	void *val = valueof(p, initEnv);
	
	printf("End of program with value: ");
	printValue(val); 
	printf("\n");
	
	// TODO recursively delete nodes
	deleteValue(val);
	deleteFrame(initEnv);
}