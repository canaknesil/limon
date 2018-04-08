%{
	#include <y.tab.h>
	#include <stdlib.h>

	void yyerror(char const *);
	extern int line;

%}

%%
	/* multi-character keywords and operators */
"def"		return DEF;
">="		return GEQ;
"<="		return LEQ;
"=="		return EQ;
"!="		return NEQ;
"+="		return PLUSEQ;
"-="		return MINEQ;
"*="		return MULEQ;
"/="		return DIVEQ;
"%="		return REMEQ;
"&="		return ANDEQ;
"|="		return OREQ;
"print"		return PRINT;
"scan"		return SCAN;
"sizeof"	return SIZEOF;
"2str"		return TOSTR;
"2char"		return TOCHAR;
"2int"		return TOINT;
"2float"	return TOFLOAT;
"while"		return WHILE;
"null"		return NULLTOK;
"run"		return RUN;

"true"	{ yylval.bVal[0] = true;
		  return BOOL; }

"false"	{ yylval.bVal[0] = false;
		  return BOOL; }

	/* single character keywords and operators */
[()[\]{}=@?:+\-*/%<>&\|!#]		return *yytext;

	/* string */
\"(\\.|[^\\"])*\"	{ yylval.sVal = new char[strlen(yytext) + 1];
					  strcpy(yylval.sVal, yytext);
		  			  return STRING; }

	/* character */
'(\\.|[^\\'])'		{ yylval.sVal = new char[strlen(yytext) + 1];
					  strcpy(yylval.sVal, yytext);
		  			  return CHAR; }

	/* integer */
[0-9]+	{ yylval.sVal = new char[strlen(yytext) + 1];
		  strcpy(yylval.sVal, yytext);
		  return INT; }

	/* binary integer */
0b[01]+	{ yylval.sVal = new char[strlen(yytext) + 1];
		  strcpy(yylval.sVal, yytext);
		  return BIN; }

	/* hexadecimal integer */
0x[0-9A-Fa-f]+	{ yylval.sVal = new char[strlen(yytext) + 1];
				  strcpy(yylval.sVal, yytext);
				  return HEX; }

	/* float */
[0-9]*\.[0-9]+	{ yylval.sVal = new char[strlen(yytext) + 1];
				  strcpy(yylval.sVal, yytext);
				  return FLOAT; }

	/* float with precision */
[0-9]*\.[0-9]+(p|P)[1-9][0-9]*	{ yylval.sVal = new char[strlen(yytext) + 1];
				  				  strcpy(yylval.sVal, yytext);
				  				  return FLOATP; }

	/* binary float */
0b[01]*\.[01]+	{ yylval.sVal = new char[strlen(yytext) + 1];
				  strcpy(yylval.sVal, yytext);
				  return BFLOAT; }

	/* binary float with precision */
0b[01]*\.[01]+(p|P)[1-9][0-9]*	{ yylval.sVal = new char[strlen(yytext) + 1];
									  strcpy(yylval.sVal, yytext);
									  return BFLOATP; }

	/* hexadecimal float */
0x[0-9A-Fa-f]*\.[0-9A-Fa-f]+	{ yylval.sVal = new char[strlen(yytext) + 1];
				  	  strcpy(yylval.sVal, yytext);
				  	  return XFLOAT; }

	/* hexadecimal float with precision */
0x[0-9A-Fa-f]*\.[0-9A-Fa-f]+(p|P)[1-9][0-9]*	{ yylval.sVal = new char[strlen(yytext) + 1];
				  				  	  strcpy(yylval.sVal, yytext);
				  				  	  return XFLOATP; }

	/* identifier */
[A-Za-z_][A-Za-z0-9_]*	{ yylval.sVal = new char[strlen(yytext) + 1];
						  strcpy(yylval.sVal, yytext);
		  				  return VAR; }

	/* comments */
"//"([^\n])*[\n]	;
"/*"([^*]|\*+[^*/])*\*+"/"	;

	/* counting line number */
\n	line++;

	/* ignored whitespace characters */
[ \t]+	;

.	{ char str[64];
	  sprintf(str, "Unknown character: '%c'. Ignoring.", *yytext);
	  yyerror(str); }


%%

// terminate scanner after EOF
int yywrap(void) {
	return 1;
}
