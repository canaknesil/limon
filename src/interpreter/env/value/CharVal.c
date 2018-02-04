#include "valueClass.h"
#include "CharVal.h"
#include "newValue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// class attributes
struct CharVal
{
	const void *class;
	char ch;
};


// dynamically linked methodes
void * CharVal_ctor(void *_self, va_list *args)
{
	struct CharVal *self = _self;
	
	self->ch = '\0';
	return self;
}

void * CharVal_dtor(void *self) 
{
	return self;
}

void CharVal_print(void *_self)
{
	struct CharVal *self = _self;
	printf("%c", self->ch);
}


// class metadata
const struct valueClass _CharVal = 
{ sizeof(struct CharVal), CharVal_ctor, CharVal_dtor, CharVal_print };

const void * CharVal = & _CharVal;




// class methodes

//private
char escapeSequence(char ec)
{
    switch(ec) {
        case 'a': return '\a';
        case 'b': return '\b';
        case 'f': return '\f';
        case 'n': return '\n';
        case 'r': return '\r';
        case 't': return '\t';
        case 'v': return '\v';
        case '\'': return '\'';
        case '"': return '"';
        case '\\': return '\\';
        case '?': return '\?';
        default: return -1;
    }
}

void * CharVal_FromRaw(char *str)
{
    size_t len = strlen(str);
    if (len < 3 || len > 4) {
        return NULL;
    }

    char ch;

    if (len == 3) {
        ch = str[1];
    } else if (str[1] == '\\') {
        ch = escapeSequence(str[2]);
    } else {
        return NULL;
    }

    if (ch < 0) {
        return NULL;
    }

    struct CharVal *val = newValue(CharVal);
    val->ch = ch;

	return val;
}



void * CharVal_FromInt(int n)
{
    if (n >= 0 && n < 128) {
        struct CharVal *val = newValue(CharVal);
        val->ch = n;
	    return val;
    } else {
        return NULL;
    }
}



char CharVal_GetCChar(void *_c)
{
    struct CharVal *c = _c;
    return c->ch;
}




int CharVal_Add(void *_c1, void *_c2)
{
	struct CharVal *c1 = _c1, *c2 = _c2;
	return ((int) c1->ch) + ((int) c2->ch);
}

int CharVal_Sub(void *_c1, void *_c2)
{
	struct CharVal *c1 = _c1, *c2 = _c2;
	return ((int) c1->ch) - ((int) c2->ch);
}

char CharVal_Eq(void *_c1, void *_c2)
{
	struct CharVal *c1 = _c1, *c2 = _c2;
	
	return c1->ch == c2->ch;
}

char CharVal_Neq(void *_c1, void *_c2)
{
	struct CharVal *c1 = _c1, *c2 = _c2;
	
	return c1->ch != c2->ch;
}

char CharVal_G(void *_c1, void *_c2)
{
	struct CharVal *c1 = _c1, *c2 = _c2;
	
	return c1->ch > c2->ch;
}

char CharVal_L(void *_c1, void *_c2)
{
	struct CharVal *c1 = _c1, *c2 = _c2;
	
	return c1->ch < c2->ch;
}

char CharVal_Geq(void *_c1, void *_c2)
{
	struct CharVal *c1 = _c1, *c2 = _c2;
	
	return c1->ch >= c2->ch;
}

char CharVal_Leq(void *_c1, void *_c2)
{
	struct CharVal *c1 = _c1, *c2 = _c2;
	
	return c1->ch <= c2->ch;
}




