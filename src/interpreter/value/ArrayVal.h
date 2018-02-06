#ifndef ARRAYVAL_H
#define ARRAYVAL_H

#include <stddef.h>

const void * ArrayVal; //class   newValue(ArrayVal, (size_t) size)

char ArrayVal_Set(void *arr, size_t i, void *val);
char ArrayVal_Get(void *arr, size_t i, void **val);


#endif


