%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.5"
%defines

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  # include "json.hpp"

  using json = nlohmann::json;

  class driver;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {
# include "driver.hh"
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  ASSIGN  ":="
  MINUS   "-"
  PLUS    "+"
  STAR    "*"
  SLASH   "/"
  LPAREN  "("
  RPAREN  ")"
;

%token <std::string> IDENTIFIER "identifier"
%token <std::string> NUMBER "number"
%nterm <json> exp assignment assignments unit

%printer { yyo << $$; } <*>;

%%
%start unit;
unit: assignments exp  { json j = {{"assignments", $1}, {"exp", $2}};
			 drv.result = {"program", j}; }

assignments:
  %empty                 { $$ = {"empty-assignments", {}}; }
| assignments assignment { json j = {{"assignments", $1}, {"assignment", $2}};
			   $$ = {"non-empty-assignments", j}; };

assignment:
"identifier" ":=" exp { json j = {{"identifier", $1}, {"exp", $3}};
                        $$ = {"assignment", j}; };

%left "+" "-";
%left "*" "/";
exp:
  "number"      { json j = {{"number-const", $1}};
                  $$ = {"number", j}; }
| "identifier"  { json j = {{"identifier-const", $1}};
                  $$ = {"identifier", j}; }
| exp "+" exp   { json j = {{"exp1", $1}, {"exp2", $3}};
                  $$ = {"addition", j}; }
| exp "-" exp   { json j = {{"exp1", $1}, {"exp2", $3}};
                  $$ = {"substraction", j}; }
| exp "*" exp   { json j = {{"exp1", $1}, {"exp2", $3}};
                  $$ = {"multiplication", j}; }
| exp "/" exp   { json j = {{"exp1", $1}, {"exp2", $3}};
                  $$ = {"division", j}; }
| "(" exp ")"   { json j = {{"exp", $2}};
                  $$ = {"precedence", j}; }
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
