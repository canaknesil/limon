#ifndef NODEI_H // Implicit interface for some functions used by interpreter
#define NODEI_H

#include "tryCatch.h"

struct node { 
	int type; 
	int line;
	void **list; 
};


void kissError(int line, char *str, ...);
void kissWarning(int line, char *str, ...);



#endif
