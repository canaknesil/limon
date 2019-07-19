%{

#include <parser.h> 

#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

#define YYERROR_VERBOSE 1 // to get better error messages

/* External variables and functions */
int yylex(void);   // yyparse calls this to get tokens
void set_scan_string(const char *str); // this is defined in limon.l

/* Internal variables and functions */
void yyerror(char const *);     // is called when an error occurs during parsing
int line = 1;                   // for counting line numbers
static Node *topNode = nullptr; // the AST top node, used during parsing
static string fname;            // name of the parsed file, used during parsing

// Transforms the text, read from the source file, to the string|character it represents.
static bool raw2str(char *raw, string &str);
static bool raw2char(char *raw, char &c);


%}

// code required by the derivations
%code requires {

#include <node.h> // to create the AST

}

// values assigned by at limon.l
%union {
  char *sVal = nullptr;
  bool bVal;
  Node *nodeVal;
};

// tokens
%token <sVal> INT BIN HEX FLOAT FLOATP BFLOAT BFLOATP XFLOAT XFLOATP VAR STRING CHAR
%token <bVal> BOOL
%token DEF GEQ LEQ EQ NEQ PRINT SIZEOF TOSTR TOCHAR TOINT TOFLOAT PLUSEQ MINEQ MULEQ DIVEQ REMEQ ANDEQ OREQ WHILE NULLTOK SCAN RUN

%right '=' PLUSEQ MINEQ MULEQ DIVEQ REMEQ ANDEQ OREQ
%left '|'
%left '&'
%right '!'
%left '<' '>' GEQ LEQ EQ NEQ
%left '+' '-'
%left '*' '/' '%'
%right UMIN
%nonassoc PLUSPLUS MINMIN

// non-terminals
%start program
%type<nodeVal> exp expList condList constant argList nonEmptyArgList itemList paramList nonEmptyParamList 

%%

program:
  expList    { topNode = new AProgram(fname, line, $1); }
  |          { topNode = new EmptyProgram(fname, line); }
  ;


expList:
  exp              { $$ = new OneExpEL(fname, line, $1); }
  | exp expList    { $$ = new MulExpEL(fname, line, $1, $2); }
  ;

exp:
  '{' expList '}'    { $$ = new ScopeExp(fname, line, $2); }
  | '(' expList ')'  { $$ = $2; }
     
  | DEF VAR           { $$ = new DefExp(fname, line, $2);
                        delete[] $2; }
  | VAR '=' exp       { $$ = new AssignExp(fname, line, $1, $3);
                        delete[] $1; }
  | DEF VAR '=' exp   { $$ = new MulExpEL(fname,
					  line,
					  new DefExp(fname, line, $2),
					  new OneExpEL(fname,
						       line,
						       new AssignExp(fname, line, $2, $4)));
                        delete[] $2; /*sugar*/ }

  | '(' condList ')'            { $$ = new CondExp(fname, line, $2); }
  | '(' condList ':' exp ')'    { $$ = new CondElseExp(fname, line, $2, $4); }
  | '(' WHILE exp '?' exp ')'   { $$ = new WhileExp(fname, line, $3, $5); }
  | '[' PRINT exp ']'           { $$ = new PrintExp(fname, line, $3); }
  | '[' SCAN ']'                { $$ = new ScanExp(fname, line); }

  | constant                    { $$ = $1; }
  | VAR                         { $$ = new VarExp(fname, line, $1);
                                  delete[] $1; }
        
  | '@' '(' paramList ')' '{' expList '}'  { $$ = new ProcExp(fname, line, $3, $6); }
  | '[' exp argList ']'                    { $$ = new CallExp(fname, line, $2, $3); }

  | '{' '#' itemList '}'                   { $$ = new ArrayConst(fname, line, $3); }
  | '[' '#' exp ']'                        { $$ = new ArrayExp(fname, line, $3); }
  | '[' '#' exp exp ']'                    { $$ = new ArrayGetExp(fname, line, $3, $4); }
  | '[' '#' exp exp exp ']'                { $$ = new ArraySetExp(fname, line, $3, $4, $5); }
  | '[' SIZEOF exp ']'                     { $$ = new SizeOfExp(fname, line, $3); }
        
  | exp '+' exp       { $$ = new AddExp(fname, line, $1, $3); }
  | exp '-' exp       { $$ = new SubExp(fname, line, $1, $3); }
  | exp '*' exp       { $$ = new MulExp(fname, line, $1, $3); }
  | exp '/' exp       { $$ = new DivExp(fname, line, $1, $3); }
  | exp '%' exp       { $$ = new RemExp(fname, line, $1, $3); }
  | exp EQ  exp       { $$ = new EquExp(fname, line, $1, $3); }
  | exp NEQ exp       { $$ = new NEqExp(fname, line, $1, $3); }
  | exp '<' exp       { $$ = new LoTExp(fname, line, $1, $3); }
  | exp '>' exp       { $$ = new GrTExp(fname, line, $1, $3); }
  | exp LEQ exp       { $$ = new LEqExp(fname, line, $1, $3); }
  | exp GEQ exp       { $$ = new GEqExp(fname, line, $1, $3); }
  | exp '&' exp       { $$ = new AndExp(fname, line, $1, $3); }
  | exp '|' exp       { $$ = new OrExp(fname, line, $1, $3); }

  | VAR PLUSEQ exp    { $$ = new AssignExp(fname, line, $1, new AddExp(fname, line,
								       new VarExp(fname, line, $1), $3));
                        delete[] $1; } 
  | VAR MINEQ exp     { $$ = new AssignExp(fname, line, $1, new SubExp(fname, line,
								       new VarExp(fname, line, $1), $3));
                        delete[] $1; }
  | VAR MULEQ exp     { $$ = new AssignExp(fname, line, $1, new MulExp(fname, line,
								       new VarExp(fname, line, $1), $3));
                        delete[] $1; }
  | VAR DIVEQ exp     { $$ = new AssignExp(fname, line, $1, new DivExp(fname, line,
								       new VarExp(fname, line, $1), $3));
                        delete[] $1; }
  | VAR REMEQ exp     { $$ = new AssignExp(fname, line, $1, new RemExp(fname, line,
								       new VarExp(fname, line, $1), $3));
                        delete[] $1; }
  | VAR ANDEQ exp     { $$ = new AssignExp(fname, line, $1, new AndExp(fname, line,
								       new VarExp(fname, line, $1), $3));
                        delete[] $1; }
  | VAR OREQ exp      { $$ = new AssignExp(fname, line, $1, new OrExp(fname, line,
								      new VarExp(fname, line, $1), $3));
                        delete[] $1; }

  | '(' '-' exp ')' %prec UMIN    { $$ = new MinExp(fname, line, $3); }
  | '!' exp                       { $$ = new NotExp(fname, line, $2); }

  | '[' TOSTR exp ']'             { $$ = new ToStrExp(fname, line, $3); }
  | '[' TOCHAR exp ']'            { $$ = new ToCharExp(fname, line, $3); }
  | '[' TOINT exp ']'             { $$ = new ToIntExp(fname, line, $3); }
  | '[' TOFLOAT exp ']'           { $$ = new ToFloatExp(fname, line, $3); }

  | '[' RUN STRING ']'            { string str;
                                    if (raw2str($3, str)) {
				      $$ = new RunExp(fname, line, str);
				      delete[] $3;
				    } else {
				      delete[] $3;
				      YYERROR;
				    } }
  ;

