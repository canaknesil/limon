/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./src/parser/kiss.y" /* yacc.c:339  */

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



#line 92 "./src/parser/y.tab.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
#line 27 "./src/parser/kiss.y" /* yacc.c:355  */

	#include <node.h>
    //#define MAX_KISS_VAR_LENGTH	512

#line 127 "./src/parser/y.tab.cc" /* yacc.c:355  */

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
    STRING = 268,
    CHAR = 269,
    BOOL = 270,
    DEF = 271,
    GEQ = 272,
    LEQ = 273,
    EQ = 274,
    NEQ = 275,
    PRINT = 276,
    SIZEOF = 277,
    TOSTR = 278,
    TOCHAR = 279,
    TOINT = 280,
    TOFLOAT = 281,
    PLUSEQ = 282,
    MINEQ = 283,
    MULEQ = 284,
    DIVEQ = 285,
    REMEQ = 286,
    ANDEQ = 287,
    OREQ = 288,
    WHILE = 289,
    NULLTOK = 290,
    SCAN = 291,
    UMIN = 292,
    PLUSPLUS = 293,
    MINMIN = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "./src/parser/kiss.y" /* yacc.c:355  */

    char *sVal = nullptr;
    bool bVal[1];
	Node *nodeVal;

#line 185 "./src/parser/y.tab.cc" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "./src/parser/y.tab.cc" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   818

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    60,     2,    47,    39,     2,
      53,    54,    45,    43,     2,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,     2,
      41,    37,    42,    56,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    38,    52,     2,     2,     2,     2,
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
      35,    36,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    59,    59,    62,    68,    69,    73,    74,    76,    78,
      80,    83,    84,    85,    86,    87,    89,    90,    93,    94,
      96,    97,    98,    99,   100,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   116,   118,
     120,   122,   124,   126,   128,   131,   132,   134,   135,   136,
     137,   141,   142,   146,   148,   150,   153,   155,   159,   161,
     165,   167,   172,   173,   181,   189,   194,   195,   199,   201,
     206,   207,   211,   212,   216,   217
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "BIN", "HEX", "FLOAT", "FLOATP",
  "BFLOAT", "BFLOATP", "XFLOAT", "XFLOATP", "VAR", "STRING", "CHAR",
  "BOOL", "DEF", "GEQ", "LEQ", "EQ", "NEQ", "PRINT", "SIZEOF", "TOSTR",
  "TOCHAR", "TOINT", "TOFLOAT", "PLUSEQ", "MINEQ", "MULEQ", "DIVEQ",
  "REMEQ", "ANDEQ", "OREQ", "WHILE", "NULLTOK", "SCAN", "'='", "'|'",
  "'&'", "'!'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMIN",
  "PLUSPLUS", "MINMIN", "'{'", "'}'", "'('", "')'", "':'", "'?'", "'['",
  "']'", "'@'", "'#'", "$accept", "program", "expList", "exp", "condList",
  "constant", "paramList", "nonEmptyParamList", "argList",
  "nonEmptyArgList", "itemList", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    61,   124,    38,
      33,    60,    62,    43,    45,    42,    47,    37,   292,   293,
     294,   123,   125,    40,    41,    58,    63,    91,    93,    64,
      35
};
# endif

