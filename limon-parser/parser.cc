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

# include "driver.hh"

#line 49 "parser.cc"


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
#line 140 "parser.cc"


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
      case 66: // "bool"
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 78: // exp
      case 79: // expList
      case 80: // condList
      case 81: // constant
      case 82: // itemList
      case 83: // nonEmptyItemList
      case 84: // paramList
      case 85: // nonEmptyParamList
      case 86: // program
        value.YY_MOVE_OR_COPY< json > (YY_MOVE (that.value));
        break;

      case 67: // "string"
      case 68: // "char"
      case 69: // "int"
      case 70: // "bin"
      case 71: // "hex"
      case 72: // "float"
      case 73: // "floarp"
      case 74: // "identifier"
      case 75: // "symbol"
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
      case 66: // "bool"
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 78: // exp
      case 79: // expList
      case 80: // condList
      case 81: // constant
      case 82: // itemList
      case 83: // nonEmptyItemList
      case 84: // paramList
      case 85: // nonEmptyParamList
      case 86: // program
        value.move< json > (YY_MOVE (that.value));
        break;

      case 67: // "string"
      case 68: // "char"
      case 69: // "int"
      case 70: // "bin"
      case 71: // "hex"
      case 72: // "float"
      case 73: // "floarp"
      case 74: // "identifier"
      case 75: // "symbol"
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
      case 66: // "bool"
        value.copy< bool > (that.value);
        break;

      case 78: // exp
      case 79: // expList
      case 80: // condList
      case 81: // constant
      case 82: // itemList
      case 83: // nonEmptyItemList
      case 84: // paramList
      case 85: // nonEmptyParamList
      case 86: // program
        value.copy< json > (that.value);
        break;

      case 67: // "string"
      case 68: // "char"
      case 69: // "int"
      case 70: // "bin"
      case 71: // "hex"
      case 72: // "float"
      case 73: // "floarp"
      case 74: // "identifier"
      case 75: // "symbol"
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
      case 66: // "bool"
        value.move< bool > (that.value);
        break;

      case 78: // exp
      case 79: // expList
      case 80: // condList
      case 81: // constant
      case 82: // itemList
      case 83: // nonEmptyItemList
      case 84: // paramList
      case 85: // nonEmptyParamList
      case 86: // program
        value.move< json > (that.value);
        break;

      case 67: // "string"
      case 68: // "char"
      case 69: // "int"
      case 70: // "bin"
      case 71: // "hex"
      case 72: // "float"
      case 73: // "floarp"
      case 74: // "identifier"
      case 75: // "symbol"
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
      case 66: // "bool"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < bool > (); }
#line 448 "parser.cc"
        break;

      case 67: // "string"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 454 "parser.cc"
        break;

      case 68: // "char"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 460 "parser.cc"
        break;

      case 69: // "int"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 466 "parser.cc"
        break;

      case 70: // "bin"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 472 "parser.cc"
        break;

      case 71: // "hex"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 478 "parser.cc"
        break;

      case 72: // "float"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 484 "parser.cc"
        break;

      case 73: // "floarp"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 490 "parser.cc"
        break;

      case 74: // "identifier"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 496 "parser.cc"
        break;

      case 75: // "symbol"
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 502 "parser.cc"
        break;

      case 78: // exp
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 508 "parser.cc"
        break;

      case 79: // expList
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 514 "parser.cc"
        break;

      case 80: // condList
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 520 "parser.cc"
        break;

      case 81: // constant
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 526 "parser.cc"
        break;

      case 82: // itemList
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 532 "parser.cc"
        break;

      case 83: // nonEmptyItemList
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 538 "parser.cc"
        break;

      case 84: // paramList
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 544 "parser.cc"
        break;

      case 85: // nonEmptyParamList
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 550 "parser.cc"
        break;

      case 86: // program
#line 119 "parser.yy"
                 { yyo << yysym.value.template as < json > (); }
#line 556 "parser.cc"
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
      case 66: // "bool"
        yylhs.value.emplace< bool > ();
        break;

      case 78: // exp
      case 79: // expList
      case 80: // condList
      case 81: // constant
      case 82: // itemList
      case 83: // nonEmptyItemList
      case 84: // paramList
      case 85: // nonEmptyParamList
      case 86: // program
        yylhs.value.emplace< json > ();
        break;

      case 67: // "string"
      case 68: // "char"
      case 69: // "int"
      case 70: // "bin"
      case 71: // "hex"
      case 72: // "float"
      case 73: // "floarp"
      case 74: // "identifier"
      case 75: // "symbol"
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
#line 125 "parser.yy"
             { json j = {{"exp_list", yystack_[0].value.as < json > ()}};
                         drv.result = {"program", j}; }
