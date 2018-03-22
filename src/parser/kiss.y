%{
#include <parser.h>

#include <stdlib.h>


#define YYERROR_VERBOSE	1

int yylex(void);
void yyerror(char const *);
int line = 1;					// for counting line numbers
static KissParser *kissParser;		// Assigned when called KissParser::parse(FILE *)
extern FILE *yyin;					// input file pointer of lex

%}

%code requires {
	#include <node.h>
    #define MAX_KISS_VAR_LENGTH	64
}

%union {
    char sVal[MAX_KISS_VAR_LENGTH];
    bool bVal[1];
	Node *nodeVal;
};

// tokens
%token <sVal> INT BIN HEX VAR STRING CHAR
%token <bVal> BOOL
%token DEF GEQ LEQ EQ NEQ PRINT SIZEOF TOSTR TOCHAR TOINT PLUSEQ MINEQ MULEQ DIVEQ REMEQ ANDEQ OREQ WHILE

%right '=' PLUSEQ MINEQ MULEQ DIVEQ REMEQ ANDEQ OREQ
%left '|'
%left '&'
%right '!'
%left '<' '>' GEQ LEQ EQ NEQ
%left '+' '-'
%left '*' '/' '%'
%right UMIN
%nonassoc PLUSPLUS MINMIN

%start program
%type<nodeVal> exp expList paramList nonEmptyParamList constant argList nonEmptyArgList itemList

%%

program:
	expList			{ kissParser->interpretProgram(new AProgram(line, $1)); }
	| 				{ kissParser->interpretProgram(new EmptyProgram(line)); }
	;

expList:
	exp							{ $$ = new OneExpEL(line, $1); }
	| exp expList				{ $$ = new MulExpEL(line, $1, $2); }
	;

exp:
	'{' expList '}'						{ $$ = nullptr; }
	| '(' expList ')'								{ $$ = nullptr; }
	
	| DEF VAR '=' exp  							{ $$ = nullptr; /*sugar*/ }
	| DEF VAR					{ $$ = nullptr; }
	| VAR '=' exp  								{ $$ = nullptr; }

	| '(' exp '?' exp ')'		{ $$ = nullptr; }
	| '(' exp '?' exp ':' exp ')' 		{ $$ = nullptr; }
	| '(' WHILE exp '?' exp ')'				{ $$ = nullptr; }
	| '[' PRINT exp ']'				{ $$ = nullptr; }

	| constant											{ $$ = nullptr; }
	| VAR			{ $$ = nullptr; }
	
	| '@' '(' paramList ')' '{' expList '}'				{ $$ = nullptr; }
	| '[' exp argList ']'			{ $$ = nullptr; }

	| '{' '#' itemList '}'						{ $$ = nullptr; }
	| '(' '#' exp ')'					{ $$ = nullptr; }
	| '(' '#' exp exp ')'				{ $$ = nullptr; }
	| '(' '#' exp exp exp ')'		{ $$ = nullptr; }
	| '[' SIZEOF exp ']'			{ $$ = nullptr; }
	
	| exp '+' exp			{ $$ = nullptr; }
	| exp '-' exp			{ $$ = nullptr; }
	| exp '*' exp			{ $$ = nullptr; }
	| exp '/' exp			{ $$ = nullptr; }
	| exp '%' exp			{ $$ = nullptr; }
	| exp EQ  exp			{ $$ = nullptr; }
	| exp NEQ exp			{ $$ = nullptr; }
	| exp '<' exp			{ $$ = nullptr; }
	| exp '>' exp			{ $$ = nullptr; }
	| exp GEQ exp			{ $$ = nullptr; }
	| exp LEQ exp			{ $$ = nullptr; }
	| exp '&' exp			{ $$ = nullptr; }
	| exp '|' exp			{ $$ = nullptr; }

	| VAR PLUSEQ exp		{ $$ = nullptr; } 
	| VAR MINEQ exp		{ $$ = nullptr; }
	| VAR MULEQ exp		{ $$ = nullptr; }
	| VAR DIVEQ exp		{ $$ = nullptr; }
	| VAR REMEQ exp		{ $$ = nullptr; }
	| VAR ANDEQ exp		{ $$ = nullptr; }
	| VAR OREQ exp		{ $$ = nullptr; }

	| '(' '-' ')' exp %prec UMIN			{ $$ = nullptr; }
	| '!' exp 					{ $$ = nullptr; }

	| '[' TOSTR exp ']'			{ $$ = nullptr; }
	| '[' TOCHAR exp ']'			{ $$ = nullptr; }
	| '[' TOINT exp ']'			{ $$ = nullptr; }
	;

itemList:
	exp					{ $$ = nullptr; }
	| exp itemList		{ $$ = nullptr; }
	;

paramList:
	nonEmptyParamList	{ $$ = nullptr; }
	|						{ $$ = nullptr; }
	;

nonEmptyParamList:
	VAR									{ $$ = nullptr; }
	| VAR nonEmptyParamList		{ $$ = nullptr; }
	;

constant:
	INT			{ $$ = nullptr; }
	| BIN		{ $$ = nullptr; }
	| HEX		{ $$ = nullptr; }
	| BOOL		{ $$ = nullptr; }
	| STRING	{ $$ = nullptr; }
	| CHAR		{ $$ = nullptr; }
	;
	
argList:
	nonEmptyArgList	{ $$ = nullptr; }
	|						{ $$ = nullptr; }
	;

nonEmptyArgList:
	exp								{ $$ = nullptr; }
	| exp nonEmptyArgList	{ $$ = nullptr; }
	;

%%

void yyerror(char const *s) 
{
	printf("Line %d: %s\n", line, s);
}

int KissParser::parse(FILE *f)
{
	yyin = f;
	kissParser = this;
	return yyparse();
}