#define YYPACT_NINF -50

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     506,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -26,   -50,   -50,   -50,    15,   -50,   506,   149,   435,    91,
     -25,    30,   -50,   378,   -50,   506,   506,   506,   506,   506,
     506,   506,   506,    -4,   771,   506,   -18,   506,   506,   -19,
     207,   -46,   506,   506,   506,   506,   506,   506,   -16,   506,
     378,    33,   -50,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   -50,   152,   152,   152,
     152,   152,   152,   152,   152,   506,   152,   449,   -50,   677,
     709,   -50,   506,   -50,   506,   509,   551,   561,   593,   603,
     635,   -50,   264,   152,   -12,   506,   -50,    11,    54,    17,
      17,    17,    17,   757,   771,    17,    17,   -31,   -31,   -50,
     -50,   -50,   152,   -50,   152,   506,   -50,   378,   726,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   321,   -50,   152,    16,
     -50,   740,   693,   -50,   -50,   -50,   645,   506,   -50,   -50,
      18,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      17,    63,    64,    62,     0,    65,     0,     0,     0,     0,
       0,     0,     2,     4,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     8,    46,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    67,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,    38,    39,    40,
      41,    42,    43,    44,     9,     0,    74,     0,     6,     0,
       0,     7,     0,    11,     0,     0,     0,     0,     0,     0,
       0,    15,     0,    72,     0,    70,    68,     0,    66,    35,
      34,    30,    31,    37,    36,    32,    33,    25,    26,    27,
      28,    29,    10,    20,    75,     0,    45,    51,     0,    14,
      24,    47,    48,    49,    50,    21,     0,    19,    73,     0,
      69,     0,     0,    52,    12,    22,     0,     0,    13,    23,
       0,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,     0,    -6,   -49,   -50,   -50,   -50,   -50,   -50,
     -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    21,    66,    23,    41,    24,    97,    98,    94,    95,
      77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    25,    26,    27,    28,    29,    30,    31,    83,    84,
      34,    32,    40,    50,    63,    64,    65,    36,    39,    67,
      68,    69,    70,    71,    72,    73,    74,    33,    51,    76,
      52,    79,    80,    75,    78,    81,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    96,   127,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      61,    62,    63,    64,    65,   129,   130,   137,   133,   112,
     141,   114,     0,     0,     0,     0,   117,     0,   118,     0,
       0,     0,     0,     0,     0,     0,   126,     0,     0,   128,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,   131,
       0,   132,    42,    43,    44,    45,    46,    47,     0,     0,
     136,     0,     0,     0,     0,     0,    15,    48,     0,     0,
       0,    16,     0,     0,     0,     0,     0,   140,     0,     0,
       0,     0,    17,     0,    18,     0,     0,     0,    19,     0,
      20,    49,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,     0,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    16,
      57,    58,     0,    59,    60,    61,    62,    63,    64,    65,
      17,     0,    18,     0,     0,     0,    19,     0,    20,    35,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    53,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,    57,    58,    16,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,    17,     0,
      18,     0,     0,    82,    19,     0,    20,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    53,    54,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,    57,    58,    16,    59,    60,    61,    62,    63,
      64,    65,     0,     0,     0,    17,     0,    18,     0,     0,
       0,    19,   125,    20,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,    57,
      58,    16,    59,    60,    61,    62,    63,    64,    65,     0,
       0,     0,    17,     0,    18,     0,     0,     0,    19,   135,
      20,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,    57,    58,    16,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,    17,
       0,    18,     0,     0,     0,    19,     0,    20,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,     0,    37,
      15,     0,     0,     0,     0,    16,     0,     0,     0,    38,
       0,     0,     0,     0,    15,     0,    17,     0,    18,    16,
       0,     0,    19,     0,    20,     0,     0,     0,     0,     0,
      17,   113,    18,     0,     0,     0,    19,     0,    20,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,     0,     0,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,    16,    57,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    17,     0,    18,
       0,     0,     0,    19,     0,    20,     0,   119,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,     0,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    65,   120,
      53,    54,    55,    56,     0,     0,     0,     0,     0,   121,
      53,    54,    55,    56,     0,     0,     0,     0,     0,     0,
       0,    57,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    57,    58,     0,    59,    60,    61,    62,    63,    64,
      65,   122,    53,    54,    55,    56,     0,     0,     0,     0,
       0,   123,    53,    54,    55,    56,     0,     0,     0,     0,
       0,     0,     0,    57,    58,     0,    59,    60,    61,    62,
      63,    64,    65,    57,    58,     0,    59,    60,    61,    62,
      63,    64,    65,   124,    53,    54,    55,    56,     0,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,     0,    57,    58,     0,    59,    60,
      61,    62,    63,    64,    65,     0,    53,    54,    55,    56,
       0,    57,    58,   115,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    53,    54,    55,    56,    57,    58,    82,
      59,    60,    61,    62,    63,    64,    65,    53,    54,    55,
      56,     0,     0,   116,    57,    58,     0,    59,    60,    61,
      62,    63,    64,    65,    53,    54,    55,    56,    57,    58,
     134,    59,    60,    61,    62,    63,    64,    65,    53,    54,
      55,    56,     0,     0,   138,     0,    58,     0,    59,    60,
      61,    62,    63,    64,    65,     0,     0,     0,     0,     0,
       0,     0,    59,    60,    61,    62,    63,    64,    65
};

