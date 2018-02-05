#ifndef CHARVAL_H
#define CHARVAL_H


const void * CharVal; //class   newValue(CharVal)

void * CharVal_FromRaw(char *str);
void * CharVal_FromInt(int n);

char CharVal_GetCChar(void *n);

int CharVal_Add(void *c1, void *c2);
int CharVal_Sub(void *c1, void *c2);

char CharVal_Eq(void *c1, void *c2);
char CharVal_Neq(void *c1, void *c2);
char CharVal_L(void *c1, void *c2);
char CharVal_G(void *c1, void *c2);
char CharVal_Geq(void *c1, void *c2);
char CharVal_Leq(void *c1, void *c2);



#endif
