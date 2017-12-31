%{
	#include "y.tab.h"
	#include <stdlib.h>

	void yyerror(char *);
%}

%%

0	{ yylval = atoi(yytext);
	  return INT; }

[0-9]+	{ yylval = atoi(yytext);
	  return INT; }

;	return *yytext;

[ \t\n]	;

.	yyerror("invalid character");

%%

int yywrap(void) {
	return 1;
}

