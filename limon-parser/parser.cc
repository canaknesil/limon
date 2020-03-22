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
      case 69: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 81: // exp
      case 82: // expList
      case 83: // condList
      case 84: // condElse
      case 85: // constant
      case 86: // itemList
      case 87: // nonEmptyItemList
      case 88: // paramList
      case 89: // nonEmptyParamList
      case 90: // program
        value.YY_MOVE_OR_COPY< json > (YY_MOVE (that.value));
        break;

      case 70: // "string"
      case 71: // "char"
      case 72: // "int"
      case 73: // "bin"
      case 74: // "hex"
      case 75: // "float"
      case 76: // "floarp"
      case 77: // "identifier"
      case 78: // "symbol"
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
      case 69: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 81: // exp
      case 82: // expList
      case 83: // condList
      case 84: // condElse
      case 85: // constant
      case 86: // itemList
      case 87: // nonEmptyItemList
      case 88: // paramList
      case 89: // nonEmptyParamList
      case 90: // program
        value.move< json > (YY_MOVE (that.value));
        break;

      case 70: // "string"
      case 71: // "char"
      case 72: // "int"
      case 73: // "bin"
      case 74: // "hex"
      case 75: // "float"
      case 76: // "floarp"
      case 77: // "identifier"
      case 78: // "symbol"
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
      case 69: // "bool"
        value.copy< bool > (that.value);
        break;

      case 81: // exp
      case 82: // expList
      case 83: // condList
      case 84: // condElse
      case 85: // constant
      case 86: // itemList
      case 87: // nonEmptyItemList
      case 88: // paramList
      case 89: // nonEmptyParamList
      case 90: // program
        value.copy< json > (that.value);
        break;

      case 70: // "string"
      case 71: // "char"
      case 72: // "int"
      case 73: // "bin"
      case 74: // "hex"
      case 75: // "float"
      case 76: // "floarp"
      case 77: // "identifier"
      case 78: // "symbol"
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
      case 69: // "bool"
        value.move< bool > (that.value);
        break;

      case 81: // exp
      case 82: // expList
      case 83: // condList
      case 84: // condElse
      case 85: // constant
      case 86: // itemList
      case 87: // nonEmptyItemList
      case 88: // paramList
      case 89: // nonEmptyParamList
      case 90: // program
        value.move< json > (that.value);
        break;

      case 70: // "string"
      case 71: // "char"
      case 72: // "int"
      case 73: // "bin"
      case 74: // "hex"
      case 75: // "float"
      case 76: // "floarp"
      case 77: // "identifier"
      case 78: // "symbol"
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
      case 69: // "bool"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < bool > (); }
#line 470 "parser.cc"
        break;

      case 70: // "string"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 476 "parser.cc"
        break;

      case 71: // "char"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 482 "parser.cc"
        break;

      case 72: // "int"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 488 "parser.cc"
        break;

      case 73: // "bin"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 494 "parser.cc"
        break;

      case 74: // "hex"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 500 "parser.cc"
        break;

      case 75: // "float"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 506 "parser.cc"
        break;

      case 76: // "floarp"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 512 "parser.cc"
        break;

      case 77: // "identifier"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 518 "parser.cc"
        break;

      case 78: // "symbol"
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 524 "parser.cc"
        break;

      case 81: // exp
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 530 "parser.cc"
        break;

      case 82: // expList
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 536 "parser.cc"
        break;

      case 83: // condList
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 542 "parser.cc"
        break;

      case 84: // condElse
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 548 "parser.cc"
        break;

      case 85: // constant
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 554 "parser.cc"
        break;

      case 86: // itemList
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 560 "parser.cc"
        break;

      case 87: // nonEmptyItemList
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 566 "parser.cc"
        break;

      case 88: // paramList
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 572 "parser.cc"
        break;

      case 89: // nonEmptyParamList
#line 140 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 578 "parser.cc"
        break;

      case 90: // program
