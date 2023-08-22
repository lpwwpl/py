// A Bison parser, made by GNU Bison 3.8.2.

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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
#define yylex   P_yylex



#include "parser.tab.hpp"


// Unqualified %code blocks.
#line 58 "parser.y"

    #include "translator.hpp"
    #include "ast.h"
    #include <stack>
    
    static int yylex(Language::Parser::semantic_type *yylval, Language::location* loc,Language::Lexer  &lexer);

    extern std::string cur_yytext;
    extern std::stack<std::string> fileNames;
    extern Language::location loc;//ÉùÃ÷Î»ÖÃÊµÀý
    # define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin.line   = YYRHSLOC (Rhs, 1).begin.line;        \
          (Current).begin.column = YYRHSLOC (Rhs, 1).begin.column;      \
          (Current).end.line    = YYRHSLOC (Rhs, N).end.line;         \
          (Current).end.column  = YYRHSLOC (Rhs, N).end.column;       \
          (Current).end.filename = &(fileNames.top());            \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin.line   = (Current).end.line   =              \
            YYRHSLOC (Rhs, 0).end.line;                                \
          (Current).begin.column = (Current).end.column =              \
            YYRHSLOC (Rhs, 0).end.column;                              \
          (Current).end.filename = &(fileNames.top());            \
        }                                                               \
    while (0)


#line 80 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"


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
#if P_YYDEBUG

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

#else // !P_YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !P_YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 15 "parser.y"
namespace Language {
#line 173 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"

