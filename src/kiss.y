%{
#include <stdio.h>
#include <stdlib.h>
#include "interpreter/node.h"
#include "main.h"

int yylex(void);
void yyerror(char *);

int argc;
char **argv;
%}

%code requires {
    #define MAX_KISS_VAR_LENGTH	64
}

%union {
    char sVal[MAX_KISS_VAR_LENGTH];
    char bVal[1];
	void *nodeVal;
};

%token <sVal> INT VAR STRING CHAR
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
%type<nodeVal> statementList statement expression compoundStatement assignmentList nonEmptyVariableList variableList constant argumentList precedentExpression nonEmptyArgumentList

%%

program:
	statementList	{ void *p = newNode(A_PROGRAM, $1);
					  handleAST(p, argc, argv);
					  exit(0); }

	| 				{ printf("Empty program\n");
					  exit(0); }
	;

statementList:
	statement					{ $$ = newNode(ONE_STATEMENT_SL, $1); }
	| statement statementList	{ $$ = newNode(MUL_STATEMENT_SL, $1, $2); }
	;

statement:
	expression ';'										{ $$ = newNode(EXPRESSION_S, $1); }
	| compoundStatement									{ $$ = newNode(COMPOUND_S, $1); }

	| DEF assignmentList ';'							{ $$ = newNode(VAR_DEF_INIT_S, $2); }
	| DEF nonEmptyVariableList ';'						{ $$ = newNode(VAR_DEF_S, $2); }
	| DEF VAR '(' variableList ')' '{' statementList '}'	{ $$ = newNode(VAR_DEF_INIT_S, newNode(ONE_ASSIGN_AL, $2, newNode(PROC_EXP, $4, $7))); }

	| IF '(' expression ')' statement %prec IFP			{ $$ = newNode(IF_S, $3, $5); }
	| IF '(' expression ')' statement ELSE statement	{ $$ = newNode(IF_ELSE_S, $3, $5, $7); }
	| WHILE '(' expression ')' statement				{ $$ = newNode(WHILE_S, $3, $5); }

	| PRINT '(' expression ')' ';'						{ $$ = newNode(PRINT_S, $3); }
	;

expression:
	precedentExpression									{ $$ = $1; }
	| VAR '=' expression								{ $$ = newNode(ASSIGN_EXP, $1, $3); }

	| constant											{ $$ = newNode(CONSTANT_EXP, $1); }
	| VAR												{ $$ = newNode(VAR_EXP, $1); }

	| '@' '(' variableList ')' '{' statementList '}'	{ $$ = newNode(PROC_EXP, $3, $6); }
	| VAR '(' argumentList ')'							{ $$ = newNode(CALL_EXP, newNode(VAR_EXP, $1), $3); }
	| precedentExpression '(' argumentList ')'			{ $$ = newNode(CALL_EXP, $1, $3); }

	| '[' expression ']'								{ $$ = newNode(ARRAY_EXP, $2); }
	| VAR '[' expression ']'							{ $$ = newNode(ARRAY_GET_EXP, newNode(VAR_EXP, $1), $3); }
	| precedentExpression '[' expression ']'			{ $$ = newNode(ARRAY_GET_EXP, $1, $3); }
	| VAR '[' expression ']' '=' expression				{ $$ = newNode(ARRAY_SET_EXP, newNode(VAR_EXP, $1), $3, $6); }
	| precedentExpression '[' expression ']' '=' expression	{ $$ = newNode(ARRAY_SET_EXP, $1, $3); }

	| '(' expression '?' expression ':' expression ')' 	{ $$ = newNode(IF_ELSE_EXP, $2, $4, $6); }

	| expression '+' expression			{ $$ = newNode(ADD_EXP, $1, $3); }
	| expression '-' expression			{ $$ = newNode(SUB_EXP, $1, $3); }
	| expression '*' expression			{ $$ = newNode(MUL_EXP, $1, $3); }
	| expression '/' expression			{ $$ = newNode(DIV_EXP, $1, $3); }
	| expression '%' expression			{ $$ = newNode(REM_EXP, $1, $3); }
	| '-' expression %prec UMIN			{ $$ = newNode(MIN_EXP, $2); }

	| expression EQ expression			{ $$ = newNode(EQ_EXP, $1, $3); }
	| expression NEQ expression			{ $$ = newNode(NEQ_EXP, $1, $3); }
	| expression '<' expression			{ $$ = newNode(L_EXP, $1, $3); }
	| expression '>' expression			{ $$ = newNode(G_EXP, $1, $3); }
	| expression GEQ expression			{ $$ = newNode(GEQ_EXP, $1, $3); }
	| expression LEQ expression			{ $$ = newNode(LEQ_EXP, $1, $3); }

	| expression '&' expression			{ $$ = newNode(AND_EXP, $1, $3); }
	| expression '|' expression			{ $$ = newNode(OR_EXP, $1, $3); }
	| '!' expression 					{ $$ = newNode(NOT_EXP, $2); }
	;


precedentExpression:
	'(' expression ')'			{ $$ = $2; }
	;

compoundStatement:
	'{' statementList '}'		{ $$ = $2; }
	;

assignmentList:
	VAR '=' expression							{ $$ = newNode(ONE_ASSIGN_AL, $1, $3); }
	| VAR '=' expression ',' assignmentList		{ $$ = newNode(MUL_ASSIGN_AL, $1, $3, $5); }
	;

argumentList:
	nonEmptyArgumentList	{ $$ = newNode(NEMPTY_ARG_LIST, $1); }
	|						{ $$ = newNode(EMPTY_ARG_LIST); }
	;

nonEmptyArgumentList:
	expression								{ $$ = newNode(ONE_ARG_AL, $1); }
	| expression ',' nonEmptyArgumentList	{ $$ = newNode(MUL_ARG_AL, $1, $3); }
	;

variableList:
	nonEmptyVariableList	{ $$ = newNode(NEMPTY_VAR_LIST, $1); }
	|						{ $$ = newNode(EMPTY_VAR_LIST); }
	;

nonEmptyVariableList:
	VAR									{ $$ = newNode(ONE_VAR_VL, $1); }
	| VAR ',' nonEmptyVariableList		{ $$ = newNode(MUL_VAR_VL, $1, $3); }
	;

constant:
	INT			{ $$ = newNode(INTEGER_CONST, $1); }
	| BOOL		{ $$ = newNode(BOOLEAN_CONST, $1); }
	| STRING	{ $$ = newNode(STRING_CONST, $1); }
	| CHAR		{ $$ = newNode(CHARACTER_CONST, $1); }
	;

%%

void yyerror(char *s) 
{
	printf("%s\n", s);
}

int main(int _argc, char *_argv[]) 
{
	argc = _argc;
	argv = _argv;
	yyparse();
	return 0;
}

