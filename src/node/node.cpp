#include <node.h>

#include <iostream>

using namespace std;


Node::Node(int line) {
    this->line = line;
}

int Node::getLine() {
    return line;
}

void Node::printOneNode(int tab, string name) {
    for (int i=0; i<tab; i++) cout << "  ";
    cout << name << endl;
}


AProgram::AProgram(int line, Node *statementList) : Node::Node(line) {
    this->statementList = statementList;
}

void AProgram::printAST(int tab) {
    printOneNode(tab, "AProgram");
    statementList->printAST(tab + 1);
}


EmptyProgram::EmptyProgram(int line) : Node::Node(line) {}

void EmptyProgram::printAST(int tab) {
    printOneNode(tab, "EmptyProgram");
}


OneStatementSL::OneStatementSL(int line, Node *statement) : Node::Node(line) {
    this->statement = statement;
}

void OneStatementSL::printAST(int tab) {
    printOneNode(tab, "OneStatementSL");
    //statement->printAST(tab + 1);
}


MulStatementSL::MulStatementSL(int line, Node *statement, Node *statementList) : Node::Node(line) {
    this->statement = statement;
    this->statementList = statementList;
}

void MulStatementSL::printAST(int tab) {
    printOneNode(tab, "MulStatementSL");
    //statement->printAST(tab + 1);
    statementList->printAST(tab + 1);
}


ExpressionS::ExpressionS(int line, Node *expression) : Node::Node(line) {
    this->expression = expression;
}

void ExpressionS::printAST(int tab) {
    printOneNode(tab, "ExpressionS");
    expression->printAST(tab + 1);
}


