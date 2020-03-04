/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./src/parser/limon.y" /* yacc.c:337  */


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
void delete_scan_string(); // this is defined in limon.l
extern int yylineno;

/* Internal variables and functions */
void yyerror(char const *);     // is called when an error occurs during parsing
static Node *topNode = nullptr; // the AST top node, used during parsing
static string fname;            // name of the parsed file, used during parsing

// Transforms the text, read from the source file, to the string|character it represents.
static bool raw2str(char *raw, string &str);
static bool raw2char(char *raw, char &c);



#line 101 "./src/parser/y.tab.cpp" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 35 "./src/parser/limon.y" /* yacc.c:352  */


#include <node.h> // to create the AST


#line 140 "./src/parser/y.tab.cpp" /* yacc.c:352  */

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
#line 42 "./src/parser/limon.y" /* yacc.c:352  */

  char *sVal = nullptr;
  bool bVal;
  Node *nodeVal;

#line 225 "./src/parser/y.tab.cpp" /* yacc.c:352  */
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



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1214

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

#define YYUNDEFTOK  2
#define YYMAXUTOK   321

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,    87,     2,    74,    66,     2,
      80,    81,    72,    70,     2,    71,     2,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,     2,
      68,    64,    69,    83,    86,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    84,     2,    85,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,    65,    79,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    75,
      76,    77
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    71,    76,    77,    81,    82,    84,    86,
      88,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     106,   107,   110,   111,   112,   114,   115,   116,   117,   118,
     119,   120,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   136,   139,   142,   145,   148,
     151,   154,   157,   160,   163,   166,   169,   172,   176,   179,
     182,   185,   188,   191,   194,   198,   199,   201,   203,   206,
     207,   208,   209,   211,   215,   216,   220,   222,   224,   227,
     229,   233,   235,   239,   241,   246,   247,   255,   263,   265,
     270,   271,   275,   277,   282,   283,   287,   288
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "BIN", "HEX", "FLOAT", "FLOATP",
  "BFLOAT", "BFLOATP", "XFLOAT", "XFLOATP", "VAR", "SYM", "STRING", "CHAR",
  "BOOL", "DEF", "GEQ", "GEQ_K", "LEQ", "LEQ_K", "EQ", "EQ_K", "NEQ",
  "NEQ_K", "PRINT", "SIZEOF", "TOSTR", "TOCHAR", "TOINT", "TOFLOAT",
  "PLUSEQ", "MINEQ", "MULEQ", "DIVEQ", "REMEQ", "ANDEQ", "OREQ", "WHILE",
  "NULLTOK", "SCAN", "RUN", "ERROR", "VALTYPE", "GENSYM", "SAME",
  "MAKEARR", "ARRGET", "ARRSET", "STRGET", "STRSET", "PLUS_K", "MIN_K",
  "UMIN_K", "MUL_K", "DIV_K", "REM_K", "LOT_K", "GRT_K", "AND_K", "OR_K",
  "NOT_K", "THREEDOTS", "'='", "'|'", "'&'", "'!'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "UMIN", "PLUSPLUS", "MINMIN", "'{'", "'}'",
  "'('", "')'", "':'", "'?'", "'['", "']'", "'@'", "'#'", "$accept",
  "program", "expList", "exp", "condList", "constant", "paramList",
  "nonEmptyParamList", "itemList", "nonEmptyItemList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    61,   124,    38,    33,    60,    62,
      43,    45,    42,    47,    37,   319,   320,   321,   123,   125,
      40,    41,    58,    63,    91,    93,    64,    35
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     369,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     147,   -68,   -68,   -68,   -68,   -10,   -68,   369,   369,   354,
     146,   -60,    36,   -68,   270,   -68,   369,   369,   369,   369,
     369,   369,   369,   369,   -24,  1140,    -4,   369,   369,    -5,
     231,   -21,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,    -7,   369,   369,   369,    -3,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   270,    68,   -68,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   -68,  1124,  1124,  1124,  1124,  1124,  1124,  1124,  1124,
     369,   -68,  1009,  1044,   -68,   369,   -68,   369,   270,   270,
     270,   270,    59,   331,   393,   411,   421,   450,   -68,   479,
     489,   507,   -68,   270,   547,   270,   270,   270,   270,   270,
     270,   565,   270,   270,   270,   270,   270,   270,   270,   575,
    1124,     1,   369,   194,     2,   -68,     4,    76,   -65,   -65,
     -65,   -65,  1133,  1140,   -65,   -65,   -49,   -49,   -68,   -68,
     -68,  1124,   369,   -68,   270,  1066,   604,   633,   643,   661,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   701,
     -68,   719,   270,   729,   270,   758,   787,   -68,   797,   815,
     855,   873,   883,   912,   941,   -68,   -68,  1124,     5,   -68,
      18,   -68,  1102,  1028,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   951,   -68,   969,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   369,   -68,   -68,   -68,    19,
     -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      21,    88,    86,    87,    85,     0,    89,     0,     0,     0,
       0,     0,     0,     2,     4,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     8,    68,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    95,    91,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,    58,    59,    60,    61,    62,    63,    64,     9,
       0,     6,     0,     0,     7,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,    94,    96,     0,    92,     0,    90,    55,    54,
      50,    51,    57,    56,    52,    53,    45,    46,    47,    48,
      49,    10,     0,    67,    74,     0,     0,     0,     0,     0,
      14,    31,    69,    70,    71,    72,    73,    16,    17,     0,
      26,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,     0,     0,    66,    25,    97,     0,    23,
       0,    93,     0,     0,    75,    12,    42,    41,    37,    38,
      19,    27,     0,    29,     0,    32,    33,    34,    35,    36,
      39,    40,    43,    44,    24,     0,    13,    28,    30,     0,
      22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,     0,   -16,   -67,   -68,   -68,   -68,    24,   -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    91,    24,    41,    25,   146,   147,   141,   142
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    35,    34,    40,    75,    86,    87,    88,    89,    90,
      92,    93,    94,    95,    96,    97,    98,    99,    36,    39,
      76,   102,   103,    88,    89,    90,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    77,   119,   120,   121,
     100,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   143,
     106,   107,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   101,   104,    78,   118,    79,
     145,    80,   122,    81,   161,   200,   196,   199,   201,   164,
     224,   165,   166,   167,   168,   169,   225,   204,   230,   144,
       0,     0,     0,     0,     0,     0,     0,   179,     0,   181,
     182,   183,   184,   185,   186,     0,   188,   189,   190,   191,
     192,   193,   194,     0,    82,    83,   197,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,     0,   202,     0,   203,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,    42,   212,    43,   214,    44,
       0,    45,    46,    47,    48,    49,    50,    51,     0,    26,
      27,    28,    29,    30,    31,    32,    16,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,    33,    78,    17,    79,     0,    80,     0,    81,     0,
       0,     0,     0,     0,    18,   229,    19,     0,     0,     0,
      20,     0,    21,    74,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    78,
       0,    79,     0,    80,     0,    81,     0,   198,     0,    82,
      83,     0,    84,    85,    86,    87,    88,    89,    90,     0,
       0,    16,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    78,     0,
      79,     0,    80,     0,    81,     0,    82,    83,    17,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,    18,
      16,    19,     0,     0,   105,    20,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    17,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,    18,    78,
      19,    79,     0,    80,    20,    81,    21,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,    37,    16,     0,    82,    83,     0,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,    16,
       0,    78,     0,    79,     0,    80,   171,    81,     0,     0,
       0,    17,     0,     0,     0,    38,     0,     0,     0,    78,
       0,    79,    18,    80,    19,    81,    17,     0,    20,    78,
      21,    79,     0,    80,     0,    81,     0,    18,     0,    19,
       0,     0,     0,    20,     0,    21,     0,     0,    82,    83,
       0,    84,    85,    86,    87,    88,    89,    90,    78,     0,
      79,     0,    80,     0,    81,     0,    82,    83,   172,    84,
      85,    86,    87,    88,    89,    90,    82,    83,     0,    84,
      85,    86,    87,    88,    89,    90,   173,    78,     0,    79,
       0,    80,     0,    81,     0,     0,   174,    78,     0,    79,
       0,    80,     0,    81,     0,    82,    83,     0,    84,    85,
      86,    87,    88,    89,    90,    78,     0,    79,     0,    80,
       0,    81,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,     0,    84,    85,    86,
      87,    88,    89,    90,    82,    83,     0,    84,    85,    86,
      87,    88,    89,    90,   176,    78,     0,    79,     0,    80,
       0,    81,    82,    83,   177,    84,    85,    86,    87,    88,
      89,    90,     0,    78,     0,    79,     0,    80,     0,    81,
       0,     0,   178,    78,     0,    79,     0,    80,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    83,     0,    84,    85,    86,    87,    88,
      89,    90,    78,     0,    79,     0,    80,     0,    81,     0,
      82,    83,   180,    84,    85,    86,    87,    88,    89,    90,
      82,    83,     0,    84,    85,    86,    87,    88,    89,    90,
     187,    78,     0,    79,     0,    80,     0,    81,     0,     0,
     195,    78,     0,    79,     0,    80,     0,    81,     0,    82,
      83,     0,    84,    85,    86,    87,    88,    89,    90,    78,
       0,    79,     0,    80,     0,    81,     0,     0,     0,   206,
       0,     0,     0,     0,     0,     0,     0,     0,    82,    83,
       0,    84,    85,    86,    87,    88,    89,    90,    82,    83,
       0,    84,    85,    86,    87,    88,    89,    90,   207,    78,
       0,    79,     0,    80,     0,    81,    82,    83,   208,    84,
      85,    86,    87,    88,    89,    90,     0,    78,     0,    79,
       0,    80,     0,    81,     0,     0,   209,    78,     0,    79,
       0,    80,     0,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,     0,    84,
      85,    86,    87,    88,    89,    90,    78,     0,    79,     0,
      80,     0,    81,     0,    82,    83,   210,    84,    85,    86,
      87,    88,    89,    90,    82,    83,     0,    84,    85,    86,
      87,    88,    89,    90,   211,    78,     0,    79,     0,    80,
       0,    81,     0,     0,   213,    78,     0,    79,     0,    80,
       0,    81,     0,    82,    83,     0,    84,    85,    86,    87,
      88,    89,    90,    78,     0,    79,     0,    80,     0,    81,
       0,     0,     0,   215,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    83,     0,    84,    85,    86,    87,    88,
      89,    90,    82,    83,     0,    84,    85,    86,    87,    88,
      89,    90,   216,    78,     0,    79,     0,    80,     0,    81,
      82,    83,   217,    84,    85,    86,    87,    88,    89,    90,
       0,    78,     0,    79,     0,    80,     0,    81,     0,     0,
     218,    78,     0,    79,     0,    80,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,     0,    84,    85,    86,    87,    88,    89,    90,
      78,     0,    79,     0,    80,     0,    81,     0,    82,    83,
     219,    84,    85,    86,    87,    88,    89,    90,    82,    83,
       0,    84,    85,    86,    87,    88,    89,    90,   220,    78,
       0,    79,     0,    80,     0,    81,     0,     0,   221,    78,
       0,    79,     0,    80,     0,    81,     0,    82,    83,     0,
      84,    85,    86,    87,    88,    89,    90,    78,     0,    79,
       0,    80,     0,    81,     0,     0,     0,   222,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    83,     0,    84,
      85,    86,    87,    88,    89,    90,    82,    83,     0,    84,
      85,    86,    87,    88,    89,    90,   223,    78,     0,    79,
       0,    80,     0,    81,    82,    83,   227,    84,    85,    86,
      87,    88,    89,    90,     0,     0,    78,     0,    79,     0,
      80,     0,    81,     0,   228,     0,     0,     0,     0,     0,
       0,     0,    78,     0,    79,     0,    80,     0,    81,     0,
       0,     0,     0,     0,    82,    83,     0,    84,    85,    86,
      87,    88,    89,    90,    78,     0,    79,     0,    80,     0,
      81,     0,   162,    82,    83,     0,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,     0,     0,     0,    82,
      83,   105,    84,    85,    86,    87,    88,    89,    90,     0,
      78,     0,    79,     0,    80,   163,    81,     0,     0,     0,
       0,    82,    83,     0,    84,    85,    86,    87,    88,    89,
      90,     0,    78,     0,    79,     0,    80,   205,    81,     0,
       0,    78,     0,    79,     0,    80,     0,    81,    78,     0,
      79,     0,    80,     0,    81,     0,     0,    82,    83,     0,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
       0,     0,     0,   226,     0,     0,     0,     0,     0,    82,
      83,     0,    84,    85,    86,    87,    88,    89,    90,    83,
       0,    84,    85,    86,    87,    88,    89,    90,    84,    85,
      86,    87,    88,    89,    90
};

