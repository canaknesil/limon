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
int line = 1;							// for counting line numbers
static KissParser *kissParser;		// Assigned when called KissParser::parse(FILE *)
static string fname;
extern FILE *yyin;					// input file pointer of lex

static bool raw2str(char *raw, string &str);
static bool raw2char(char *raw, char &c);

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
%token DEF GEQ LEQ EQ NEQ PRINT SIZEOF TOSTR TOCHAR TOINT PLUSEQ MINEQ MULEQ DIVEQ REMEQ ANDEQ OREQ WHILE NULLTOK

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
	expList			{ Node *prog = new AProgram(fname, line, $1);
					  kissParser->interpretProgram(prog);
					  delete (AProgram *) prog; }
	| 				{ Node *prog = new EmptyProgram(fname, line);
					  kissParser->interpretProgram(prog);
					  delete (EmptyProgram *) prog; }
	;

expList:
	exp							{ $$ = new OneExpEL(fname, line, $1); }
	| exp expList				{ $$ = new MulExpEL(fname, line, $1, $2); }
	;

exp:
	'{' expList '}'							{ $$ = new ScopeExp(fname, line, $2); }
	| '(' expList ')'						{ $$ = $2; }
	
	| DEF VAR								{ $$ = new DefExp(fname, line, $2); }
	| VAR '=' exp  							{ $$ = new AssignExp(fname, line, $1, $3); }
	| DEF VAR '=' exp  						{ $$ = new MulExpEL(fname, line, new DefExp(fname, line, $2), new OneExpEL(fname, line, new AssignExp(fname, line, $2, $4))); /*sugar*/ }

	| '(' exp '?' exp ')'					{ $$ = new IfExp(fname, line, $2, $4); }
	| '(' exp '?' exp ':' exp ')' 			{ $$ = new IfElseExp(fname, line, $2, $4, $6); }
	| '(' WHILE exp '?' exp ')'				{ $$ = new WhileExp(fname, line, $3, $5); }
	| '[' PRINT exp ']'						{ $$ = new PrintExp(fname, line, $3); }

	| constant								{ $$ = $1; }
	| VAR									{ $$ = new VarExp(fname, line, $1); }
	
	| '@' '(' paramList ')' '{' expList '}'	{ $$ = new ProcExp(fname, line, $3, $6); }
	| '[' exp argList ']'					{ $$ = new CallExp(fname, line, $2, $3); }

	| '{' '#' itemList '}'					{ $$ = new ArrayConst(fname, line, $3); }
	| '[' '#' exp ']'						{ $$ = new ArrayExp(fname, line, $3); }
	| '[' '#' exp exp ']'					{ $$ = new ArrayGetExp(fname, line, $3, $4); }
	| '[' '#' exp exp exp ']'				{ $$ = new ArraySetExp(fname, line, $3, $4, $5); }
	| '[' SIZEOF exp ']'					{ $$ = new SizeOfExp(fname, line, $3); }
	
	| exp '+' exp					{ $$ = new AddExp(fname, line, $1, $3); }
	| exp '-' exp					{ $$ = new SubExp(fname, line, $1, $3); }
	| exp '*' exp					{ $$ = new MulExp(fname, line, $1, $3); }
	| exp '/' exp					{ $$ = new DivExp(fname, line, $1, $3); }
	| exp '%' exp					{ $$ = new RemExp(fname, line, $1, $3); }
	| exp EQ  exp					{ $$ = new EquExp(fname, line, $1, $3); }
	| exp NEQ exp					{ $$ = new NEqExp(fname, line, $1, $3); }
	| exp '<' exp					{ $$ = new LoTExp(fname, line, $1, $3); }
	| exp '>' exp					{ $$ = new GrTExp(fname, line, $1, $3); }
	| exp LEQ exp					{ $$ = new LEqExp(fname, line, $1, $3); }
	| exp GEQ exp					{ $$ = new GEqExp(fname, line, $1, $3); }
	| exp '&' exp					{ $$ = new AndExp(fname, line, $1, $3); }
	| exp '|' exp					{ $$ = new OrExp(fname, line, $1, $3); }

	| VAR PLUSEQ exp				{ $$ = new AssignExp(fname, line, $1, new AddExp(fname, line, new VarExp(fname, line, $1), $3)); } 
	| VAR MINEQ exp					{ $$ = new AssignExp(fname, line, $1, new SubExp(fname, line, new VarExp(fname, line, $1), $3)); }
	| VAR MULEQ exp					{ $$ = new AssignExp(fname, line, $1, new MulExp(fname, line, new VarExp(fname, line, $1), $3)); }
	| VAR DIVEQ exp					{ $$ = new AssignExp(fname, line, $1, new DivExp(fname, line, new VarExp(fname, line, $1), $3)); }
	| VAR REMEQ exp					{ $$ = new AssignExp(fname, line, $1, new RemExp(fname, line, new VarExp(fname, line, $1), $3)); }
	| VAR ANDEQ exp					{ $$ = new AssignExp(fname, line, $1, new AndExp(fname, line, new VarExp(fname, line, $1), $3)); }
	| VAR OREQ exp					{ $$ = new AssignExp(fname, line, $1, new OrExp(fname, line, new VarExp(fname, line, $1), $3)); }

	| '(' '-' exp ')' %prec UMIN	{ $$ = new MinExp(fname, line, $3); }
	| '!' exp 						{ $$ = new NotExp(fname, line, $2); }

	| '[' TOSTR exp ']'				{ $$ = new ToStrExp(fname, line, $3); }
	| '[' TOCHAR exp ']'			{ $$ = new ToCharExp(fname, line, $3); }
	| '[' TOINT exp ']'				{ $$ = new ToIntExp(fname, line, $3); }
	;

