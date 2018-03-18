#ifndef PARSER_H // Interface for scanner&parser (lex and yacc)
#define PARSER_H

#include <stdio.h>
#include <node.h>

// start parsing from file. Returns the program node.
Node * yybegin(FILE *file);


#endif