static const yytype_int16 yycheck[] =
{
       0,    17,    12,    19,    20,    70,    71,    72,    73,    74,
      26,    27,    28,    29,    30,    31,    32,    33,    18,    19,
      80,    37,    38,    72,    73,    74,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     0,    53,    54,    55,
      64,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      81,    82,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    79,    81,    18,    85,    20,
      12,    22,    85,    24,   100,    81,    85,    85,    12,   105,
      85,   107,   108,   109,   110,   111,    78,   164,    79,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,   125,
     126,   127,   128,   129,   130,    -1,   132,   133,   134,   135,
     136,   137,   138,    -1,    65,    66,   142,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,   162,    -1,   164,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,   182,    21,   184,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    -1,    32,
      33,    34,    35,    36,    37,    38,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    64,    18,    67,    20,    -1,    22,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    78,   225,    80,    -1,    -1,    -1,
      84,    -1,    86,    87,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    20,    -1,    22,    -1,    24,    -1,    63,    -1,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    40,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    -1,    22,    -1,    24,    -1,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      40,    80,    -1,    -1,    83,    84,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    78,    18,
      80,    20,    -1,    22,    84,    24,    86,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    40,
      -1,    18,    -1,    20,    -1,    22,    85,    24,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    -1,    18,
      -1,    20,    78,    22,    80,    24,    67,    -1,    84,    18,
      86,    20,    -1,    22,    -1,    24,    -1,    78,    -1,    80,
      -1,    -1,    -1,    84,    -1,    86,    -1,    -1,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    18,    -1,
      20,    -1,    22,    -1,    24,    -1,    65,    66,    85,    68,
      69,    70,    71,    72,    73,    74,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    85,    18,    -1,    20,
      -1,    22,    -1,    24,    -1,    -1,    85,    18,    -1,    20,
      -1,    22,    -1,    24,    -1,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    18,    -1,    20,    -1,    22,
      -1,    24,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    85,    18,    -1,    20,    -1,    22,
      -1,    24,    65,    66,    85,    68,    69,    70,    71,    72,
      73,    74,    -1,    18,    -1,    20,    -1,    22,    -1,    24,
      -1,    -1,    85,    18,    -1,    20,    -1,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    18,    -1,    20,    -1,    22,    -1,    24,    -1,
      65,    66,    85,    68,    69,    70,    71,    72,    73,    74,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      85,    18,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,
      85,    18,    -1,    20,    -1,    22,    -1,    24,    -1,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    18,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    85,    18,
      -1,    20,    -1,    22,    -1,    24,    65,    66,    85,    68,
      69,    70,    71,    72,    73,    74,    -1,    18,    -1,    20,
      -1,    22,    -1,    24,    -1,    -1,    85,    18,    -1,    20,
      -1,    22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    18,    -1,    20,    -1,
      22,    -1,    24,    -1,    65,    66,    85,    68,    69,    70,
      71,    72,    73,    74,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    85,    18,    -1,    20,    -1,    22,
      -1,    24,    -1,    -1,    85,    18,    -1,    20,    -1,    22,
      -1,    24,    -1,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    18,    -1,    20,    -1,    22,    -1,    24,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    85,    18,    -1,    20,    -1,    22,    -1,    24,
      65,    66,    85,    68,    69,    70,    71,    72,    73,    74,
      -1,    18,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,
      85,    18,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      18,    -1,    20,    -1,    22,    -1,    24,    -1,    65,    66,
      85,    68,    69,    70,    71,    72,    73,    74,    65,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    85,    18,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    85,    18,
      -1,    20,    -1,    22,    -1,    24,    -1,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    18,    -1,    20,
      -1,    22,    -1,    24,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    85,    18,    -1,    20,
      -1,    22,    -1,    24,    65,    66,    85,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    18,    -1,    20,    -1,
      22,    -1,    24,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    20,    -1,    22,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    18,    -1,    20,    -1,    22,    -1,
      24,    -1,    83,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    83,    68,    69,    70,    71,    72,    73,    74,    -1,
      18,    -1,    20,    -1,    22,    81,    24,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    -1,    18,    -1,    20,    -1,    22,    81,    24,    -1,
      -1,    18,    -1,    20,    -1,    22,    -1,    24,    18,    -1,
      20,    -1,    22,    -1,    24,    -1,    -1,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    68,    69,
      70,    71,    72,    73,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    40,    67,    78,    80,
      84,    86,    89,    90,    91,    93,    32,    33,    34,    35,
      36,    37,    38,    64,    12,    91,    90,    39,    71,    90,
      91,    92,    19,    21,    23,    25,    26,    27,    28,    29,
      30,    31,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    87,    91,    80,     0,    18,    20,
      22,    24,    65,    66,    68,    69,    70,    71,    72,    73,
      74,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      64,    79,    91,    91,    81,    83,    81,    82,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    85,    91,
      91,    91,    85,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    96,    97,    91,    96,    12,    94,    95,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    83,    81,    91,    91,    91,    91,    91,    91,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    91,
      85,    91,    91,    91,    91,    91,    91,    85,    91,    91,
      91,    91,    91,    91,    91,    85,    85,    91,    63,    85,
      81,    12,    91,    91,    92,    81,    85,    85,    85,    85,
      85,    85,    91,    85,    91,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    78,    81,    85,    85,    90,
      79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    90,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    92,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     3,     3,     2,     3,
       4,     3,     5,     6,     4,     3,     4,     4,     3,     5,
       1,     1,     7,     4,     5,     4,     4,     5,     6,     5,
       6,     4,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     4,     2,     4,
       4,     4,     4,     4,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     2,     1,     0,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 70 "./src/parser/limon.y" /* yacc.c:1652  */
    { topNode = new AProgram(fname, (yyloc).first_line, (yyvsp[0].nodeVal)); }
#line 1779 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 3:
#line 71 "./src/parser/limon.y" /* yacc.c:1652  */
    { topNode = new EmptyProgram(fname, yylineno); }
#line 1785 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 4:
#line 76 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OneExpEL(fname, yylineno, (yyvsp[0].nodeVal)); }
#line 1791 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 5:
#line 77 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulExpEL(fname, yylineno, (yyvsp[-1].nodeVal), (yyvsp[0].nodeVal)); }
#line 1797 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 81 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ScopeExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 1803 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 82 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = (yyvsp[-1].nodeVal); }
#line 1809 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 84 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new DefExp(fname, yylineno, (yyvsp[0].sVal));
                        delete[] (yyvsp[0].sVal); }