constant:
	INT							{ $$ = new IntExp(fname, line, $1); }
	| BIN						{ long long n = stoll($1 + 2, nullptr, 2);
								  $$ = new IntExp(fname, line, to_string(n)); }
	| HEX						{ long long n = stoll($1 + 2, nullptr, 16);
								  $$ = new IntExp(fname, line, to_string(n)); }
	| BOOL						{ $$ = new BoolExp(fname, line, *($1)); }
	| STRING					{ string str;
								  if (raw2str($1, str)) $$ = new StringExp(fname, line, str);
								  else YYERROR; }
	| CHAR						{ char c;
								  if (raw2char($1, c)) $$ = new CharExp(fname, line, c);
								  else YYERROR; }
	| NULLTOK					{ $$ = new NullExp(fname, line); }
	;


paramList:
	nonEmptyParamList			{ $$ = $1; }
	|							{ $$ = new EmptyPL(fname, line); }
	;

nonEmptyParamList:
	VAR							{ $$ = new OneVarPL(fname, line, $1); }
	| nonEmptyParamList VAR		{ $$ = new MulVarPL(fname, line, $2, $1); }
	;

argList:
	nonEmptyArgList				{ $$ = $1; }
	|							{ $$ = new EmptyAL(fname, line); }
	;

nonEmptyArgList:
	exp							{ $$ = new OneArgAL(fname, line, $1); }
	| nonEmptyArgList exp		{ $$ = new MulArgAL(fname, line, $2, $1); }
	;

itemList:
	exp					{ $$ = new OneExpIL(fname, line, $1); }
	| itemList exp		{ $$ = new MulExpIL(fname, line, $2, $1); }
	;

%%

void yyerror(char const *s) 
{
	printf(" %s:%d: %s\a\n", fname.c_str(), line, s);
}

int KissParser::parse(FILE *f, string filename)
{
	yyin = f;
	fname = filename;
	kissParser = this;
	int res = yyparse();
	return res;
}


bool raw2str(char *_raw, string &str)
{
	str = "";
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
					return false;
			}
			raw.erase(0, 2);
		} else {
			str.append(1, raw[0]);
			raw.erase(0, 1);
		}
	}

	return true;
}

bool raw2char(char *raw, char &c)
{
	if (raw[1] == '\\') {
		switch (raw[2]) {
			case 'a': c = '\a'; break;
			case 'b': c = '\b'; break;
			case 'f': c = '\f'; break;
			case 'n': c = '\n'; break;
			case 'r': c = '\r'; break;
			case 't': c = '\t'; break;
			case 'v': c = '\v'; break;
			case '\'': c = '\''; break;
			case '\\': c = '\\'; break;
			case '?': c = '\?'; break;
			default:
				stringstream ss;
				ss << "\"\\" << raw[2] << "\" is not a valid excape sequence for a character literal.";
				yyerror(ss.str().c_str());
				return false;
		}
	} else {
		c = raw[1];
	}

	return true;
}