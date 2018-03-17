%{
#include <stdlib.h>
#include "interpreter/node.h"
#include "parser.h"

#define YYERROR_VERBOSE	1

int yylex(void);
void yyerror(char const *);
int yyLineNo = 1;					// for counting line numbers
static void (*handleProg)(void *);	// This is set in yybegin function called from parser.h and is called with the top node.
extern FILE *yyin;					// input file pointer of lex

%}

%code requires {
    #define MAX_KISS_VAR_LENGTH	64
}

%union {
    char sVal[MAX_KISS_VAR_LENGTH];
    char bVal[1];
	void *nodeVal;
};

// tokens
%token <sVal> INT VAR STRING CHAR
%token <bVal> BOOL
%token DEF IF ELSE GEQ LEQ EQ NEQ WHILE PRINT

// Operator precedences
%nonassoc IFP // for dangling else problem
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
	statementList	{ void *p = newNode(A_PROGRAM, yyLineNo, $1);
					  handleProg(p); }

	| 				{ handleProg(NULL); }
	;

statementList:
	statement					{ $$ = newNode(ONE_STATEMENT_SL, yyLineNo, $1); }
	| statement statementList	{ $$ = newNode(MUL_STATEMENT_SL, yyLineNo, $1, $2); }
	;

statement:
	expression ';'										{ $$ = newNode(EXPRESSION_S, yyLineNo, $1); }
	| compoundStatement									{ $$ = newNode(COMPOUND_S, yyLineNo, $1); }

	| DEF assignmentList ';'							{ $$ = newNode(VAR_DEF_INIT_S, yyLineNo, $2); }
	| DEF nonEmptyVariableList ';'						{ $$ = newNode(VAR_DEF_S, yyLineNo, $2); }
	| DEF VAR '(' variableList ')' '{' statementList '}'	{ $$ = newNode(VAR_DEF_INIT_S, yyLineNo, newNode(ONE_ASSIGN_AL, yyLineNo, $2, newNode(PROC_EXP, yyLineNo, $4, $7))); }

	| IF '(' expression ')' statement %prec IFP			{ $$ = newNode(IF_S, yyLineNo, $3, $5); }
	| IF '(' expression ')' statement ELSE statement	{ $$ = newNode(IF_ELSE_S, yyLineNo, $3, $5, $7); }
	| WHILE '(' expression ')' statement				{ $$ = newNode(WHILE_S, yyLineNo, $3, $5); }

	| PRINT '(' expression ')' ';'						{ $$ = newNode(PRINT_S, yyLineNo, $3); }
	;