#line 1816 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 9:
#line 86 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, yylineno, (yyvsp[-2].sVal), (yyvsp[0].nodeVal));
                        delete[] (yyvsp[-2].sVal); }
#line 1823 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 88 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulExpEL(fname,
                                          yylineno,
                                          new DefExp(fname, yylineno, (yyvsp[-2].sVal)),
                                          new OneExpEL(fname,
                                                       yylineno,
                                                       new AssignExp(fname, yylineno, (yyvsp[-2].sVal), (yyvsp[0].nodeVal))));
                        delete[] (yyvsp[-2].sVal); /*sugar*/ }
#line 1835 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 96 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CondExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 1841 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 97 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CondElseExp(fname, yylineno, (yyvsp[-3].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1847 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 98 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new WhileExp(fname, yylineno, (yyvsp[-3].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1853 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 99 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new PrintExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 1859 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 100 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ScanExp(fname, yylineno); }
#line 1865 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 101 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ErrorExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 1871 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 102 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ValtypeExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 1877 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 103 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new GensymExp(fname, yylineno); }
#line 1883 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 104 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new SameExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1889 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 106 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = (yyvsp[0].nodeVal); }
#line 1895 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 107 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new VarExp(fname, yylineno, (yyvsp[0].sVal));
                                  delete[] (yyvsp[0].sVal); }
