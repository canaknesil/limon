#include "valueClass.h"
#include "newValue.h"
#include <stdio.h>


void *newValue(const void *cl, ...);
void deleteValue(void *val);
void printValue(void *val);



void * newValue(const void *_class, ...)
{
	const struct valueClass *class = _class;
	
	void *inst = malloc(class->size);
	*((const struct valueClass **) inst) = class;
	
	va_list args;
	va_start(args, _class);
	
	inst = class->ctor(inst, &args);
	
	va_end(args);
	
	return inst;
}


void deleteValue(void *self)
{
	if (self == NULL)
	{
		printf("Can't delete NULL value\n");
		return;
	}
	
	const struct valueClass **cp = self;
	self = (*cp)->dtor(self);
	
	free(self);
}


void printValue(void *self)
{
	if (self == NULL)
	{
		printf("Can't print NULL value\n");
		return;
	}

	const struct valueClass **cp = self;
	(*cp)->print(self);
}


char checkValueType(const void *_des, void *_val)
{
	return _des == *((struct valueClass **) _val);
}
