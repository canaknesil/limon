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

/* Internal variables and functions */
void yyerror(char const *);     // is called when an error occurs during parsing
int line = 1;                   // for counting line numbers
static Node *topNode = nullptr; // the AST top node, used during parsing
static string fname;            // name of the parsed file, used during parsing

// Transforms the text, read from the source file, to the string|character it represents.
static bool raw2str(char *raw, string &str);
static bool raw2char(char *raw, char &c);



#line 100 "./src/parser/y.tab.cpp" /* yacc.c:337  */
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
#line 32 "./src/parser/limon.y" /* yacc.c:352  */


#include <node.h> // to create the AST


#line 139 "./src/parser/y.tab.cpp" /* yacc.c:352  */

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
    UMIN = 296,
    PLUSPLUS = 297,
    MINMIN = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 39 "./src/parser/limon.y" /* yacc.c:352  */

  char *sVal = nullptr;
  bool bVal;
  Node *nodeVal;

#line 201 "./src/parser/y.tab.cpp" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

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
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   913

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
       2,     2,     2,    44,     2,    64,     2,    51,    43,     2,
      57,    58,    49,    47,     2,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
      45,    41,    46,    60,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,    42,    56,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    68,    73,    74,    78,    79,    81,    83,
      85,    93,    94,    95,    96,    97,    98,    99,   101,   102,
     105,   106,   108,   109,   110,   111,   112,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     128,   131,   134,   137,   140,   143,   146,   150,   151,   153,
     154,   155,   156,   158,   169,   170,   174,   176,   178,   181,
     183,   187,   189,   193,   195,   200,   201,   209,   217,   219,
     224,   225,   229,   231,   236,   237,   241,   242,   246,   247
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "BIN", "HEX", "FLOAT", "FLOATP",
  "BFLOAT", "BFLOATP", "XFLOAT", "XFLOATP", "VAR", "SYM", "STRING", "CHAR",
  "BOOL", "DEF", "GEQ", "LEQ", "EQ", "NEQ", "PRINT", "SIZEOF", "TOSTR",
  "TOCHAR", "TOINT", "TOFLOAT", "PLUSEQ", "MINEQ", "MULEQ", "DIVEQ",
  "REMEQ", "ANDEQ", "OREQ", "WHILE", "NULLTOK", "SCAN", "RUN", "ERROR",
  "VALTYPE", "'='", "'|'", "'&'", "'!'", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "UMIN", "PLUSPLUS", "MINMIN", "'{'", "'}'", "'('", "')'",
  "':'", "'?'", "'['", "']'", "'@'", "'#'", "$accept", "program",
  "expList", "exp", "condList", "constant", "paramList",
  "nonEmptyParamList", "argList", "nonEmptyArgList", "itemList", YY_NULLPTR
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
     295,    61,   124,    38,    33,    60,    62,    43,    45,    42,
      47,    37,   296,   297,   298,   123,   125,    40,    41,    58,
      63,    91,    93,    64,    35
};
# endif

