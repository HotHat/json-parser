// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   json_yylex

// First part of user prologue.

#include <stdio.h>
#include "json.h"
#include "json_parser.h"



#include "json_parser.tab.h"


// Unqualified %code blocks.

static int json_yylex(Json::JsonParser::semantic_type *value, json_parser *parser);
static void json_yyerror(json_parser *parser, char const *msg);




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



// Enable debugging if requested.
#if JSON_YYDEBUG

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
      yy_stack_print_ ();                \
  } while (false)

#else // !JSON_YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !JSON_YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace Json {

  /// Build a parser object.
  JsonParser::JsonParser (json_parser *parser_yyarg)
#if JSON_YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      parser (parser_yyarg)
  {}

  JsonParser::~JsonParser ()
  {}

  JsonParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  JsonParser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  JsonParser::symbol_kind_type
  JsonParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  JsonParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  JsonParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  JsonParser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  JsonParser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  JsonParser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  JsonParser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  JsonParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  JsonParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  JsonParser::symbol_kind_type
  JsonParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  JsonParser::symbol_kind_type
  JsonParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  JsonParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  JsonParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  JsonParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  JsonParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  JsonParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  JsonParser::symbol_kind_type
  JsonParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  JsonParser::stack_symbol_type::stack_symbol_type ()
  {}

  JsonParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  JsonParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  JsonParser::stack_symbol_type&
  JsonParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  JsonParser::stack_symbol_type&
  JsonParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  JsonParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if JSON_YYDEBUG
  template <typename Base>
  void
  JsonParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  JsonParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  JsonParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  JsonParser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if JSON_YYDEBUG
  std::ostream&
  JsonParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  JsonParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  JsonParser::debug_level_type
  JsonParser::debug_level () const
  {
    return yydebug_;
  }

  void
  JsonParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // JSON_YYDEBUG

  JsonParser::state_type
  JsonParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  JsonParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  JsonParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  JsonParser::operator() ()
  {
    return parse ();
  }

  int
  JsonParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

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
    YY_STACK_PRINT ();

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
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, parser));
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // json: value JSON_T_EOI
                     { parser->result = *((yylhs.value.value)); YYACCEPT; }
    break;

  case 3: // value: object
    { (yylhs.value.value) = (yystack_[0].value.value); }
    break;

  case 4: // value: array
    { (yylhs.value.value) = (yystack_[0].value.value); }
    break;

  case 5: // value: JSON_T_STRING
                      { (yylhs.value.value) = new JsonValue(*((yystack_[0].value.value)), JSON_STRING); }
    break;

  case 6: // value: JSON_T_ESTRING
                       { (yylhs.value.value) = new JsonValue(*((yystack_[0].value.value)), JSON_STRING); }
    break;

  case 7: // value: JSON_T_INT
                   { (yylhs.value.value) = new JsonValue(*((yystack_[0].value.value)), JSON_INT); }
    break;

  case 8: // value: JSON_T_DOUBLE
                      { (yylhs.value.value) = new JsonValue(*((yystack_[0].value.value)), JSON_DOUBLE); }
    break;

  case 9: // value: JSON_T_NUL
                   { (yylhs.value.value) = new JsonValue(JSON_NULL); }
    break;

  case 10: // value: JSON_T_TRUE
                    { (yylhs.value.value) = new JsonValue(JSON_TRUE); }
    break;

  case 11: // value: JSON_T_FALSE
                     { (yylhs.value.value) = new JsonValue(JSON_FALSE); }
    break;

  case 12: // $@1: %empty
      {
     printf("array start\n");
   }
    break;

  case 13: // array: '[' $@1 elements array_end
                     {
     printf("array end\n");
     (yylhs.value.value) = new JsonValue(*((yystack_[1].value.value)), JSON_ARRAY);
  }
    break;

  case 15: // array_end: '}'
    { printf("array end mismatched!\n"); YYERROR; }
    break;

  case 16: // elements: %empty
           { printf(" empty element\n"); (yylhs.value.value) = new JsonValue(JSON_ARRAY); }
    break;

  case 17: // elements: value
          {
        std::cout << " element value: " << (yystack_[0].value.value)->js_str << std::endl;
        (yylhs.value.value) = new JsonValue(JSON_ARRAY);
        (yylhs.value.value)->js_array.push_back(*((yystack_[0].value.value)));
    }
    break;

  case 18: // elements: elements ',' value
                       { std::cout << " more element value: " << (yystack_[0].value.value)->js_str << std::endl;  (yystack_[2].value.value)->js_array.push_back(*((yystack_[0].value.value))); }
    break;

  case 19: // object: '{' members object_end
                        { printf("not empty object\n"); (yylhs.value.value) = (yystack_[1].value.value); }
    break;

  case 21: // object_end: ']'
        { YYERROR; }
    break;

  case 22: // members: %empty
           { (yylhs.value.value) = new JsonValue(JSON_OBJECT); std::cout << " empty object \n"; }
    break;

  case 23: // members: member
           {
        (yylhs.value.value) = new JsonValue(*((yystack_[0].value.value)), JSON_OBJECT); std::cout << " just one member object \n";
        for (auto s: (yystack_[0].value.value)->js_object) {
           std::cout << s.first << ":" << s.second.js_str << "\n";
        }
    }
    break;

  case 24: // members: members ',' member
                       {
       std::cout << " more element value: " << (yystack_[0].value.value)->js_str << "\n";
       (yystack_[2].value.value)->js_object.insert((yystack_[0].value.value)->js_object.begin(), (yystack_[0].value.value)->js_object.end());
    }
    break;

  case 25: // member: key ':' value
                  {
        (yylhs.value.value)->js_object[(yystack_[2].value.value)->js_str] = *((yystack_[0].value.value));
        std::cout << "object key:" << (yystack_[2].value.value)->js_str << " value:" << (yystack_[0].value.value)->js_str << std::endl;
    }
    break;

  case 26: // key: JSON_T_STRING
                  { (yylhs.value.value) = new JsonValue(*(yystack_[0].value.value));  std::cout << "key:" << (yylhs.value.value)->js_str <<  std::endl;}
    break;

  case 27: // key: JSON_T_ESTRING
        { (yylhs.value.value) = (yystack_[0].value.value); }
    break;



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
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


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
    YY_STACK_PRINT ();
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
  JsonParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if JSON_YYDEBUG || 0
  const char *
  JsonParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if JSON_YYDEBUG || 0





  const signed char JsonParser::yypact_ninf_ = -15;

  const signed char JsonParser::yytable_ninf_ = -1;

  const signed char
  JsonParser::yypact_[] =
  {
      -1,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,     1,
      12,    -9,   -15,   -15,    -1,   -15,   -15,     5,   -15,    -4,
     -15,   -15,   -15,     8,   -15,   -15,     1,   -15,    -1,   -15,
     -15,    -1,   -15,   -15,   -15,   -15
  };

  const signed char
  JsonParser::yydefact_[] =
  {
       0,     9,    10,    11,     7,     8,     5,     6,    12,    22,
       0,     0,     4,     3,    16,    26,    27,     0,    23,     0,
       1,     2,    17,     0,    21,    20,     0,    19,     0,    14,
      15,     0,    13,    24,    25,    18
  };

  const signed char
  JsonParser::yypgoto_[] =
  {
     -15,   -15,   -14,   -15,   -15,   -15,   -15,   -15,   -15,   -15,
     -10,   -15
  };

  const signed char
  JsonParser::yydefgoto_[] =
  {
       0,    10,    11,    12,    14,    32,    23,    13,    27,    17,
      18,    19
  };

  const signed char
  JsonParser::yytable_[] =
  {
      22,    21,     1,     2,     3,     4,     5,     6,     7,    15,
      16,     8,    20,    28,    34,     9,    33,    35,    24,    25,
      26,    29,    30,    31
  };

  const signed char
  JsonParser::yycheck_[] =
  {
      14,    10,     3,     4,     5,     6,     7,     8,     9,     8,
       9,    12,     0,    17,    28,    16,    26,    31,    13,    14,
      15,    13,    14,    15
  };

  const signed char
  JsonParser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    12,    16,
      19,    20,    21,    25,    22,     8,     9,    27,    28,    29,
       0,    10,    20,    24,    13,    14,    15,    26,    17,    13,
      14,    15,    23,    28,    20,    20
  };

  const signed char
  JsonParser::yyr1_[] =
  {
       0,    18,    19,    20,    20,    20,    20,    20,    20,    20,
      20,    20,    22,    21,    23,    23,    24,    24,    24,    25,
      26,    26,    27,    27,    27,    28,    29,    29
  };

  const signed char
  JsonParser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     1,     0,     1,     3,     3,
       1,     1,     0,     1,     3,     3,     1,     1
  };


