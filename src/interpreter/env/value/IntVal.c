#include "valueClass.h"
#include "IntVal.h"
#include "newValue.h"
#include <stdlib.h>
#include <stdio.h>

// class attributes
struct IntVal
{
	const void *class;
	int n;
};


// dynamically linked methodes
void * IntVal_ctor(void *_self, va_list *args)
{
	struct IntVal *self = _self;
	
	self->n = 0;
	return self;
}

void * IntVal_dtor(void *self) 
{
	return self;
}

void IntVal_print(void *_self)
{
	struct IntVal *self = _self;
	printf("%d", self->n);
}


// class metadata
const struct valueClass _IntVal = 
{ sizeof(struct IntVal), IntVal_ctor, IntVal_dtor, IntVal_print };

const void * IntVal = & _IntVal;


// class methodes
void * IntVal_FromString(char *str)
{
	struct IntVal *val = newValue(IntVal);
	val->n = atoi(str);
	return val;
}

void * IntVal_FromInt(int n)
{
	struct IntVal *val = newValue(IntVal);
	val->n = n;
	return val;
}

int IntVal_GetCInt(void *_n)
{
	struct IntVal *n = _n;
	return n->n;
}

void * IntVal_Add(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	struct IntVal *result = newValue(IntVal);
	result->n = n1->n + n2->n;
	
	return result;
}

void * IntVal_Sub(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	struct IntVal *result = newValue(IntVal);
	result->n = n1->n - n2->n;
	
	return result;
}

void * IntVal_Mul(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	struct IntVal *result = newValue(IntVal);
	result->n = n1->n * n2->n;
	
	return result;
}

void * IntVal_Div(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	struct IntVal *result = newValue(IntVal);
	result->n = n1->n / n2->n;
	
	return result;
}

void * IntVal_Rem(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	struct IntVal *result = newValue(IntVal);
	result->n = n1->n % n2->n;
	
	return result;
}

void * IntVal_Neg(void *_n)
{
	struct IntVal *n = _n;
	
	struct IntVal *result = newValue(IntVal);
	result->n = -n->n;
	
	return result;
}

char IntVal_Eq(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	return n1->n == n2->n;
}

char IntVal_Neq(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	return n1->n != n2->n;
}

char IntVal_L(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	return n1->n < n2->n;
}

char IntVal_G(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	return n1->n > n2->n;
}

char IntVal_Geq(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	return n1->n >= n2->n;
}

char IntVal_Leq(void *_n1, void *_n2)
{
	struct IntVal *n1 = _n1, *n2 = _n2;
	
	return n1->n <= n2->n;
}




