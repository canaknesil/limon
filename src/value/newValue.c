#include "valueClass.h"
#include "newValue.h"


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
	const struct valueClass **cp = self;
	self = (*cp)->dtor(self);
	
	free(self);
}


void printValue(void *self)
{
	const struct valueClass **cp = self;
	(*cp)->print(self);
}