#if JSON_YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const JsonParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "JSON_T_NUL",
  "JSON_T_TRUE", "JSON_T_FALSE", "JSON_T_INT", "JSON_T_DOUBLE",
  "JSON_T_STRING", "JSON_T_ESTRING", "JSON_T_EOI", "JSON_T_ERROR", "'['",
  "']'", "'}'", "','", "'{'", "':'", "$accept", "json", "value", "array",
  "$@1", "array_end", "elements", "object", "object_end", "members",
  "member", "key", YY_NULLPTR
  };
#endif


#if JSON_YYDEBUG
  const signed char
  JsonParser::yyrline_[] =
  {
       0,    43,    43,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    59,    59,    69,    71,    75,    77,    82,    86,
      91,    93,    97,    98,   104,   111,   118,   119
  };

  void
  JsonParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  JsonParser::yy_reduce_print_ (int yyrule) const
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
#endif // JSON_YYDEBUG

  JsonParser::symbol_kind_type
  JsonParser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    15,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    17,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    12,     2,    13,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    16,     2,    14,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11
    };
    // Last valid token kind.
    const int code_max = 266;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // Json



static int json_yylex(Json::JsonParser::semantic_type *value, json_parser *parser)
{
	int token = json_lexer(&parser->scanner);
	value->value = new JsonValue(*(parser->scanner.val));
	// value->value = parser->scanner.val;
	std::cout << "yylex: " << value->value->js_str << std::endl;
	return token;
}

void Json::JsonParser::error(const std::string& msg)
{
	std::cout << msg << std::endl;
}

