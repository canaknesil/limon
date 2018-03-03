#ifndef VALUECLASS_H // inplicit blueprint for "class" structure for each class.
#define VALUECLASS_H

#include <stdarg.h>
#include <stdlib.h>


// class metadata structure
struct valueClass
{
	size_t size;
	void *(*ctor) (void *self, va_list *args);
	void *(*dtor) (void *self);
	void (*print) (void *self);
};


#endif
