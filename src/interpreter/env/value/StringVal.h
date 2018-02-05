#ifndef STRINGVAL_H
#define STRINGVAL_H

#include <stddef.h>


const void * StringVal; //class   newValue(StringVal)

void * StringVal_FromRaw(char *str);
void * StringVal_FromString(char *str);

char * StringVal_GetCString(void *s);

char StringVal_CharAt(void *s, size_t i, char *ch);
void * StringVal_Concat(void *s1, void *s2);



#endif
