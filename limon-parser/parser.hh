// A Bison parser, made by GNU Bison 3.5.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
// "%code requires" blocks.
#line 9 "parser.yy"

  # include <string>
  # include "json.hpp"

  using json = nlohmann::json;

  class driver;

#line 57 "parser.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 191 "parser.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // "bool"
      char dummy1[sizeof (bool)];

      // exp
      // expList
      // condList
      // condElse
      // constant
      // itemList
      // nonEmptyItemList
      // paramList
      // nonEmptyParamList
      // program
      char dummy2[sizeof (json)];

      // "string"
      // "char"
      // "int"
      // "bin"
      // "hex"
      // "float"
      // "floarp"
      // "identifier"
      // "symbol"
      char dummy3[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_END = 0,
        TOK_DEF = 258,
        TOK_GEQ = 259,
        TOK_GEQ_K = 260,
        TOK_LEQ = 261,
        TOK_LEQ_K = 262,
        TOK_EQ = 263,
        TOK_EQ_K = 264,
        TOK_NEQ = 265,
        TOK_NEQ_K = 266,
        TOK_PLUSEQ = 267,
        TOK_MINEQ = 268,
        TOK_MULEQ = 269,
        TOK_DIVEQ = 270,
        TOK_REMEQ = 271,
        TOK_ANDEQ = 272,
        TOK_OREQ = 273,
        TOK_PRINT = 274,
        TOK_SHOW = 275,
        TOK_SCAN = 276,
        TOK_SIZEOF = 277,
        TOK_NULLTOK = 278,
        TOK_RUN = 279,
        TOK_TRY = 280,
        TOK_CATCH = 281,
        TOK_RAISE = 282,
        TOK_CONVERT = 283,
        TOK_VALTYPE = 284,
        TOK_GENSYM = 285,
        TOK_SAME = 286,
        TOK_MAKEARR = 287,
        TOK_ARRGET = 288,
        TOK_ARRSET = 289,
        TOK_STRGET = 290,
        TOK_STRSET = 291,
        TOK_THREEDOTS = 292,
        TOK_PLUS_K = 293,
        TOK_MIN_K = 294,
        TOK_UMIN_K = 295,
        TOK_MUL_K = 296,
        TOK_DIV_K = 297,
        TOK_REM_K = 298,
        TOK_LOT_K = 299,
        TOK_GRT_K = 300,
        TOK_AND_K = 301,
        TOK_OR_K = 302,
        TOK_NOT_K = 303,
        TOK_LPAREN = 304,
        TOK_RPAREN = 305,
        TOK_LBRACK = 306,
        TOK_RBRACK = 307,
        TOK_LBRACE = 308,
        TOK_RBRACE = 309,
        TOK_ASSIGN = 310,
        TOK_AT = 311,
        TOK_QMARK = 312,
        TOK_COLON = 313,
        TOK_PLUS = 314,
        TOK_MIN = 315,
        TOK_STAR = 316,
        TOK_DIV = 317,
        TOK_PERCENT = 318,
        TOK_LT = 319,
        TOK_GT = 320,
        TOK_AND = 321,
        TOK_OR = 322,
        TOK_NOT = 323,
        TOK_HASH = 324,
        TOK_BOOL = 325,
        TOK_STRING = 326,
        TOK_CHAR = 327,
        TOK_INT = 328,
        TOK_BIN = 329,
        TOK_HEX = 330,
        TOK_FLOAT = 331,
        TOK_FLOATP = 332,
        TOK_IDENTIFIER = 333,
        TOK_SYMBOL = 334,
        TOK_UMIN = 335
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, bool&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, json&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const json& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 70: // "bool"
        value.template destroy< bool > ();
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
        value.template destroy< json > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_END || tok == token::TOK_DEF || tok == token::TOK_GEQ || tok == token::TOK_GEQ_K || tok == token::TOK_LEQ || tok == token::TOK_LEQ_K || tok == token::TOK_EQ || tok == token::TOK_EQ_K || tok == token::TOK_NEQ || tok == token::TOK_NEQ_K || tok == token::TOK_PLUSEQ || tok == token::TOK_MINEQ || tok == token::TOK_MULEQ || tok == token::TOK_DIVEQ || tok == token::TOK_REMEQ || tok == token::TOK_ANDEQ || tok == token::TOK_OREQ || tok == token::TOK_PRINT || tok == token::TOK_SHOW || tok == token::TOK_SCAN || tok == token::TOK_SIZEOF || tok == token::TOK_NULLTOK || tok == token::TOK_RUN || tok == token::TOK_TRY || tok == token::TOK_CATCH || tok == token::TOK_RAISE || tok == token::TOK_CONVERT || tok == token::TOK_VALTYPE || tok == token::TOK_GENSYM || tok == token::TOK_SAME || tok == token::TOK_MAKEARR || tok == token::TOK_ARRGET || tok == token::TOK_ARRSET || tok == token::TOK_STRGET || tok == token::TOK_STRSET || tok == token::TOK_THREEDOTS || tok == token::TOK_PLUS_K || tok == token::TOK_MIN_K || tok == token::TOK_UMIN_K || tok == token::TOK_MUL_K || tok == token::TOK_DIV_K || tok == token::TOK_REM_K || tok == token::TOK_LOT_K || tok == token::TOK_GRT_K || tok == token::TOK_AND_K || tok == token::TOK_OR_K || tok == token::TOK_NOT_K || tok == token::TOK_LPAREN || tok == token::TOK_RPAREN || tok == token::TOK_LBRACK || tok == token::TOK_RBRACK || tok == token::TOK_LBRACE || tok == token::TOK_RBRACE || tok == token::TOK_ASSIGN || tok == token::TOK_AT || tok == token::TOK_QMARK || tok == token::TOK_COLON || tok == token::TOK_PLUS || tok == token::TOK_MIN || tok == token::TOK_STAR || tok == token::TOK_DIV || tok == token::TOK_PERCENT || tok == token::TOK_LT || tok == token::TOK_GT || tok == token::TOK_AND || tok == token::TOK_OR || tok == token::TOK_NOT || tok == token::TOK_HASH || tok == token::TOK_UMIN);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::TOK_END || tok == token::TOK_DEF || tok == token::TOK_GEQ || tok == token::TOK_GEQ_K || tok == token::TOK_LEQ || tok == token::TOK_LEQ_K || tok == token::TOK_EQ || tok == token::TOK_EQ_K || tok == token::TOK_NEQ || tok == token::TOK_NEQ_K || tok == token::TOK_PLUSEQ || tok == token::TOK_MINEQ || tok == token::TOK_MULEQ || tok == token::TOK_DIVEQ || tok == token::TOK_REMEQ || tok == token::TOK_ANDEQ || tok == token::TOK_OREQ || tok == token::TOK_PRINT || tok == token::TOK_SHOW || tok == token::TOK_SCAN || tok == token::TOK_SIZEOF || tok == token::TOK_NULLTOK || tok == token::TOK_RUN || tok == token::TOK_TRY || tok == token::TOK_CATCH || tok == token::TOK_RAISE || tok == token::TOK_CONVERT || tok == token::TOK_VALTYPE || tok == token::TOK_GENSYM || tok == token::TOK_SAME || tok == token::TOK_MAKEARR || tok == token::TOK_ARRGET || tok == token::TOK_ARRSET || tok == token::TOK_STRGET || tok == token::TOK_STRSET || tok == token::TOK_THREEDOTS || tok == token::TOK_PLUS_K || tok == token::TOK_MIN_K || tok == token::TOK_UMIN_K || tok == token::TOK_MUL_K || tok == token::TOK_DIV_K || tok == token::TOK_REM_K || tok == token::TOK_LOT_K || tok == token::TOK_GRT_K || tok == token::TOK_AND_K || tok == token::TOK_OR_K || tok == token::TOK_NOT_K || tok == token::TOK_LPAREN || tok == token::TOK_RPAREN || tok == token::TOK_LBRACK || tok == token::TOK_RBRACK || tok == token::TOK_LBRACE || tok == token::TOK_RBRACE || tok == token::TOK_ASSIGN || tok == token::TOK_AT || tok == token::TOK_QMARK || tok == token::TOK_COLON || tok == token::TOK_PLUS || tok == token::TOK_MIN || tok == token::TOK_STAR || tok == token::TOK_DIV || tok == token::TOK_PERCENT || tok == token::TOK_LT || tok == token::TOK_GT || tok == token::TOK_AND || tok == token::TOK_OR || tok == token::TOK_NOT || tok == token::TOK_HASH || tok == token::TOK_UMIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, bool v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_BOOL);
      }
