%{
#include <parser.h>

#include <stdlib.h>
#include <string>

using namespace std;


#define YYERROR_VERBOSE	1

int yylex(void);
void yyerror(char const *);
int line = 1;					// for counting line numbers
static KissParser *kissParser;		// Assigned when called KissParser::parse(FILE *)
extern FILE *yyin;					// input file pointer of lex

%}

%code requires {
	#include <node.h>
    #define MAX_KISS_VAR_LENGTH	256
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
	'{' expList '}'							{ $$ = new ScopeExp(line, $2); }
	| '(' expList ')'						{ $$ = $2; }
	
	| DEF VAR								{ $$ = new DefExp(line, $2); }
	| VAR '=' exp  							{ $$ = new AssignExp(line, $1, $3); }
	| DEF VAR '=' exp  						{ $$ = new MulExpEL(line, new DefExp(line, $2), new AssignExp(line, $2, $4)); /*sugar*/ }

	| '(' exp '?' exp ')'					{ $$ = new IfExp(line, $2, $4); }
	| '(' exp '?' exp ':' exp ')' 			{ $$ = new IfElseExp(line, $2, $4, $6); }
	| '(' WHILE exp '?' exp ')'				{ $$ = new WhileExp(line, $3, $5); }
	| '[' PRINT exp ']'						{ $$ = new PrintExp(line, $3); }

	| constant								{ $$ = $1; }
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

constant:
	INT			{ int n = stoi($1);
				  $$ = new IntConst(line, n); }
	| BIN		{ int n = stoi($1 + 2, nullptr, 2);
				  $$ = new IntConst(line, n); }
	| HEX		{ int n = stoi($1 + 2, nullptr, 16);
				  $$ = new IntConst(line, n); }
	| BOOL		{ $$ = nullptr; }
	| STRING	{ $$ = nullptr; }
	| CHAR		{ $$ = nullptr; }
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
