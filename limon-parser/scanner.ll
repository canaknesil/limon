%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "driver.hh"
# include "parser.hh"
%}

%{
#if defined __clang__
# define CLANG_VERSION (__clang_major__ * 100 + __clang_minor__)
#endif

// Clang and ICC like to pretend they are GCC.
#if defined __GNUC__ && !defined __clang__ && !defined __ICC
# define GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
#endif

// Pacify warnings in yy_init_buffer (observed with Flex 2.6.4)
// and GCC 6.4.0, 7.3.0 with -O3.
#if defined GCC_VERSION && 600 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wnull-dereference"
#endif

// This example uses Flex's C backend, yet compiles it as C++.
// So expect warnings about C style casts and NULL.
#if defined CLANG_VERSION && 500 <= CLANG_VERSION
# pragma clang diagnostic ignored "-Wold-style-cast"
# pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#elif defined GCC_VERSION && 407 <= GCC_VERSION
# pragma GCC diagnostic ignored "-Wold-style-cast"
# pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

#define FLEX_VERSION (YY_FLEX_MAJOR_VERSION * 100 + YY_FLEX_MINOR_VERSION)

// Old versions of Flex (2.5.35) generate an incomplete documentation comment.
//
//  In file included from src/scan-code-c.c:3:
//  src/scan-code.c:2198:21: error: empty paragraph passed to '@param' command
//        [-Werror,-Wdocumentation]
//   * @param line_number
//     ~~~~~~~~~~~~~~~~~^
//  1 error generated.
#if FLEX_VERSION < 206 && defined CLANG_VERSION
# pragma clang diagnostic ignored "-Wdocumentation"
#endif

// Old versions of Flex (2.5.35) use 'register'.  Warnings introduced in
// GCC 7 and Clang 6.
#if FLEX_VERSION < 206
# if defined CLANG_VERSION && 600 <= CLANG_VERSION
#  pragma clang diagnostic ignored "-Wdeprecated-register"
# elif defined GCC_VERSION && 700 <= GCC_VERSION
#  pragma GCC diagnostic ignored "-Wregister"
# endif
#endif

#if FLEX_VERSION < 206
# if defined CLANG_VERSION
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wdocumentation"
#  pragma clang diagnostic ignored "-Wshorten-64-to-32"
#  pragma clang diagnostic ignored "-Wsign-conversion"
# elif defined GCC_VERSION
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wsign-conversion"
# endif
#endif
%}

%option noyywrap nounput noinput batch debug

%{
  // A number symbol corresponding to the value in S.
  //yy::parser::symbol_type
  //make_NUMBER (const std::string &s, const yy::parser::location_type& loc);
%}

string     \"(\\.|[^\\\"])*\"
char       \'(\\.|[^\\\'])\'
int        [0-9]+
bin        0b[01]+
hex        0x[0-9A-Fa-f]+
float      [0-9]*\.[0-9]+
floatp     [0-9]*\.[0-9]+(p|P)[1-9][0-9]*
id         [a-zA-Z_][a-zA-Z_0-9]*
symbol     :[a-zA-Z_][a-zA-Z_0-9]*
blank      [ \t\r]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%x C_COMMENT

%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}
{blank}+   loc.step ();
\n+        loc.lines (yyleng); loc.step ();

