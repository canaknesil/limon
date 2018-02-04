#ifndef INTVAL_H
#define INTVAL_H


const void * IntVal; //class   newValue(IntVal)

void * IntVal_FromString(char *str);
void * IntVal_FromInt(int n);

int IntVal_GetCInt(void *n);

void * IntVal_Add(void *n1, void *n2);
void * IntVal_Sub(void *n1, void *n2);
void * IntVal_Mul(void *n1, void *n2);
void * IntVal_Div(void *n1, void *n2);
void * IntVal_Rem(void *n1, void *n2);
void * IntVal_Neg(void *n);

char IntVal_Eq(void *n1, void *n2);
char IntVal_Neq(void *n1, void *n2);
char IntVal_L(void *n1, void *n2);
char IntVal_G(void *n1, void *n2);
char IntVal_Geq(void *n1, void *n2);
char IntVal_Leq(void *n1, void *n2);



#endif
