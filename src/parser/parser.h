/*
 * Interface for scanner&parser (lex and yacc)
 */

#ifndef PARSER_H 
#define PARSER_H

#include <node.h>

#include <stdio.h>


class LimonParser
{
public:
  static Node *parse(FILE *f, string filename);
};


#endif
