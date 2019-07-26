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
extern int yylineno;

/* Internal variables and functions */
void yyerror(char const *);     // is called when an error occurs during parsing
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
%token <sVal> INT BIN HEX FLOAT FLOATP BFLOAT BFLOATP XFLOAT XFLOATP VAR SYM STRING CHAR
%token <bVal> BOOL
%token DEF GEQ LEQ EQ NEQ PRINT SIZEOF TOSTR TOCHAR TOINT TOFLOAT PLUSEQ MINEQ MULEQ DIVEQ REMEQ ANDEQ OREQ WHILE NULLTOK SCAN RUN ERROR VALTYPE GENSYM SAME MAKEARR ARRGET ARRSET STRGET STRSET

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
%type<nodeVal> exp expList condList constant argList nonEmptyArgList itemList nonEmptyItemList  paramList nonEmptyParamList 

%%

program:
  expList    { topNode = new AProgram(fname, yylineno, $1); }
  |          { topNode = new EmptyProgram(fname, yylineno); }
  ;


expList:
  exp              { $$ = new OneExpEL(fname, yylineno, $1); }
  | exp expList    { $$ = new MulExpEL(fname, yylineno, $1, $2); }
  ;

exp:
  '{' expList '}'    { $$ = new ScopeExp(fname, yylineno, $2); }
  | '(' expList ')'  { $$ = $2; }
     
  | DEF VAR           { $$ = new DefExp(fname, yylineno, $2);
                        delete[] $2; }
  | VAR '=' exp       { $$ = new AssignExp(fname, yylineno, $1, $3);
                        delete[] $1; }
  | DEF VAR '=' exp   { $$ = new MulExpEL(fname,
                                          yylineno,
                                          new DefExp(fname, yylineno, $2),
                                          new OneExpEL(fname,
                                                       yylineno,
                                                       new AssignExp(fname, yylineno, $2, $4)));
                        delete[] $2; /*sugar*/ }

  | '(' condList ')'            { $$ = new CondExp(fname, yylineno, $2); }
  | '(' condList ':' exp ')'    { $$ = new CondElseExp(fname, yylineno, $2, $4); }
  | '(' WHILE exp '?' exp ')'   { $$ = new WhileExp(fname, yylineno, $3, $5); }
  | '[' PRINT exp ']'           { $$ = new PrintExp(fname, yylineno, $3); }
  | '[' SCAN ']'                { $$ = new ScanExp(fname, yylineno); }
  | '[' ERROR exp ']'           { $$ = new ErrorExp(fname, yylineno, $3); }
  | '[' VALTYPE exp ']'         { $$ = new ValtypeExp(fname, yylineno, $3); }
  | '[' GENSYM ']'              { $$ = new GensymExp(fname, yylineno); }
  | '[' SAME exp exp ']'        { $$ = new SameExp(fname, yylineno, $3, $4); }
  
  | constant                    { $$ = $1; }
  | VAR                         { $$ = new VarExp(fname, yylineno, $1);
                                  delete[] $1; }
        
  | '@' '(' paramList ')' '{' expList '}'  { $$ = new ProcExp(fname, yylineno, $3, $6); }
  | '[' exp argList ']'                    { $$ = new CallExp(fname, yylineno, $2, $3); }

  | '[' '#' itemList ']'                   { $$ = new ArrayConst(fname, yylineno, $3); }
  | '[' MAKEARR exp ']'                    { $$ = new ArrayExp(fname, yylineno, $3); }
  | '[' ARRGET exp exp ']'                 { $$ = new ArrayGetExp(fname, yylineno, $3, $4); }
  | '[' ARRSET exp exp exp ']'             { $$ = new ArraySetExp(fname, yylineno, $3, $4, $5); }
  | '[' STRGET exp exp ']'                 { $$ = new StrGetExp(fname, yylineno, $3, $4); }
  | '[' STRSET exp exp exp ']'             { $$ = new StrSetExp(fname, yylineno, $3, $4, $5); }
  | '[' SIZEOF exp ']'                     { $$ = new SizeOfExp(fname, yylineno, $3); }
        
  | exp '+' exp       { $$ = new AddExp(fname, yylineno, $1, $3); }
  | exp '-' exp       { $$ = new SubExp(fname, yylineno, $1, $3); }
  | exp '*' exp       { $$ = new MulExp(fname, yylineno, $1, $3); }
  | exp '/' exp       { $$ = new DivExp(fname, yylineno, $1, $3); }
  | exp '%' exp       { $$ = new RemExp(fname, yylineno, $1, $3); }
  | exp EQ  exp       { $$ = new EquExp(fname, yylineno, $1, $3); }
  | exp NEQ exp       { $$ = new NEqExp(fname, yylineno, $1, $3); }
  | exp '<' exp       { $$ = new LoTExp(fname, yylineno, $1, $3); }
  | exp '>' exp       { $$ = new GrTExp(fname, yylineno, $1, $3); }
  | exp LEQ exp       { $$ = new LEqExp(fname, yylineno, $1, $3); }
  | exp GEQ exp       { $$ = new GEqExp(fname, yylineno, $1, $3); }
  | exp '&' exp       { $$ = new AndExp(fname, yylineno, $1, $3); }
  | exp '|' exp       { $$ = new OrExp(fname, yylineno, $1, $3); }

  | VAR PLUSEQ exp    { $$ = new AssignExp(fname, yylineno, $1, new AddExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, $1), $3));
                        delete[] $1; } 
  | VAR MINEQ exp     { $$ = new AssignExp(fname, yylineno, $1, new SubExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, $1), $3));
                        delete[] $1; }
  | VAR MULEQ exp     { $$ = new AssignExp(fname, yylineno, $1, new MulExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, $1), $3));
                        delete[] $1; }
  | VAR DIVEQ exp     { $$ = new AssignExp(fname, yylineno, $1, new DivExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, $1), $3));
                        delete[] $1; }
  | VAR REMEQ exp     { $$ = new AssignExp(fname, yylineno, $1, new RemExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, $1), $3));
                        delete[] $1; }
  | VAR ANDEQ exp     { $$ = new AssignExp(fname, yylineno, $1, new AndExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, $1), $3));
                        delete[] $1; }
  | VAR OREQ exp      { $$ = new AssignExp(fname, yylineno, $1, new OrExp(fname, yylineno,
                                                                      new VarExp(fname, yylineno, $1), $3));
                        delete[] $1; }

  | '(' '-' exp ')' %prec UMIN    { $$ = new MinExp(fname, yylineno, $3); }
  | '!' exp                       { $$ = new NotExp(fname, yylineno, $2); }

  | '[' TOSTR exp ']'             { $$ = new ToStrExp(fname, yylineno, $3); }
  | '[' TOCHAR exp ']'            { $$ = new ToCharExp(fname, yylineno, $3); }
  | '[' TOINT exp ']'             { $$ = new ToIntExp(fname, yylineno, $3); }
  | '[' TOFLOAT exp ']'           { $$ = new ToFloatExp(fname, yylineno, $3); }

  | '[' RUN exp ']'               { $$ = new RunExp(fname, yylineno, $3); }
  ;