#line 826 "parser.cc"
    break;

  case 3:
#line 127 "parser.yy"
             { drv.result = {"empty_program", {}}; }
#line 832 "parser.cc"
    break;

  case 4:
#line 132 "parser.yy"
                   { json j = {{"exp", yystack_[0].value.as < json > ()}};
                     yylhs.value.as < json > () = {"one_exp_exp_list", j}; }
#line 839 "parser.cc"
    break;

  case 5:
#line 134 "parser.yy"
                   { json j = {{"exp", yystack_[1].value.as < json > ()}, {"exp_list", yystack_[0].value.as < json > ()}};
                     yylhs.value.as < json > () = {"mul_exp_exp_list", j}; }
#line 846 "parser.cc"
    break;

  case 6:
#line 140 "parser.yy"
                     { json j = {{"exp_list", yystack_[1].value.as < json > ()}};
                       yylhs.value.as < json > () = {"scope_exp", j}; }
#line 853 "parser.cc"
    break;

  case 7:
#line 142 "parser.yy"
                     { yylhs.value.as < json > () = yystack_[1].value.as < json > (); }
#line 859 "parser.cc"
    break;

  case 8:
#line 144 "parser.yy"
                     { json j = {{"var", yystack_[0].value.as < std::string > ()}};
                       yylhs.value.as < json > () = {"def_exp", j}; }
#line 866 "parser.cc"
    break;

  case 9:
#line 146 "parser.yy"
                           { json j = {{"var", yystack_[2].value.as < std::string > ()}, {"exp", yystack_[0].value.as < json > ()}};
                             yylhs.value.as < json > () = {"assign_exp", j}; }
#line 873 "parser.cc"
    break;

  case 10:
#line 148 "parser.yy"
                                        { json j = {{"param_list", yystack_[3].value.as < json > ()}, {"exp", yystack_[0].value.as < json > ()}};
                                          yylhs.value.as < json > () = {"mul_assign_exp", j}; }
#line 880 "parser.cc"
    break;

  case 11:
#line 150 "parser.yy"
                               { json assign_node = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()}, 
                                                                    {"exp", yystack_[0].value.as < json > ()}}};
                                 json def_node = {"def_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                              {"exp", yystack_[0].value.as < json > ()}}};
                                 yylhs.value.as < json > () = {"mul_exp_exp_list", {{"exp", def_node}, 
                                                            {"exp_list", {"one_exp_exp_list", {{"exp", assign_node}}}}}}; }
#line 891 "parser.cc"
    break;

  case 12:
#line 156 "parser.yy"
                                { yylhs.value.as < json > () = {"cond_exp", {{"cond_list", yystack_[1].value.as < json > ()}}}; }
#line 897 "parser.cc"
    break;

  case 13:
#line 157 "parser.yy"
                                { yylhs.value.as < json > () = {"cond_else_exp", {{"cond_list", yystack_[3].value.as < json > ()}, {"exp", yystack_[1].value.as < json > ()}}}; }
#line 903 "parser.cc"
    break;

  case 14:
#line 158 "parser.yy"
                                { yylhs.value.as < json > () = {"print_exp", {{"exp", yystack_[1].value.as < json > ()}}}; }
#line 909 "parser.cc"
    break;

  case 15:
#line 159 "parser.yy"
                                { yylhs.value.as < json > () = {"scan_exp", {}}; }
#line 915 "parser.cc"
    break;

  case 16:
#line 160 "parser.yy"
                                { yylhs.value.as < json > () = {"error_exp", {{"exp", yystack_[1].value.as < json > ()}}}; }
#line 921 "parser.cc"
    break;

  case 17:
#line 161 "parser.yy"
                                { yylhs.value.as < json > () = {"valtype_exp", {{"exp", yystack_[1].value.as < json > ()}}}; }
#line 927 "parser.cc"
    break;

  case 18:
#line 162 "parser.yy"
                                { yylhs.value.as < json > () = {"gensym_exp", {}}; }
#line 933 "parser.cc"
    break;

  case 19:
