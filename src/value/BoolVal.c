#include "valueClass.h"
#include "BoolVal.h"
#include "newValue.h"
#include <stdlib.h>
#include <stdio.h>

// class attributes
struct BoolVal
{
	const void *class;
	char b;
};


// dynamically linked methodes
void * BoolVal_ctor(void *_self, va_list *args)
{
	struct BoolVal *self = _self;
	
	self->b = va_arg(*args, int);
	return self;
}

void * BoolVal_dtor(void *self) 
{
	return self;
}

void BoolVal_print(void *_self)
{
	struct BoolVal *self = _self;
	printf("%s\n", self->b ? "#true" : "#false");
}


// class metadata
const struct valueClass _BoolVal = 
{ sizeof(struct BoolVal), BoolVal_ctor, BoolVal_dtor, BoolVal_print };

const void * BoolVal = & _BoolVal;


// class methodes
void * BoolVal_And(void *_b1, void *_b2)
{
	struct BoolVal *b1 = _b1, *b2 = _b2;
	
	struct BoolVal *result = newValue(BoolVal, b1->b && b2->b);
	return result;
}

void * BoolVal_Or(void *_b1, void *_b2)
{
	struct BoolVal *b1 = _b1, *b2 = _b2;
	
	struct BoolVal *result = newValue(BoolVal, b1->b || b2->b);
	return result;
}


void * BoolVal_Eq(void *_b1, void *_b2)
{
	struct BoolVal *b1 = _b1, *b2 = _b2;
	
	struct BoolVal *result = newValue(BoolVal, b1->b == b2->b);
	return result;
}

void * BoolVal_Neq(void *_b1, void *_b2)
{
	struct BoolVal *b1 = _b1, *b2 = _b2;
	
	struct BoolVal *result = newValue(BoolVal, b1->b != b2->b);
	return result;
}

void * BoolVal_Not(void *_b)
{
	struct BoolVal *b = _b;
	
	struct BoolVal *result = newValue(BoolVal, !b->b);
	return result;
}

char BoolVal_GetVal(void *_b)
{
	struct BoolVal *b = _b;
	
	return b->b;
}





