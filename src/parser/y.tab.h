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
#line 32 "./src/parser/limon.y" /* yacc.c:1921  */


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
    LEQ = 274,
    EQ = 275,
    NEQ = 276,
    PRINT = 277,
    SIZEOF = 278,
    TOSTR = 279,
    TOCHAR = 280,
    TOINT = 281,
    TOFLOAT = 282,
    PLUSEQ = 283,
    MINEQ = 284,
    MULEQ = 285,
    DIVEQ = 286,
    REMEQ = 287,
    ANDEQ = 288,
    OREQ = 289,
    WHILE = 290,
    NULLTOK = 291,
    SCAN = 292,
    RUN = 293,
    ERROR = 294,
    VALTYPE = 295,
    GENSYM = 296,
    UMIN = 297,
    PLUSPLUS = 298,
    MINMIN = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "./src/parser/limon.y" /* yacc.c:1921  */

  char *sVal = nullptr;
  bool bVal;
  Node *nodeVal;

#line 117 "./src/parser/y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_Y_TAB_H_INCLUDED  */
