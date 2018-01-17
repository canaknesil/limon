%{
	#include "y.tab.h"
	#include <stdlib.h>

	void yyerror(char *);
%}

%%

[0-9]+	{ strcpy(yylval.sVal, yytext);
		  return INT; }

[;()[\]{}=@?:+\-*/%<>&\|!,]		return *yytext;

"def"	return DEF;
"if"	return IF;
"else"	return ELSE;
">="	return GEQ;
"<="	return LEQ;
"=="	return EQ;
"!="	return NEQ;
"while"	return WHILE;
"print"	return PRINT;

"true"	{ yylval.bVal = 1;
		  return BOOL; }

"false"	{ yylval.bVal = 0;
		  return BOOL; }

[ \t\n]+	;

[A-Za-z_][A-Za-z0-9]*	{ strcpy(yylval.sVal, yytext);
		  				  return VAR; }

%%

int yywrap(void) {
	return 1;
}