condList:
  exp '?' exp              { $$ = new OneCondCL(fname, yylineno, $1, $3); }
  | exp '?' exp condList   { $$ = new MulCondCL(fname, yylineno, $1, $3, $4); }
  ;

constant:
  INT           { $$ = new IntExp(fname, yylineno, $1);
                  delete[] $1; }
  | BIN         { $$ = new IntExp(fname, yylineno, $1 + 2, 2);
                  delete[] $1; }
  | HEX         { $$ = new IntExp(fname, yylineno, $1 + 2, 16);
                  delete[] $1; }

  | FLOAT       { $$ = new FloatExp(fname, yylineno, $1, 10, 0);
                  delete[] $1; }
  | FLOATP      { char *f = strtok($1, "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
                  $$ = new FloatExp(fname, yylineno, f, 10, p);
                  delete[] $1; }
  | BFLOAT      { $$ = new FloatExp(fname, yylineno, $1 + 2, 2, 0);
                  delete[] $1; }
  | BFLOATP     { char *f = strtok($1, "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
                  $$ = new FloatExp(fname, yylineno, f + 2, 2, p);
                  delete[] $1; }
  | XFLOAT      { $$ = new FloatExp(fname, yylineno, $1 + 2, 16, 0);
                  delete[] $1; }
  | XFLOATP     { char *f = strtok($1, "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
                  $$ = new FloatExp(fname, yylineno, f + 2, 16, p);
                  delete[] $1; }

  | BOOL        { $$ = new BoolExp(fname, yylineno, $1); }
  | STRING      { string str;
                  if (raw2str($1, str)) {
                    $$ = new StringExp(fname, yylineno, str);
                    delete[] $1;
                  } else {
                    delete[] $1;
                    YYERROR;
                  } }
  | CHAR        { char c;
                  if (raw2char($1, c)) {
                    $$ = new CharExp(fname, yylineno, c);
                    delete[] $1;
                  } else {
                    delete[] $1;
                    YYERROR;
                  } }
  | SYM         { $$ = new SymbolExp(fname, yylineno, $1+1);
                  delete[] $1; }
  | NULLTOK     { $$ = new NullExp(fname, yylineno); }
  ;


paramList:
  nonEmptyParamList    { $$ = $1; }
  |                    { $$ = new EmptyPL(fname, yylineno); }
  ;

nonEmptyParamList:
  VAR                        { $$ = new OneVarPL(fname, yylineno, $1);
                               delete[] $1; }
  | nonEmptyParamList VAR    { $$ = new MulVarPL(fname, yylineno, $2, $1);
                               delete[] $2; }
  ;

argList:
  nonEmptyArgList   { $$ = $1; }
  |                 { $$ = new EmptyAL(fname, yylineno); }
  ;

nonEmptyArgList:
  exp                     { $$ = new OneArgAL(fname, yylineno, $1); }
  | nonEmptyArgList exp   { $$ = new MulArgAL(fname, yylineno, $2, $1); }
  ;

itemList:
  nonEmptyItemList   { $$ = $1; }
  |                  { $$ = new EmptyIL(fname, yylineno); }
  ;

nonEmptyItemList:
  exp              { $$ = new OneExpIL(fname, yylineno, $1); }
  | itemList exp   { $$ = new MulExpIL(fname, yylineno, $2, $1); }
  ;


  

%%

void yyerror(char const *s) 
{
  printf("%s:%d: %s\n", fname.c_str(), yylineno, s);
}

Node *LimonParser::parse(char *code_str, string filename)
{
  set_scan_string(code_str); // Set input string
  fname = filename;
  yylineno = 1;
  
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