#else
      symbol_type (int tok, const bool& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_BOOL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::TOK_STRING || tok == token::TOK_CHAR || tok == token::TOK_INT || tok == token::TOK_BIN || tok == token::TOK_HEX || tok == token::TOK_FLOAT || tok == token::TOK_FLOATP || tok == token::TOK_IDENTIFIER || tok == token::TOK_SYMBOL);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::TOK_STRING || tok == token::TOK_CHAR || tok == token::TOK_INT || tok == token::TOK_BIN || tok == token::TOK_HEX || tok == token::TOK_FLOAT || tok == token::TOK_FLOATP || tok == token::TOK_IDENTIFIER || tok == token::TOK_SYMBOL);
      }
#endif
    };

    /// Build a parser object.
    parser (driver& drv_yyarg);
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::TOK_END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::TOK_END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEF (location_type l)
      {
        return symbol_type (token::TOK_DEF, std::move (l));
      }
#else
      static
      symbol_type
      make_DEF (const location_type& l)
      {
        return symbol_type (token::TOK_DEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GEQ (location_type l)
      {
        return symbol_type (token::TOK_GEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_GEQ (const location_type& l)
      {
        return symbol_type (token::TOK_GEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GEQ_K (location_type l)
      {
        return symbol_type (token::TOK_GEQ_K, std::move (l));
      }
#else
      static
      symbol_type
      make_GEQ_K (const location_type& l)
      {
        return symbol_type (token::TOK_GEQ_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEQ (location_type l)
      {
        return symbol_type (token::TOK_LEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_LEQ (const location_type& l)
      {
        return symbol_type (token::TOK_LEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEQ_K (location_type l)
      {
        return symbol_type (token::TOK_LEQ_K, std::move (l));
      }
#else
      static
      symbol_type
      make_LEQ_K (const location_type& l)
      {
        return symbol_type (token::TOK_LEQ_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (location_type l)
      {
        return symbol_type (token::TOK_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const location_type& l)
      {
        return symbol_type (token::TOK_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ_K (location_type l)
      {
        return symbol_type (token::TOK_EQ_K, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ_K (const location_type& l)
      {
        return symbol_type (token::TOK_EQ_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEQ (location_type l)
      {
        return symbol_type (token::TOK_NEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_NEQ (const location_type& l)
      {
        return symbol_type (token::TOK_NEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEQ_K (location_type l)
      {
        return symbol_type (token::TOK_NEQ_K, std::move (l));
      }
#else
      static
      symbol_type
      make_NEQ_K (const location_type& l)
      {
        return symbol_type (token::TOK_NEQ_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUSEQ (location_type l)
      {
        return symbol_type (token::TOK_PLUSEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUSEQ (const location_type& l)
      {
        return symbol_type (token::TOK_PLUSEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINEQ (location_type l)
      {
        return symbol_type (token::TOK_MINEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_MINEQ (const location_type& l)
      {
        return symbol_type (token::TOK_MINEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULEQ (location_type l)
      {
        return symbol_type (token::TOK_MULEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_MULEQ (const location_type& l)
      {
        return symbol_type (token::TOK_MULEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVEQ (location_type l)
      {
        return symbol_type (token::TOK_DIVEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_DIVEQ (const location_type& l)
      {
        return symbol_type (token::TOK_DIVEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REMEQ (location_type l)
      {
        return symbol_type (token::TOK_REMEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_REMEQ (const location_type& l)
      {
        return symbol_type (token::TOK_REMEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANDEQ (location_type l)
      {
        return symbol_type (token::TOK_ANDEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_ANDEQ (const location_type& l)
      {
        return symbol_type (token::TOK_ANDEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OREQ (location_type l)
      {
        return symbol_type (token::TOK_OREQ, std::move (l));
      }
#else
      static
      symbol_type
      make_OREQ (const location_type& l)
      {
        return symbol_type (token::TOK_OREQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINT (location_type l)
      {
        return symbol_type (token::TOK_PRINT, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINT (const location_type& l)
      {
        return symbol_type (token::TOK_PRINT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHOW (location_type l)
      {
        return symbol_type (token::TOK_SHOW, std::move (l));
      }
#else
      static
      symbol_type
      make_SHOW (const location_type& l)
      {
        return symbol_type (token::TOK_SHOW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SCAN (location_type l)
      {
        return symbol_type (token::TOK_SCAN, std::move (l));
      }
#else
      static
      symbol_type
      make_SCAN (const location_type& l)
      {
        return symbol_type (token::TOK_SCAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZEOF (location_type l)
      {
        return symbol_type (token::TOK_SIZEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_SIZEOF (const location_type& l)
      {
        return symbol_type (token::TOK_SIZEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NULLTOK (location_type l)
      {
        return symbol_type (token::TOK_NULLTOK, std::move (l));
      }
#else
      static
      symbol_type
      make_NULLTOK (const location_type& l)
      {
        return symbol_type (token::TOK_NULLTOK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RUN (location_type l)
      {
        return symbol_type (token::TOK_RUN, std::move (l));
      }
#else
      static
      symbol_type
      make_RUN (const location_type& l)
      {
        return symbol_type (token::TOK_RUN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRY (location_type l)
      {
        return symbol_type (token::TOK_TRY, std::move (l));
      }
#else
      static
      symbol_type
      make_TRY (const location_type& l)
      {
        return symbol_type (token::TOK_TRY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CATCH (location_type l)
      {
        return symbol_type (token::TOK_CATCH, std::move (l));
      }
#else
      static
      symbol_type
      make_CATCH (const location_type& l)
      {
        return symbol_type (token::TOK_CATCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RAISE (location_type l)
      {
        return symbol_type (token::TOK_RAISE, std::move (l));
      }
#else
      static
      symbol_type
      make_RAISE (const location_type& l)
      {
        return symbol_type (token::TOK_RAISE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONVERT (location_type l)
      {
        return symbol_type (token::TOK_CONVERT, std::move (l));
      }
#else
      static
      symbol_type
      make_CONVERT (const location_type& l)
      {
        return symbol_type (token::TOK_CONVERT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VALTYPE (location_type l)
      {
        return symbol_type (token::TOK_VALTYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_VALTYPE (const location_type& l)
      {
        return symbol_type (token::TOK_VALTYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GENSYM (location_type l)
      {
        return symbol_type (token::TOK_GENSYM, std::move (l));
      }
#else
      static
      symbol_type
      make_GENSYM (const location_type& l)
      {
        return symbol_type (token::TOK_GENSYM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SAME (location_type l)
      {
        return symbol_type (token::TOK_SAME, std::move (l));
      }
#else
      static
      symbol_type
      make_SAME (const location_type& l)
      {
        return symbol_type (token::TOK_SAME, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAKEARR (location_type l)
      {
        return symbol_type (token::TOK_MAKEARR, std::move (l));
      }
#else
      static
      symbol_type
      make_MAKEARR (const location_type& l)
      {
        return symbol_type (token::TOK_MAKEARR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRGET (location_type l)
      {
        return symbol_type (token::TOK_ARRGET, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRGET (const location_type& l)
      {
        return symbol_type (token::TOK_ARRGET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRSET (location_type l)
      {
        return symbol_type (token::TOK_ARRSET, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRSET (const location_type& l)
      {
        return symbol_type (token::TOK_ARRSET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRGET (location_type l)
      {
        return symbol_type (token::TOK_STRGET, std::move (l));
      }
#else
      static
      symbol_type
      make_STRGET (const location_type& l)
      {
        return symbol_type (token::TOK_STRGET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRSET (location_type l)
      {
        return symbol_type (token::TOK_STRSET, std::move (l));
      }
#else
      static
      symbol_type
      make_STRSET (const location_type& l)
      {
        return symbol_type (token::TOK_STRSET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THREEDOTS (location_type l)
      {
        return symbol_type (token::TOK_THREEDOTS, std::move (l));
      }
#else
      static
      symbol_type
      make_THREEDOTS (const location_type& l)
      {
        return symbol_type (token::TOK_THREEDOTS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS_K (location_type l)
      {
        return symbol_type (token::TOK_PLUS_K, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS_K (const location_type& l)
      {
        return symbol_type (token::TOK_PLUS_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN_K (location_type l)
      {
        return symbol_type (token::TOK_MIN_K, std::move (l));
      }
#else
      static
      symbol_type
      make_MIN_K (const location_type& l)
      {
        return symbol_type (token::TOK_MIN_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMIN_K (location_type l)
      {
        return symbol_type (token::TOK_UMIN_K, std::move (l));
      }
#else
      static
      symbol_type
      make_UMIN_K (const location_type& l)
      {
        return symbol_type (token::TOK_UMIN_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL_K (location_type l)
      {
        return symbol_type (token::TOK_MUL_K, std::move (l));
      }
#else
      static
      symbol_type
      make_MUL_K (const location_type& l)
      {
        return symbol_type (token::TOK_MUL_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_K (location_type l)
      {
        return symbol_type (token::TOK_DIV_K, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV_K (const location_type& l)
      {
        return symbol_type (token::TOK_DIV_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REM_K (location_type l)
      {
        return symbol_type (token::TOK_REM_K, std::move (l));
      }
#else
      static
      symbol_type
      make_REM_K (const location_type& l)
      {
        return symbol_type (token::TOK_REM_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOT_K (location_type l)
      {
        return symbol_type (token::TOK_LOT_K, std::move (l));
      }
#else
      static
      symbol_type
      make_LOT_K (const location_type& l)
      {
        return symbol_type (token::TOK_LOT_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GRT_K (location_type l)
      {
        return symbol_type (token::TOK_GRT_K, std::move (l));
      }
#else
      static
      symbol_type
      make_GRT_K (const location_type& l)
      {
        return symbol_type (token::TOK_GRT_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_K (location_type l)
      {
        return symbol_type (token::TOK_AND_K, std::move (l));
      }
#else
      static
      symbol_type
      make_AND_K (const location_type& l)
      {
        return symbol_type (token::TOK_AND_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_K (location_type l)
      {
        return symbol_type (token::TOK_OR_K, std::move (l));
      }
#else
      static
      symbol_type
      make_OR_K (const location_type& l)
      {
        return symbol_type (token::TOK_OR_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT_K (location_type l)
      {
        return symbol_type (token::TOK_NOT_K, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT_K (const location_type& l)
      {
        return symbol_type (token::TOK_NOT_K, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::TOK_LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::TOK_RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::TOK_RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACK (location_type l)
      {
        return symbol_type (token::TOK_LBRACK, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACK (const location_type& l)
      {
        return symbol_type (token::TOK_LBRACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACK (location_type l)
      {
        return symbol_type (token::TOK_RBRACK, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACK (const location_type& l)
      {
        return symbol_type (token::TOK_RBRACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (location_type l)
      {
        return symbol_type (token::TOK_LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const location_type& l)
      {
        return symbol_type (token::TOK_LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (location_type l)
      {
        return symbol_type (token::TOK_RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const location_type& l)
      {
        return symbol_type (token::TOK_RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::TOK_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::TOK_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT (location_type l)
      {
        return symbol_type (token::TOK_AT, std::move (l));
      }
#else
      static
      symbol_type
      make_AT (const location_type& l)
      {
        return symbol_type (token::TOK_AT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QMARK (location_type l)
      {
        return symbol_type (token::TOK_QMARK, std::move (l));
      }
#else
      static
      symbol_type
      make_QMARK (const location_type& l)
      {
        return symbol_type (token::TOK_QMARK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::TOK_COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::TOK_COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::TOK_PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::TOK_PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN (location_type l)
      {
        return symbol_type (token::TOK_MIN, std::move (l));
      }
#else
      static
      symbol_type
      make_MIN (const location_type& l)
      {
        return symbol_type (token::TOK_MIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::TOK_STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::TOK_STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (location_type l)
      {
        return symbol_type (token::TOK_DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const location_type& l)
      {
        return symbol_type (token::TOK_DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT (location_type l)
      {
        return symbol_type (token::TOK_PERCENT, std::move (l));
      }
#else
      static
      symbol_type
      make_PERCENT (const location_type& l)
      {
        return symbol_type (token::TOK_PERCENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (location_type l)
      {
        return symbol_type (token::TOK_LT, std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const location_type& l)
      {
        return symbol_type (token::TOK_LT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (location_type l)
      {
        return symbol_type (token::TOK_GT, std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const location_type& l)
      {
        return symbol_type (token::TOK_GT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::TOK_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::TOK_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::TOK_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::TOK_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::TOK_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::TOK_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HASH (location_type l)
      {
        return symbol_type (token::TOK_HASH, std::move (l));
      }
#else
      static
      symbol_type
      make_HASH (const location_type& l)
      {
        return symbol_type (token::TOK_HASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (bool v, location_type l)
      {
        return symbol_type (token::TOK_BOOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const bool& v, const location_type& l)
      {
        return symbol_type (token::TOK_BOOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CHAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CHAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_BIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_BIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEX (std::string v, location_type l)
      {
        return symbol_type (token::TOK_HEX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HEX (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_HEX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOATP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FLOATP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOATP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FLOATP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYMBOL (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SYMBOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SYMBOL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SYMBOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMIN (location_type l)
      {
        return symbol_type (token::TOK_UMIN, std::move (l));
      }
#else
      static
      symbol_type
      make_UMIN (const location_type& l)
      {
        return symbol_type (token::TOK_UMIN, l);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 1308,     ///< Last index in yytable_.
      yynnts_ = 11,  ///< Number of nonterminal symbols.
      yyfinal_ = 85, ///< Termination state number.
      yyntokens_ = 81  ///< Number of tokens.
    };


    // User arguments.
    driver& drv;
  };

  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80
    };
    const int user_token_number_max_ = 335;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 70: // "bool"
        value.move< bool > (std::move (that.value));
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
        value.move< json > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 70: // "bool"
        value.copy< bool > (YY_MOVE (that.value));
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
        value.copy< json > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 70: // "bool"
        value.move< bool > (YY_MOVE (s.value));
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
        value.move< json > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

} // yy
#line 2584 "parser.hh"





#endif // !YY_YY_PARSER_HH_INCLUDED