#define YYPACT_NINF -49

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-49)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     531,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
      26,   -49,   -49,   -49,   -49,   -10,   -49,   531,   149,   455,
      87,   -36,    33,   -49,   394,   -49,   531,   531,   531,   531,
     531,   531,   531,   531,    -7,   862,   531,     5,   531,   531,
       4,   211,   -19,   531,   531,   531,   531,   531,   531,     2,
      52,   531,   531,   531,   394,    56,   -49,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     -49,   152,   152,   152,   152,   152,   152,   152,   152,   531,
     152,   470,   -49,   759,   794,   -49,   531,   -49,   531,   534,
     579,   589,   624,   634,   669,   -49,     7,   679,   714,   272,
     152,     9,   531,   -49,    15,    62,   -42,   -42,   -42,   -42,
     845,   862,   -42,   -42,   -25,   -25,   -49,   -49,   -49,   152,
     -49,   152,   531,   -49,   394,   811,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   333,   -49,   152,    20,
     -49,   828,   775,   -49,   -49,   -49,   724,   531,   -49,   -49,
      21,   -49
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      19,    68,    66,    67,    65,     0,    69,     0,     0,     0,
       0,     0,     0,     2,     4,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     8,    48,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    71,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,    40,    41,    42,    43,    44,    45,    46,     9,     0,
      78,     0,     6,     0,     0,     7,     0,    11,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      76,     0,    74,    72,     0,    70,    37,    36,    32,    33,
      39,    38,    34,    35,    27,    28,    29,    30,    31,    10,
      22,    79,     0,    47,    54,     0,    14,    26,    49,    50,
      51,    52,    53,    16,    17,    23,     0,    21,    77,     0,
      73,     0,     0,    55,    12,    24,     0,     0,    13,    25,
       0,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,     0,   -16,   -48,   -49,   -49,   -49,   -49,   -49,
     -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    22,    70,    24,    42,    25,   104,   105,   101,   102,
      81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    35,    34,    41,    54,    65,    66,    67,    68,    69,
      71,    72,    73,    74,    75,    76,    77,    78,    37,    40,
      80,    55,    83,    84,    67,    68,    69,    89,    90,    91,
      92,    93,    94,    56,    79,    97,    98,    99,   100,    87,
      88,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    26,    27,    28,    29,    30,    31,
      32,    82,    85,   119,    95,   121,    96,    33,   103,   132,
     124,   137,   125,   139,   140,   147,   143,   151,     0,     0,
       0,     0,     0,   136,     0,     0,   138,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,   141,     0,   142,    43,
      44,    45,    46,    47,    48,     0,     0,     0,     0,     0,
     146,     0,     0,    16,    49,    50,    51,    52,     0,     0,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    19,     0,     0,   150,    20,     0,
      21,    53,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,    17,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    18,     0,    19,     0,     0,     0,
      20,     0,    21,    36,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    61,    62,    17,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,    18,     0,    19,     0,
       0,    86,    20,     0,    21,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,    61,    62,    17,    63,    64,    65,
      66,    67,    68,    69,     0,     0,     0,    18,     0,    19,
       0,     0,     0,    20,   135,    21,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
       0,     0,     0,     0,     0,    61,    62,    17,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    18,     0,
      19,     0,     0,     0,    20,   145,    21,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    61,    62,    17,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,    18,
       0,    19,     0,     0,     0,    20,     0,    21,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
      38,    16,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,    39,     0,     0,    16,     0,     0,     0,
      18,     0,    19,     0,    17,     0,    20,     0,    21,     0,
       0,     0,     0,     0,     0,    18,   120,    19,     0,     0,
       0,    20,     0,    21,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,     0,
       0,     0,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,    17,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    18,     0,    19,     0,
       0,     0,    20,     0,    21,     0,   126,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,   127,    57,    58,    59,    60,     0,     0,     0,     0,
       0,   128,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,   129,    57,    58,    59,
      60,     0,     0,     0,     0,     0,   130,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,   131,    57,    58,    59,    60,     0,     0,     0,     0,
       0,   133,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,   134,    57,    58,    59,
      60,     0,     0,     0,     0,     0,   149,     0,     0,     0,
       0,     0,     0,    57,    58,    59,    60,     0,     0,     0,
       0,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,     0,    57,    58,    59,    60,     0,    61,    62,   122,
      63,    64,    65,    66,    67,    68,    69,     0,     0,    57,
      58,    59,    60,     0,     0,    86,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    57,    58,    59,    60,
       0,     0,   123,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    57,    58,    59,    60,     0,     0,   144,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      57,    58,    59,    60,     0,     0,   148,     0,    62,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69
};

