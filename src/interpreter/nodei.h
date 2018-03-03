#ifndef NODEI_H // Implicit interface for some functions used by interpreter
#define NODEI_H


struct node { 
	int type; 
	void **list; 
};


void kissError(char *str, ...);
void kissWarning(char *str, ...);


#endif
