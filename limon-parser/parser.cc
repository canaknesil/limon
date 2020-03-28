// A Bison parser, made by GNU Bison 3.5.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 26 "parser.yy"

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

#line 67 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 158 "parser.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 70: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 82: // exp
      case 83: // expList
      case 84: // condList
      case 85: // condElse
      case 86: // constant
      case 87: // itemList
      case 88: // nonEmptyItemList
      case 89: // paramList
      case 90: // nonEmptyParamList
      case 91: // program
        value.YY_MOVE_OR_COPY< json > (YY_MOVE (that.value));
        break;

      case 71: // "string"
      case 72: // "char"
      case 73: // "int"
      case 74: // "bin"
      case 75: // "hex"
      case 76: // "float"
      case 77: // "floarp"
      case 78: // "identifier"
      case 79: // "symbol"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 70: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 82: // exp
      case 83: // expList
      case 84: // condList
      case 85: // condElse
      case 86: // constant
      case 87: // itemList
      case 88: // nonEmptyItemList
      case 89: // paramList
      case 90: // nonEmptyParamList
      case 91: // program
        value.move< json > (YY_MOVE (that.value));
        break;

      case 71: // "string"
      case 72: // "char"
      case 73: // "int"
      case 74: // "bin"
      case 75: // "hex"
      case 76: // "float"
      case 77: // "floarp"
      case 78: // "identifier"
      case 79: // "symbol"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 70: // "bool"
        value.copy< bool > (that.value);
        break;

      case 82: // exp
      case 83: // expList
      case 84: // condList
      case 85: // condElse
      case 86: // constant
      case 87: // itemList
      case 88: // nonEmptyItemList
      case 89: // paramList
      case 90: // nonEmptyParamList
      case 91: // program
        value.copy< json > (that.value);
        break;

      case 71: // "string"
      case 72: // "char"
      case 73: // "int"
      case 74: // "bin"
      case 75: // "hex"
      case 76: // "float"
      case 77: // "floarp"
      case 78: // "identifier"
      case 79: // "symbol"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 70: // "bool"
        value.move< bool > (that.value);
        break;

      case 82: // exp
      case 83: // expList
      case 84: // condList
      case 85: // condElse
      case 86: // constant
      case 87: // itemList
      case 88: // nonEmptyItemList
      case 89: // paramList
      case 90: // nonEmptyParamList
      case 91: // program
        value.move< json > (that.value);
        break;

      case 71: // "string"
      case 72: // "char"
      case 73: // "int"
      case 74: // "bin"
      case 75: // "hex"
      case 76: // "float"
      case 77: // "floarp"
      case 78: // "identifier"
      case 79: // "symbol"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 70: // "bool"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < bool > (); }
#line 470 "parser.cc"
        break;

      case 71: // "string"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 476 "parser.cc"
        break;

      case 72: // "char"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 482 "parser.cc"
        break;

      case 73: // "int"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 488 "parser.cc"
        break;

      case 74: // "bin"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 494 "parser.cc"
        break;

      case 75: // "hex"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 500 "parser.cc"
        break;

      case 76: // "float"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 506 "parser.cc"
        break;

      case 77: // "floarp"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 512 "parser.cc"
        break;

      case 78: // "identifier"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 518 "parser.cc"
        break;

      case 79: // "symbol"
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 524 "parser.cc"
        break;

      case 82: // exp
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 530 "parser.cc"
        break;

      case 83: // expList
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 536 "parser.cc"
        break;

      case 84: // condList
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 542 "parser.cc"
        break;

      case 85: // condElse
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 548 "parser.cc"
        break;

      case 86: // constant
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 554 "parser.cc"
        break;

      case 87: // itemList
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 560 "parser.cc"
        break;

      case 88: // nonEmptyItemList
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 566 "parser.cc"
        break;

      case 89: // paramList
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 572 "parser.cc"
        break;

      case 90: // nonEmptyParamList
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 578 "parser.cc"
        break;

      case 91: // program