static const yytype_int16 yycheck[] =
{
       0,    17,    12,    19,    20,    47,    48,    49,    50,    51,
      26,    27,    28,    29,    30,    31,    32,    33,    18,    19,
      36,    57,    38,    39,    49,    50,    51,    43,    44,    45,
      46,    47,    48,     0,    41,    51,    52,    53,    54,    58,
      59,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    28,    29,    30,    31,    32,    33,
      34,    56,    58,    79,    62,    81,    14,    41,    12,    62,
      86,    62,    88,    58,    12,    55,   124,    56,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,   102,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,   122,    -1,   124,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    -1,    57,    -1,    -1,   147,    61,    -1,
      63,    64,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    42,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    55,    -1,    57,    -1,    -1,    -1,
      61,    -1,    63,    64,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    55,    -1,    57,    -1,
      -1,    60,    61,    -1,    63,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    55,    -1,    57,
      -1,    -1,    -1,    61,    62,    63,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    -1,    55,    -1,
      57,    -1,    -1,    -1,    61,    62,    63,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    55,
      -1,    57,    -1,    -1,    -1,    61,    -1,    63,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    -1,    36,    -1,    -1,    -1,
      55,    -1,    57,    -1,    44,    -1,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    -1,    -1,
      -1,    61,    -1,    63,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    55,    -1,    57,    -1,
      -1,    -1,    61,    -1,    63,    -1,    62,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    62,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    62,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    62,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    62,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    62,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    62,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    62,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    -1,    18,    19,    20,    21,    -1,    42,    43,    60,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    18,
      19,    20,    21,    -1,    -1,    60,    42,    43,    -1,    45,
      46,    47,    48,    49,    50,    51,    18,    19,    20,    21,
      -1,    -1,    58,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    18,    19,    20,    21,    -1,    -1,    58,
      42,    43,    -1,    45,    46,    47,    48,    49,    50,    51,
      18,    19,    20,    21,    -1,    -1,    58,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    36,    44,    55,    57,
      61,    63,    66,    67,    68,    70,    28,    29,    30,    31,
      32,    33,    34,    41,    12,    68,    64,    67,    35,    48,
      67,    68,    69,    22,    23,    24,    25,    26,    27,    37,
      38,    39,    40,    64,    68,    57,     0,    18,    19,    20,
      21,    42,    43,    45,    46,    47,    48,    49,    50,    51,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    41,
      68,    75,    56,    68,    68,    58,    60,    58,    59,    68,
      68,    68,    68,    68,    68,    62,    14,    68,    68,    68,
      68,    73,    74,    12,    71,    72,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      56,    68,    60,    58,    68,    68,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    68,    62,    68,    58,
      12,    68,    68,    69,    58,    62,    68,    55,    58,    62,
      67,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     3,     3,     2,     3,
       4,     3,     5,     6,     4,     3,     4,     4,     1,     1,
       7,     4,     4,     4,     5,     6,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     2,     4,
       4,     4,     4,     4,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     2,     1,     0,     1,     2,     1,     2
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 67 "./src/parser/limon.y" /* yacc.c:1652  */
    { topNode = new AProgram(fname, line, (yyvsp[0].nodeVal)); }
#line 1549 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 3:
#line 68 "./src/parser/limon.y" /* yacc.c:1652  */
    { topNode = new EmptyProgram(fname, line); }
#line 1555 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 4:
#line 73 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OneExpEL(fname, line, (yyvsp[0].nodeVal)); }
#line 1561 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 5:
#line 74 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulExpEL(fname, line, (yyvsp[-1].nodeVal), (yyvsp[0].nodeVal)); }
#line 1567 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 6:
#line 78 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ScopeExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1573 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 7:
#line 79 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = (yyvsp[-1].nodeVal); }
#line 1579 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 8:
#line 81 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new DefExp(fname, line, (yyvsp[0].sVal));
                        delete[] (yyvsp[0].sVal); }
#line 1586 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 9:
#line 83 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), (yyvsp[0].nodeVal));
                        delete[] (yyvsp[-2].sVal); }
#line 1593 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 10:
#line 85 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulExpEL(fname,
                                          line,
                                          new DefExp(fname, line, (yyvsp[-2].sVal)),
                                          new OneExpEL(fname,
                                                       line,
                                                       new AssignExp(fname, line, (yyvsp[-2].sVal), (yyvsp[0].nodeVal))));
                        delete[] (yyvsp[-2].sVal); /*sugar*/ }
#line 1605 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 11:
#line 93 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CondExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1611 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 12:
#line 94 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CondElseExp(fname, line, (yyvsp[-3].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1617 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 13:
#line 95 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new WhileExp(fname, line, (yyvsp[-3].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1623 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 14:
#line 96 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new PrintExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1629 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 15:
#line 97 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ScanExp(fname, line); }
#line 1635 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 16:
#line 98 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ErrorExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1641 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 17:
#line 99 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ValtypeExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1647 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 18:
#line 101 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = (yyvsp[0].nodeVal); }
#line 1653 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 19:
#line 102 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new VarExp(fname, line, (yyvsp[0].sVal));
                                  delete[] (yyvsp[0].sVal); }