#line 163 "parser.yy"
                                { yylhs.value.as < json > () = {"same_exp", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 939 "parser.cc"
    break;

  case 20:
#line 165 "parser.yy"
                                { yylhs.value.as < json > () = yystack_[0].value.as < json > (); }
#line 945 "parser.cc"
    break;

  case 21:
#line 166 "parser.yy"
                                { yylhs.value.as < json > () = {"var_exp", {{"exp", yystack_[0].value.as < std::string > ()}}}; }
#line 951 "parser.cc"
    break;

  case 22:
#line 168 "parser.yy"
                                           { yylhs.value.as < json > () = {"proc_exp", {{"param_list", yystack_[4].value.as < json > ()}, {"exp_list", yystack_[1].value.as < json > ()}}}; }
#line 957 "parser.cc"
    break;

  case 23:
#line 169 "parser.yy"
                                           { yylhs.value.as < json > () = {"call_exp", {{"exp", yystack_[2].value.as < json > ()}, {"item_list", yystack_[1].value.as < json > ()}}}; }
#line 963 "parser.cc"
    break;

  case 24:
#line 170 "parser.yy"
                                           { yylhs.value.as < json > () = {"splice_call_exp", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[2].value.as < json > ()}}}; }
#line 969 "parser.cc"
    break;

  case 25:
#line 172 "parser.yy"
                                           { yylhs.value.as < json > () = {"array_const_exp", {{"item_list", yystack_[1].value.as < json > ()}}}; }
#line 975 "parser.cc"
    break;

  case 26:
#line 173 "parser.yy"
                                           { yylhs.value.as < json > () = {"make_array_exp", {{"exp", yystack_[1].value.as < json > ()}}}; }
#line 981 "parser.cc"
    break;

  case 27:
#line 174 "parser.yy"
                                           { yylhs.value.as < json > () = {"array_get_exp", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 987 "parser.cc"
    break;

  case 28:
#line 175 "parser.yy"
                                           { yylhs.value.as < json > () = {"array_set_exp", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[2].value.as < json > ()}, {"exp3", yystack_[1].value.as < json > ()}}}; }
#line 993 "parser.cc"
    break;

  case 29:
#line 176 "parser.yy"
                                           { yylhs.value.as < json > () = {"size_of_exp", {{"exp", yystack_[1].value.as < json > ()}}}; }
#line 999 "parser.cc"
    break;

  case 30:
