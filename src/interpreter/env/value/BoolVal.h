#ifndef BOOLVAL_H
#define BOOLVAL_H


#define TRUE 1
#define FALSE 0

const void * BoolVal; //class   newValue(BoolVal, (int) boolMacro)

void * BoolVal_And(void *b1, void *b2);
void * BoolVal_Or(void *b1, void *b2);
void * BoolVal_Eq(void *b1, void *b2);
void * BoolVal_Neq(void *b1, void *b2);
void * BoolVal_Not(void *b);

char BoolVal_GetVal(void *b);


#endif


