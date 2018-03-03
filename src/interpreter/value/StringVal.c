#include "valueClass.h"
#include "StringVal.h"
#include "newValue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// class attributes
struct StringVal
{
	const void *class;
	char *str;
};


// dynamically linked methodes
void * StringVal_ctor(void *_self, va_list *args)
{
	struct StringVal *self = _self;
	
	self->str = NULL;
	return self;
}

void * StringVal_dtor(void *_self) 
{
    struct StringVal *self = _self;

    if (self->str != NULL) free(self->str);
	return self;
}

void StringVal_print(void *_self)
{
	struct StringVal *self = _self;
	printf("%s", self->str);
}


// class metadata
const struct valueClass _StringVal = 
{ sizeof(struct StringVal), StringVal_ctor, StringVal_dtor, StringVal_print };

const void * StringVal = & _StringVal;




// class methodes

void * StringVal_FromRaw(const char *_raw)
{
    size_t len = strlen(_raw);
    if (len < 2) return NULL;

    char *rawq = malloc(sizeof(char) * (len + 1));
    strcpy(rawq, _raw);

    // get rid of quotations
    rawq[len-1] = '\0';
    char *raw = rawq + 1;
    len -= 2;

    char *str = malloc(sizeof(char) * (len + 1));
    
    int c = 0;
    for (int i=0; i<len; i++) 
    {
        if (raw[i] == '\\') {
            i++;
            switch(raw[i]) {
                case 'a': str[c++] = '\a'; break;
                case 'b': str[c++] = '\b'; break;
                case 'f': str[c++] = '\f'; break;
                case 'n': str[c++] = '\n'; break;
                case 'r': str[c++] = '\r'; break;
                case 't': str[c++] = '\t'; break;
                case 'v': str[c++] = '\v'; break;
                case '"': str[c++] = '"';  break;               
                case '\\':str[c++] = '\\'; break;
                case '?': str[c++] = '\?'; break;
                default: 
                    free(str);
                    free(rawq);
                    return NULL;
            }
        } else {
            str[c++] = raw[i];
        }
    }
    str[c] = '\0';

    void *val = StringVal_FromString(str);
    free(str);
    free(rawq);
    return val;
}

void * StringVal_FromString(const char *str)
{
    struct StringVal *val = newValue(StringVal);
    val->str = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(val->str, str);
    return val;
}

char * StringVal_GetCString(void *_s)
{
    struct StringVal *s = _s;
    char *str = malloc(sizeof(char) * (strlen(s->str) + 1));
    strcpy(str, s->str);
    return str;
}

char StringVal_CharAt(void *_s, size_t i, char *ch)
{
    struct StringVal *s = _s;
    if (i >= strlen(s->str)) return 0;
    *ch = s->str[i];
    return 1;
}

void * StringVal_Concat(void *_s1, void *_s2)
{
    struct StringVal *s1 = _s1, *s2 = _s2;

    char *str = malloc(sizeof(char) * (strlen(s1->str) + strlen(s2->str) + 1));
    strcpy(str, s1->str);
    strcat(str, s2->str);

    void * val = StringVal_FromString(str);
    free(str);
    return val;
}




