#ifndef TRYCATCH_H
#define TRYCATCH_H


#include <setjmp.h>


#define raise(N)        longjmp(__kiss_jmp_buff__, N)
#define try             int __KISS_EXC_NUM__ = setjmp(__kiss_jmp_buff__); if (__KISS_EXC_NUM__ == 0) 
#define catch else
#define KISS_EXCEPTION	__KISS_EXC_NUM__

extern jmp_buf __kiss_jmp_buff__;



#endif