#line 1902 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 110 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ProcExp(fname, yylineno, (yyvsp[-4].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1908 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 111 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1914 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 112 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new SpliceCallExp(fname, yylineno, (yyvsp[-3].nodeVal), (yyvsp[-2].nodeVal)); }
#line 1920 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 114 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ArrayConst(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 1926 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 115 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ArrayExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 1932 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 116 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ArrayGetExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1938 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 117 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ArraySetExp(fname, yylineno, (yyvsp[-3].nodeVal), (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1944 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 118 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new StrGetExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1950 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 119 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new StrSetExp(fname, yylineno, (yyvsp[-3].nodeVal), (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1956 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 120 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new SizeOfExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 1962 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 122 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AddExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1968 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 123 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new SubExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1974 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 124 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1980 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 125 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new DivExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1986 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 126 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new RemExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1992 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 127 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new EquExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1998 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 128 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new NEqExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2004 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 39:
#line 129 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new LoTExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2010 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 40:
#line 130 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new GrTExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2016 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 41:
#line 131 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new LEqExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2022 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 42:
#line 132 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new GEqExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2028 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 43:
#line 133 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AndExp(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2034 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 134 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OrExp(fname, yylineno,  (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2040 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 136 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_plus"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2048 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 139 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_min"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2056 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 142 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_mul"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2064 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 145 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_div"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2072 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 148 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_rem"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2080 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 151 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_eq"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2088 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 154 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_neq"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2096 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 157 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_lot"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2104 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 160 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_grt"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2112 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 163 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_leq"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2120 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 166 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_geq"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2128 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 169 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_and"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2136 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 172 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_or"),
                                             new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal),
					          new OneExpIL(fname, yylineno, (yyvsp[-2].nodeVal)))); }
