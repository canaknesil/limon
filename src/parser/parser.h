#ifndef PARSER_H // Interface for scanner&parser (lex and yacc)
#define PARSER_H

#include <stdio.h>

// start parsing from file. After parsing handleProg is called with the AST.
extern "C" int yybegin(FILE *file, void (* _handleProg)(void *prog));


#endif