#line 1660 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 20:
#line 105 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ProcExp(fname, line, (yyvsp[-4].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1666 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 21:
#line 106 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new CallExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1672 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 22:
#line 108 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ArrayConst(fname, line, (yyvsp[-1].nodeVal)); }
#line 1678 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 23:
#line 109 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ArrayExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1684 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 24:
#line 110 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ArrayGetExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1690 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 25:
#line 111 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ArraySetExp(fname, line, (yyvsp[-3].nodeVal), (yyvsp[-2].nodeVal), (yyvsp[-1].nodeVal)); }
#line 1696 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 26:
#line 112 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new SizeOfExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1702 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 27:
#line 114 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AddExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1708 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 28:
#line 115 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new SubExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1714 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 29:
#line 116 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1720 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 30:
#line 117 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new DivExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1726 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 31:
#line 118 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new RemExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1732 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 32:
#line 119 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new EquExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1738 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 33:
#line 120 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new NEqExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1744 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 34:
#line 121 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new LoTExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1750 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 35:
#line 122 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new GrTExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1756 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 36:
#line 123 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new LEqExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1762 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 37:
#line 124 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new GEqExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1768 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 38:
#line 125 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AndExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1774 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 39:
#line 126 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OrExp(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1780 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 40:
#line 128 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new AddExp(fname, line,
                                                                       new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 1788 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 41:
#line 131 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new SubExp(fname, line,
                                                                       new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 1796 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 42:
#line 134 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new MulExp(fname, line,
                                                                       new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 1804 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 43:
#line 137 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new DivExp(fname, line,
                                                                       new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 1812 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 44:
#line 140 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new RemExp(fname, line,
                                                                       new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 1820 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 45:
#line 143 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new AndExp(fname, line,
                                                                       new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 1828 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 46:
#line 146 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new AssignExp(fname, line, (yyvsp[-2].sVal), new OrExp(fname, line,
                                                                      new VarExp(fname, line, (yyvsp[-2].sVal)), (yyvsp[0].nodeVal)));
                        delete[] (yyvsp[-2].sVal); }
#line 1836 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 47:
#line 150 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MinExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1842 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 48:
#line 151 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new NotExp(fname, line, (yyvsp[0].nodeVal)); }
#line 1848 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 49:
#line 153 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ToStrExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1854 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 50:
#line 154 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ToCharExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1860 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 51:
#line 155 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ToIntExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1866 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 52:
#line 156 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new ToFloatExp(fname, line, (yyvsp[-1].nodeVal)); }
#line 1872 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 53:
#line 158 "./src/parser/limon.y" /* yacc.c:1652  */
    { string str;
                                    if (raw2str((yyvsp[-1].sVal), str)) {
                                      (yyval.nodeVal) = new RunExp(fname, line, str);
                                      delete[] (yyvsp[-1].sVal);
                                    } else {
                                      delete[] (yyvsp[-1].sVal);
                                      YYERROR;
                                    } }
#line 1885 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 54:
#line 169 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OneCondCL(fname, line, (yyvsp[-2].nodeVal), (yyvsp[0].nodeVal)); }
#line 1891 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 55:
#line 170 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulCondCL(fname, line, (yyvsp[-3].nodeVal), (yyvsp[-1].nodeVal), (yyvsp[0].nodeVal)); }
#line 1897 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 56:
#line 174 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new IntExp(fname, line, (yyvsp[0].sVal));
                  delete[] (yyvsp[0].sVal); }
#line 1904 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 57:
#line 176 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new IntExp(fname, line, (yyvsp[0].sVal) + 2, 2);
                  delete[] (yyvsp[0].sVal); }
#line 1911 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 58:
#line 178 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new IntExp(fname, line, (yyvsp[0].sVal) + 2, 16);
                  delete[] (yyvsp[0].sVal); }
