#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>


int yybegin(FILE *file, void (* _handleProg)(void *prog));


#endif