expression:
	precedentExpression									{ $$ = $1; }
	| VAR '=' expression								{ $$ = newNode(ASSIGN_EXP, yyLineNo, $1, $3); }

	| constant											{ $$ = newNode(CONSTANT_EXP, yyLineNo, $1); }
	| VAR												{ $$ = newNode(VAR_EXP, yyLineNo, $1); }

	| '@' '(' variableList ')' '{' statementList '}'	{ $$ = newNode(PROC_EXP, yyLineNo, $3, $6); }
	| VAR '(' argumentList ')'							{ $$ = newNode(CALL_EXP, yyLineNo, newNode(VAR_EXP, yyLineNo, $1), $3); }
	| precedentExpression '(' argumentList ')'			{ $$ = newNode(CALL_EXP, yyLineNo, $1, $3); }
	| '@' '(' variableList ')' '{' statementList '}' '(' argumentList ')'
														{ $$ = newNode(CALL_EXP, yyLineNo, newNode(PROC_EXP, yyLineNo, $3, $6), $9); }

	| '[' expression ']'								{ $$ = newNode(ARRAY_EXP, yyLineNo, $2); }
	| VAR '[' expression ']'							{ $$ = newNode(ARRAY_GET_EXP, yyLineNo, newNode(VAR_EXP, yyLineNo, $1), $3); }
	| precedentExpression '[' expression ']'			{ $$ = newNode(ARRAY_GET_EXP, yyLineNo, $1, $3); }
	| VAR '[' expression ']' '=' expression				{ $$ = newNode(ARRAY_SET_EXP, yyLineNo, newNode(VAR_EXP, yyLineNo, $1), $3, $6); }
	| precedentExpression '[' expression ']' '=' expression	{ $$ = newNode(ARRAY_SET_EXP, yyLineNo, $1, $3, $6); }

	| '(' expression '?' expression ':' expression ')' 	{ $$ = newNode(IF_ELSE_EXP, yyLineNo, $2, $4, $6); }

	| expression '-' expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(SUB_EXP, yyLineNo, $1, $3)); }
	| expression '+' expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(ADD_EXP, yyLineNo, $1, $3)); }
	| expression '*' expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(MUL_EXP, yyLineNo, $1, $3)); }
	| expression '/' expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(DIV_EXP, yyLineNo, $1, $3)); }
	| expression '%' expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(REM_EXP, yyLineNo, $1, $3)); }
	| expression EQ expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(EQ_EXP, yyLineNo, $1, $3)); }
	| expression NEQ expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(NEQ_EXP, yyLineNo, $1, $3)); }
	| expression '<' expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(L_EXP, yyLineNo, $1, $3)); }
	| expression '>' expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(G_EXP, yyLineNo, $1, $3)); }
	| expression GEQ expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(GEQ_EXP, yyLineNo, $1, $3)); }
	| expression LEQ expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(LEQ_EXP, yyLineNo, $1, $3)); }

	| expression '&' expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(AND_EXP, yyLineNo, $1, $3)); }
	| expression '|' expression			{ $$ = newNode(BIN_OP_EXP, yyLineNo, newNode(OR_EXP, yyLineNo, $1, $3)); }

	| '-' expression %prec UMIN			{ $$ = newNode(UNI_OP_EXP, yyLineNo, newNode(MIN_EXP, yyLineNo, $2)); }
	| '!' expression 					{ $$ = newNode(UNI_OP_EXP, yyLineNo, newNode(NOT_EXP, yyLineNo, $2)); }
	;

precedentExpression:
	'(' expression ')'			{ $$ = $2; }
	;

compoundStatement:
	'{' statementList '}'		{ $$ = $2; }
	;

assignmentList:
	VAR '=' expression							{ $$ = newNode(ONE_ASSIGN_AL, yyLineNo, $1, $3); }
	| VAR '=' expression ',' assignmentList		{ $$ = newNode(MUL_ASSIGN_AL, yyLineNo, $1, $3, $5); }
	;

argumentList:
	nonEmptyArgumentList	{ $$ = newNode(NEMPTY_ARG_LIST, yyLineNo, $1); }
	|						{ $$ = newNode(EMPTY_ARG_LIST, yyLineNo); }
	;

nonEmptyArgumentList:
	expression								{ $$ = newNode(ONE_ARG_AL, yyLineNo, $1); }
	| expression ',' nonEmptyArgumentList	{ $$ = newNode(MUL_ARG_AL, yyLineNo, $1, $3); }
	;

variableList:
	nonEmptyVariableList	{ $$ = newNode(NEMPTY_VAR_LIST, yyLineNo, $1); }
	|						{ $$ = newNode(EMPTY_VAR_LIST, yyLineNo); }
	;

nonEmptyVariableList:
	VAR									{ $$ = newNode(ONE_VAR_VL, yyLineNo, $1); }
	| VAR ',' nonEmptyVariableList		{ $$ = newNode(MUL_VAR_VL, yyLineNo, $1, $3); }
	;

constant:
	INT			{ $$ = newNode(INTEGER_CONST, yyLineNo, $1); }
	| BOOL		{ $$ = newNode(BOOLEAN_CONST, yyLineNo, $1); }
	| STRING	{ $$ = newNode(STRING_CONST, yyLineNo, $1); }
	| CHAR		{ $$ = newNode(CHARACTER_CONST, yyLineNo, $1); }
	;

%%

void yyerror(char const *s) 
{
	printf("Line %d: %s\n", yyLineNo, s);
}

int yybegin(FILE *file, void (* _handleProg)(void *prog)) 
{
	yyin = file;
	handleProg = _handleProg;
	return yyparse();
}

