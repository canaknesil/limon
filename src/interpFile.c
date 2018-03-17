#include "interpFile.h"
#include "parser.h"
#include "interpreter/node.h"
#include "interpreter/tryCatch.h"
#include "interpreter/env/env.h"
#include "interpreter/value/value.h"
#include "interpreter/gc/gc.h"
#include <stddef.h>
#include <stdio.h>


static void handleAST(void *p)
{
	if (p == NULL) {
		printf("Empty program\n");
		return;
	}

	CEGC_initialize();

	void *initEnv = emptyFrameWithCEGC(NULL);

	//printAST(p, NULL);

	void *val = NULL;
	try {
		val = valueof(p, initEnv);
		printf("End of program with value: ");
		printValue(val); 
		printf("\n");
	} catch {
		printf("Error occured while interpretation.\n");
	}
	
	deleteNodeRec(p);
	CEGC_deleteAllAndFinalize();
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
