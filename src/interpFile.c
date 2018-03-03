#include "interpFile.h"
#include "parser.h"
#include "interpreter/node.h"
#include "interpreter/env/env.h"
#include "interpreter/value/value.h"
#include <stddef.h>
#include <stdio.h>


static void handleAST(void *p)
{
	if (p == NULL) {
		printf("Empty program\n");
		return;
	}

	void *initEnv = emptyFrame(NULL);

	//printAST(p, NULL);				  
	void *val = valueof(p, initEnv);
	
	printf("End of program with value: ");
	printValue(val); 
	printf("\n");
	
	// TODO recursively delete nodes
	deleteValue(val);
	deleteFrame(initEnv);
}


int interpFile(char *filename)
{
	FILE *f = fopen(filename, "r");
	if (!f) {
		printf("Can not open file \"%s\".\n", filename);
		return 1;
	}

	int res = yybegin(f, &handleAST);

	fclose(f);
	return res;
}