#line 141 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 584 "parser.cc"
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 70: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case 82: // exp
      case 83: // expList
      case 84: // condList
      case 85: // condElse
      case 86: // constant
      case 87: // itemList
      case 88: // nonEmptyItemList
      case 89: // paramList
      case 90: // nonEmptyParamList
      case 91: // program
        yylhs.value.emplace< json > ();
        break;

      case 71: // "string"
      case 72: // "char"
      case 73: // "int"
      case 74: // "bin"
      case 75: // "hex"
      case 76: // "float"
      case 77: // "floarp"
      case 78: // "identifier"
      case 79: // "symbol"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 147 "parser.yy"
             { json j = {{"exp_list", yystack_[0].value.as < json > ()}};
               drv.result = {"program", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 855 "parser.cc"
    break;

  case 3:
#line 149 "parser.yy"
             { drv.result = {"empty_program", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 861 "parser.cc"
    break;

  case 4:
#line 154 "parser.yy"
                   { json j = {{"exp", yystack_[0].value.as < json > ()}};
                     yylhs.value.as < json > () = {"one_exp_exp_list", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 868 "parser.cc"
    break;

  case 5:
#line 156 "parser.yy"
                   { json j = {{"exp", yystack_[1].value.as < json > ()}, {"exp_list", yystack_[0].value.as < json > ()}};
                     yylhs.value.as < json > () = {"mul_exp_exp_list", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 875 "parser.cc"
    break;

  case 6:
#line 162 "parser.yy"
                     { json j = {{"exp_list", yystack_[1].value.as < json > ()}};
                       yylhs.value.as < json > () = {"scope_exp", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 882 "parser.cc"
    break;

  case 7:
#line 164 "parser.yy"
                     { yylhs.value.as < json > () = yystack_[1].value.as < json > (); }
#line 888 "parser.cc"
    break;

  case 8:
#line 166 "parser.yy"
                     { json j = {{"var", yystack_[0].value.as < std::string > ()}};
                       yylhs.value.as < json > () = {"def_exp", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 895 "parser.cc"
    break;

  case 9:
#line 168 "parser.yy"
                           { json j = {{"var", yystack_[2].value.as < std::string > ()}, {"exp", yystack_[0].value.as < json > ()}};
                             yylhs.value.as < json > () = {"assign_exp", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 902 "parser.cc"
    break;

  case 10:
#line 170 "parser.yy"
                                        { json j = {{"param_list", yystack_[3].value.as < json > ()}, {"exp", yystack_[0].value.as < json > ()}};
                                          yylhs.value.as < json > () = {"mul_assign_exp", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 909 "parser.cc"
    break;

  case 11:
#line 172 "parser.yy"
                               { json assign_node = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()}, 
                                                                    {"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)};
                                 json def_node = {"def_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                              {"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)};
                                 yylhs.value.as < json > () = {"mul_exp_exp_list", {{"exp", def_node}, 
                                                            {"exp_list", {"one_exp_exp_list", {{"exp", assign_node}}, LOC_JSON(yylhs.location, yylhs.location)}}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 920 "parser.cc"
    break;

  case 12:
#line 178 "parser.yy"
                                { yylhs.value.as < json > () = {"cond_exp", {{"cond_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 926 "parser.cc"
    break;

  case 13:
#line 179 "parser.yy"
                                { yylhs.value.as < json > () = {"print_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 932 "parser.cc"
    break;

  case 14:
#line 180 "parser.yy"
                                { yylhs.value.as < json > () = {"show_exp" , {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 938 "parser.cc"
    break;

  case 15:
#line 181 "parser.yy"
                                { yylhs.value.as < json > () = {"scan_exp", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 944 "parser.cc"
    break;

  case 16:
#line 183 "parser.yy"
                                                                   { yylhs.value.as < json > () = {"try_catch_exp", {{"try_exp_list", yystack_[8].value.as < json > ()},
                                                                                             {"catch_var", yystack_[4].value.as < std::string > ()},
                                                                                             {"catch_exp_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 952 "parser.cc"
    break;

  case 17:
#line 186 "parser.yy"
                      { yylhs.value.as < json > () = {"raise_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 958 "parser.cc"
    break;

  case 18:
#line 188 "parser.yy"
                                { yylhs.value.as < json > () = {"convert_exp", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 964 "parser.cc"
    break;

  case 19:
#line 189 "parser.yy"
                                { yylhs.value.as < json > () = {"valtype_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 970 "parser.cc"
    break;

  case 20:
#line 190 "parser.yy"
                                { yylhs.value.as < json > () = {"gensym_exp", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 976 "parser.cc"
    break;

  case 21:
#line 191 "parser.yy"
                                { yylhs.value.as < json > () = {"same_exp", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 982 "parser.cc"
    break;

  case 22:
#line 193 "parser.yy"
                                { yylhs.value.as < json > () = yystack_[0].value.as < json > (); }
#line 988 "parser.cc"
    break;

  case 23:
#line 194 "parser.yy"
                                { yylhs.value.as < json > () = {"var_exp", {{"var", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 994 "parser.cc"
    break;

  case 24:
#line 196 "parser.yy"
                                           { yylhs.value.as < json > () = {"proc_exp", {{"param_list", yystack_[4].value.as < json > ()}, {"exp_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1000 "parser.cc"
    break;

  case 25:
#line 197 "parser.yy"
                                           { yylhs.value.as < json > () = {"call_exp", {{"exp", yystack_[2].value.as < json > ()}, {"item_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1006 "parser.cc"
    break;

  case 26:
#line 198 "parser.yy"
                                           { yylhs.value.as < json > () = {"splice_call_exp", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[2].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1012 "parser.cc"
    break;

  case 27:
#line 200 "parser.yy"
                                           { yylhs.value.as < json > () = {"array_const_exp", {{"item_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1018 "parser.cc"
    break;

  case 28:
#line 201 "parser.yy"
                                           { yylhs.value.as < json > () = {"make_array_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1024 "parser.cc"
    break;

  case 29:
#line 202 "parser.yy"
                                           { yylhs.value.as < json > () = {"array_get_exp", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1030 "parser.cc"
    break;

  case 30:
#line 203 "parser.yy"
                                           { yylhs.value.as < json > () = {"array_set_exp", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[2].value.as < json > ()}, {"exp3", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1036 "parser.cc"
    break;

  case 31:
#line 204 "parser.yy"
                                           { yylhs.value.as < json > () = {"size_of_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1042 "parser.cc"
    break;

  case 32:
#line 206 "parser.yy"
                            { yylhs.value.as < json > () = {"plus_k", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1048 "parser.cc"
    break;

  case 33:
#line 207 "parser.yy"
                            { yylhs.value.as < json > () = {"min_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1054 "parser.cc"
    break;

  case 34:
#line 208 "parser.yy"
                            { yylhs.value.as < json > () = {"mul_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1060 "parser.cc"
    break;

  case 35:
#line 209 "parser.yy"
                            { yylhs.value.as < json > () = {"div_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1066 "parser.cc"
    break;

  case 36:
#line 210 "parser.yy"
                            { yylhs.value.as < json > () = {"rem_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1072 "parser.cc"
    break;

  case 37:
#line 211 "parser.yy"
                            { yylhs.value.as < json > () = {"eq_k"  , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1078 "parser.cc"
    break;

  case 38:
#line 212 "parser.yy"
                            { yylhs.value.as < json > () = {"neq_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1084 "parser.cc"
    break;

  case 39:
#line 213 "parser.yy"
                            { yylhs.value.as < json > () = {"lot_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1090 "parser.cc"
    break;

  case 40:
#line 214 "parser.yy"
                            { yylhs.value.as < json > () = {"grt_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1096 "parser.cc"
    break;

  case 41:
#line 215 "parser.yy"
                            { yylhs.value.as < json > () = {"leq_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1102 "parser.cc"
    break;

  case 42:
#line 216 "parser.yy"
                            { yylhs.value.as < json > () = {"geq_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1108 "parser.cc"
    break;

  case 43:
#line 217 "parser.yy"
                            { yylhs.value.as < json > () = {"and_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1114 "parser.cc"
    break;

  case 44:
#line 218 "parser.yy"
                            { yylhs.value.as < json > () = {"or_k"  , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1120 "parser.cc"
    break;

  case 45:
#line 220 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_plus", yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1126 "parser.cc"
    break;

  case 46:
#line 221 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_min" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1132 "parser.cc"
    break;

  case 47:
#line 222 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_mul" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1138 "parser.cc"
    break;

  case 48:
#line 223 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_div" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1144 "parser.cc"
    break;

  case 49:
#line 224 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_rem" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1150 "parser.cc"
    break;

  case 50:
#line 225 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_eq"  , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1156 "parser.cc"
    break;

  case 51:
#line 226 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_neq" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1162 "parser.cc"
    break;

  case 52:
#line 227 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_lt"  , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1168 "parser.cc"
    break;

  case 53:
#line 228 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_gt"  , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1174 "parser.cc"
    break;

  case 54:
#line 229 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_leq" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1180 "parser.cc"
    break;

  case 55:
#line 230 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_geq" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1186 "parser.cc"
    break;

  case 56:
#line 231 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_and" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1192 "parser.cc"
    break;

  case 57:
#line 232 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_or"  , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1198 "parser.cc"
    break;

  case 58:
#line 234 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_plus", yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1204 "parser.cc"
    break;

  case 59:
#line 235 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_min" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1210 "parser.cc"
    break;

  case 60:
#line 236 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_mul" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1216 "parser.cc"
    break;

  case 61:
#line 237 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_div" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1222 "parser.cc"
    break;

  case 62:
#line 238 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_rem" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1228 "parser.cc"
    break;

  case 63:
#line 239 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_and" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1234 "parser.cc"
    break;

  case 64:
#line 240 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_or"  , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1240 "parser.cc"
    break;

  case 65:
#line 242 "parser.yy"
                         { yylhs.value.as < json > () = {"umin_k", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1246 "parser.cc"
    break;

  case 66:
#line 243 "parser.yy"
                         { yylhs.value.as < json > () = {"not_k",  {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1252 "parser.cc"
    break;

  case 67:
#line 245 "parser.yy"
                                 { yylhs.value.as < json > () = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_umin"}}, LOC_JSON(yylhs.location, yylhs.location)}},
                                                      {"item_list", {"one_exp_item_list", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}}},
						     LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1260 "parser.cc"
    break;

  case 68:
#line 248 "parser.yy"
                                 { yylhs.value.as < json > () = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_not"}}, LOC_JSON(yylhs.location, yylhs.location)}},
                                                      {"item_list", {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}}},
						     LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1268 "parser.cc"
    break;

  case 69:
#line 252 "parser.yy"
                                 { yylhs.value.as < json > () = {"run_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1274 "parser.cc"
    break;

  case 70:
#line 257 "parser.yy"
                           { yylhs.value.as < json > () = {"one_cond_cond_list", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}, {"cond_else", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1280 "parser.cc"
    break;

  case 71:
#line 258 "parser.yy"
                           { yylhs.value.as < json > () = {"mul_cond_cond_list", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}, {"cond_list", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1286 "parser.cc"
    break;

  case 72:
#line 262 "parser.yy"
            { yylhs.value.as < json > () = {"non_empty_cond_else", {{"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1292 "parser.cc"
    break;

  case 73:
#line 263 "parser.yy"
            { yylhs.value.as < json > () = {"empty_cond_else", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1298 "parser.cc"
    break;

  case 74:
#line 267 "parser.yy"
                { yylhs.value.as < json > () = {"int_exp", {{"int_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1304 "parser.cc"
    break;

  case 75:
#line 268 "parser.yy"
                { yylhs.value.as < json > () = {"bin_exp", {{"bin_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1310 "parser.cc"
    break;

  case 76:
#line 269 "parser.yy"
                { yylhs.value.as < json > () = {"hex_exp", {{"hex_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1316 "parser.cc"
    break;

  case 77:
#line 271 "parser.yy"
                { yylhs.value.as < json > () = {"float_exp", {{"float_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1322 "parser.cc"
    break;

  case 78:
#line 272 "parser.yy"
                { yylhs.value.as < json > () = {"floatp_exp", {{"floatp_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1328 "parser.cc"
    break;

  case 79:
#line 274 "parser.yy"
                { yylhs.value.as < json > () = {"bool_exp", {{"bool", yystack_[0].value.as < bool > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1334 "parser.cc"
    break;

  case 80:
#line 275 "parser.yy"
                { yylhs.value.as < json > () = {"string_exp", {{"string_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1340 "parser.cc"
    break;

  case 81:
#line 276 "parser.yy"
                { yylhs.value.as < json > () = {"char_exp", {{"char_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1346 "parser.cc"
    break;

  case 82:
#line 277 "parser.yy"
                { yylhs.value.as < json > () = {"symbol_exp", {{"symbol_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1352 "parser.cc"
    break;

  case 83:
#line 279 "parser.yy"
                { yylhs.value.as < json > () = {"null_exp", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1358 "parser.cc"
    break;

  case 84:
#line 284 "parser.yy"
                       { yylhs.value.as < json > () = yystack_[0].value.as < json > (); }
#line 1364 "parser.cc"
    break;

  case 85:
#line 285 "parser.yy"
                       { yylhs.value.as < json > () = {"empty_param_list", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1370 "parser.cc"
    break;

  case 86:
#line 289 "parser.yy"
                                      { yylhs.value.as < json > () = {"one_var_param_list", {{"var", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1376 "parser.cc"
    break;

  case 87:
#line 290 "parser.yy"
                                      { yylhs.value.as < json > () = {"mul_var_param_list", {{"var", yystack_[1].value.as < std::string > ()}, {"non_empty_param_list", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1382 "parser.cc"
    break;

  case 88:
#line 294 "parser.yy"
                     { yylhs.value.as < json > () = yystack_[0].value.as < json > (); }
#line 1388 "parser.cc"
    break;

  case 89:
#line 295 "parser.yy"
                     { yylhs.value.as < json > () = {"empty_item_list", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1394 "parser.cc"
    break;

  case 90:
#line 299 "parser.yy"
                           { yylhs.value.as < json > () = {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1400 "parser.cc"
    break;

  case 91:
#line 300 "parser.yy"
                           { yylhs.value.as < json > () = {"mul_exp_item_list", {{"exp", yystack_[1].value.as < json > ()}, {"non_empty_item_list", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1406 "parser.cc"
    break;


#line 1410 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -102;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     461,   -75,  -102,   -41,   101,   186,   461,   -36,   461,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,     2,  -102,   429,
    -102,  -102,    21,   -29,   461,   -45,   461,   243,   -11,     8,
     461,   461,   461,   461,   461,   461,     7,   461,   461,   461,
     461,   461,    29,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   429,
      28,   -45,   462,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,   461,   461,   461,   461,   461,   461,
     461,   461,   461,   461,  -102,  -102,   461,    31,   -45,    37,
    -102,    80,   461,  -102,  -102,   429,   429,   429,   429,   273,
     396,  -102,   505,   537,   569,   429,   601,  -102,   429,   633,
     429,   429,   429,   429,   665,   429,   429,   429,   429,   429,
     429,   429,   697,   429,    39,  -102,   320,    47,  -102,    50,
    1218,  1218,  1218,  1218,  1218,  1218,  1218,  1218,   -52,   -52,
     -52,   -52,    35,    35,  -102,  -102,  -102,   -52,   -52,   462,
     462,  1218,    75,  -102,    48,  -102,   352,   729,   761,   793,
     825,  -102,  -102,  -102,  -102,  -102,   857,  -102,   889,  -102,
     921,   429,   953,   985,  -102,  1017,  1049,  1081,  1113,  1145,
    1177,  1209,  -102,  -102,  -102,    54,  -102,    58,    70,   461,
     461,   287,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  1241,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,   461,    43,  1218,  1218,  -102,    68,    77,  -102,
      72,   461,    74,  -102
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,    83,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    74,    75,    76,    77,    78,    23,    82,     4,
       2,    22,     0,     8,     0,    85,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    89,
       0,    85,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     1,     0,     0,    86,     0,
      84,     0,     0,     7,    12,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,    88,    90,     0,     6,     0,
      58,    59,    60,    61,    62,    63,    64,     9,    55,    54,
      50,    51,    45,    46,    47,    48,    49,    52,    53,    56,
      57,    11,     0,    87,     0,    67,    73,     0,     0,     0,
       0,    13,    14,    31,    69,    17,     0,    19,     0,    28,
       0,     0,     0,     0,    65,     0,     0,     0,     0,     0,
       0,     0,    66,    91,    27,     0,    25,     0,     0,     0,
       0,     0,    71,    70,    42,    41,    37,    38,    18,    21,
      29,     0,    32,    33,    34,    35,    36,    39,    40,    43,
      44,    26,     0,     0,    10,    72,    30,     0,     0,    24,
       0,     0,     0,    16
  };

  const signed char
  parser::yypgoto_[] =
  {
    -102,    -3,     0,   -27,  -102,  -102,    73,  -101,    76,    45,
    -102
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    19,    84,    29,   193,    21,   124,   125,    89,    90,
      22
  };

  const unsigned char
  parser::yytable_[] =
  {
      20,    27,    59,    23,    28,    62,    60,    75,    76,    77,
      78,    79,    24,    61,    63,    64,    65,    66,    67,    68,
      69,    85,   183,    91,    87,   183,    86,    95,    96,    97,
      98,    99,   100,    88,   102,   103,   104,   105,   106,    93,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   126,    70,    94,   101,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   107,   128,   151,    71,   152,    72,   154,    73,   156,
      74,   184,   157,   158,   159,   160,    77,    78,    79,   186,
     187,   188,   166,   189,     1,   168,   211,   170,   171,   172,
     173,   212,   175,   176,   177,   178,   179,   180,   181,   213,
     123,   218,   219,   123,     2,   221,     3,   220,   223,   192,
     155,     0,   127,   153,     0,     0,     0,   129,    25,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       4,     0,     5,   191,     6,     0,     0,     7,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,   201,     8,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     0,     0,     0,     0,     0,   214,   215,     0,     1,
       0,    30,     0,    31,     0,    32,     0,    33,     0,     0,
       0,     0,     0,     0,     0,    34,    35,    36,    37,     2,
      38,     3,   217,    39,    40,    41,    42,    43,    44,    45,
      46,   222,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     4,     0,     5,     0,     6,
       0,     0,     7,     0,     0,     0,     1,    71,     0,    72,
       0,    73,     0,    74,     8,    58,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     2,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,    71,     0,    72,
       0,    73,     0,    74,     0,     0,     0,     0,     0,     0,
       0,    71,     4,    72,     5,    73,     6,    74,     0,     7,
      92,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     8,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     1,    71,   161,    72,     0,    73,     0,
      74,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     2,    92,     3,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     1,    71,   185,    72,     0,
      73,     0,    74,     0,     0,     0,     0,     0,     0,     4,
       0,     5,     0,     6,     0,     2,     7,     3,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     8,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      71,     4,    72,     5,    73,     6,    74,     0,     7,     0,
     190,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       8,     0,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     1,    71,     0,    72,     0,    73,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,   162,     0,
       0,     0,     2,     0,     3,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     1,     0,    71,     0,    72,     0,
      73,     0,    74,     0,     0,     0,     0,     0,     4,     0,
       5,     0,     6,     0,     2,     7,     3,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     8,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    71,
       4,    72,     5,    73,     6,    74,     0,     7,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    81,     0,     8,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    71,     0,    72,     0,    73,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    71,     0,    72,     0,    73,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   164,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    71,     0,    72,     0,    73,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    71,     0,    72,
       0,    73,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    71,
       0,    72,     0,    73,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    71,     0,    72,     0,    73,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    71,     0,    72,     0,    73,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   182,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    71,     0,    72,     0,    73,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    71,     0,    72,
       0,    73,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   195,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    71,
       0,    72,     0,    73,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   196,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    71,     0,    72,     0,    73,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   197,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    71,     0,    72,     0,    73,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    71,     0,    72,     0,    73,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    71,     0,    72,
       0,    73,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    71,
       0,    72,     0,    73,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    71,     0,    72,     0,    73,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    71,     0,    72,     0,    73,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    71,     0,    72,     0,    73,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    71,     0,    72,
       0,    73,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    71,
       0,    72,     0,    73,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   207,     0,     0,     0,     0,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    71,     0,    72,     0,    73,     0,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    71,     0,    72,     0,    73,     0,    74,
       0,     0,    71,     0,    72,     0,    73,     0,    74,   209,
       0,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    71,     0,    72,     0,    73,
       0,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    83
  };

  const short
  parser::yycheck_[] =
  {
       0,     4,     5,    78,     4,     8,     6,    59,    60,    61,
      62,    63,    53,    49,    12,    13,    14,    15,    16,    17,
      18,     0,   123,    26,    24,   126,    55,    30,    31,    32,
      33,    34,    35,    78,    37,    38,    39,    40,    41,    50,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    55,    50,    52,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    52,    54,    86,     4,    54,     6,    50,     8,    92,
      10,    52,    95,    96,    97,    98,    61,    62,    63,    52,
      50,    26,   105,    55,     3,   108,    52,   110,   111,   112,
     113,    53,   115,   116,   117,   118,   119,   120,   121,    49,
     123,    78,    54,   126,    23,    53,    25,    50,    54,   156,
      50,    -1,    59,    88,    -1,    -1,    -1,    61,    37,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    -1,
      49,    -1,    51,   156,    53,    -1,    -1,    56,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,   171,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    -1,    -1,   189,   190,    -1,     3,
      -1,     5,    -1,     7,    -1,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,   212,    27,    28,    29,    30,    31,    32,    33,
      34,   221,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    51,    -1,    53,
      -1,    -1,    56,    -1,    -1,    -1,     3,     4,    -1,     6,
      -1,     8,    -1,    10,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    49,     6,    51,     8,    53,    10,    -1,    56,
      57,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     3,     4,    52,     6,    -1,     8,    -1,
      10,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    -1,    23,    57,    25,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     3,     4,    37,     6,    -1,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    51,    -1,    53,    -1,    23,    56,    25,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       4,    49,     6,    51,     8,    53,    10,    -1,    56,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     3,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    23,    -1,    25,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     3,    -1,     4,    -1,     6,    -1,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    -1,    53,    -1,    23,    56,    25,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     4,
      49,     6,    51,     8,    53,    10,    -1,    56,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    -1,    68,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     4,    -1,     6,    -1,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     4,
      -1,     6,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     4,    -1,     6,    -1,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     4,
      -1,     6,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     4,    -1,     6,    -1,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     4,
      -1,     6,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     4,    -1,     6,    -1,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     4,
      -1,     6,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     4,    -1,     6,    -1,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    23,    25,    49,    51,    53,    56,    68,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    82,
      83,    86,    91,    78,    53,    37,    60,    82,    83,    84,
       5,     7,     9,    11,    19,    20,    21,    22,    24,    27,
      28,    29,    30,    31,    32,    33,    34,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    69,    82,
      83,    49,    82,    12,    13,    14,    15,    16,    17,    18,
      55,     4,     6,     8,    10,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    83,     0,    55,    83,    78,    89,
      90,    82,    57,    50,    50,    82,    82,    82,    82,    82,
      82,    52,    82,    82,    82,    82,    82,    52,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    87,    88,    82,    87,    54,    89,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    54,    90,    50,    50,    82,    82,    82,    82,
      82,    52,    52,    52,    52,    52,    82,    52,    82,    52,
      82,    82,    82,    82,    52,    82,    82,    82,    82,    82,
      82,    82,    52,    88,    52,    37,    52,    50,    26,    55,
      58,    82,    84,    85,    52,    52,    52,    52,    52,    52,
      52,    82,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    49,    82,    82,    52,    83,    78,    54,
      50,    53,    83,    54
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    81,    91,    91,    83,    83,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    89,    89,    90,    90,    87,    87,
      88,    88
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     2,     3,     3,     2,     3,
       6,     4,     3,     4,     4,     3,    11,     4,     5,     4,
       3,     5,     1,     1,     7,     4,     5,     4,     4,     5,
       6,     4,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     4,     2,     4,
       4,     4,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     2,     1,     0,
       1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"def\"", "\">=\"",
  "\"__geq__\"", "\"<=\"", "\"__leq__\"", "\"==\"", "\"__eq__\"", "\"!=\"",
  "\"__neq__\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"",
  "\"&=\"", "\"|=\"", "\"print\"", "\"show\"", "\"scan\"",
  "\"__sizeof__\"", "\"null\"", "\"run\"", "\"try\"", "\"catch\"",
  "\"raise\"", "\"__convert__\"", "\"__valuetype__\"", "\"__gensym__\"",
  "\"__same__\"", "\"__make_array__\"", "\"__array_get__\"",
  "\"__array_set__\"", "\"__string_get__\"", "\"__string_set__\"",
  "\"...\"", "\"__plus__\"", "\"__min__\"", "\"__umin__\"", "\"__mul__\"",
  "\"__div__\"", "\"__rem__\"", "\"__lot__\"", "\"__grt__\"",
  "\"__and__\"", "\"__or__\"", "\"__not__\"", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\"{\"", "\"}\"", "\"=\"", "\"@\"", "\"?\"", "\":\"", "\"+\"",
  "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"<\"", "\">\"", "\"&\"", "\"|\"",
  "\"!\"", "\"#\"", "\"bool\"", "\"string\"", "\"char\"", "\"int\"",
  "\"bin\"", "\"hex\"", "\"float\"", "\"floarp\"", "\"identifier\"",
  "\"symbol\"", "UMIN", "$accept", "exp", "expList", "condList",
  "condElse", "constant", "itemList", "nonEmptyItemList", "paramList",
  "nonEmptyParamList", "program", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   147,   147,   149,   154,   156,   162,   164,   166,   168,
     170,   172,   178,   179,   180,   181,   183,   186,   188,   189,
     190,   191,   193,   194,   196,   197,   198,   200,   201,   202,
     203,   204,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   234,   235,
     236,   237,   238,   239,   240,   242,   243,   245,   248,   252,
     257,   258,   262,   263,   267,   268,   269,   271,   272,   274,
     275,   276,   277,   279,   284,   285,   289,   290,   294,   295,
     299,   300
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2159 "parser.cc"

#line 304 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
