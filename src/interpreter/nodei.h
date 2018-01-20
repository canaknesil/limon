#ifndef NODEI_H
#define NODEI_H


struct node { 
	int type; 
	void **list; 
};

void varcpy(char **orj);

void kissError(char *str);
void kissWarning(char *str);


#endif
