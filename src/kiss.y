%{
#include <stdio.h>
#include <stdlib.h>
#include "interpreter/value/value.h"
#include "interpreter/node.h"

int yylex(void);
void yyerror(char *);
%}

%union {
    char *sVal;
    char bVal;
};

%token <sVal> INT VAR
%token <bVal> BOOL
%token DEF IF ELSE GEQ LEQ EQ NEQ WHILE PRINT

%nonassoc IFP
%nonassoc ELSE

%right '='
%left '|'
%left '&'
%right '!'
%left '<' '>' GEQ LEQ EQ NEQ
%left '+' '-'
%left '*' '/' '%'
%right UMIN

%start program

%%

program:
	statementList	{ void *p = newNode(A_PROGRAM, $1);
					  void *val = evaluate(p, );
					  DEL_NODE(p);
					  printf("End of program with value: ");
					  printValue(val); 
					  deleteValue(val);
					  exit(0); }
	| 				{ printf("Empty program\n"); }
	;

statementList:
	statement					{ printf("\n"); }
	| statement statementList
	;

statement:
	expression ';'										{ $$ = $1; }
	| compoundStatement									{ $$ = $1; }

	| DEF assignmentList ';'							{ $$ = $1; }
	| DEF nonEmptyVariableList ';'						{ $$ = $1; }
	| DEF VAR '(' variableList ')' compoundStatement	{ }

	| IF '(' expression ')' statement %prec IFP
	| IF '(' expression ')' statement ELSE statement
	| WHILE '(' expression ')' statement

	| PRINT '(' expression ')'
	;

expression:
	VAR '=' expression

	| constant
	| VAR

	| '@' '(' variableList ')' compoundStatement
	| VAR '(' argumentList ')'
	| precedentExpression '(' argumentList ')'

	| '[' expression ']'
	| VAR '[' expression ']'
	| precedentExpression '[' expression ']'

	| '(' expression '?' expression ')'
	| '(' expression '?' expression ':' expression ')' 

	| expression '+' expression
	| expression '-' expression
	| expression '*' expression
	| expression '/' expression
	| expression '%' expression
	| '-' expression %prec UMIN

	| expression EQ expression
	| expression NEQ expression
	| expression '<' expression
	| expression '>' expression
	| expression GEQ expression
	| expression LEQ expression

	| expression '&' expression
	| expression '|' expression
	| '!' expression 
	;


precedentExpression:
	'(' expression ')'
	;

compoundStatement:
	'{' statementList '}'
	;

assignmentList:
	VAR '=' expression
	| VAR '=' expression ',' assignmentList
	;

argumentList:
	nonEmptyArgumentList
	|
	;

nonEmptyArgumentList:
	expression
	| expression ',' nonEmptyArgumentList
	;

variableList:
	nonEmptyVariableList
	|
	;

nonEmptyVariableList:
	VAR
	| VAR ',' nonEmptyVariableList
	;

constant:
	INT		
	| BOOL
	;

%%

void yyerror(char *s) {
	printf("%s\n", s);
}

int main(void) {
	yyparse();
	return 0;
}

