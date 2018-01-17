%{
#include <stdio.h>
#include <stdlib.h>
#include "interpreter/value/value.h"
#include "interpreter/node.h"
#include "interpreter/env/env.h"

int yylex(void);
void yyerror(char *);
%}

%union {
    char *sVal;
    char bVal;
	void *nodeVal;
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
%type<nodeVal> statementList statement expression compoundStatement assignmentList nonEmptyVariableList variableList constant argumentList precedentExpression

%%

program:
	statementList	{ void *p = newNode(A_PROGRAM, $1);
					  void *initEnv = NULL;
					  
					  void *val = evaluate(p, initEnv);
					  
					  printf("End of program with value: ");
					  printValue(val); 
					  
					  deleteNode(p);
					  deleteValue(val);
					  // TODO delete environment
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
	| DEF VAR '(' variableList ')' compoundStatement	{ $$ = newNode(FUNC_DEF_S, $2, $4, $6); }

	| IF '(' expression ')' statement %prec IFP			{ $$ = newNode(IF_S, $3, $5); }
	| IF '(' expression ')' statement ELSE statement	{ $$ = newNode(IF_ELSE_S, $3, $5, $7); }
	| WHILE '(' expression ')' statement				{ $$ = newNode(WHILE_S, $3, $5); }

	| PRINT '(' expression ')'							{ $$ = newNode(PRINT_S, $3); }
	;

expression:
	VAR '=' expression									{ $$ = newNode(ASSIGN_EXP, $1, $3); }

	| constant											{ $$ = newNode(CONSTANT_EXP, $1); }
	| VAR												{ $$ = newNode(VAR_EXP, $1); }

	| '@' '(' variableList ')' compoundStatement		{ $$ = newNode(PROC_EXP, $3, $5); }
	| VAR '(' argumentList ')'							{ $$ = newNode(VAR_CALL_EXP, $1, $3); }
	| precedentExpression '(' argumentList ')'			{ $$ = newNode(EXP_CALL_EXP, $1, $3); }

	| '[' expression ']'								{ $$ = newNode(ARRAY_EXP, $2); }
	| VAR '[' expression ']'							{ $$ = newNode(VAR_ARRAY_GET_EXP, $1, $3); }
	| precedentExpression '[' expression ']'			{ $$ = newNode(EXP_ARRAY_GET_EXP, $1, $3); }
	| VAR '[' expression ']' '=' expression				{ $$ = newNode(VAR_ARRAY_SET_EXP, $1, $3, $6); }
	| precedentExpression '[' expression ']' '=' expression	{ $$ = newNode(EXP_ARRAY_SET_EXP, $1, $3); }

	| '(' expression '?' expression ')'					{ $$ = newNode(IF_EXP, $2, $4); }
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
	INT			{ $$ = newNode(INTEGER_CONST, IntVal_FromString($1)); }
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

