%token INT BOOL DEF VAR IF THEN ELSE FUNC END CALL ARRAY

%left '+' '-'
%left '*' '/'

%%

program:
	expressionList
	| 
	;

expressionList:
	expression
	| expression expressionList
	;

expression:
	DEF VAR '=' expression ';'
	| VAR '=' expression ';'
	| '(' expression ')'
	| compoundExpression
	| constant
	| VAR
	| FUNC '[' parameterList ']' '{' expressionList '}'
	| '[' expression argumentList ']'
	| ARRAY '(' expression expression ')'
	| '[' expression '@' expression ']'
	| IF expression THEN expression END
	| IF expression THEN expression ELSE expression END
	| expression '+' expression
	| expression '-' expression
	| expression '*' expression
	| expression '/' expression
	| '(' '-' expression ')'
	;

compoundExpression:
	'{' expressionList '}'
	;

argumentList:
	nonEmptyArgumentList
	|
	;

nonEmptyArgumentList:
	expression
	| expression nonEmptyArgumentList
	;

parameterList:
	nonEmptyParameterList
	|
	;

nonEmptyParameterList:
	VAR
	| VAR nonEmptyParameterList
	;

constant:
	INT
	| BOOL
	;
