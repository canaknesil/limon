%{
#include <parser.h>

#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;


#define YYERROR_VERBOSE	1

int yylex(void);
void yyerror(char const *);
int line = 1;					// for counting line numbers
static KissParser *kissParser;		// Assigned when called KissParser::parse(FILE *)
extern FILE *yyin;					// input file pointer of lex

string raw2str(char *raw);
char raw2char(char *raw);

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
%type<nodeVal> exp expList constant argList nonEmptyArgList itemList paramList nonEmptyParamList 

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
	| DEF VAR '=' exp  						{ $$ = new MulExpEL(line, new DefExp(line, $2), new OneExpEL(line, new AssignExp(line, $2, $4))); /*sugar*/ }

	| '(' exp '?' exp ')'					{ $$ = new IfExp(line, $2, $4); }
	| '(' exp '?' exp ':' exp ')' 			{ $$ = new IfElseExp(line, $2, $4, $6); }
	| '(' WHILE exp '?' exp ')'				{ $$ = new WhileExp(line, $3, $5); }
	| '[' PRINT exp ']'						{ $$ = new PrintExp(line, $3); }

	| constant								{ $$ = $1; }
	| VAR									{ $$ = new VarExp(line, $1); }
	
	| '@' '(' paramList ')' '{' expList '}'	{ $$ = new ProcExp(line, $3, $6); }
	| '[' exp argList ']'					{ $$ = new CallExp(line, $2, $3); }

	| '{' '#' itemList '}'					{ $$ = new ArrayConst(line, $3); }
	| '[' '#' exp ']'						{ $$ = new ArrayExp(line, $3); }
	| '[' '#' exp exp ']'					{ $$ = new ArrayGetExp(line, $3, $4); }
	| '[' '#' exp exp exp ']'				{ $$ = new ArraySetExp(line, $3, $4, $5); }
	| '[' SIZEOF exp ']'					{ $$ = new SizeOfExp(line, $3); }
	
	| exp '+' exp					{ $$ = new AddExp(line, $1, $3); }
	| exp '-' exp					{ $$ = new SubExp(line, $1, $3); }
	| exp '*' exp					{ $$ = new MulExp(line, $1, $3); }
	| exp '/' exp					{ $$ = new DivExp(line, $1, $3); }
	| exp '%' exp					{ $$ = new RemExp(line, $1, $3); }
	| exp EQ  exp					{ $$ = new EquExp(line, $1, $3); }
	| exp NEQ exp					{ $$ = new NEqExp(line, $1, $3); }
	| exp '<' exp					{ $$ = new LoTExp(line, $1, $3); }
	| exp '>' exp					{ $$ = new GrTExp(line, $1, $3); }
	| exp LEQ exp					{ $$ = new LEqExp(line, $1, $3); }
	| exp GEQ exp					{ $$ = new GEqExp(line, $1, $3); }
	| exp '&' exp					{ $$ = new AndExp(line, $1, $3); }
	| exp '|' exp					{ $$ = new OrExp(line, $1, $3); }

	| VAR PLUSEQ exp				{ $$ = new AssignExp(line, $1, new AddExp(line, new VarExp(line, $1), $3)); } 
	| VAR MINEQ exp					{ $$ = new AssignExp(line, $1, new SubExp(line, new VarExp(line, $1), $3)); }
	| VAR MULEQ exp					{ $$ = new AssignExp(line, $1, new MulExp(line, new VarExp(line, $1), $3)); }
	| VAR DIVEQ exp					{ $$ = new AssignExp(line, $1, new DivExp(line, new VarExp(line, $1), $3)); }
	| VAR REMEQ exp					{ $$ = new AssignExp(line, $1, new RemExp(line, new VarExp(line, $1), $3)); }
	| VAR ANDEQ exp					{ $$ = new AssignExp(line, $1, new AndExp(line, new VarExp(line, $1), $3)); }
	| VAR OREQ exp					{ $$ = new AssignExp(line, $1, new OrExp(line, new VarExp(line, $1), $3)); }

	| '(' '-' exp ')' %prec UMIN	{ $$ = new MinExp(line, $3); }
	| '!' exp 						{ $$ = new NotExp(line, $2); }

	| '[' TOSTR exp ']'				{ $$ = new ToStrExp(line, $3); }
	| '[' TOCHAR exp ']'			{ $$ = new ToCharExp(line, $3);; }
	| '[' TOINT exp ']'				{ $$ = new ToIntExp(line, $3);; }
	;

constant:
	INT							{ int n = stoi($1);
								  $$ = new IntExp(line, n); }
	| BIN						{ int n = stoi($1 + 2, nullptr, 2);
								  $$ = new IntExp(line, n); }
	| HEX						{ int n = stoi($1 + 2, nullptr, 16);
								  $$ = new IntExp(line, n); }
	| BOOL						{ $$ = new BoolExp(line, *($1)); }
	| STRING					{ $$ = new StringExp(line, raw2str($1)); }
	| CHAR						{ $$ = new CharExp(line, raw2char($1)); }
	;


paramList:
	nonEmptyParamList			{ $$ = $1; }
	|							{ $$ = new EmptyPL(line); }
	;

nonEmptyParamList:
	VAR							{ $$ = new OneVarPL(line, $1); }
	| VAR nonEmptyParamList		{ $$ = new MulVarPL(line, $1, $2); }
	;

argList:
	nonEmptyArgList				{ $$ = $1; }
	|							{ $$ = new EmptyAL(line); }
	;

nonEmptyArgList:
	exp							{ $$ = new OneArgAL(line, $1); }
	| exp nonEmptyArgList		{ $$ = new MulArgAL(line, $1, $2); }
	;

itemList:
	exp					{ $$ = new OneExpIL(line, $1); }
	| exp itemList		{ $$ = new MulExpIL(line, $1, $2); }
	;

%%

void yyerror(char const *s) 
{
	printf(" Line %d: %s\n", line, s);
}

int KissParser::parse(FILE *f)
{
	yyin = f;
	kissParser = this;
	return yyparse();
}


string raw2str(char *_raw)
{
	string str = "";
	string raw = _raw;
	raw.erase(0, 1);
	raw.erase(raw.size() - 1, 1);
	
	while (raw.size() != 0) {
		if (raw[0] == '\\') {
			switch (raw[1]) {
				case 'a': str.append(1, '\a'); break;
				case 'b': str.append(1, '\b'); break;
				case 'f': str.append(1, '\f'); break;
				case 'n': str.append(1, '\n'); break;
				case 'r': str.append(1, '\r'); break;
				case 't': str.append(1, '\t'); break;
				case 'v': str.append(1, '\v'); break;
				case '"': str.append(1, '"'); break;
				case '\\': str.append(1, '\\'); break;
				case '?': str.append(1, '\?'); break;
				default:
					stringstream ss;
					ss << "\"\\" << raw[1] << "\" is not a valid excape sequence for a string literal.";
					yyerror(ss.str().c_str());
					//YYERROR;
			}
			raw.erase(0, 2);
		} else {
			str.append(1, raw[0]);
			raw.erase(0, 1);
		}
	}

	return str;
}

char raw2char(char *raw)
{
	if (raw[1] == '\\') {
		switch (raw[2]) {
			case 'a': return '\a';
			case 'b': return '\b';
			case 'f': return '\f';
			case 'n': return '\n';
			case 'r': return '\r';
			case 't': return '\t';
			case 'v': return '\v';
			case '\'': return '\'';
			case '\\': return '\\';
			case '?': return '\?';
			default:
				stringstream ss;
				ss << "\"\\" << raw[2] << "\" is not a valid excape sequence for a character literal.";
				yyerror(ss.str().c_str());
				//YYERROR;
		}
	} else {
		return raw[1];
	}
	return 'c'; //never reaches there
}