"def"            return yy::parser::make_DEF(loc);
">="             return yy::parser::make_GEQ(loc);
"__geq__"        return yy::parser::make_GEQ_K(loc);
"<="             return yy::parser::make_LEQ(loc);
"__leq__"        return yy::parser::make_LEQ_K(loc);
"=="             return yy::parser::make_EQ(loc);
"__eq__"         return yy::parser::make_EQ_K(loc);
"!="             return yy::parser::make_NEQ(loc);
"__neq__"        return yy::parser::make_NEQ_K(loc);
"+="             return yy::parser::make_PLUSEQ(loc);
"-="             return yy::parser::make_MINEQ(loc);
"*="             return yy::parser::make_MULEQ(loc);
"/="             return yy::parser::make_DIVEQ(loc);
"%="             return yy::parser::make_REMEQ(loc);
"&="             return yy::parser::make_ANDEQ(loc);
"|="             return yy::parser::make_OREQ(loc);
"print"          return yy::parser::make_PRINT(loc); // TODO: To be implemented in standard library
"scan"           return yy::parser::make_SCAN(loc); // TODO: To be implemented in standard library
"__sizeof__"     return yy::parser::make_SIZEOF(loc);
"null"           return yy::parser::make_NULLTOK(loc);
"run"            return yy::parser::make_RUN(loc); /* Don't abstract this, it evaluates the file in the current environment.*/
"error"          return yy::parser::make_ERROR(loc); /* Don't abstract this, it should get filename and line information where it is invoked.*/
"__valuetype__"  return yy::parser::make_VALTYPE(loc);
"__gensym__"     return yy::parser::make_GENSYM(loc);
"__same__"       return yy::parser::make_SAME(loc);
"__make_array__" return yy::parser::make_MAKEARR(loc);
"__array_get__"  return yy::parser::make_ARRGET(loc);
"__array_set__"  return yy::parser::make_ARRSET(loc);
"__string_get__" return yy::parser::make_STRGET(loc);
"__string_set__" return yy::parser::make_STRSET(loc);
"..."            return yy::parser::make_THREEDOTS(loc);
"__plus__"       return yy::parser::make_PLUS_K(loc);
"__min__"        return yy::parser::make_MIN_K(loc);
"__umin__"       return yy::parser::make_UMIN_K(loc);
"__mul__"        return yy::parser::make_MUL_K(loc);
"__div__"        return yy::parser::make_DIV_K(loc);
"__rem__"        return yy::parser::make_REM_K(loc);
"__lot__"        return yy::parser::make_LOT_K(loc);
"__grt__"        return yy::parser::make_GRT_K(loc);
"__and__"        return yy::parser::make_AND_K(loc);
"__or__"         return yy::parser::make_OR_K(loc);
"__not__"        return yy::parser::make_NOT_K(loc);
"("              return yy::parser::make_LPAREN(loc);           
")"              return yy::parser::make_RPAREN(loc);           
"["              return yy::parser::make_LBRACK(loc);           
"]"              return yy::parser::make_RBRACK(loc);           
"{"              return yy::parser::make_LBRACE(loc);           
"}"              return yy::parser::make_RBRACE(loc);           
"="              return yy::parser::make_ASSIGN(loc);           
"@"              return yy::parser::make_AT(loc);               
"?"              return yy::parser::make_QMARK(loc);            
":"              return yy::parser::make_COLON(loc);            
"+"              return yy::parser::make_PLUS(loc);             
"-"              return yy::parser::make_MIN(loc);              
"*"              return yy::parser::make_STAR(loc);             
"/"              return yy::parser::make_DIV(loc);              
"%"              return yy::parser::make_PERCENT(loc);          
"<"              return yy::parser::make_LT(loc);               
">"              return yy::parser::make_GT(loc);               
"&"              return yy::parser::make_AND(loc);              
"|"              return yy::parser::make_OR(loc);               
"!"              return yy::parser::make_NOT(loc);              
"#"              return yy::parser::make_HASH(loc);             


"true"           return yy::parser::make_BOOL(true, loc);
"false"          return yy::parser::make_BOOL(false, loc);

{string}    return yy::parser::make_STRING (yytext, loc);
{char}      return yy::parser::make_CHAR (yytext, loc);
{int}       return yy::parser::make_INT (yytext, loc);
{bin}       return yy::parser::make_BIN (yytext, loc);
{hex}       return yy::parser::make_HEX (yytext, loc);
{float}     return yy::parser::make_FLOAT (yytext, loc);
{floatp}    return yy::parser::make_FLOATP (yytext, loc);
{id}        return yy::parser::make_IDENTIFIER (yytext, loc);
{symbol}    return yy::parser::make_SYMBOL (yytext, loc);

"/*"                { BEGIN(C_COMMENT); }
<C_COMMENT>"*/"     { BEGIN(INITIAL); }
<C_COMMENT>\n       { loc.lines (yyleng); loc.step (); }
<C_COMMENT>.        { loc.step (); }

"//"[^\n]*+\n            { loc.lines (1); loc.step (); }
 /* "//"[^<<EOF>>]*+<<EOF>>  return yy::parser::make_END (loc); */

.          {
             throw yy::parser::syntax_error
               (loc, "invalid character: " + std::string(yytext));
           }
<<EOF>>    return yy::parser::make_END (loc);
%%

// yy::parser::symbol_type
// make_NUMBER (const std::string &s, const yy::parser::location_type& loc)
// {
//   errno = 0;
//   long n = strtol (s.c_str(), NULL, 10);
//   if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
//     throw yy::parser::syntax_error (loc, "integer is out of range: " + s);
//   return yy::parser::make_NUMBER ((int) n, loc);
// }

void
driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void
driver::scan_end ()
{
  fclose (yyin);
}
