%{
	#include <y.tab.h>
	#include <stdlib.h>

	void yyerror(char const *);
	extern int yyLineNo;
%}

%%
	/* multi-character keywords and operators */
"def"	return DEF;
">="	return GEQ;
"<="	return LEQ;
"=="	return EQ;
"!="	return NEQ;
"+="	return PLUSEQ;
"-="	return MINEQ;
"*="	return MULEQ;
"/="	return DIVEQ;
"%="	return REMEQ;
"&="	return ANDEQ;
"|="	return OREQ;
"print"	return PRINT;
"sizeof"	return SIZEOF;
"2str"	return TOSTR;
"2char"	return TOCHAR;
"2int"	return TOINT;
"while"	return WHILE;

"true"	{ yylval.bVal[0] = 1;
		  return BOOL; }

"false"	{ yylval.bVal[0] = 0;
		  return BOOL; }

	/* single character keywords and operators */
[;()[\]{}=@?:+\-*/%<>&\|!,$#]		return *yytext;

	/* string */
\"(\\.|[^\\"])*\"	{ strcpy(yylval.sVal, yytext);
		  			  return STRING; }

	/* character */
'([^\\]|[\\+.])'		{ strcpy(yylval.sVal, yytext);
		  			  	  return CHAR; }

	/* integer */
[0-9]+	{ strcpy(yylval.sVal, yytext);
		  return INT; }

	/* binary number */
0b[01]+	{ strcpy(yylval.sVal, yytext);
		  return BIN; }

	/* hexadecimal number */
0x[0-9A-Fa-f]+	{ strcpy(yylval.sVal, yytext);
				  return HEX; }

	/* identifier */
[A-Za-z_][A-Za-z0-9_]*	{ strcpy(yylval.sVal, yytext);
		  				  return VAR; }

	/* comments */
"//"([^\n])*[\n]	;
"/*"([^*]|\*+[^*/])*\*+"/"	;

	/* counting line number */
\n	yyLineNo++;

	/* ignored whitespace characters */
[ \t]+	;

	/* other */
.	;

%%

// terminate scanner after EOF
int yywrap(void) {
	return 1;
}

