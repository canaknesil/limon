#ifndef INTVAL_H
#define INTVAL_H


// class descriptor is private
//const void * IntVal; //class   new(IntVal)

void * IntVal_FromString(char *str);

void * IntVal_Add(void *n1, void *n2);
void * IntVal_Sub(void *n1, void *n2);
void * IntVal_Mul(void *n1, void *n2);
void * IntVal_Div(void *n1, void *n2);
void * IntVal_Rem(void *n1, void *n2);
void * IntVal_Neg(void *n);

char IntVal_Eq(void *n1, void *n2);
char IntVal_Neq(void *n1, void *n2);
char IntVal_l(void *n1, void *n2);
char IntVal_g(void *n1, void *n2);
char IntVal_geq(void *n1, void *n2);
char IntVal_leq(void *n1, void *n2);



#endif
