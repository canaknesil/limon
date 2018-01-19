#include "valueClass.h"
#include "ProcVal.h"
#include "newValue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// class attributes
struct ProcVal
{
	const void *class;
	void *bVarList;
	void *body;
	void *env;
};


// dynamically linked methodes
void * ProcVal_ctor(void *_self, va_list *args)
{
	struct ProcVal *self = _self;
	
	self->bVarList = va_arg(*args, void *);
	self->body = va_arg(*args, void *);
	self->env = va_arg(*args, void *);
	
	return self;
}

void * ProcVal_dtor(void *_self) 
{
	struct ProcVal *self = _self;
	return self;
}

void ProcVal_print(void *_self)
{
	//struct ProcVal *self = _self;
	printf("#procedure\n");
}


// class metadata
const struct valueClass _ProcVal = 
{ sizeof(struct ProcVal), ProcVal_ctor, ProcVal_dtor, ProcVal_print };

const void * ProcVal = & _ProcVal;


// class methodes
void *ProcVal_GetBVarList(void *_proc)
{
	struct ProcVal *proc = _proc;
	return proc->bVarList;
}

void *ProcVal_GetBody(void *_proc)
{
	struct ProcVal *proc = _proc;
	return proc->body;
}

void *ProcVal_GetEnv(void *_proc)
{
	struct ProcVal *proc = _proc;
	return proc->env;
}








