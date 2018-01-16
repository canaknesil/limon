#ifndef NODE_H
#define NODE_H


// (ID << 8) + N_ARG
#define A_PROGRAM 		(0 << 8) + 1
#define EMPTY_PROGRAM	(1 << 8) + 0


void *newNode(int type, ...);
void deleteNode(void *node);
void *evaluate(void *node, void *env);


#endif