static const yytype_int16 yycheck[] =
{
       0,    27,    28,    29,    30,    31,    32,    33,    54,    55,
      16,    37,    18,    19,    45,    46,    47,    17,    18,    25,
      26,    27,    28,    29,    30,    31,    32,    12,    53,    35,
       0,    37,    38,    37,    52,    54,    42,    43,    44,    45,
      46,    47,    58,    49,    50,    12,    58,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      43,    44,    45,    46,    47,    54,    12,    51,   117,    75,
      52,    77,    -1,    -1,    -1,    -1,    82,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    95,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,   115,
      -1,   117,    21,    22,    23,    24,    25,    26,    -1,    -1,
     126,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,    -1,
      59,    60,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,
      38,    39,    -1,    41,    42,    43,    44,    45,    46,    47,
      51,    -1,    53,    -1,    -1,    -1,    57,    -1,    59,    60,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    51,    -1,
      53,    -1,    -1,    56,    57,    -1,    59,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,
      -1,    57,    58,    59,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,    58,
      59,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,    -1,    59,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    35,    -1,    51,    -1,    53,    40,
      -1,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    57,    -1,    59,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    40,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    51,    -1,    53,
      -1,    -1,    -1,    57,    -1,    59,    -1,    58,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    47,    58,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    58,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    38,    39,    -1,    41,    42,    43,    44,    45,    46,
      47,    58,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    58,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    58,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    -1,    38,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    17,    18,    19,    20,
      -1,    38,    39,    56,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    17,    18,    19,    20,    38,    39,    56,
      41,    42,    43,    44,    45,    46,    47,    17,    18,    19,
      20,    -1,    -1,    54,    38,    39,    -1,    41,    42,    43,
      44,    45,    46,    47,    17,    18,    19,    20,    38,    39,
      54,    41,    42,    43,    44,    45,    46,    47,    17,    18,
      19,    20,    -1,    -1,    54,    -1,    39,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    35,    40,    51,    53,    57,
      59,    62,    63,    64,    66,    27,    28,    29,    30,    31,
      32,    33,    37,    12,    64,    60,    63,    34,    44,    63,
      64,    65,    21,    22,    23,    24,    25,    26,    36,    60,
      64,    53,     0,    17,    18,    19,    20,    38,    39,    41,
      42,    43,    44,    45,    46,    47,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    37,    64,    71,    52,    64,
      64,    54,    56,    54,    55,    64,    64,    64,    64,    64,
      64,    58,    64,    64,    69,    70,    12,    67,    68,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    52,    64,    56,    54,    64,    64,    58,
      58,    58,    58,    58,    58,    58,    64,    58,    64,    54,
      12,    64,    64,    65,    54,    58,    64,    51,    54,    58,
      63,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     3,     3,     2,     3,
       4,     3,     5,     6,     4,     3,     1,     1,     7,     4,
       4,     4,     5,     6,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     2,     4,     4,     4,
       4,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     2,
       1,     0,     1,     2,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 59 "./src/parser/kiss.y" /* yacc.c:1646  */
    { Node *prog = new AProgram(fname, line, (yyvsp[0].nodeVal));
					  kissParser->interpretProgram(prog);
					  delete (AProgram *) prog; }
#line 1514 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "./src/parser/kiss.y" /* yacc.c:1646  */
    { Node *prog = new EmptyProgram(fname, line);
					  kissParser->interpretProgram(prog);
					  delete (EmptyProgram *) prog; }
#line 1522 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new OneExpEL(fname, line, (yyvsp[0].nodeVal)); }
#line 1528 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new MulExpEL(fname, line, (yyvsp[-1].nodeVal), (yyvsp[0].nodeVal)); }
#line 1534 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ScopeExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1540 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = (yyvsp[-1].nodeVal); }
#line 1546 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 76 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new DefExp(fname, line, (yyvsp[0].sVal));
											  delete[] (yyvsp[0].sVal); }