  /// Build a parser object.
  Parser::Parser (Lexer  &lexer_yyarg)
#if P_YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}


  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if P_YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if P_YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // P_YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, lexer));
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
  case 2: // program: declaration_list
#line 160 "parser.y"
                     {}
#line 646 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 3: // declaration_list: declaration
#line 164 "parser.y"
                 {(yylhs.value.listNode) = new DeclareListNode((yystack_[0].value.pNode));}
#line 652 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 4: // declaration_list: declaration_list declaration
#line 165 "parser.y"
                                     {(yystack_[1].value.listNode)->push_back((yystack_[0].value.pNode));}
#line 658 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 5: // declaration: function_declaration
#line 169 "parser.y"
                         {(yylhs.value.pNode)=(yystack_[0].value.functionNode);}
#line 664 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 6: // declaration: var_assignment
#line 170 "parser.y"
                    {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 670 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 7: // declaration: Class_declare
#line 171 "parser.y"
                    {(yylhs.value.pNode)=(yystack_[0].value.pNode);}
#line 676 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 8: // Class_declare: CLASS Identifier COLON declaration
#line 176 "parser.y"
                                        { IdentifierNode* id = new IdentifierNode((yystack_[2].value.sval));(yylhs.value.pNode) = new StructDescNode(id, (yystack_[0].value.pNode)); }
#line 682 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 9: // Class_declare: CLASS Identifier LC struct_index RC COLON declaration
#line 178 "parser.y"
                                                           { IdentifierNode* id = new IdentifierNode((yystack_[5].value.sval));(yylhs.value.pNode) = new StructDescNode(id, (yystack_[3].value.pNode),(yystack_[0].value.pNode)); }
#line 688 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 10: // function_declaration: DEF Identifier LC parameter_declaration_list RC COLON block
#line 185 "parser.y"
    {
        (yylhs.value.functionNode) = new FunctionNode(NULL, (yystack_[5].value.sval), (yystack_[3].value.parameterListNode), (yystack_[0].value.statementListNode)); 
    }
#line 696 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 11: // parameter_declaration_list: parameter_declaration
#line 191 "parser.y"
                          { (yylhs.value.parameterListNode) = new ListNode<ParameterNode>((yystack_[0].value.parameterNode)); }
#line 702 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 12: // parameter_declaration_list: parameter_declaration_list COMMA parameter_declaration
#line 192 "parser.y"
                                                             {(yystack_[2].value.parameterListNode)->push_back((yystack_[0].value.parameterNode));}
#line 708 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 13: // parameter_declaration_list: %empty
#line 193 "parser.y"
      {(yylhs.value.parameterListNode) = new ListNode<ParameterNode>();}
#line 714 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 14: // parameter_declaration: var_expression
#line 197 "parser.y"
                   {(yylhs.value.parameterNode) = new ParameterNode((yystack_[0].value.pNode),nullptr);}
#line 720 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 15: // func_call_parameter_list: expression
#line 202 "parser.y"
    {
        (yylhs.value.listNode) = new ListNode<ASTNode>((yystack_[0].value.pNode)); 
    }
#line 728 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 16: // func_call_parameter_list: func_call_parameter_list COMMA expression
#line 206 "parser.y"
        {
        (yystack_[2].value.listNode)->push_back((yystack_[0].value.pNode));   
	}
#line 736 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 17: // block: statement_list
#line 211 "parser.y"
                         { (yylhs.value.statementListNode) = (yystack_[0].value.statementListNode); }
#line 742 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 18: // statement_list: statement
#line 216 "parser.y"
              {(yylhs.value.statementListNode) = new StatementListNode((yystack_[0].value.pNode));}
#line 748 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 19: // statement_list: statement_list statement
#line 217 "parser.y"
                               {(yystack_[1].value.statementListNode)->push_back((yystack_[0].value.pNode));}
#line 754 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 20: // function_call: Identifier LC func_call_parameter_list RC
#line 221 "parser.y"
                                                { (yylhs.value.pNode) = new FunctionCallNode((yystack_[3].value.sval), (yystack_[1].value.listNode));}
#line 760 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 21: // function_call: Identifier LC RC
#line 222 "parser.y"
                         { (yylhs.value.pNode) = new FunctionCallNode((yystack_[2].value.sval), NULL);}
#line 766 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 22: // statement: assignment
#line 226 "parser.y"
                 {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 772 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 23: // statement: if
#line 227 "parser.y"
         { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 778 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 24: // statement: while_loop
#line 228 "parser.y"
                 { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 784 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 25: // statement: for
#line 229 "parser.y"
          { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 790 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 26: // statement: return
#line 230 "parser.y"
              { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 796 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 27: // statement: function_call
#line 231 "parser.y"
                    {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 802 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 28: // statement: BREAK
#line 232 "parser.y"
            {(yylhs.value.pNode) = new BreakNode();}
#line 808 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 29: // statement: CONTINUE
#line 233 "parser.y"
                {(yylhs.value.pNode) = new ContinueNode();}
#line 814 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 30: // statement: PASS
#line 234 "parser.y"
           {(yylhs.value.pNode) = new PassNode();}
#line 820 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 31: // return: RETURN
#line 238 "parser.y"
        {(yylhs.value.pNode) = new ReturnNode(NULL); }
#line 826 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 32: // return: RETURN expression
#line 239 "parser.y"
                       {(yylhs.value.pNode) = new ReturnNode((yystack_[0].value.pNode)); }
#line 832 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 33: // while_loop: WHILE expression COLON block
#line 243 "parser.y"
                                               { (yylhs.value.pNode) = new WhileNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 838 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 34: // for_expression: RANGE LC dim_num_stm RC
#line 248 "parser.y"
                            { (yylhs.value.pNode) = new ForExprNode((yystack_[1].value.dim_num_stmNode));}
#line 844 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 35: // for_expression: Identifier
#line 250 "parser.y"
               { IdentifierNode* id = new IdentifierNode((yystack_[0].value.sval));(yylhs.value.pNode) = new ForExprNode(id);}
#line 850 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 36: // for_expression: LR dim_num_stm RR
#line 252 "parser.y"
                      { (yylhs.value.pNode) = new ForExprNode((yystack_[1].value.dim_num_stmNode));}
#line 856 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 37: // for: FOR Identifier IN for_expression COLON block
#line 256 "parser.y"
                                                  {  IdentifierNode* id = new IdentifierNode((yystack_[4].value.sval));(yylhs.value.pNode) = new ForNode(id,(yystack_[2].value.pNode),(yystack_[0].value.statementListNode));}
#line 862 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 38: // if: IF expression COLON block
#line 260 "parser.y"
                                 { (yylhs.value.pNode) = new IfNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 868 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 39: // if: IF expression COLON block elseif_statment_list
#line 261 "parser.y"
                                                      { (yylhs.value.pNode) = new IfNode((yystack_[3].value.pNode), (yystack_[1].value.statementListNode), (yystack_[0].value.elseifListNode)); }
#line 874 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 40: // elseif_statment_list: elseif_statment
#line 265 "parser.y"
                     {(yylhs.value.elseifListNode) = new ListNode<ElseIfNode>((yystack_[0].value.elseif_stmNode));}
#line 880 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 41: // elseif_statment_list: elseif_statment_list elseif_statment
#line 266 "parser.y"
                                           {(yystack_[1].value.elseifListNode)->push_back((yystack_[0].value.elseif_stmNode));}
#line 886 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 42: // elseif_statment: ELSE COLON block
#line 270 "parser.y"
                      { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[0].value.statementListNode)); }
#line 892 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 43: // elseif_statment: ELIF expression COLON block
#line 271 "parser.y"
                                  { (yylhs.value.elseif_stmNode) = new ElseIfNode((yystack_[2].value.pNode), (yystack_[0].value.statementListNode)); }
#line 898 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 44: // var_expression: Identifier
#line 276 "parser.y"
               { (yylhs.value.pNode) = new IdentifierNode((yystack_[0].value.sval)); }
#line 904 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 45: // var_expression: array_index
#line 277 "parser.y"
                  { (yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 910 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 46: // var_expression: struct_index
#line 278 "parser.y"
                   {(yylhs.value.pNode) = (yystack_[0].value.pNode); }
#line 916 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 47: // var_assignment: Identifier ASS expression
#line 283 "parser.y"
                               { IdentifierNode* id = new IdentifierNode((yystack_[2].value.sval));(yylhs.value.pNode) = new VariableNode(0,nullptr,id,(yystack_[0].value.pNode),loc);}
#line 922 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 48: // var_assignment: array_index ASS expression
#line 284 "parser.y"
                                   { (yylhs.value.pNode) = new VariableNode(0,nullptr,(yystack_[2].value.pNode),(yystack_[0].value.pNode),loc);}
#line 928 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 49: // var_assignment: struct_index ASS expression
#line 285 "parser.y"
                                   { (yylhs.value.pNode) = new VariableNode(0,nullptr,(yystack_[2].value.pNode),(yystack_[0].value.pNode),loc);}
#line 934 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 50: // assignment: var_expression ASS expression
#line 292 "parser.y"
    { 
        (yylhs.value.pNode) = new AssignmentNode((yystack_[2].value.pNode), (yystack_[0].value.pNode));
    }
#line 942 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 51: // dim_num_stm: expression
#line 300 "parser.y"
    {
        (yylhs.value.dim_num_stmNode) = new DimNumsNode((yystack_[0].value.pNode)); 
    }
#line 950 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 52: // dim_num_stm: dim_num_stm COMMA expression
#line 304 "parser.y"
        {
       (yystack_[2].value.dim_num_stmNode)->push_back((yystack_[0].value.pNode));   
	}
#line 958 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 53: // struct_index: var_expression DOT Identifier
#line 310 "parser.y"
                                   { IdentifierNode* id = new IdentifierNode((yystack_[0].value.sval));(yylhs.value.pNode) = new StructIndexNode((yystack_[2].value.pNode),id); }
#line 964 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 54: // array_index: Identifier LBRACE expression RBRACE
#line 314 "parser.y"
                                     {IdentifierNode* id = new IdentifierNode((yystack_[3].value.sval));(yylhs.value.pNode) = new ArrayIndexNode(id, (yystack_[1].value.pNode));}
#line 970 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 55: // op_expr: expression ADD expression
#line 319 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::ADD, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 976 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 56: // op_expr: expression SUB expression
#line 320 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::SUB, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 982 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 57: // op_expr: SUB expression
#line 321 "parser.y"
                               { (yylhs.value.pNode) = new OperatorNode(token::UMINUS, (yystack_[0].value.pNode)); }
#line 988 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 58: // op_expr: expression MUL expression
#line 322 "parser.y"
                             { (yylhs.value.pNode) = new OperatorNode(token::MUL, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 994 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 59: // op_expr: expression LT expression
#line 323 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::LT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1000 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 60: // op_expr: expression GT expression
#line 324 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::GT, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1006 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 61: // op_expr: expression GE expression
#line 325 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::GE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1012 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 62: // op_expr: expression LE expression
#line 326 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::LE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1018 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 63: // op_expr: expression NE expression
#line 327 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::NE, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1024 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 64: // op_expr: expression EQ expression
#line 328 "parser.y"
                            { (yylhs.value.pNode) = new OperatorNode(token::EQ, (yystack_[2].value.pNode), (yystack_[0].value.pNode)); }
#line 1030 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 65: // op_expr: expression AND expression
#line 329 "parser.y"
                             {(yylhs.value.pNode) = new OperatorNode(token::AND, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1036 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 66: // op_expr: expression OR expression
#line 330 "parser.y"
                            {(yylhs.value.pNode) = new OperatorNode(token::OR, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1042 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 67: // op_expr: expression MOD expression
#line 331 "parser.y"
                             {(yylhs.value.pNode) = new OperatorNode(token::MOD, (yystack_[2].value.pNode), (yystack_[0].value.pNode));}
#line 1048 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 68: // op_expr: NOT expression
#line 334 "parser.y"
                              {(yylhs.value.pNode) = new OperatorNode(token::NOT, (yystack_[0].value.pNode));}
#line 1054 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 69: // op_expr: LC expression RC
#line 335 "parser.y"
                    {(yylhs.value.pNode) = (yylhs.value.pNode) = new OperatorNode(token::LC, (yystack_[1].value.pNode));}
#line 1060 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 70: // expression: String
#line 341 "parser.y"
        { (yylhs.value.pNode) = new StringLiteralNode((yystack_[0].value.sval));}
#line 1066 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 71: // expression: FNULL
#line 342 "parser.y"
         { (yylhs.value.pNode) = new NullNode();}
#line 1072 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 72: // expression: Number
#line 343 "parser.y"
          {(yylhs.value.pNode) = new NumberLiteralNode((yystack_[0].value.dval)); }
#line 1078 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 73: // expression: LNumber
#line 344 "parser.y"
           {(yylhs.value.pNode) = new Integer((yystack_[0].value.ival)); }
#line 1084 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 74: // expression: FTRUE
#line 345 "parser.y"
         {(yylhs.value.pNode) = new Boolean(1);}
#line 1090 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 75: // expression: FFALSE
#line 346 "parser.y"
          {(yylhs.value.pNode) = new Boolean(0);}
#line 1096 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 76: // expression: var_expression
#line 347 "parser.y"
                  {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1102 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 77: // expression: op_expr
#line 348 "parser.y"
           {(yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1108 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 78: // expression: function_call
#line 349 "parser.y"
                  { (yylhs.value.pNode) = (yystack_[0].value.pNode);}
#line 1114 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;

  case 79: // expression: LR dim_num_stm RR
#line 350 "parser.y"
                     {(yylhs.value.pNode) = (yystack_[1].value.dim_num_stmNode);}
#line 1120 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"
    break;


#line 1124 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
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

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
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

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

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
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -67;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      38,   -45,   -40,   -19,    40,    38,   -67,   -67,   -67,    11,
     -67,    37,    44,    19,    28,   260,   260,   -67,   -67,    22,
     260,   260,    27,    38,    27,   260,   260,   260,   -67,   260,
     -67,   -67,   -67,   -67,    32,   -67,   -67,    11,   -67,   -67,
     -67,   173,    23,   -67,   173,   173,    57,    55,   -67,    74,
     -67,    11,   -67,    65,   173,   120,   -67,   239,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     -67,    76,    27,    80,   -67,   260,   -67,   -67,    77,   173,
       6,     6,   210,     6,     7,     7,   -67,     6,     6,   225,
     225,   -67,    38,   -67,   231,   173,   260,   -67,   -67,   260,
     260,   -67,   -67,   -67,    58,   260,   -67,   231,   -67,   -67,
     -67,   -67,   -67,   -67,     9,   -67,   173,   137,   173,    92,
     148,   -67,   260,   231,    41,   231,   173,     8,    85,   260,
     -67,    83,   -67,    89,   260,     8,   -67,   260,    70,   231,
     231,   158,   -67,    78,   -67,   -67,   -67,   231,   -67,   -67
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,    44,     0,     2,     3,     7,     5,     0,
       6,    46,    45,     0,     0,     0,     0,     1,     4,     0,
       0,     0,     0,     0,    13,     0,     0,     0,    71,     0,
      74,    75,    72,    73,    44,    70,    78,    76,    46,    45,
      77,    47,     0,    53,    49,    48,    44,    46,     8,     0,
      11,    14,    57,     0,    51,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,    79,     0,    69,    21,     0,    15,
      61,    62,    64,    63,    55,    56,    58,    59,    60,    65,
      66,    67,     0,    12,     0,    52,     0,    20,     9,     0,
      31,    28,    30,    29,     0,     0,    10,    17,    27,    18,
      26,    24,    25,    23,     0,    22,    16,     0,    32,     0,
       0,    19,     0,     0,     0,     0,    50,    38,     0,     0,
      35,     0,    33,     0,     0,    39,    40,     0,     0,     0,
       0,     0,    41,     0,    36,    37,    42,     0,    34,    43
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -67,   -67,   -67,     5,   -67,   -67,   -67,    64,   -67,   -66,
     -67,   -36,    30,   -67,   -67,   -67,   -67,   -67,   -67,    18,
       0,   -67,   -67,   -39,     3,     4,   -67,   -14
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     4,     5,     6,     7,     8,    49,    50,    78,   106,
     107,    36,   109,   110,   111,   131,   112,   113,   135,   136,
      37,    10,   115,    53,    38,    39,    40,    54
  };

  const unsigned char
  Parser::yytable_[] =
  {
       9,    41,    42,    11,    12,     9,    44,    45,    11,    12,
      18,    52,   133,    55,    15,    56,    13,    62,    63,    64,
      64,    14,     9,     9,    51,    47,    11,    12,    48,    58,
      59,    60,    61,    16,    62,    63,    64,    65,    66,    19,
      17,    19,   122,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    22,   127,   108,   132,
      23,    95,     1,    69,    69,    24,   134,     2,   128,    57,
      20,   108,    51,   145,   146,   129,    70,    21,    67,    68,
      69,   149,   116,    43,    16,   117,   118,   108,    46,   108,
     138,   120,     9,    71,   114,    11,    12,    98,   143,     3,
      74,    75,   130,   108,   108,   144,    75,   114,   126,    16,
      72,   108,    73,    96,    75,    97,   148,    92,   124,   119,
     141,    94,   137,   114,   139,   114,    58,    59,    60,    61,
     140,    62,    63,    64,    65,    66,    93,   121,     0,   114,
     114,     0,     0,    58,    59,    60,    61,   114,    62,    63,
      64,    65,    66,   142,    58,    59,    60,    61,    76,    62,
      63,    64,    65,    66,    58,    59,    60,    61,     0,    62,
      63,    64,    65,    66,     0,    67,    68,    69,   123,    58,
      59,    60,    61,     0,    62,    63,    64,    65,    66,   125,
       0,     0,    67,    68,    69,     0,     0,     0,     0,   147,
       0,     0,     0,    67,    68,    69,     0,     0,     0,     0,
       0,     0,     0,    67,    68,    69,    58,    59,     0,    61,
       0,    62,    63,    64,    65,    66,     0,     0,    67,    68,
      69,    58,    59,     0,    61,     0,    62,    63,    64,    65,
      66,    99,     0,     0,     0,     0,     0,   100,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,   102,   103,     0,    67,    68,    69,     0,     0,
       0,     0,    25,    26,     0,     0,    27,    77,     0,     0,
     104,    28,    69,    29,     0,   105,    30,    31,     0,     0,
       0,     0,    34,     0,    26,     0,     0,    27,    32,    33,
      34,    35,    28,     0,    29,     0,     0,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,    34,    35
  };

  const short
  Parser::yycheck_[] =
  {
       0,    15,    16,     0,     0,     5,    20,    21,     5,     5,
       5,    25,     4,    27,    33,    29,    61,    11,    12,    13,
      13,    61,    22,    23,    24,    22,    23,    23,    23,     6,
       7,     8,     9,    52,    11,    12,    13,    14,    15,    30,
       0,    30,    33,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    37,   123,    94,   125,
      41,    75,    24,    57,    57,    37,    58,    29,    27,    37,
      33,   107,    72,   139,   140,    34,    53,    33,    55,    56,
      57,   147,    96,    61,    52,    99,   100,   123,    61,   125,
     129,   105,    92,    38,    94,    92,    92,    92,   137,    61,
      35,    36,    61,   139,   140,    35,    36,   107,   122,    52,
      36,   147,    38,    36,    36,    38,    38,    41,    26,    61,
     134,    41,    37,   123,    41,   125,     6,     7,     8,     9,
      41,    11,    12,    13,    14,    15,    72,   107,    -1,   139,
     140,    -1,    -1,     6,     7,     8,     9,   147,    11,    12,
      13,    14,    15,   135,     6,     7,     8,     9,    38,    11,
      12,    13,    14,    15,     6,     7,     8,     9,    -1,    11,
      12,    13,    14,    15,    -1,    55,    56,    57,    41,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,    41,
      -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,     6,     7,    -1,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    55,    56,
      57,     6,     7,    -1,     9,    -1,    11,    12,    13,    14,
      15,    10,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    31,    32,    -1,    55,    56,    57,    -1,    -1,
      -1,    -1,    12,    34,    -1,    -1,    37,    38,    -1,    -1,
      49,    42,    57,    44,    -1,    54,    47,    48,    -1,    -1,
      -1,    -1,    61,    -1,    34,    -1,    -1,    37,    59,    60,
      61,    62,    42,    -1,    44,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    24,    29,    61,    64,    65,    66,    67,    68,    83,
      84,    87,    88,    61,    61,    33,    52,     0,    66,    30,
      33,    33,    37,    41,    37,    12,    34,    37,    42,    44,
      47,    48,    59,    60,    61,    62,    74,    83,    87,    88,
      89,    90,    90,    61,    90,    90,    61,    87,    66,    69,
      70,    83,    90,    86,    90,    90,    90,    37,     6,     7,
       8,     9,    11,    12,    13,    14,    15,    55,    56,    57,
      53,    38,    36,    38,    35,    36,    38,    38,    71,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    41,    70,    41,    90,    36,    38,    66,    10,
      16,    28,    31,    32,    49,    54,    72,    73,    74,    75,
      76,    77,    79,    80,    83,    85,    90,    90,    90,    61,
      90,    75,    33,    41,    26,    41,    90,    72,    27,    34,
      61,    78,    72,     4,    58,    81,    82,    37,    86,    41,
      41,    90,    82,    86,    35,    72,    72,    41,    38,    72
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    63,    64,    65,    65,    66,    66,    66,    67,    67,
      68,    69,    69,    69,    70,    71,    71,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    76,    76,    77,    78,    78,    78,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    84,    84,    84,
      85,    86,    86,    87,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     4,     7,
       7,     1,     3,     0,     1,     1,     3,     1,     1,     2,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     1,     3,     6,     4,     5,
       1,     2,     3,     4,     1,     1,     1,     3,     3,     3,
       3,     1,     3,     3,     4,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3
  };


#if P_YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DIVIDE", "ELSE",
  "PREFIX", "GE", "LE", "EQ", "NE", "IF", "ADD", "SUB", "MUL", "LT", "GT",
  "RETURN", "NumberType", "TextType", "VoidType", "SPACE", "THEN", "DOLAR",
  "UMINUS", "CLASS", "SELF", "IN", "RANGE", "BREAK", "DEF", "DOT", "PASS",
  "CONTINUE", "ASS", "LR", "RR", "COMMA", "LC", "RC", "LESS", "GREATER",
  "COLON", "FNULL", "DEVCOLON", "NOT", "UNINDENT", "INDENT", "FTRUE",
  "FFALSE", "FOR", "FROM", "SEMICOLON", "LBRACE", "RBRACE", "WHILE", "AND",
  "OR", "MOD", "ELIF", "Number", "LNumber", "Identifier", "String",
  "$accept", "program", "declaration_list", "declaration", "Class_declare",
  "function_declaration", "parameter_declaration_list",
  "parameter_declaration", "func_call_parameter_list", "block",
  "statement_list", "function_call", "statement", "return", "while_loop",
  "for_expression", "for", "if", "elseif_statment_list", "elseif_statment",
  "var_expression", "var_assignment", "assignment", "dim_num_stm",
  "struct_index", "array_index", "op_expr", "expression", YY_NULLPTR
  };
#endif


#if P_YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   160,   160,   164,   165,   169,   170,   171,   176,   178,
     184,   191,   192,   193,   197,   201,   205,   211,   216,   217,
     221,   222,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   238,   239,   243,   248,   250,   252,   256,   260,   261,
     265,   266,   270,   271,   276,   277,   278,   283,   284,   285,
     291,   299,   303,   310,   314,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   334,   335,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350
  };

  void
  Parser::yy_stack_print_ () const
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
  Parser::yy_reduce_print_ (int yyrule) const
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
#endif // P_YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
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
      55,    56,    57,    58,    59,    60,    61,    62
    };
    // Last valid token kind.
    const int code_max = 317;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 15 "parser.y"
} // Language
#line 1780 "D:\\source\\repos\\py\\\\py\\parser.tab.cpp"

#line 354 "parser.y"



static int yylex( Language::Parser::semantic_type *yylval,Language::location* loc,Language::Lexer  &lexer)
{
   return( lexer.yylex(yylval,loc) );
}
void Language::Parser::error( const Language::location& location,const std::string &err_message )
{
    printf("error parsed %s(%s)at %d.%d-%d.%d: %s\n",loc.end.filename->c_str(), err_message.c_str(),loc.begin.line, loc.begin.column, loc.end.line, loc.end.column,cur_yytext.c_str());   
}
