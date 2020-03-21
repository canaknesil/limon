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
                         drv.result = {"program", j}; }
  |          { drv.result = {"empty_program", {}}; }
  ;


expList:
  exp              { json j = {{"exp", $1}};
                     $$ = {"one_exp_exp_list", j}; }
  | exp expList    { json j = {{"exp", $1}, {"exp_list", $2}};
                     $$ = {"mul_exp_exp_list", j}; }
  ;


exp:
  "{" expList "}"    { json j = {{"exp_list", $2}};
                       $$ = {"scope_exp", j}; }
  | "(" expList ")"  { $$ = $2; }
     
  | DEF "identifier" { json j = {{"var", $2}};
                       $$ = {"def_exp", j}; }
  | "identifier" "=" exp   { json j = {{"var", $1}, {"exp", $3}};
                             $$ = {"assign_exp", j}; }
  | "(" THREEDOTS paramList ")" "=" exp { json j = {{"param_list", $3}, {"exp", $6}};
                                          $$ = {"mul_assign_exp", j}; }
  | DEF "identifier" "=" exp   { json assign_node = {"assign_exp", {{"var", $2}, 
                                                                    {"exp", $4}}};
                                 json def_node = {"def_exp", {{"var", $2},
                                                              {"exp", $4}}};
                                 $$ = {"mul_exp_exp_list", {{"exp", def_node}, 
                                                            {"exp_list", {"one_exp_exp_list", {{"exp", assign_node}}}}}}; }
  | "(" condList ")"            { $$ = {"cond_exp", {{"cond_list", $2}}}; }
  | "[" PRINT exp "]"           { $$ = {"print_exp", {{"exp", $3}}}; }
  | "[" SCAN "]"                { $$ = {"scan_exp", {}}; }
  | "[" ERROR exp "]"           { $$ = {"error_exp", {{"exp", $3}}}; }
  | "[" VALTYPE exp "]"         { $$ = {"valtype_exp", {{"exp", $3}}}; }
  | "[" GENSYM "]"              { $$ = {"gensym_exp", {}}; }
  | "[" SAME exp exp "]"        { $$ = {"same_exp", {{"exp1", $3}, {"exp2", $4}}}; }
  
  | constant                    { $$ = $1; }
  | "identifier"                { $$ = {"var_exp", {{"var", $1}}}; }
        
  | "@" "(" paramList ")" "{" expList "}"  { $$ = {"proc_exp", {{"param_list", $3}, {"exp_list", $6}}}; }
  | "[" exp itemList "]"                   { $$ = {"call_exp", {{"exp", $2}, {"item_list", $3}}}; }
  | "[" exp exp THREEDOTS "]"              { $$ = {"splice_call_exp", {{"exp1", $2}, {"exp2", $3}}}; }

  | "[" "#" itemList "]"                   { $$ = {"array_const_exp", {{"item_list", $3}}}; }
  | "[" MAKEARR exp "]"                    { $$ = {"make_array_exp", {{"exp", $3}}}; }
  | "[" ARRGET exp exp "]"                 { $$ = {"array_get_exp", {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" ARRSET exp exp exp "]"             { $$ = {"array_set_exp", {{"exp1", $3}, {"exp2", $4}, {"exp3", $5}}}; }
  | "[" SIZEOF exp "]"                     { $$ = {"size_of_exp", {{"exp", $3}}}; }
        
  | "[" PLUS_K exp exp "]"  { $$ = {"plus_k", {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" MIN_K exp exp "]"   { $$ = {"min_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" MUL_K exp exp "]"   { $$ = {"mul_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" DIV_K exp exp "]"   { $$ = {"div_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" REM_K exp exp "]"   { $$ = {"rem_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" EQ_K exp exp "]"    { $$ = {"eq_k"  , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" NEQ_K exp exp "]"   { $$ = {"neq_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" LOT_K exp exp "]"   { $$ = {"lot_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" GRT_K exp exp "]"   { $$ = {"grt_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" LEQ_K exp exp "]"   { $$ = {"leq_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" GEQ_K exp exp "]"   { $$ = {"geq_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" AND_K exp exp "]"   { $$ = {"and_k" , {{"exp1", $3}, {"exp2", $4}}}; }
  | "[" OR_K exp exp "]"    { $$ = {"or_k"  , {{"exp1", $3}, {"exp2", $4}}}; }

  | exp "+" exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_plus"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp "-" exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_min"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp "*" exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_mul"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp "/" exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_div"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp "%" exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_rem"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp EQ exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_eq"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp NEQ exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_neq"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp "<" exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_lt"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp ">" exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_gt"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp LEQ exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_leq"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp GEQ exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_geq"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp "&" exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_and"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }
  | exp "|" exp       { $$ = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_or"}}}},
					   {"item_list", {"mul_exp_item_list", {{"exp", $1},
										{"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}}; }

  | "identifier" PLUSEQ exp    { json op_node = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_plus"}}}},
					                      {"item_list", {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", $1}}}},
												   {"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}};
                                 $$ = {"assign_exp", {{"var", $1},
                                                      {"exp", op_node}}}; }
  | "identifier" MINEQ exp     { json op_node = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_min"}}}},
					                      {"item_list", {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", $1}}}},
												   {"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}};
                                 $$ = {"assign_exp", {{"var", $1},
                                                      {"exp", op_node}}}; }
  | "identifier" MULEQ exp     { json op_node = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_mul"}}}},
					                      {"item_list", {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", $1}}}},
												   {"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}};
                                 $$ = {"assign_exp", {{"var", $1},
                                                      {"exp", op_node}}}; }
  | "identifier" DIVEQ exp     { json op_node = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_div"}}}},
					                      {"item_list", {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", $1}}}},
												   {"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}};
                                 $$ = {"assign_exp", {{"var", $1},
                                                      {"exp", op_node}}}; }
  | "identifier" REMEQ exp     { json op_node = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_rem"}}}},
					                      {"item_list", {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", $1}}}},
												   {"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}};
                                 $$ = {"assign_exp", {{"var", $1},
                                                      {"exp", op_node}}}; }
  | "identifier" ANDEQ exp     { json op_node = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_and"}}}},
					                      {"item_list", {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", $1}}}},
												   {"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}};
                                 $$ = {"assign_exp", {{"var", $1},
                                                      {"exp", op_node}}}; }
  | "identifier" OREQ exp      { json op_node = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_or"}}}},
					                      {"item_list", {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", $1}}}},
												   {"non_empty_item_list", {"one_exp_item_list", {{"exp", $3}}}}}}}}};
                                 $$ = {"assign_exp", {{"var", $1},
                                                      {"exp", op_node}}}; }

  | "[" UMIN_K exp "]"   { $$ = {"umin_k", {{"exp", $3}}}; }
  | "[" NOT_K exp "]"    { $$ = {"not_k",  {{"exp", $3}}}; }

  | "(" "-" exp ")" %prec UMIN   { $$ = {"call_exp", {{"var_exp", {{"var", "sw_umin"}}},
                                                      {"one_exp_item_list", {{"exp", $3}}}}}; }
  | "!" exp                      { $$ = {"call_exp", {{"var_exp", {{"var", "sw_not"}}},
                                                      {"one_exp_item_list", {{"exp", $2}}}}}; }

  | "[" RUN exp "]"              { $$ = {"run_exp", {{"exp", $3}}}; }
  ;


condList:
  exp "?" exp condElse     { $$ = {"one_cond_cond_list", {{"exp1", $1}, {"exp2", $3}, {"cond_else", $4}}}; }
  | exp "?" exp condList   { $$ = {"mul_cond_cond_list", {{"exp1", $1}, {"exp2", $3}, {"cond_list", $4}}}; }
  ;

condElse:
  ":" exp   { $$ = {"non_empty_cond_else", {{"exp", $2}}}; }
  |         { $$ = {"empty_cond_else", {}}; }
  ;

constant:
  INT           { $$ = {"int_exp", {{"int_str", $1}}}; }
  | BIN         { $$ = {"int_exp", {{"bin_str", $1}}}; }
  | HEX         { $$ = {"hex_exp", {{"hex_str", $1}}}; }

  | FLOAT       { $$ = {"float_exp", {{"float_str", $1}}}; }
  | FLOATP      { $$ = {"floatp_exp", {{"floatp_str", $1}}}; }

  | BOOL        { $$ = {"bool_exp", {{"bool", $1}}}; }
  | STRING      { $$ = {"string_exp", {{"string_str", $1}}}; }
  | CHAR        { $$ = {"char_exp", {{"char_str", $1}}}; }
  | SYMBOL      { $$ = {"symbol_exp", {{"symbol_str", $1}}}; }
  
  | NULLTOK     { $$ = {"null_exp", {}}; }
  ;


paramList:
  nonEmptyParamList    { $$ = $1; }
  |                    { $$ = {"empty_param_list", {}}; }
  ;

nonEmptyParamList:
  "identifier"                        { $$ = {"one_var_param_list", {{"var", $1}}}; }
  | "identifier" nonEmptyParamList    { $$ = {"mul_var_param_list", {{"var", $1}, {"non_empty_param_list", $2}}}; }
  ;

itemList:
  nonEmptyItemList   { $$ = $1; }
  |                  { $$ = {"empty_item_list", {}}; }
  ;

nonEmptyItemList:
  exp                      { $$ = {"one_exp_item_list", {{"exp", $1}}}; }
  | exp nonEmptyItemList   { $$ = {"mul_exp_item_list", {{"exp", $1}, {"non_empty_item_list", $2}}}; }
  ;


%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
