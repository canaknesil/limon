%start program
%token INT BOOL DEF VAR IF ELSE GEQ LEQ EQ NEQ WHILE

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

%%

program:
	statementList
	| 
	;

statementList:
	statement
	| statement statementList
	;

statement:
	expression ';'
	| compoundStatement

	| DEF assignmentList ';'
	| DEF nonEmptyVariableList ';'
	| DEF VAR '(' variableList ')' compoundStatement

	| IF '(' expression ')' statement %prec IFP
	| IF '(' expression ')' statement ELSE statement
	| WHILE '(' expression ')' statement
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