#line 140 "parser.yy"
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
      case 69: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case 81: // exp
      case 82: // expList
      case 83: // condList
      case 84: // condElse
      case 85: // constant
      case 86: // itemList
      case 87: // nonEmptyItemList
      case 88: // paramList
      case 89: // nonEmptyParamList
      case 90: // program
        yylhs.value.emplace< json > ();
        break;

      case 70: // "string"
      case 71: // "char"
      case 72: // "int"
      case 73: // "bin"
      case 74: // "hex"
      case 75: // "float"
      case 76: // "floarp"
      case 77: // "identifier"
      case 78: // "symbol"
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
#line 146 "parser.yy"
             { json j = {{"exp_list", yystack_[0].value.as < json > ()}};
               drv.result = {"program", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 855 "parser.cc"
    break;

  case 3:
#line 148 "parser.yy"
             { drv.result = {"empty_program", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 861 "parser.cc"
    break;

  case 4:
#line 153 "parser.yy"
                   { json j = {{"exp", yystack_[0].value.as < json > ()}};
                     yylhs.value.as < json > () = {"one_exp_exp_list", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 868 "parser.cc"
    break;

  case 5:
#line 155 "parser.yy"
                   { json j = {{"exp", yystack_[1].value.as < json > ()}, {"exp_list", yystack_[0].value.as < json > ()}};
                     yylhs.value.as < json > () = {"mul_exp_exp_list", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 875 "parser.cc"
    break;

  case 6:
#line 161 "parser.yy"
                     { json j = {{"exp_list", yystack_[1].value.as < json > ()}};
                       yylhs.value.as < json > () = {"scope_exp", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 882 "parser.cc"
    break;

  case 7:
#line 163 "parser.yy"
                     { yylhs.value.as < json > () = yystack_[1].value.as < json > (); }
#line 888 "parser.cc"
    break;

  case 8:
#line 165 "parser.yy"
                     { json j = {{"var", yystack_[0].value.as < std::string > ()}};
                       yylhs.value.as < json > () = {"def_exp", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 895 "parser.cc"
    break;

  case 9:
#line 167 "parser.yy"
                           { json j = {{"var", yystack_[2].value.as < std::string > ()}, {"exp", yystack_[0].value.as < json > ()}};
                             yylhs.value.as < json > () = {"assign_exp", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 902 "parser.cc"
    break;

  case 10:
#line 169 "parser.yy"
                                        { json j = {{"param_list", yystack_[3].value.as < json > ()}, {"exp", yystack_[0].value.as < json > ()}};
                                          yylhs.value.as < json > () = {"mul_assign_exp", j, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 909 "parser.cc"
    break;

  case 11:
#line 171 "parser.yy"
                               { json assign_node = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()}, 
                                                                    {"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)};
                                 json def_node = {"def_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                              {"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)};
                                 yylhs.value.as < json > () = {"mul_exp_exp_list", {{"exp", def_node}, 
                                                            {"exp_list", {"one_exp_exp_list", {{"exp", assign_node}}, LOC_JSON(yylhs.location, yylhs.location)}}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 920 "parser.cc"
    break;

  case 12:
#line 177 "parser.yy"
                                { yylhs.value.as < json > () = {"cond_exp", {{"cond_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 926 "parser.cc"
    break;

  case 13:
#line 178 "parser.yy"
                                { yylhs.value.as < json > () = {"print_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 932 "parser.cc"
    break;

  case 14:
#line 179 "parser.yy"
                                { yylhs.value.as < json > () = {"show_exp" , {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 938 "parser.cc"
    break;

  case 15:
#line 180 "parser.yy"
                                { yylhs.value.as < json > () = {"scan_exp", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 944 "parser.cc"
    break;

  case 16:
#line 182 "parser.yy"
                                                                   { yylhs.value.as < json > () = {"try_catch_exp", {{"try_exp_list", yystack_[8].value.as < json > ()},
                                                                                             {"catch_var", yystack_[4].value.as < std::string > ()},
                                                                                             {"catch_exp_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 952 "parser.cc"
    break;

  case 17:
#line 185 "parser.yy"
                      { yylhs.value.as < json > () = {"raise_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 958 "parser.cc"
    break;

  case 18:
#line 187 "parser.yy"
                                { yylhs.value.as < json > () = {"valtype_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 964 "parser.cc"
    break;

  case 19:
#line 188 "parser.yy"
                                { yylhs.value.as < json > () = {"gensym_exp", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 970 "parser.cc"
    break;

  case 20:
#line 189 "parser.yy"
                                { yylhs.value.as < json > () = {"same_exp", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 976 "parser.cc"
    break;

  case 21:
#line 191 "parser.yy"
                                { yylhs.value.as < json > () = yystack_[0].value.as < json > (); }
#line 982 "parser.cc"
    break;

  case 22:
#line 192 "parser.yy"
                                { yylhs.value.as < json > () = {"var_exp", {{"var", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 988 "parser.cc"
    break;

  case 23:
#line 194 "parser.yy"
                                           { yylhs.value.as < json > () = {"proc_exp", {{"param_list", yystack_[4].value.as < json > ()}, {"exp_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 994 "parser.cc"
    break;

  case 24:
#line 195 "parser.yy"
                                           { yylhs.value.as < json > () = {"call_exp", {{"exp", yystack_[2].value.as < json > ()}, {"item_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1000 "parser.cc"
    break;

  case 25:
#line 196 "parser.yy"
                                           { yylhs.value.as < json > () = {"splice_call_exp", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[2].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1006 "parser.cc"
    break;

  case 26:
#line 198 "parser.yy"
                                           { yylhs.value.as < json > () = {"array_const_exp", {{"item_list", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1012 "parser.cc"
    break;

  case 27:
#line 199 "parser.yy"
                                           { yylhs.value.as < json > () = {"make_array_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1018 "parser.cc"
    break;

  case 28:
#line 200 "parser.yy"
                                           { yylhs.value.as < json > () = {"array_get_exp", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1024 "parser.cc"
    break;

  case 29:
#line 201 "parser.yy"
                                           { yylhs.value.as < json > () = {"array_set_exp", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[2].value.as < json > ()}, {"exp3", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1030 "parser.cc"
    break;

  case 30:
#line 202 "parser.yy"
                                           { yylhs.value.as < json > () = {"size_of_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1036 "parser.cc"
    break;

  case 31:
#line 204 "parser.yy"
                            { yylhs.value.as < json > () = {"plus_k", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1042 "parser.cc"
    break;

  case 32:
#line 205 "parser.yy"
                            { yylhs.value.as < json > () = {"min_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1048 "parser.cc"
    break;

  case 33:
#line 206 "parser.yy"
                            { yylhs.value.as < json > () = {"mul_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1054 "parser.cc"
    break;

  case 34:
#line 207 "parser.yy"
                            { yylhs.value.as < json > () = {"div_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1060 "parser.cc"
    break;

  case 35:
#line 208 "parser.yy"
                            { yylhs.value.as < json > () = {"rem_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1066 "parser.cc"
    break;

  case 36:
#line 209 "parser.yy"
                            { yylhs.value.as < json > () = {"eq_k"  , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1072 "parser.cc"
    break;

  case 37:
#line 210 "parser.yy"
                            { yylhs.value.as < json > () = {"neq_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1078 "parser.cc"
    break;

  case 38:
#line 211 "parser.yy"
                            { yylhs.value.as < json > () = {"lot_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1084 "parser.cc"
    break;

  case 39:
#line 212 "parser.yy"
                            { yylhs.value.as < json > () = {"grt_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1090 "parser.cc"
    break;

  case 40:
#line 213 "parser.yy"
                            { yylhs.value.as < json > () = {"leq_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1096 "parser.cc"
    break;

  case 41:
#line 214 "parser.yy"
                            { yylhs.value.as < json > () = {"geq_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1102 "parser.cc"
    break;

  case 42:
#line 215 "parser.yy"
                            { yylhs.value.as < json > () = {"and_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1108 "parser.cc"
    break;

  case 43:
#line 216 "parser.yy"
                            { yylhs.value.as < json > () = {"or_k"  , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1114 "parser.cc"
    break;

  case 44:
#line 218 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_plus", yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1120 "parser.cc"
    break;

  case 45:
#line 219 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_min" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1126 "parser.cc"
    break;

  case 46:
#line 220 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_mul" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1132 "parser.cc"
    break;

  case 47:
#line 221 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_div" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1138 "parser.cc"
    break;

  case 48:
#line 222 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_rem" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1144 "parser.cc"
    break;

  case 49:
#line 223 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_eq"  , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1150 "parser.cc"
    break;

  case 50:
#line 224 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_neq" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1156 "parser.cc"
    break;

  case 51:
#line 225 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_lt"  , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1162 "parser.cc"
    break;

  case 52:
#line 226 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_gt"  , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1168 "parser.cc"
    break;

  case 53:
#line 227 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_leq" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1174 "parser.cc"
    break;

  case 54:
#line 228 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_geq" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1180 "parser.cc"
    break;

  case 55:
#line 229 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_and" , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1186 "parser.cc"
    break;

  case 56:
#line 230 "parser.yy"
                      { yylhs.value.as < json > () = BIN_OP_SUGAR("sw_or"  , yystack_[2].value.as < json > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1192 "parser.cc"
    break;

  case 57:
#line 232 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_plus", yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1198 "parser.cc"
    break;

  case 58:
#line 233 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_min" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1204 "parser.cc"
    break;

  case 59:
#line 234 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_mul" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1210 "parser.cc"
    break;

  case 60:
#line 235 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_div" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1216 "parser.cc"
    break;

  case 61:
#line 236 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_rem" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1222 "parser.cc"
    break;

  case 62:
#line 237 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_and" , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1228 "parser.cc"
    break;

  case 63:
#line 238 "parser.yy"
                               { BIN_OP_EQ_SUGAR("sw_or"  , yylhs.value.as < json > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < json > (), yylhs.location, yylhs.location); }
#line 1234 "parser.cc"
    break;

  case 64:
#line 240 "parser.yy"
                         { yylhs.value.as < json > () = {"umin_k", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1240 "parser.cc"
    break;

  case 65:
#line 241 "parser.yy"
                         { yylhs.value.as < json > () = {"not_k",  {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1246 "parser.cc"
    break;

  case 66:
#line 243 "parser.yy"
                                 { yylhs.value.as < json > () = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_umin"}}, LOC_JSON(yylhs.location, yylhs.location)}},
                                                      {"item_list", {"one_exp_item_list", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}}},
						     LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1254 "parser.cc"
    break;

  case 67:
#line 246 "parser.yy"
                                 { yylhs.value.as < json > () = {"call_exp", {{"exp", {"var_exp", {{"var", "sw_not"}}, LOC_JSON(yylhs.location, yylhs.location)}},
                                                      {"item_list", {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}}},
						     LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1262 "parser.cc"
    break;

  case 68:
#line 250 "parser.yy"
                                 { yylhs.value.as < json > () = {"run_exp", {{"exp", yystack_[1].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1268 "parser.cc"
    break;

  case 69:
#line 255 "parser.yy"
                           { yylhs.value.as < json > () = {"one_cond_cond_list", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}, {"cond_else", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1274 "parser.cc"
    break;

  case 70:
#line 256 "parser.yy"
                           { yylhs.value.as < json > () = {"mul_cond_cond_list", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}, {"cond_list", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1280 "parser.cc"
    break;

  case 71:
#line 260 "parser.yy"
            { yylhs.value.as < json > () = {"non_empty_cond_else", {{"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1286 "parser.cc"
    break;

  case 72:
#line 261 "parser.yy"
            { yylhs.value.as < json > () = {"empty_cond_else", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1292 "parser.cc"
    break;

  case 73:
#line 265 "parser.yy"
                { yylhs.value.as < json > () = {"int_exp", {{"int_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1298 "parser.cc"
    break;

  case 74:
#line 266 "parser.yy"
                { yylhs.value.as < json > () = {"bin_exp", {{"bin_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1304 "parser.cc"
    break;

  case 75:
#line 267 "parser.yy"
                { yylhs.value.as < json > () = {"hex_exp", {{"hex_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1310 "parser.cc"
    break;

  case 76:
#line 269 "parser.yy"
                { yylhs.value.as < json > () = {"float_exp", {{"float_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1316 "parser.cc"
    break;

  case 77:
#line 270 "parser.yy"
                { yylhs.value.as < json > () = {"floatp_exp", {{"floatp_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1322 "parser.cc"
    break;

  case 78:
#line 272 "parser.yy"
                { yylhs.value.as < json > () = {"bool_exp", {{"bool", yystack_[0].value.as < bool > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1328 "parser.cc"
    break;

  case 79:
#line 273 "parser.yy"
                { yylhs.value.as < json > () = {"string_exp", {{"string_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1334 "parser.cc"
    break;

  case 80:
#line 274 "parser.yy"
                { yylhs.value.as < json > () = {"char_exp", {{"char_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1340 "parser.cc"
    break;

  case 81:
#line 275 "parser.yy"
                { yylhs.value.as < json > () = {"symbol_exp", {{"symbol_str", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1346 "parser.cc"
    break;

  case 82:
#line 277 "parser.yy"
                { yylhs.value.as < json > () = {"null_exp", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1352 "parser.cc"
    break;

  case 83:
#line 282 "parser.yy"
                       { yylhs.value.as < json > () = yystack_[0].value.as < json > (); }
#line 1358 "parser.cc"
    break;

  case 84:
#line 283 "parser.yy"
                       { yylhs.value.as < json > () = {"empty_param_list", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1364 "parser.cc"
    break;

  case 85:
#line 287 "parser.yy"
                                      { yylhs.value.as < json > () = {"one_var_param_list", {{"var", yystack_[0].value.as < std::string > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1370 "parser.cc"
    break;

  case 86:
#line 288 "parser.yy"
                                      { yylhs.value.as < json > () = {"mul_var_param_list", {{"var", yystack_[1].value.as < std::string > ()}, {"non_empty_param_list", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1376 "parser.cc"
    break;

  case 87:
#line 292 "parser.yy"
                     { yylhs.value.as < json > () = yystack_[0].value.as < json > (); }
#line 1382 "parser.cc"
    break;

  case 88:
#line 293 "parser.yy"
                     { yylhs.value.as < json > () = {"empty_item_list", {}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1388 "parser.cc"
    break;

  case 89:
#line 297 "parser.yy"
                           { yylhs.value.as < json > () = {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1394 "parser.cc"
    break;

  case 90:
#line 298 "parser.yy"
                           { yylhs.value.as < json > () = {"mul_exp_item_list", {{"exp", yystack_[1].value.as < json > ()}, {"non_empty_item_list", yystack_[0].value.as < json > ()}}, LOC_JSON(yylhs.location, yylhs.location)}; }
#line 1400 "parser.cc"
    break;


#line 1404 "parser.cc"

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


  const signed char parser::yypact_ninf_ = -100;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     452,   -74,  -100,   -40,    97,   182,   452,   -35,   452,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,     2,  -100,   421,
    -100,  -100,    21,   -28,   452,   -44,   452,   238,   -11,     8,
     452,   452,   452,   452,   452,   452,     7,   452,   452,   452,
     452,    29,   452,   452,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   452,   452,   452,   452,   452,   421,    31,
     -44,  1238,   452,   452,   452,   452,   452,   452,   452,   452,
     452,   452,   452,   452,   452,   452,   452,   452,   452,   452,
     452,   452,   452,  -100,  -100,   452,    33,   -44,    40,  -100,
      77,   452,  -100,  -100,   421,   421,   421,   421,   268,   450,
    -100,   527,   543,   559,   622,  -100,   421,   638,   421,   421,
     421,   421,   654,   421,   421,   421,   421,   421,   421,   421,
     717,   421,    39,  -100,   314,    47,  -100,    50,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,   -51,   -51,   -51,   -51,
      35,    35,  -100,  -100,  -100,   -51,   -51,  1238,  1238,  1228,
      75,  -100,    48,  -100,   345,   733,   749,   812,   828,  -100,
    -100,  -100,  -100,  -100,  -100,   844,  -100,   907,   421,   923,
     939,  -100,  1002,  1018,  1034,  1097,  1113,  1129,  1192,  -100,
    -100,  -100,    53,  -100,    57,    69,   452,   452,  1203,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  1219,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,   452,    42,
    1228,  1228,  -100,    70,    76,  -100,    72,   452,    74,  -100
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,    82,     0,     0,     0,     0,     0,     0,    78,
      79,    80,    73,    74,    75,    76,    77,    22,    81,     4,
       2,    21,     0,     8,     0,    84,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    88,     0,
      84,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     1,     0,     0,    85,     0,    83,
       0,     0,     7,    12,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,    87,    89,     0,     6,     0,    57,    58,
      59,    60,    61,    62,    63,     9,    54,    53,    49,    50,
      44,    45,    46,    47,    48,    51,    52,    55,    56,    11,
       0,    86,     0,    66,    72,     0,     0,     0,     0,    13,
      14,    30,    68,    17,    18,     0,    27,     0,     0,     0,
       0,    64,     0,     0,     0,     0,     0,     0,     0,    65,
      90,    26,     0,    24,     0,     0,     0,     0,     0,    70,
      69,    41,    40,    36,    37,    20,    28,     0,    31,    32,
      33,    34,    35,    38,    39,    42,    43,    25,     0,     0,
      10,    71,    29,     0,     0,    23,     0,     0,     0,    16
  };

  const signed char
  parser::yypgoto_[] =
  {
    -100,    -3,     0,   -26,  -100,  -100,    71,   -99,    84,    43,
    -100
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    19,    83,    29,   190,    21,   122,   123,    88,    89,
      22
  };

  const unsigned char
  parser::yytable_[] =
  {
      20,    27,    58,    23,    28,    61,    59,    74,    75,    76,
      77,    78,    24,    60,    62,    63,    64,    65,    66,    67,
      68,    84,   180,    90,    86,   180,    85,    94,    95,    96,
      97,    98,    99,    87,   101,   102,   103,   104,    92,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   124,    69,    93,   100,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     105,    70,   149,    71,   126,    72,   150,    73,   154,   152,
     181,   155,   156,   157,   158,    76,    77,    78,   183,   184,
       1,   185,   186,   165,   207,   167,   168,   169,   170,   208,
     172,   173,   174,   175,   176,   177,   178,   209,   121,   214,
       2,   121,     3,   215,   217,   216,   153,   219,   189,   125,
     151,     0,     0,    25,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   127,     4,     0,     5,     0,     6,
       0,   188,     7,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     8,   197,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,     0,
       0,     0,     0,   210,   211,     1,     0,    30,     0,    31,
       0,    32,     0,    33,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,    37,     2,    38,     3,   213,    39,
      40,    41,    42,    43,    44,    45,     0,   218,     0,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       4,     0,     5,     0,     6,     0,     0,     7,     0,     0,
       0,     1,    70,     0,    71,     0,    72,     0,    73,     8,
      57,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     2,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,    71,     0,    72,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     5,     0,
       6,     0,     0,     7,    91,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     8,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     1,    70,   159,
      71,     0,    72,     0,    73,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,     2,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    70,
     182,    71,     0,    72,     0,    73,     0,     0,     0,     0,
       0,     0,     4,     0,     5,     0,     6,     0,     2,     7,
       3,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     8,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     4,     0,     5,     0,     6,     0,     0,
       7,     0,   187,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     8,     0,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     1,    70,     0,    71,     0,    72,
       0,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     3,     0,     0,     0,
       0,     0,     0,     0,    70,     1,    71,     0,    72,     0,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,     5,     0,     6,     0,     2,     7,     3,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     8,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       4,   160,     5,     0,     6,     0,     0,     7,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,     0,     8,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    70,     0,    71,     0,    72,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,    71,
       0,    72,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,    71,     0,    72,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   162,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     163,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    70,     0,    71,     0,
      72,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,    71,     0,    72,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
      71,     0,    72,     0,    73,     0,     0,     0,     0,     0,
       0,     0,     0,   164,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   166,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,   171,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    70,     0,    71,     0,    72,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,    71,
       0,    72,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,    71,     0,    72,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   191,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     192,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    70,     0,    71,     0,
      72,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,    71,     0,    72,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
      71,     0,    72,     0,    73,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   194,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,   195,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    70,     0,    71,     0,    72,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,    71,
       0,    72,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,    71,     0,    72,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   198,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     199,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    70,     0,    71,     0,
      72,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,    71,     0,    72,     0,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
      71,     0,    72,     0,    73,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   201,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,   202,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    70,     0,    71,     0,    72,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,    71,
       0,    72,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,    71,     0,    72,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,   203,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   204,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     205,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    70,     0,    71,     0,
      72,     0,    73,     0,     0,     0,     0,    70,     0,    71,
       0,    72,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,    71,     0,    72,     0,    73,
       0,     0,    70,     0,    71,     0,    72,     0,    73,     0,
       0,     0,    70,   206,    71,     0,    72,     0,    73,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    91,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     212,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,    74,    75,    76,    77,
      78,    79,    80
  };

  const short
  parser::yycheck_[] =
  {
       0,     4,     5,    77,     4,     8,     6,    58,    59,    60,
      61,    62,    52,    48,    12,    13,    14,    15,    16,    17,
      18,     0,   121,    26,    24,   124,    54,    30,    31,    32,
      33,    34,    35,    77,    37,    38,    39,    40,    49,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    54,    49,    51,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      51,     4,    85,     6,    53,     8,    53,    10,    91,    49,
      51,    94,    95,    96,    97,    60,    61,    62,    51,    49,
       3,    26,    54,   106,    51,   108,   109,   110,   111,    52,
     113,   114,   115,   116,   117,   118,   119,    48,   121,    77,
      23,   124,    25,    53,    52,    49,    49,    53,   154,    58,
      87,    -1,    -1,    36,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    60,    48,    -1,    50,    -1,    52,
      -1,   154,    55,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,   168,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,     3,    -1,     5,    -1,     7,
      -1,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,   208,    27,
      28,    29,    30,    31,    32,    33,    -1,   217,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    -1,    52,    -1,    -1,    55,    -1,    -1,
      -1,     3,     4,    -1,     6,    -1,     8,    -1,    10,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,
      52,    -1,    -1,    55,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     3,     4,    51,
       6,    -1,     8,    -1,    10,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    -1,    23,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      36,     6,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,    52,    -1,    23,    55,
      25,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    48,    -1,    50,    -1,    52,    -1,    -1,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     3,     4,    -1,     6,    -1,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     3,     6,    -1,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    52,    -1,    23,    55,    25,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      48,    51,    50,    -1,    52,    -1,    -1,    55,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     4,    -1,     6,    -1,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
       6,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     4,    -1,     6,    -1,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
       6,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     4,    -1,     6,    -1,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
       6,    -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     4,    -1,     6,    -1,
       8,    -1,    10,    -1,    -1,    -1,    -1,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    -1,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    -1,     4,    51,     6,    -1,     8,    -1,    10,    -1,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    -1,    58,    59,    60,    61,
      62,    63,    64
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    23,    25,    48,    50,    52,    55,    67,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    81,
      82,    85,    90,    77,    52,    36,    59,    81,    82,    83,
       5,     7,     9,    11,    19,    20,    21,    22,    24,    27,
      28,    29,    30,    31,    32,    33,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    68,    81,    82,
      48,    81,    12,    13,    14,    15,    16,    17,    18,    54,
       4,     6,     8,    10,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    82,     0,    54,    82,    77,    88,    89,
      81,    56,    49,    49,    81,    81,    81,    81,    81,    81,
      51,    81,    81,    81,    81,    51,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    86,    87,    81,    86,    53,    88,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      53,    89,    49,    49,    81,    81,    81,    81,    81,    51,
      51,    51,    51,    51,    51,    81,    51,    81,    81,    81,
      81,    51,    81,    81,    81,    81,    81,    81,    81,    51,
      87,    51,    36,    51,    49,    26,    54,    57,    81,    83,
      84,    51,    51,    51,    51,    51,    51,    81,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    48,
      81,    81,    51,    82,    77,    53,    49,    52,    82,    53
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    80,    90,    90,    82,    82,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    88,    88,    89,    89,    86,    86,    87,
      87
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     2,     3,     3,     2,     3,
       6,     4,     3,     4,     4,     3,    11,     4,     4,     3,
       5,     1,     1,     7,     4,     5,     4,     4,     5,     6,
       4,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     4,     2,     4,     4,
       4,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     2,     1,     0,     1,
       2
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
  "\"raise\"", "\"__valuetype__\"", "\"__gensym__\"", "\"__same__\"",
  "\"__make_array__\"", "\"__array_get__\"", "\"__array_set__\"",
  "\"__string_get__\"", "\"__string_set__\"", "\"...\"", "\"__plus__\"",
  "\"__min__\"", "\"__umin__\"", "\"__mul__\"", "\"__div__\"",
  "\"__rem__\"", "\"__lot__\"", "\"__grt__\"", "\"__and__\"", "\"__or__\"",
  "\"__not__\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"",
  "\"=\"", "\"@\"", "\"?\"", "\":\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"%\"", "\"<\"", "\">\"", "\"&\"", "\"|\"", "\"!\"", "\"#\"",
  "\"bool\"", "\"string\"", "\"char\"", "\"int\"", "\"bin\"", "\"hex\"",
  "\"float\"", "\"floarp\"", "\"identifier\"", "\"symbol\"", "UMIN",
  "$accept", "exp", "expList", "condList", "condElse", "constant",
  "itemList", "nonEmptyItemList", "paramList", "nonEmptyParamList",
  "program", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   146,   146,   148,   153,   155,   161,   163,   165,   167,
     169,   171,   177,   178,   179,   180,   182,   185,   187,   188,
     189,   191,   192,   194,   195,   196,   198,   199,   200,   201,
     202,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   232,   233,   234,
     235,   236,   237,   238,   240,   241,   243,   246,   250,   255,
     256,   260,   261,   265,   266,   267,   269,   270,   272,   273,
     274,   275,   277,   282,   283,   287,   288,   292,   293,   297,
     298
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
#line 2150 "parser.cc"

#line 302 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