condList:
  exp '?' exp              { $$ = new OneCondCL(fname, line, $1, $3); }
  | exp '?' exp condList   { $$ = new MulCondCL(fname, line, $1, $3, $4); }
  ;

constant:
  INT           { $$ = new IntExp(fname, line, $1);
                  delete[] $1; }
  | BIN         { $$ = new IntExp(fname, line, $1 + 2, 2);
                  delete[] $1; }
  | HEX         { $$ = new IntExp(fname, line, $1 + 2, 16);
                  delete[] $1; }

  | FLOAT       { $$ = new FloatExp(fname, line, $1, 10, 0);
                  delete[] $1; }
  | FLOATP      { char *f = strtok($1, "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
		  $$ = new FloatExp(fname, line, f, 10, p);
		  delete[] $1; }
  | BFLOAT      { $$ = new FloatExp(fname, line, $1 + 2, 2, 0);
                  delete[] $1; }
  | BFLOATP     { char *f = strtok($1, "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
		  $$ = new FloatExp(fname, line, f + 2, 2, p);
		  delete[] $1; }
  | XFLOAT      { $$ = new FloatExp(fname, line, $1 + 2, 16, 0);
                  delete[] $1; }
  | XFLOATP     { char *f = strtok($1, "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
		  $$ = new FloatExp(fname, line, f + 2, 16, p);
		  delete[] $1; }

  | BOOL        { $$ = new BoolExp(fname, line, $1); }
  | STRING      { string str;
                  if (raw2str($1, str)) {
		    $$ = new StringExp(fname, line, str);
		    delete[] $1;
		  } else {
		    delete[] $1;
		    YYERROR;
		  } }
  | CHAR        { char c;
                  if (raw2char($1, c)) {
		    $$ = new CharExp(fname, line, c);
		    delete[] $1;
		  } else {
		    delete[] $1;
		    YYERROR;
		  } }
  | NULLTOK     { $$ = new NullExp(fname, line); }
  ;


paramList:
  nonEmptyParamList    { $$ = $1; }
  |                    { $$ = new EmptyPL(fname, line); }
  ;

nonEmptyParamList:
  VAR                        { $$ = new OneVarPL(fname, line, $1);
                               delete[] $1; }
  | nonEmptyParamList VAR    { $$ = new MulVarPL(fname, line, $2, $1);
                               delete[] $2; }
  ;

argList:
  nonEmptyArgList   { $$ = $1; }
  |                 { $$ = new EmptyAL(fname, line); }
  ;

nonEmptyArgList:
  exp                     { $$ = new OneArgAL(fname, line, $1); }
  | nonEmptyArgList exp   { $$ = new MulArgAL(fname, line, $2, $1); }
  ;

itemList:
  exp              { $$ = new OneExpIL(fname, line, $1); }
  | itemList exp   { $$ = new MulExpIL(fname, line, $2, $1); }
  ;

%%

void yyerror(char const *s) 
{
  printf(" %s:%d: %s\a\n", fname.c_str(), line, s);
}

Node *LimonParser::parse(char *code_str, string filename)
{
  set_scan_string(code_str); // Set input string
  fname = filename;
  line = 1;
  
  int res = yyparse();
  
  if (res == 0) return topNode;
  else return nullptr;
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