#line 1553 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 78 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), (yyvsp[0].nodeVal));
											  delete[] (yyvsp[-2].sVal); }
#line 1560 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 80 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new MulExpEL(fname, line, new DefExp(fname, line, (yyvsp[-2].sVal)), new OneExpEL(fname, line, new AssignExp(fname, line, (yyvsp[-2].sVal), (yyvsp[0].nodeVal))));
											  delete[] (yyvsp[-2].sVal); /*sugar*/ }
#line 1567 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 83 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new CondExp(fname, line, (yyvsp[-1].nodeVal));         /*new IfExp(fname, line, $2, $4);         */ }
#line 1573 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 84 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new CondElseExp(fname, line, (yyvsp[-3].nodeVal), (yyvsp[-1].nodeVal)); /*new IfElseExp(fname, line, $2, $4, $6); */ }
#line 1579 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 85 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new WhileExp(fname, line, (yyvsp[-3].nodeVal), (yyvsp[-1].nodeVal));       }
#line 1585 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 86 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new PrintExp(fname, line, (yyvsp[-1].nodeVal));           }
#line 1591 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 87 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ScanExp(fname, line);                }
#line 1597 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 89 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = (yyvsp[0].nodeVal); }
#line 1603 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 90 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new VarExp(fname, line, (yyvsp[0].sVal));
											  delete[] (yyvsp[0].sVal); }
#line 1610 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 93 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ProcExp(fname, line, (yyvsp[-4].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1616 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new CallExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1622 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 96 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ArrayConst(fname, line, (yyvsp[-1].nodeVal)); }
#line 1628 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 97 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ArrayExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1634 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 98 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ArrayGetExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1640 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 99 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ArraySetExp(fname, line, (yyvsp[-3].nodeVal), (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1646 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 100 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new SizeOfExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1652 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 102 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AddExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1658 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 103 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new SubExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1664 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 104 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new MulExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1670 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 105 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new DivExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1676 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 106 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new RemExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1682 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 107 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new EquExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1688 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 108 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new NEqExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1694 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 109 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new LoTExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1700 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 110 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new GrTExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1706 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 111 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new LEqExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1712 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 112 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new GEqExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1718 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 113 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AndExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1724 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 114 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new OrExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1730 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 116 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new AddExp(fname, line, new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
									  delete[] (yyvsp[-2].sVal); }
#line 1737 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 118 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new SubExp(fname, line, new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
									  delete[] (yyvsp[-2].sVal); }
#line 1744 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 120 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new MulExp(fname, line, new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
									  delete[] (yyvsp[-2].sVal); }
#line 1751 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 122 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new DivExp(fname, line, new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
									  delete[] (yyvsp[-2].sVal); }
#line 1758 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 124 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new RemExp(fname, line, new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
									  delete[] (yyvsp[-2].sVal); }
#line 1765 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 126 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new AndExp(fname, line, new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
									  delete[] (yyvsp[-2].sVal); }
#line 1772 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 128 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new OrExp(fname, line, new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
									  delete[] (yyvsp[-2].sVal); }
#line 1779 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 131 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new MinExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1785 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 132 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new NotExp(fname, line, (yyvsp[0].nodeVal)); }
#line 1791 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 134 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ToStrExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1797 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 135 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ToCharExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1803 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 136 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ToIntExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1809 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 137 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new ToFloatExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1815 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 141 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new OneCondCL(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1821 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 142 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new MulCondCL(fname, line, (yyvsp[-3].nodeVal), (yyvsp[-1].nodeVal), (yyvsp[0].nodeVal)); }
#line 1827 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 146 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new IntExp(fname, line, (yyvsp[0].sVal));
								  delete[] (yyvsp[0].sVal); }