/*

	| compoundStatement									{ $$ = new compoundS(yyLineNo, $1); }

	| DEF varDefInitList ';'							{ $$ = new VarDefInitS(yyLineNo, $2); }
	| DEF varDefList ';'								{ $$ = new VarDefS(yyLineNo, $2); }
	| DEF VAR '(' parameterList ')' '{' statementList '}'	
			{ $$ = new VarDefInitS(yyLineNo, OneVarDefInitList(yyLineNo, $2, new ProcExp(yyLineNo, $4, $7)); }

	| IF '(' expression ')' statement %prec IFP			{ $$ = new IfS(yyLineNo, $3, $5); }
	| IF '(' expression ')' statement ELSE statement	{ $$ = new IfElseS(yyLineNo, $3, $5, $7); }
	| WHILE '(' expression ')' statement				{ $$ = new WhileS(yyLineNo, $3, $5); }

	| PRINT '(' expression ')' ';'						{ $$ = new PrintS(yyLineNo, $3); }
	;

expression:
	precedentExpression									{ $$ = $1; }
	| VAR '=' expression								{ $$ = new AssignExp(yyLineNo, $1, $3); }

	| constant											{ $$ = new ConstExp(yyLineNo, $1); }
	| VAR												{ $$ = new VarExp(yyLineNo, $1); }

	| '@' '(' parameterList ')' '{' statementList '}'	{ $$ = new ProcExp(yyLineNo, $3, $6); }
	| VAR '(' argumentList ')'							{ $$ = new CallExp(yyLineNo, new VarExp(yyLineNo, $1), $3); }
	| precedentExpression '(' argumentList ')'			{ $$ = new CallExp(yyLineNo, $1, $3); }
	| '@' '(' parameterList ')' '{' statementList '}' '(' argumentList ')'
														{ $$ = new CallExp(yyLineNo, new ProcExp(yyLineNo, $3, $6), $9); }

	| '[' expression ']'								{ $$ = new ArrayAllocExp(yyLineNo, $2); }
	| VAR '[' expression ']'							{ $$ = new ArrayGetExp(yyLineNo, new VarExp(yyLineNo, $1), $3); }
	| precedentExpression '[' expression ']'			{ $$ = new ArrayGetExp(yyLineNo, $1, $3); }
	| VAR '[' expression ']' '=' expression				{ $$ = new ArraySetExp(yyLineNo, new VarExp(yyLineNo, $1), $3, $6); }
	| precedentExpression '[' expression ']' '=' expression	{ $$ = new ArraySetExp(yyLineNo, $1, $3, $6); }

	| '(' expression '?' expression ':' expression ')' 	{ $$ = new IfElseExp(yyLineNo, $2, $4, $6); }

	| expression '+' expression			{ $$ = new BinOpExp(yyLineNo, new AddExp(yyLineNo, $1, $3)); }
	| expression '-' expression			{ $$ = new BinOpExp(yyLineNo, new SubExp(yyLineNo, $1, $3)); }
	| expression '*' expression			{ $$ = new BinOpExp(yyLineNo, new MulExp(yyLineNo, $1, $3)); }
	| expression '/' expression			{ $$ = new BinOpExp(yyLineNo, new DivExp(yyLineNo, $1, $3)); }
	| expression '%' expression			{ $$ = new BinOpExp(yyLineNo, new RemExp(yyLineNo, $1, $3)); }
	| expression EQ expression			{ $$ = new BinOpExp(yyLineNo, new EqExp(yyLineNo, $1, $3)); }
	| expression NEQ expression			{ $$ = new BinOpExp(yyLineNo, new NeqExp(yyLineNo, $1, $3)); }
	| expression '<' expression			{ $$ = new BinOpExp(yyLineNo, new LTExp(yyLineNo, $1, $3)); }
	| expression '>' expression			{ $$ = new BinOpExp(yyLineNo, new GTExp(yyLineNo, $1, $3)); }
	| expression GEQ expression			{ $$ = new BinOpExp(yyLineNo, new GEqExp(yyLineNo, $1, $3)); }
	| expression LEQ expression			{ $$ = new BinOpExp(yyLineNo, new LEqExp(yyLineNo, $1, $3)); }
	| expression '&' expression			{ $$ = new BinOpExp(yyLineNo, new AndExp(yyLineNo, $1, $3)); }
	| expression '|' expression			{ $$ = new BinOpExp(yyLineNo, new OrExp(yyLineNo, $1, $3)); }

	| '-' expression %prec UMIN			{ $$ = new UnaOp(yyLineNo, new MinExp(yyLineNo, $2)); }
	| '!' expression 					{ $$ = new UnaOp(yyLineNo, new NotExp(yyLineNo, $2)); }
	;

precedentExpression:
	'(' expression ')'			{ $$ = $2; }
	;

compoundStatement:
	'{' statementList '}'		{ $$ = $2; }
	;

varDefInitList:
	VAR '=' expression							{ $$ = new OneVarDefInitList(yyLineNo, $1, $3); }
	| VAR '=' expression ',' varDefInitList		{ $$ = new MulVarDefInitList(yyLineNo, $1, $3, $5); }
	;

varDefList:
	VAR						{ $$ = new OneVarDefList(yyLineNo, $1); }
	| VAR "," varDefList	{ $$ = new MulVarDefList(yyLineNo, $1, $3); }
	;

parameterList:
	nonEmptyParameterList	{ $$ = new NonEmptyParamList(yyLineNo, $1); }
	|						{ $$ = new EmptyParamList(yyLineNo); }
	;

nonEmptyParameterList:
	VAR									{ $$ = new OneVarParamList(yyLineNo, $1); }
	| VAR "," nonEmptyParameterList		{ $$ = new MulVarParamList(yyLineNo, $1, $3); }
	;

argumentList:
	nonEmptyArgumentList	{ $$ = new NonEmptyArgList(yyLineNo, $1); }
	|						{ $$ = new EmptyArgList(yyLineNo);}
	;

nonEmptyArgumentList:
	expression								{ $$ = new OneExpArgList(yyLineNo, $1); }
	| expression ',' nonEmptyArgumentList	{ $$ = new MulExpArgList(yyLineNo, $1, $3); }
	;

constant:
	INT			{ $$ = new IntegerConst(yyLineNo, $1); }
	| BOOL		{ $$ = new BooleanConst(yyLineNo, $1); }
	| STRING	{ $$ = new StringConst(yyLineNo, $1); }
	| CHAR		{ $$ = new CharConst(yyLineNo, $1); }
	;

*/