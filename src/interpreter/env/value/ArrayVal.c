#include "valueClass.h"
#include "ArrayVal.h"
#include "newValue.h"
#include <stdlib.h>
#include <stdio.h>

// class attributes
struct ArrayVal
{
	const void *class;
	size_t size;
	void **list;
};



// dynamically linked methodes
void * ArrayVal_ctor(void *_self, va_list *args)
{
	struct ArrayVal *self = _self;
	
	int size = va_arg(*args, size_t);
	self->size = size;

	self->list = malloc(sizeof(void *) * size);
	for (int i=0; i<size; i++) self->list[i] = NULL;

	return self;
}

void * ArrayVal_dtor(void *_self) 
{
	struct ArrayVal *self = _self;
	free(self->list);
	return self;
}

void ArrayVal_print(void *_self)
{
	struct ArrayVal *self = _self;
	printf("[");
	if (self->size > 0) 
	{
		printValue(self->list[0]);
	}
	for (int i=1; i<self->size; i++)
	{
		printf(" ");
		printValue(self->list[i]);
	}
	printf("]");
}


// class metadata
const struct valueClass _ArrayVal = 
{ sizeof(struct ArrayVal), ArrayVal_ctor, ArrayVal_dtor, ArrayVal_print };

const void * ArrayVal = & _ArrayVal;


// class methodes

char ArrayVal_Set(void *_self, size_t i, void *val)
{
	struct ArrayVal *self = _self;

	if (i >= self->size) return 0;

	self->list[i] = val;	
	return 1;
}


char ArrayVal_Get(void *_self, size_t i, void **val)
{
	struct ArrayVal *self = _self;

	if (i >= self->size) return 0;

	*val = self->list[i];	
	return 1;
}