#line 1834 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 148 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new IntExp(fname, line, (yyvsp[0].sVal) + 2, 2);
								  delete[] (yyvsp[0].sVal); }
#line 1841 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 150 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new IntExp(fname, line, (yyvsp[0].sVal) + 2, 16);
								  delete[] (yyvsp[0].sVal); }
#line 1848 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 153 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new FloatExp(fname, line, (yyvsp[0].sVal), 10, 0);
								  delete[] (yyvsp[0].sVal); }
#line 1855 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 155 "./src/parser/kiss.y" /* yacc.c:1646  */
    { char *f = strtok((yyvsp[0].sVal), "pP");
								  size_t p = atoi(strtok(NULL, "pP"));
								  (yyval.nodeVal) = new FloatExp(fname, line, f, 10, p);
								  delete[] (yyvsp[0].sVal); }
#line 1864 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 159 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new FloatExp(fname, line, (yyvsp[0].sVal) + 2, 2, 0);
								  delete[] (yyvsp[0].sVal); }
#line 1871 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 161 "./src/parser/kiss.y" /* yacc.c:1646  */
    { char *f = strtok((yyvsp[0].sVal), "pP");
								  size_t p = atoi(strtok(NULL, "pP"));
								  (yyval.nodeVal) = new FloatExp(fname, line, f + 2, 2, p);
								  delete[] (yyvsp[0].sVal); }
#line 1880 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 165 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new FloatExp(fname, line, (yyvsp[0].sVal) + 2, 16, 0);
								  delete[] (yyvsp[0].sVal); }
#line 1887 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 167 "./src/parser/kiss.y" /* yacc.c:1646  */
    { char *f = strtok((yyvsp[0].sVal), "pP");
								  size_t p = atoi(strtok(NULL, "pP"));
								  (yyval.nodeVal) = new FloatExp(fname, line, f + 2, 16, p);
								  delete[] (yyvsp[0].sVal); }
#line 1896 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 172 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new BoolExp(fname, line, *((yyvsp[0].bVal))); }
#line 1902 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 173 "./src/parser/kiss.y" /* yacc.c:1646  */
    { string str;
								  if (raw2str((yyvsp[0].sVal), str)) {
									  (yyval.nodeVal) = new StringExp(fname, line, str);
									  delete[] (yyvsp[0].sVal);
								  } else {
									  delete[] (yyvsp[0].sVal);
									  YYERROR;
								  } }
#line 1915 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 181 "./src/parser/kiss.y" /* yacc.c:1646  */
    { char c;
								  if (raw2char((yyvsp[0].sVal), c)) {
									  (yyval.nodeVal) = new CharExp(fname, line, c);
									  delete[] (yyvsp[0].sVal);
								  } else {
									  delete[] (yyvsp[0].sVal);
									  YYERROR;
								  } }
#line 1928 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 189 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new NullExp(fname, line); }
#line 1934 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 194 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = (yyvsp[0].nodeVal); }
#line 1940 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 195 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new EmptyPL(fname, line); }
#line 1946 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 199 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new OneVarPL(fname, line, (yyvsp[0].sVal));
								  delete[] (yyvsp[0].sVal); }
#line 1953 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 201 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new MulVarPL(fname, line, (yyvsp[0].sVal), (yyvsp[-1].nodeVal));
								  delete[] (yyvsp[0].sVal); }
#line 1960 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 206 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = (yyvsp[0].nodeVal); }
#line 1966 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 207 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new EmptyAL(fname, line); }
#line 1972 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 211 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new OneArgAL(fname, line, (yyvsp[0].nodeVal)); }
#line 1978 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 212 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new MulArgAL(fname, line, (yyvsp[0].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1984 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 216 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new OneExpIL(fname, line, (yyvsp[0].nodeVal)); }
#line 1990 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 217 "./src/parser/kiss.y" /* yacc.c:1646  */
    { (yyval.nodeVal) = new MulExpIL(fname, line, (yyvsp[0].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1996 "./src/parser/y.tab.cc" /* yacc.c:1646  */
    break;


#line 2000 "./src/parser/y.tab.cc" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 220 "./src/parser/kiss.y" /* yacc.c:1906  */


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