#line 2144 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 176 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, yylineno, (yyvsp[-2].sVal), new AddExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 2152 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 179 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, yylineno, (yyvsp[-2].sVal), new SubExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 2160 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 182 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, yylineno, (yyvsp[-2].sVal), new MulExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 2168 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 185 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, yylineno, (yyvsp[-2].sVal), new DivExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 2176 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 188 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, yylineno, (yyvsp[-2].sVal), new RemExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 2184 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 191 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, yylineno, (yyvsp[-2].sVal), new AndExp(fname, yylineno,
                                                                       new VarExp(fname, yylineno, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 2192 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 194 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, yylineno, (yyvsp[-2].sVal), new OrExp(fname, yylineno,
                                                                      new VarExp(fname, yylineno, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 2200 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 198 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MinExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 2206 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 199 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new NotExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 2212 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 201 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_umin"),
       					          new OneExpIL(fname, yylineno, (yyvsp[-1].nodeVal))); }
#line 2219 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 203 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, yylineno, new VarExp(fname, yylineno, "sw_not"),
					          new OneExpIL(fname, yylineno, (yyvsp[0].nodeVal))); }
#line 2226 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 206 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ToStrExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 2232 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 207 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ToCharExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 2238 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 208 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ToIntExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 2244 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 209 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ToFloatExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 2250 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 211 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new RunExp(fname, yylineno, (yyvsp[-1].nodeVal)); }
#line 2256 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 74:
#line 215 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OneCondCL(fname, yylineno, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 2262 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 75:
#line 216 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulCondCL(fname, yylineno, (yyvsp[-3].nodeVal), (yyvsp[-1].nodeVal), (yyvsp[0].nodeVal)); }
#line 2268 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 76:
#line 220 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new IntExp(fname, yylineno, (yyvsp[0].sVal));
                  delete[] (yyvsp[0].sVal); }