#line 1918 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 59:
#line 181 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new FloatExp(fname, line, (yyvsp[0].sVal), 10, 0);
                  delete[] (yyvsp[0].sVal); }
#line 1925 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 60:
#line 183 "./src/parser/limon.y" /* yacc.c:1652  */
    { char *f = strtok((yyvsp[0].sVal), "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
                  (yyval.nodeVal) = new FloatExp(fname, line, f, 10, p);
                  delete[] (yyvsp[0].sVal); }
#line 1934 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 61:
#line 187 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new FloatExp(fname, line, (yyvsp[0].sVal) + 2, 2, 0);
                  delete[] (yyvsp[0].sVal); }
#line 1941 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 62:
#line 189 "./src/parser/limon.y" /* yacc.c:1652  */
    { char *f = strtok((yyvsp[0].sVal), "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
                  (yyval.nodeVal) = new FloatExp(fname, line, f + 2, 2, p);
                  delete[] (yyvsp[0].sVal); }
#line 1950 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 63:
#line 193 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new FloatExp(fname, line, (yyvsp[0].sVal) + 2, 16, 0);
                  delete[] (yyvsp[0].sVal); }
#line 1957 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 64:
#line 195 "./src/parser/limon.y" /* yacc.c:1652  */
    { char *f = strtok((yyvsp[0].sVal), "pP");
                  size_t p = atoi(strtok(NULL, "pP"));
                  (yyval.nodeVal) = new FloatExp(fname, line, f + 2, 16, p);
                  delete[] (yyvsp[0].sVal); }
#line 1966 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 65:
#line 200 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new BoolExp(fname, line, (yyvsp[0].bVal)); }
#line 1972 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 66:
#line 201 "./src/parser/limon.y" /* yacc.c:1652  */
    { string str;
                  if (raw2str((yyvsp[0].sVal), str)) {
                    (yyval.nodeVal) = new StringExp(fname, line, str);
                    delete[] (yyvsp[0].sVal);
                  } else {
                    delete[] (yyvsp[0].sVal);
                    YYERROR;
                  } }
#line 1985 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 67:
#line 209 "./src/parser/limon.y" /* yacc.c:1652  */
    { char c;
                  if (raw2char((yyvsp[0].sVal), c)) {
                    (yyval.nodeVal) = new CharExp(fname, line, c);
                    delete[] (yyvsp[0].sVal);
                  } else {
                    delete[] (yyvsp[0].sVal);
                    YYERROR;
                  } }
#line 1998 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 68:
#line 217 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new SymbolExp(fname, line, (yyvsp[0].sVal)+1);
                  delete[] (yyvsp[0].sVal); }
#line 2005 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 69:
#line 219 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new NullExp(fname, line); }
#line 2011 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 70:
#line 224 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = (yyvsp[0].nodeVal); }
#line 2017 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 71:
#line 225 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new EmptyPL(fname, line); }
#line 2023 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 72:
#line 229 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OneVarPL(fname, line, (yyvsp[0].sVal));
                               delete[] (yyvsp[0].sVal); }
#line 2030 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 73:
#line 231 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulVarPL(fname, line, (yyvsp[0].sVal), (yyvsp[-1].nodeVal));
                               delete[] (yyvsp[0].sVal); }
#line 2037 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 74:
#line 236 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = (yyvsp[0].nodeVal); }
#line 2043 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 75:
#line 237 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new EmptyAL(fname, line); }
#line 2049 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 76:
#line 241 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OneArgAL(fname, line, (yyvsp[0].nodeVal)); }
#line 2055 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 77:
#line 242 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulArgAL(fname, line, (yyvsp[0].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2061 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 78:
#line 246 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new OneExpIL(fname, line, (yyvsp[0].nodeVal)); }
#line 2067 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;

  case 79:
#line 247 "./src/parser/limon.y" /* yacc.c:1652  */
    { (yyval.nodeVal) = new MulExpIL(fname, line, (yyvsp[0].nodeVal), (yyvsp[-1].nodeVal)); }
#line 2073 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
    break;


#line 2077 "./src/parser/y.tab.cpp" /* yacc.c:1652  */
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
#line 250 "./src/parser/limon.y" /* yacc.c:1918  */


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

