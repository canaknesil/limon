#ifndef PARSER_H // Interface for scanner&parser (lex and yacc)
#define PARSER_H

#include <node.h>

#include <stdio.h>


class KissParser
{
  public:
	int parse(FILE *f);
	virtual void interpretExp(Node *exp) = 0;
};


#endif
