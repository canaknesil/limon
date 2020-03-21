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
#include "driver.hh"
#define LOC_JSON(START, END) {drv.file, START.begin.line, START.begin.column, END.end.line, END.end.column}

#define BIN_OP_SUGAR(OP, EXP1, EXP2, LOC1, LOC2)                                                                           \
{"call_exp", {{"exp", {"var_exp", {{"var", OP}}, LOC_JSON(LOC1, LOC2)}},                                                   \
              {"item_list", {"mul_exp_item_list", {{"exp", EXP1},                                                          \
                                                   {"non_empty_item_list", {"one_exp_item_list", {{"exp", EXP2}},          \
                                                                                                 LOC_JSON(LOC1, LOC2)}}},  \
                                                  LOC_JSON(LOC1, LOC2)}}}, LOC_JSON(LOC1, LOC2)}

#define BIN_OP_EQ_SUGAR(OP, EXP, EXP1, EXP2, LOC1, LOC2)                                                                                 \
json op_node = {"call_exp", {{"exp", {"var_exp", {{"var", OP}}, LOC_JSON(LOC1, LOC2)}},                                                  \
                             {"item_list", {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", EXP1}}, LOC_JSON(LOC1, LOC2)}},           \
                                                                  {"non_empty_item_list", {"one_exp_item_list", {{"exp", EXP2}},         \
                                                                                                                LOC_JSON(LOC1, LOC2)}}}, \
                                                                 LOC_JSON(LOC1, LOC2)}}},                                                \
                            LOC_JSON(LOC1, LOC2)};                                                                                       \
EXP = {"assign_exp", {{"var", EXP1},                             \
                      {"exp", op_node}}, LOC_JSON(LOC1, LOC2)}
}

%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  DEF              "def"
  GEQ              ">="
  GEQ_K            "__geq__"
  LEQ              "<="
  LEQ_K            "__leq__"
  EQ               "=="
  EQ_K             "__eq__"
  NEQ              "!="
  NEQ_K            "__neq__"
  PLUSEQ           "+="
  MINEQ            "-="
  MULEQ            "*="
  DIVEQ            "/="
  REMEQ            "%="
  ANDEQ            "&="
  OREQ             "|="
  PRINT            "print" // TODO: To be implemented in standard library
  SCAN             "scan"  // TODO: To be implemented in standard library
  SIZEOF           "__sizeof__"
  NULLTOK          "null"
  RUN              "run" /* Don't abstract this, it evaluates the file in the current environment.*/
  ERROR            "error" /* Don't abstract this, it should get filename and line information where it is invoked.*/
  VALTYPE          "__valuetype__"
  GENSYM           "__gensym__"
  SAME             "__same__"
  MAKEARR          "__make_array__"
  ARRGET           "__array_get__"
  ARRSET           "__array_set__"
  STRGET           "__string_get__"
  STRSET           "__string_set__"
  THREEDOTS        "..."
  PLUS_K           "__plus__"
  MIN_K            "__min__"
  UMIN_K           "__umin__"
  MUL_K            "__mul__"
  DIV_K            "__div__"
  REM_K            "__rem__"
  LOT_K            "__lot__"
  GRT_K            "__grt__"
  AND_K            "__and__"
  OR_K             "__or__"
  NOT_K            "__not__"
  LPAREN           "("
  RPAREN           ")"
  LBRACK           "["
  RBRACK           "]"
  LBRACE           "{"
  RBRACE           "}"
  ASSIGN           "="
  AT               "@"
  QMARK            "?"
  COLON            ":"
  PLUS             "+"
  MIN              "-"
  STAR             "*"
  DIV              "/"
  PERCENT          "%"
  LT               "<"
  GT               ">"
  AND              "&"
  OR               "|"
  NOT              "!"
  HASH             "#"
;

%token <bool> BOOL "bool"
%token <std::string> STRING "string"
%token <std::string> CHAR "char"
%token <std::string> INT "int"
%token <std::string> BIN "bin"
%token <std::string> HEX "hex"
%token <std::string> FLOAT "float"
%token <std::string> FLOATP "floarp"
%token <std::string> IDENTIFIER "identifier"
%token <std::string> SYMBOL "symbol"

%right "=" "+=" "-=" "*=" "/=" "%=" "&=" "|="
%left "&" "|"
%right "!"
%left "<" ">" "<=" ">=" "==" "!="
%left "+" "-";
%left "*" "/" "%";
%right UMIN

%nterm <json> exp expList condList condElse constant itemList nonEmptyItemList  paramList nonEmptyParamList program

%printer { yyo << $$; } <*>;

%%
%start program;

program:
  expList    { json j = {{"exp_list", $1}};
               drv.result = {"program", j, LOC_JSON(@$, @$)}; }
  |          { drv.result = {"empty_program", {}, LOC_JSON(@$, @$)}; }
  ;


expList:
  exp              { json j = {{"exp", $1}};
                     $$ = {"one_exp_exp_list", j, LOC_JSON(@$, @$)}; }
  | exp expList    { json j = {{"exp", $1}, {"exp_list", $2}};
                     $$ = {"mul_exp_exp_list", j, LOC_JSON(@$, @$)}; }
  ;


exp:
  "{" expList "}"    { json j = {{"exp_list", $2}};
                       $$ = {"scope_exp", j, LOC_JSON(@$, @$)}; }
  | "(" expList ")"  { $$ = $2; }
     
  | DEF "identifier" { json j = {{"var", $2}};
                       $$ = {"def_exp", j, LOC_JSON(@$, @$)}; }
  | "identifier" "=" exp   { json j = {{"var", $1}, {"exp", $3}};
                             $$ = {"assign_exp", j, LOC_JSON(@$, @$)}; }
  | "(" THREEDOTS paramList ")" "=" exp { json j = {{"param_list", $3}, {"exp", $6}};
                                          $$ = {"mul_assign_exp", j, LOC_JSON(@$, @$)}; }
  | DEF "identifier" "=" exp   { json assign_node = {"assign_exp", {{"var", $2}, 
                                                                    {"exp", $4}}, LOC_JSON(@$, @$)};
                                 json def_node = {"def_exp", {{"var", $2},
                                                              {"exp", $4}}, LOC_JSON(@$, @$)};
                                 $$ = {"mul_exp_exp_list", {{"exp", def_node}, 
                                                            {"exp_list", {"one_exp_exp_list", {{"exp", assign_node}}, LOC_JSON(@$, @$)}}}, LOC_JSON(@$, @$)}; }
  | "(" condList ")"            { $$ = {"cond_exp", {{"cond_list", $2}}, LOC_JSON(@$, @$)}; }
  | "[" PRINT exp "]"           { $$ = {"print_exp", {{"exp", $3}}, LOC_JSON(@$, @$)}; }
  | "[" SCAN "]"                { $$ = {"scan_exp", {}, LOC_JSON(@$, @$)}; }
  | "[" ERROR exp "]"           { $$ = {"error_exp", {{"exp", $3}}, LOC_JSON(@$, @$)}; }
  | "[" VALTYPE exp "]"         { $$ = {"valtype_exp", {{"exp", $3}}, LOC_JSON(@$, @$)}; }
  | "[" GENSYM "]"              { $$ = {"gensym_exp", {}, LOC_JSON(@$, @$)}; }
  | "[" SAME exp exp "]"        { $$ = {"same_exp", {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  
  | constant                    { $$ = $1; }
  | "identifier"                { $$ = {"var_exp", {{"var", $1}}, LOC_JSON(@$, @$)}; }
        
  | "@" "(" paramList ")" "{" expList "}"  { $$ = {"proc_exp", {{"param_list", $3}, {"exp_list", $6}}, LOC_JSON(@$, @$)}; }
  | "[" exp itemList "]"                   { $$ = {"call_exp", {{"exp", $2}, {"item_list", $3}}, LOC_JSON(@$, @$)}; }
  | "[" exp exp THREEDOTS "]"              { $$ = {"splice_call_exp", {{"exp1", $2}, {"exp2", $3}}, LOC_JSON(@$, @$)}; }

  | "[" "#" itemList "]"                   { $$ = {"array_const_exp", {{"item_list", $3}}, LOC_JSON(@$, @$)}; }
  | "[" MAKEARR exp "]"                    { $$ = {"make_array_exp", {{"exp", $3}}, LOC_JSON(@$, @$)}; }
  | "[" ARRGET exp exp "]"                 { $$ = {"array_get_exp", {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" ARRSET exp exp exp "]"             { $$ = {"array_set_exp", {{"exp1", $3}, {"exp2", $4}, {"exp3", $5}}, LOC_JSON(@$, @$)}; }
  | "[" SIZEOF exp "]"                     { $$ = {"size_of_exp", {{"exp", $3}}, LOC_JSON(@$, @$)}; }
        
  | "[" PLUS_K exp exp "]"  { $$ = {"plus_k", {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" MIN_K exp exp "]"   { $$ = {"min_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" MUL_K exp exp "]"   { $$ = {"mul_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" DIV_K exp exp "]"   { $$ = {"div_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" REM_K exp exp "]"   { $$ = {"rem_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" EQ_K exp exp "]"    { $$ = {"eq_k"  , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" NEQ_K exp exp "]"   { $$ = {"neq_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" LOT_K exp exp "]"   { $$ = {"lot_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" GRT_K exp exp "]"   { $$ = {"grt_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" LEQ_K exp exp "]"   { $$ = {"leq_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" GEQ_K exp exp "]"   { $$ = {"geq_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" AND_K exp exp "]"   { $$ = {"and_k" , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }
  | "[" OR_K exp exp "]"    { $$ = {"or_k"  , {{"exp1", $3}, {"exp2", $4}}, LOC_JSON(@$, @$)}; }

  | exp "+" exp       { $$ = BIN_OP_SUGAR("sw_plus", $1, $3, @$, @$); }
  | exp "-" exp       { $$ = BIN_OP_SUGAR("sw_min" , $1, $3, @$, @$); }
  | exp "*" exp       { $$ = BIN_OP_SUGAR("sw_mul" , $1, $3, @$, @$); }
  | exp "/" exp       { $$ = BIN_OP_SUGAR("sw_div" , $1, $3, @$, @$); }
  | exp "%" exp       { $$ = BIN_OP_SUGAR("sw_rem" , $1, $3, @$, @$); }
  | exp EQ exp        { $$ = BIN_OP_SUGAR("sw_eq"  , $1, $3, @$, @$); }
  | exp NEQ exp       { $$ = BIN_OP_SUGAR("sw_neq" , $1, $3, @$, @$); }
  | exp "<" exp       { $$ = BIN_OP_SUGAR("sw_lt"  , $1, $3, @$, @$); }
  | exp ">" exp       { $$ = BIN_OP_SUGAR("sw_gt"  , $1, $3, @$, @$); }
  | exp LEQ exp       { $$ = BIN_OP_SUGAR("sw_leq" , $1, $3, @$, @$); }
  | exp GEQ exp       { $$ = BIN_OP_SUGAR("sw_geq" , $1, $3, @$, @$); }
  | exp "&" exp       { $$ = BIN_OP_SUGAR("sw_and" , $1, $3, @$, @$); }
  | exp "|" exp       { $$ = BIN_OP_SUGAR("sw_or"  , $1, $3, @$, @$); }

  | "identifier" PLUSEQ exp    { BIN_OP_EQ_SUGAR("sw_plus", $$, $1, $3, @$, @$); }
  | "identifier" MINEQ exp     { BIN_OP_EQ_SUGAR("sw_min" , $$, $1, $3, @$, @$); }
  | "identifier" MULEQ exp     { BIN_OP_EQ_SUGAR("sw_mul" , $$, $1, $3, @$, @$); }
  | "identifier" DIVEQ exp     { BIN_OP_EQ_SUGAR("sw_div" , $$, $1, $3, @$, @$); }
  | "identifier" REMEQ exp     { BIN_OP_EQ_SUGAR("sw_rem" , $$, $1, $3, @$, @$); }
  | "identifier" ANDEQ exp     { BIN_OP_EQ_SUGAR("sw_and" , $$, $1, $3, @$, @$); }
  | "identifier" OREQ exp      { BIN_OP_EQ_SUGAR("sw_or"  , $$, $1, $3, @$, @$); }

  | "[" UMIN_K exp "]"   { $$ = {"umin_k", {{"exp", $3}}, LOC_JSON(@$, @$)}; }
  | "[" NOT_K exp "]"    { $$ = {"not_k",  {{"exp", $3}}, LOC_JSON(@$, @$)}; }

  | "(" "-" exp ")" %prec UMIN   { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_umin"}}, LOC_JSON(@$, @$)}},
                                                      {"item_list", {"one_exp_item_list", {{"exp", $3}}, LOC_JSON(@$, @$)}}},
						     LOC_JSON(@$, @$)}; }
  | "!" exp                      { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_not"}}, LOC_JSON(@$, @$)}},
                                                      {"item_list", {"one_exp_item_list", {{"exp", $2}}, LOC_JSON(@$, @$)}}},
						     LOC_JSON(@$, @$)}; }

  | "[" RUN exp "]"              { $$ = {"run_exp", {{"exp", $3}}, LOC_JSON(@$, @$)}; }
  ;


condList:
  exp "?" exp condElse     { $$ = {"one_cond_cond_list", {{"exp1", $1}, {"exp2", $3}, {"cond_else", $4}}, LOC_JSON(@$, @$)}; }
  | exp "?" exp condList   { $$ = {"mul_cond_cond_list", {{"exp1", $1}, {"exp2", $3}, {"cond_list", $4}}, LOC_JSON(@$, @$)}; }
  ;

condElse:
  ":" exp   { $$ = {"non_empty_cond_else", {{"exp", $2}}, LOC_JSON(@$, @$)}; }
  |         { $$ = {"empty_cond_else", {}, LOC_JSON(@$, @$)}; }
  ;

constant:
  INT           { $$ = {"int_exp", {{"int_str", $1}}, LOC_JSON(@$, @$)}; }
  | BIN         { $$ = {"int_exp", {{"bin_str", $1}}, LOC_JSON(@$, @$)}; }
  | HEX         { $$ = {"hex_exp", {{"hex_str", $1}}, LOC_JSON(@$, @$)}; }

  | FLOAT       { $$ = {"float_exp", {{"float_str", $1}}, LOC_JSON(@$, @$)}; }
  | FLOATP      { $$ = {"floatp_exp", {{"floatp_str", $1}}, LOC_JSON(@$, @$)}; }

  | BOOL        { $$ = {"bool_exp", {{"bool", $1}}, LOC_JSON(@$, @$)}; }
  | STRING      { $$ = {"string_exp", {{"string_str", $1}}, LOC_JSON(@$, @$)}; }
  | CHAR        { $$ = {"char_exp", {{"char_str", $1}}, LOC_JSON(@$, @$)}; }
  | SYMBOL      { $$ = {"symbol_exp", {{"symbol_str", $1}}, LOC_JSON(@$, @$)}; }
  
  | NULLTOK     { $$ = {"null_exp", {}, LOC_JSON(@$, @$)}; }
  ;


paramList:
  nonEmptyParamList    { $$ = $1; }
  |                    { $$ = {"empty_param_list", {}, LOC_JSON(@$, @$)}; }
  ;

nonEmptyParamList:
  "identifier"                        { $$ = {"one_var_param_list", {{"var", $1}}, LOC_JSON(@$, @$)}; }
  | "identifier" nonEmptyParamList    { $$ = {"mul_var_param_list", {{"var", $1}, {"non_empty_param_list", $2}}, LOC_JSON(@$, @$)}; }
  ;

itemList:
  nonEmptyItemList   { $$ = $1; }
  |                  { $$ = {"empty_item_list", {}, LOC_JSON(@$, @$)}; }
  ;

nonEmptyItemList:
  exp                      { $$ = {"one_exp_item_list", {{"exp", $1}}, LOC_JSON(@$, @$)}; }
  | exp nonEmptyItemList   { $$ = {"mul_exp_item_list", {{"exp", $1}, {"non_empty_item_list", $2}}, LOC_JSON(@$, @$)}; }
  ;


%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