#line 2275 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 77:
#line 222 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new IntExp(fname, yylineno, (yyvsp[0].sVal) + 2, 2);
                  delete[] (yyvsp[0].sVal); }
#line 2282 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 78:
#line 224 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new IntExp(fname, yylineno, (yyvsp[0].sVal) + 2, 16);
                  delete[] (yyvsp[0].sVal); }
#line 2289 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 79:
#line 227 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new FloatExp(fname, yylineno, (yyvsp[0].sVal), 10, 0);
                  delete[] (yyvsp[0].sVal); }
#line 2296 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 80:
#line 229 "./src/parser/limon.y" /* yacc.c:1652  */
    { char *f = strtok((yyvsp[0].sVal), "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
                  (yyval.nodeVal) = new FloatExp(fname, yylineno, f, 10, p);
                  delete[] (yyvsp[0].sVal); }
#line 2305 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 81:
#line 233 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new FloatExp(fname, yylineno, (yyvsp[0].sVal) + 2, 2, 0);
                  delete[] (yyvsp[0].sVal); }
#line 2312 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 82:
#line 235 "./src/parser/limon.y" /* yacc.c:1652  */
    { char *f = strtok((yyvsp[0].sVal), "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
                  (yyval.nodeVal) = new FloatExp(fname, yylineno, f + 2, 2, p);
                  delete[] (yyvsp[0].sVal); }
#line 2321 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 83:
#line 239 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new FloatExp(fname, yylineno, (yyvsp[0].sVal) + 2, 16, 0);
                  delete[] (yyvsp[0].sVal); }
