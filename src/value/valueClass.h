#ifndef CLASS_H
#define CLASS_H

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