#line 178 "parser.yy"
                            { yylhs.value.as < json > () = {"plus_k", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1005 "parser.cc"
    break;

  case 31:
#line 179 "parser.yy"
                            { yylhs.value.as < json > () = {"min_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1011 "parser.cc"
    break;

  case 32:
#line 180 "parser.yy"
                            { yylhs.value.as < json > () = {"mul_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1017 "parser.cc"
    break;

  case 33:
#line 181 "parser.yy"
                            { yylhs.value.as < json > () = {"div_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1023 "parser.cc"
    break;

  case 34:
#line 182 "parser.yy"
                            { yylhs.value.as < json > () = {"rem_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1029 "parser.cc"
    break;

  case 35:
#line 183 "parser.yy"
                            { yylhs.value.as < json > () = {"eq_k"  , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1035 "parser.cc"
    break;

  case 36:
#line 184 "parser.yy"
                            { yylhs.value.as < json > () = {"neq_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1041 "parser.cc"
    break;

  case 37:
#line 185 "parser.yy"
                            { yylhs.value.as < json > () = {"lot_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1047 "parser.cc"
    break;

  case 38:
#line 186 "parser.yy"
                            { yylhs.value.as < json > () = {"grt_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1053 "parser.cc"
    break;

  case 39:
#line 187 "parser.yy"
                            { yylhs.value.as < json > () = {"leq_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1059 "parser.cc"
    break;

  case 40:
#line 188 "parser.yy"
                            { yylhs.value.as < json > () = {"geq_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1065 "parser.cc"
    break;

  case 41:
#line 189 "parser.yy"
                            { yylhs.value.as < json > () = {"and_k" , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1071 "parser.cc"
    break;

  case 42:
#line 190 "parser.yy"
                            { yylhs.value.as < json > () = {"or_k"  , {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}}}; }
#line 1077 "parser.cc"
    break;

  case 43:
#line 192 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_plus"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1085 "parser.cc"
    break;

  case 44:
#line 195 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_min"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1093 "parser.cc"
    break;

  case 45:
#line 198 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_mul"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1101 "parser.cc"
    break;

  case 46:
#line 201 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_div"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1109 "parser.cc"
    break;

  case 47:
#line 204 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_rem"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1117 "parser.cc"
    break;

  case 48:
#line 207 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_eq"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1125 "parser.cc"
    break;

  case 49:
#line 210 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_neq"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1133 "parser.cc"
    break;

  case 50:
#line 213 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_lt"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1141 "parser.cc"
    break;

  case 51:
#line 216 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_gt"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1149 "parser.cc"
    break;

  case 52:
#line 219 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_leq"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1157 "parser.cc"
    break;

  case 53:
#line 222 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_geq"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1165 "parser.cc"
    break;

  case 54:
#line 225 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_and"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1173 "parser.cc"
    break;

  case 55:
#line 228 "parser.yy"
                      { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_or"}}},
                                           {"mul_exp_item_list", {{"exp", yystack_[2].value.as < json > ()},
                                                                  {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}}; }
#line 1181 "parser.cc"
    break;

  case 56:
#line 232 "parser.yy"
                               { json op_node = {"call_exp", {{"var_exp", {{"var", "sw_plus"}}},
                                                              {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", yystack_[2].value.as < std::string > ()}}}},
                                                                                     {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}};
                                 yylhs.value.as < json > () = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                      {"exp", op_node}}}; }
#line 1191 "parser.cc"
    break;

  case 57:
#line 237 "parser.yy"
                               { json op_node = {"call_exp", {{"var_exp", {{"var", "sw_min"}}},
                                                              {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", yystack_[2].value.as < std::string > ()}}}},
                                                                                     {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}};
                                 yylhs.value.as < json > () = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                      {"exp", op_node}}}; }
#line 1201 "parser.cc"
    break;

  case 58:
#line 242 "parser.yy"
                               { json op_node = {"call_exp", {{"var_exp", {{"var", "sw_mul"}}},
                                                              {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", yystack_[2].value.as < std::string > ()}}}},
                                                                                     {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}};
                                 yylhs.value.as < json > () = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                      {"exp", op_node}}}; }
#line 1211 "parser.cc"
    break;

  case 59:
#line 247 "parser.yy"
                               { json op_node = {"call_exp", {{"var_exp", {{"var", "sw_div"}}},
                                                              {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", yystack_[2].value.as < std::string > ()}}}},
                                                                                     {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}};
                                 yylhs.value.as < json > () = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                      {"exp", op_node}}}; }
#line 1221 "parser.cc"
    break;

  case 60:
#line 252 "parser.yy"
                               { json op_node = {"call_exp", {{"var_exp", {{"var", "sw_div"}}},
                                                              {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", yystack_[2].value.as < std::string > ()}}}},
                                                                                     {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}};
                                 yylhs.value.as < json > () = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                      {"exp", op_node}}}; }
#line 1231 "parser.cc"
    break;

  case 61:
#line 257 "parser.yy"
                               { json op_node = {"call_exp", {{"var_exp", {{"var", "sw_and"}}},
                                                              {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", yystack_[2].value.as < std::string > ()}}}},
                                                                                     {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}};
                                 yylhs.value.as < json > () = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                      {"exp", op_node}}}; }
#line 1241 "parser.cc"
    break;

  case 62:
#line 262 "parser.yy"
                               { json op_node = {"call_exp", {{"var_exp", {{"var", "sw_or"}}},
                                                              {"mul_exp_item_list", {{"exp", {"var_exp", {{"var", yystack_[2].value.as < std::string > ()}}}},
                                                                                     {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}}};
                                 yylhs.value.as < json > () = {"assign_exp", {{"var", yystack_[2].value.as < std::string > ()},
                                                      {"exp", op_node}}}; }
#line 1251 "parser.cc"
    break;

  case 63:
#line 268 "parser.yy"
                         { yylhs.value.as < json > () = {"umin_k", {{"exp", yystack_[1].value.as < json > ()}}}; }
#line 1257 "parser.cc"
    break;

  case 64:
#line 269 "parser.yy"
                         { yylhs.value.as < json > () = {"not_k",  {{"exp", yystack_[1].value.as < json > ()}}}; }
#line 1263 "parser.cc"
    break;

  case 65:
#line 271 "parser.yy"
                                 { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_umin"}}},
                                                      {"one_exp_item_list", {{"exp", yystack_[1].value.as < json > ()}}}}}; }
#line 1270 "parser.cc"
    break;

  case 66:
#line 273 "parser.yy"
                                 { yylhs.value.as < json > () = {"call_exp", {{"var_exp", {{"var", "sw_not"}}},
                                                      {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}}}; }
#line 1277 "parser.cc"
    break;

  case 67:
#line 276 "parser.yy"
                                 { yylhs.value.as < json > () = {"run_exp", {{"exp", yystack_[1].value.as < json > ()}}}; }
#line 1283 "parser.cc"
    break;

  case 68:
#line 280 "parser.yy"
                           { yylhs.value.as < json > () = {"one_cond_cond_list", {{"exp1", yystack_[2].value.as < json > ()}, {"exp2", yystack_[0].value.as < json > ()}}}; }
#line 1289 "parser.cc"
    break;

  case 69:
#line 281 "parser.yy"
                           { yylhs.value.as < json > () = {"mul_cond_cond_list", {{"exp1", yystack_[3].value.as < json > ()}, {"exp2", yystack_[1].value.as < json > ()}, {"cond_list", yystack_[0].value.as < json > ()}}}; }
#line 1295 "parser.cc"
    break;

  case 70:
#line 285 "parser.yy"
                { yylhs.value.as < json > () = {"int_exp", {{"int_str", yystack_[0].value.as < std::string > ()}}}; }
#line 1301 "parser.cc"
    break;

  case 71:
#line 286 "parser.yy"
                { yylhs.value.as < json > () = {"int_exp", {{"bin_str", yystack_[0].value.as < std::string > ()}}}; }
#line 1307 "parser.cc"
    break;

  case 72:
#line 287 "parser.yy"
                { yylhs.value.as < json > () = {"hex_exp", {{"hex_str", yystack_[0].value.as < std::string > ()}}}; }
#line 1313 "parser.cc"
    break;

  case 73:
#line 289 "parser.yy"
                { yylhs.value.as < json > () = {"float_exp", {{"float_str", yystack_[0].value.as < std::string > ()}}}; }
#line 1319 "parser.cc"
    break;

  case 74:
#line 290 "parser.yy"
                { yylhs.value.as < json > () = {"floatp_exp", {{"floatp_str", yystack_[0].value.as < std::string > ()}}}; }
#line 1325 "parser.cc"
    break;

  case 75:
#line 292 "parser.yy"
                { yylhs.value.as < json > () = {"bool_exp", {{"bool", yystack_[0].value.as < bool > ()}}}; }
#line 1331 "parser.cc"
    break;

  case 76:
#line 293 "parser.yy"
                { yylhs.value.as < json > () = {"string_exp", {{"string_str", yystack_[0].value.as < std::string > ()}}}; }
#line 1337 "parser.cc"
    break;

  case 77:
#line 294 "parser.yy"
                { yylhs.value.as < json > () = {"char_exp", {{"char_str", yystack_[0].value.as < std::string > ()}}}; }
#line 1343 "parser.cc"
    break;

  case 78:
#line 295 "parser.yy"
                { yylhs.value.as < json > () = {"symbol_exp", {{"symbol_str", yystack_[0].value.as < std::string > ()}}}; }
#line 1349 "parser.cc"
    break;

  case 79:
#line 297 "parser.yy"
                { yylhs.value.as < json > () = {"null_exp", {}}; }
#line 1355 "parser.cc"
    break;

  case 80:
#line 302 "parser.yy"
                       { yylhs.value.as < json > () = yystack_[0].value.as < json > (); }
#line 1361 "parser.cc"
    break;

  case 81:
#line 303 "parser.yy"
                       { yylhs.value.as < json > () = {"empty_param_list", {}}; }
#line 1367 "parser.cc"
    break;

  case 82:
#line 307 "parser.yy"
                                      { yylhs.value.as < json > () = {"one_var_param_list", {{"var", yystack_[0].value.as < std::string > ()}}}; }
#line 1373 "parser.cc"
    break;

  case 83:
#line 308 "parser.yy"
                                      { yylhs.value.as < json > () = {"mul_var_param_list", {{"var", yystack_[1].value.as < std::string > ()}, {"non_empty_param_list", yystack_[0].value.as < json > ()}}}; }
#line 1379 "parser.cc"
    break;

  case 84:
#line 312 "parser.yy"
                     { yylhs.value.as < json > () = yystack_[0].value.as < json > (); }
#line 1385 "parser.cc"
    break;

  case 85:
#line 313 "parser.yy"
                     { yylhs.value.as < json > () = {"empty_item_list", {}}; }
#line 1391 "parser.cc"
    break;

  case 86:
#line 317 "parser.yy"
                           { yylhs.value.as < json > () = {"one_exp_item_list", {{"exp", yystack_[0].value.as < json > ()}}}; }
#line 1397 "parser.cc"
    break;

  case 87:
#line 318 "parser.yy"
                           { yylhs.value.as < json > () = {"mul_exp_item_list", {{"exp", yystack_[1].value.as < json > ()}, {"non_empty_item_list", yystack_[0].value.as < json > ()}}}; }
#line 1403 "parser.cc"
    break;


#line 1407 "parser.cc"

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
     401,   -72,  -102,   360,   150,   401,   -41,   401,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,     8,  -102,   328,  -102,
    -102,    17,   -43,   -56,   401,   223,   -10,   -45,   401,   401,
     401,   401,   401,    -7,   401,   401,   401,   401,    12,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   328,    11,   -56,   152,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
    -102,  -102,   401,   -56,    37,  -102,   432,   401,  -102,  -102,
     401,   328,   328,   328,   328,   448,  -102,   473,   508,   533,
     549,  -102,   328,   568,   328,   328,   328,   328,   609,   328,
     328,   328,   328,   328,   328,   328,   628,   328,    36,  -102,
     255,    38,  -102,    41,  1006,  1006,  1006,  1006,  1006,  1006,
    1006,  1006,   -44,   -44,   -44,   -44,   -29,   -29,  -102,  -102,
    -102,   -44,   -44,   152,   152,  1006,  -102,    40,  -102,   328,
     646,   669,   689,   706,   730,  -102,  -102,  -102,  -102,  -102,
     749,  -102,   766,   328,   790,   809,  -102,   826,   850,   869,
     886,   910,   929,   946,  -102,  -102,  -102,    44,  -102,    39,
     401,   970,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
     989,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,   401,  1006,  -102,    48,  -102
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,    79,     0,     0,     0,     0,     0,    75,    76,
      77,    70,    71,    72,    73,    74,    21,    78,     4,     2,
      20,     0,     8,    81,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    85,     0,    81,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     1,     0,    82,     0,    80,     0,     0,     7,    12,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,    84,
      86,     0,     6,     0,    56,    57,    58,    59,    60,    61,
      62,     9,    53,    52,    48,    49,    43,    44,    45,    46,
      47,    50,    51,    54,    55,    11,    83,     0,    65,    68,
       0,     0,     0,     0,     0,    14,    29,    67,    16,    17,
       0,    26,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,    64,    87,    25,     0,    23,     0,
       0,     0,    69,    13,    40,    39,    35,    36,    19,    27,
       0,    30,    31,    32,    33,    34,    37,    38,    41,    42,
      24,     0,    10,    28,     0,    22
  };

  const signed char
  parser::yypgoto_[] =
  {
    -102,     3,     0,   -60,  -102,    45,  -101,    42,    18,  -102
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    18,    80,    27,    20,   118,   119,    84,    85,    21
  };

  const unsigned char
  parser::yytable_[] =
  {
      19,    89,    22,    26,    57,    56,    25,    55,    82,    90,
      58,    71,    72,    73,    74,    75,   175,    81,    83,   175,
      59,    60,    61,    62,    63,    64,    65,    86,    73,    74,
      75,    91,    92,    93,    94,    95,    88,    97,    98,    99,
     100,    96,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   120,    66,
     101,   122,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   147,   176,   145,   178,   179,   201,   182,
     149,   180,   200,   150,   151,   152,   153,   154,   205,   123,
     121,   146,     0,     0,     0,   160,     0,   162,   163,   164,
     165,     0,   167,   168,   169,   170,   171,   172,   173,     0,
     117,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   181,     1,     0,    28,    67,    29,    68,    30,
      69,    31,    70,     0,     0,     0,   190,     0,     0,    32,
      33,    34,     2,    35,    36,    37,    38,    39,    40,    41,
      42,     0,     0,   202,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     3,     0,     4,     0,     5,
       0,   204,     6,     0,     0,     0,     0,    71,    72,    73,
      74,    75,    76,    77,     7,    54,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     1,    67,     0,    68,
       0,    69,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    67,
       0,    68,     0,    69,     0,    70,     0,     0,     3,     0,
       4,     0,     5,     0,     0,     6,    87,     2,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     7,   177,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       3,     0,     4,     0,     5,     0,     0,     6,     0,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     7,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     1,    67,     0,    68,     0,    69,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     4,     0,     5,     0,     0,
       6,     0,     2,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     7,    23,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     1,     3,     0,     4,     0,     5,
       0,     0,     6,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,     2,     7,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    67,     0,    68,     0,
      69,     0,    70,     0,     0,     0,     3,     0,     4,     0,
       5,     0,    67,     6,    68,     0,    69,     0,    70,     0,
       0,     0,     0,     0,     0,     7,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    67,   148,    68,
       0,    69,     0,    70,     0,     0,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,   155,     0,     0,     0,
       0,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    67,     0,    68,     0,    69,     0,    70,     0,
       0,   156,     0,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    67,     0,    68,
       0,    69,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    68,   157,    69,     0,    70,
       0,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    67,     0,    68,     0,    69,     0,    70,     0,
       0,   158,     0,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,   159,     0,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    67,     0,    68,   161,    69,     0,    70,
       0,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    67,     0,    68,     0,    69,     0,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,    68,     0,    69,     0,    70,   166,     0,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    67,     0,    68,   174,    69,     0,    70,
       0,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78,    79,   183,    67,     0,    68,     0,    69,     0,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      67,     0,    68,     0,    69,     0,    70,   184,     0,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    67,     0,    68,   185,    69,     0,
      70,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    67,   186,    68,     0,    69,     0,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      67,     0,    68,     0,    69,     0,    70,     0,   187,     0,
       0,     0,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    67,     0,    68,   188,    69,     0,
      70,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    67,   189,    68,     0,    69,     0,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      67,     0,    68,     0,    69,     0,    70,     0,   191,     0,
       0,     0,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    67,     0,    68,   192,    69,     0,
      70,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    67,   193,    68,     0,    69,     0,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      67,     0,    68,     0,    69,     0,    70,     0,   194,     0,
       0,     0,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    67,     0,    68,   195,    69,     0,
      70,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    67,   196,    68,     0,    69,     0,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      67,     0,    68,     0,    69,     0,    70,     0,   197,     0,
       0,     0,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    67,     0,    68,   198,    69,     0,
      70,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    67,   199,    68,     0,    69,     0,    70,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      67,     0,    68,     0,    69,     0,    70,     0,     0,     0,
       0,     0,     0,    87,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79
  };

  const short
  parser::yycheck_[] =
  {
       0,    46,    74,     3,    45,     5,     3,     4,    51,    54,
       7,    55,    56,    57,    58,    59,   117,     0,    74,   120,
      12,    13,    14,    15,    16,    17,    18,    24,    57,    58,
      59,    28,    29,    30,    31,    32,    46,    34,    35,    36,
      37,    48,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    51,
      48,    50,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    46,    48,    82,    48,    46,    49,   149,
      87,    51,    48,    90,    91,    92,    93,    94,    50,    57,
      55,    83,    -1,    -1,    -1,   102,    -1,   104,   105,   106,
     107,    -1,   109,   110,   111,   112,   113,   114,   115,    -1,
     117,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,     3,    -1,     5,     4,     7,     6,     9,
       8,    11,    10,    -1,    -1,    -1,   163,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,   180,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    47,    -1,    49,
      -1,   201,    52,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     3,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,     6,    -1,     8,    -1,    10,    -1,    -1,    45,    -1,
      47,    -1,    49,    -1,    -1,    52,    53,    22,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    33,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    -1,
      45,    -1,    47,    -1,    49,    -1,    -1,    52,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     3,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    47,    -1,    49,    -1,    -1,
      52,    -1,    22,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    33,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     3,    45,    -1,    47,    -1,    49,
      -1,    -1,    52,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     4,    -1,     6,    -1,
       8,    -1,    10,    -1,    -1,    -1,    45,    -1,    47,    -1,
      49,    -1,     4,    52,     6,    -1,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     4,    46,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     4,    -1,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,    -1,     6,    48,     8,    -1,    10,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     4,    -1,     6,    48,     8,    -1,    10,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     4,    -1,     6,    -1,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,    -1,     6,    -1,     8,    -1,    10,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     4,    -1,     6,    48,     8,    -1,    10,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    46,     4,    -1,     6,    -1,     8,    -1,    10,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       4,    -1,     6,    -1,     8,    -1,    10,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,     4,    -1,     6,    48,     8,    -1,
      10,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     4,    48,     6,    -1,     8,    -1,    10,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       4,    -1,     6,    -1,     8,    -1,    10,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     4,    -1,     6,    48,     8,    -1,
      10,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     4,    48,     6,    -1,     8,    -1,    10,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       4,    -1,     6,    -1,     8,    -1,    10,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     4,    -1,     6,    48,     8,    -1,
      10,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     4,    48,     6,    -1,     8,    -1,    10,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       4,    -1,     6,    -1,     8,    -1,    10,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     4,    -1,     6,    48,     8,    -1,
      10,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     4,    48,     6,    -1,     8,    -1,    10,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       4,    -1,     6,    -1,     8,    -1,    10,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     4,    -1,     6,    48,     8,    -1,
      10,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     4,    48,     6,    -1,     8,    -1,    10,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       4,    -1,     6,    -1,     8,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    22,    45,    47,    49,    52,    64,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    78,    79,
      81,    86,    74,    33,    56,    78,    79,    80,     5,     7,
       9,    11,    19,    20,    21,    23,    24,    25,    26,    27,
      28,    29,    30,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    65,    78,    79,    45,    78,    12,
      13,    14,    15,    16,    17,    18,    51,     4,     6,     8,
      10,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      79,     0,    51,    74,    84,    85,    78,    53,    46,    46,
      54,    78,    78,    78,    78,    78,    48,    78,    78,    78,
      78,    48,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    82,    83,
      78,    82,    50,    84,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    85,    46,    46,    78,
      78,    78,    78,    78,    78,    48,    48,    48,    48,    48,
      78,    48,    78,    78,    78,    78,    48,    78,    78,    78,
      78,    78,    78,    78,    48,    83,    48,    33,    48,    46,
      51,    78,    80,    46,    48,    48,    48,    48,    48,    48,
      78,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    78,    48,    79,    50
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    77,    86,    86,    79,    79,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      84,    84,    85,    85,    82,    82,    83,    83
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     1,     2,     3,     3,     2,     3,
       6,     4,     3,     5,     4,     3,     4,     4,     3,     5,
       1,     1,     7,     4,     5,     4,     4,     5,     6,     4,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     4,     2,     4,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     2,     1,     0,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"def\"", "\">=\"",
  "\"__geq__\"", "\"<=\"", "\"__leq__\"", "\"==\"", "\"__eq__\"", "\"!=\"",
  "\"__neq__\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"",
  "\"&=\"", "\"|=\"", "\"print\"", "\"scan\"", "\"__sizeof__\"",
  "\"null\"", "\"run\"", "\"error\"", "\"__valuetype__\"",
  "\"__gensym__\"", "\"__same__\"", "\"__make_array__\"",
  "\"__array_get__\"", "\"__array_set__\"", "\"__string_get__\"",
  "\"__string_set__\"", "\"...\"", "\"__plus__\"", "\"__min__\"",
  "\"__umin__\"", "\"__mul__\"", "\"__div__\"", "\"__rem__\"",
  "\"__lot__\"", "\"__grt__\"", "\"__and__\"", "\"__or__\"", "\"__not__\"",
  "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\"=\"", "\"@\"",
  "\"?\"", "\":\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\"<\"",
  "\">\"", "\"&\"", "\"|\"", "\"!\"", "\"#\"", "\"bool\"", "\"string\"",
  "\"char\"", "\"int\"", "\"bin\"", "\"hex\"", "\"float\"", "\"floarp\"",
  "\"identifier\"", "\"symbol\"", "UMIN", "$accept", "exp", "expList",
  "condList", "constant", "itemList", "nonEmptyItemList", "paramList",
  "nonEmptyParamList", "program", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   125,   125,   127,   132,   134,   140,   142,   144,   146,
     148,   150,   156,   157,   158,   159,   160,   161,   162,   163,
     165,   166,   168,   169,   170,   172,   173,   174,   175,   176,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   192,   195,   198,   201,   204,   207,   210,
     213,   216,   219,   222,   225,   228,   232,   237,   242,   247,
     252,   257,   262,   268,   269,   271,   273,   276,   280,   281,
     285,   286,   287,   289,   290,   292,   293,   294,   295,   297,
     302,   303,   307,   308,   312,   313,   317,   318
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
#line 2096 "parser.cc"

#line 322 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
