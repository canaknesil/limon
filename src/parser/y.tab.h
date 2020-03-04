/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_PARSER_Y_TAB_H_INCLUDED
# define YY_YY_SRC_PARSER_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 35 "./src/parser/limon.y" /* yacc.c:1921  */


#include <node.h> // to create the AST


#line 54 "./src/parser/y.tab.h" /* yacc.c:1921  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    BIN = 259,
    HEX = 260,
    FLOAT = 261,
    FLOATP = 262,
    BFLOAT = 263,
    BFLOATP = 264,
    XFLOAT = 265,
    XFLOATP = 266,
    VAR = 267,
    SYM = 268,
    STRING = 269,
    CHAR = 270,
    BOOL = 271,
    DEF = 272,
    GEQ = 273,
    GEQ_K = 274,
    LEQ = 275,
    LEQ_K = 276,
    EQ = 277,
    EQ_K = 278,
    NEQ = 279,
    NEQ_K = 280,
    PRINT = 281,
    SIZEOF = 282,
    TOSTR = 283,
    TOCHAR = 284,
    TOINT = 285,
    TOFLOAT = 286,
    PLUSEQ = 287,
    MINEQ = 288,
    MULEQ = 289,
    DIVEQ = 290,
    REMEQ = 291,
    ANDEQ = 292,
    OREQ = 293,
    WHILE = 294,
    NULLTOK = 295,
    SCAN = 296,
    RUN = 297,
    ERROR = 298,
    VALTYPE = 299,
    GENSYM = 300,
    SAME = 301,
    MAKEARR = 302,
    ARRGET = 303,
    ARRSET = 304,
    STRGET = 305,
    STRSET = 306,
    PLUS_K = 307,
    MIN_K = 308,
    UMIN_K = 309,
    MUL_K = 310,
    DIV_K = 311,
    REM_K = 312,
    LOT_K = 313,
    GRT_K = 314,
    AND_K = 315,
    OR_K = 316,
    NOT_K = 317,
    THREEDOTS = 318,
    UMIN = 319,
    PLUSPLUS = 320,
    MINMIN = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 42 "./src/parser/limon.y" /* yacc.c:1921  */

  char *sVal = nullptr;
  bool bVal;
  Node *nodeVal;

#line 139 "./src/parser/y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_Y_TAB_H_INCLUDED  */