#line 2328 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 84:
#line 241 "./src/parser/limon.y" /* yacc.c:1652  */
    { char *f = strtok((yyvsp[0].sVal), "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
                  (yyval.nodeVal) = new FloatExp(fname, yylineno, f + 2, 16, p);
                  delete[] (yyvsp[0].sVal); }
#line 2337 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 85:
#line 246 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new BoolExp(fname, yylineno, (yyvsp[0].bVal)); }
#line 2343 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 86:
#line 247 "./src/parser/limon.y" /* yacc.c:1652  */
    { string str;
                  if (raw2str((yyvsp[0].sVal), str)) {
                    (yyval.nodeVal) = new StringExp(fname, yylineno, str);
                    delete[] (yyvsp[0].sVal);
                  } else {
                    delete[] (yyvsp[0].sVal);
                    YYERROR;
                  } }
#line 2356 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 87:
#line 255 "./src/parser/limon.y" /* yacc.c:1652  */
    { char c;
                  if (raw2char((yyvsp[0].sVal), c)) {
                    (yyval.nodeVal) = new CharExp(fname, yylineno, c);
                    delete[] (yyvsp[0].sVal);
                  } else {
                    delete[] (yyvsp[0].sVal);
                    YYERROR;
                  } }
#line 2369 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 88:
#line 263 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new SymbolExp(fname, yylineno, (yyvsp[0].sVal)+1);
                  delete[] (yyvsp[0].sVal); }
#line 2376 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 89:
#line 265 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new NullExp(fname, yylineno); }
#line 2382 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 90:
#line 270 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = (yyvsp[0].nodeVal); }
#line 2388 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 91:
#line 271 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new EmptyPL(fname, yylineno); }
#line 2394 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 92:
#line 275 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OneVarPL(fname, yylineno, (yyvsp[0].sVal));
                               delete[] (yyvsp[0].sVal); }
#line 2401 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 93:
#line 277 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulVarPL(fname, yylineno, (yyvsp[0].sVal), (yyvsp[-1].nodeVal));
                               delete[] (yyvsp[0].sVal); }
#line 2408 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 94:
#line 282 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = (yyvsp[0].nodeVal); }
#line 2414 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 95:
#line 283 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new EmptyIL(fname, yylineno); }
#line 2420 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 96:
#line 287 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OneExpIL(fname, yylineno, (yyvsp[0].nodeVal)); }
#line 2426 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 97:
#line 288 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulExpIL(fname, yylineno, (yyvsp[0].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2432 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;


#line 2436 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 294 "./src/parser/limon.y" /* yacc.c:1918  */


void yyerror(char const *s) 
{
  printf("%s:%d: %s\n", fname.c_str(), yylloc.first_line, s);
}

Node *LimonParser::parse(char *code_str, string filename)
{
  set_scan_string(code_str); // Set input string
  fname = filename;
  yylineno = 1;
  
  int res = yyparse();

  delete_scan_string();
  
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

