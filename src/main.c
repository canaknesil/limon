#include "main.h"
#include "interpreter/node.h"
#include "interpreter/env/env.h"
#include "interpreter/value/value.h"
#include <stddef.h>
#include <stdio.h>


void handleAST(void *p, int argc, char **argv)
{
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
