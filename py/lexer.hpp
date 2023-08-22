#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#if ! defined(yyFlexLexerOnce)
#undef yyFlexLexer
#define yyFlexLexer P_yyFlexLexer
#include <FlexLexer.h>
#endif

//#if ! defined(yyFlexLexerOnce)
//#include <FlexLexer.h>
//#endif

#undef  YY_DECL
#define YY_DECL int  Language::Lexer::yylex()

#include "parser.tab.hpp"
#include "location.hh"
namespace Language
{

class Lexer : public yyFlexLexer{
public:

   Lexer(std::istream *in) : yyFlexLexer(in),
                                  yylval( nullptr ), yyloc(nullptr){};



   int yylex(Parser::semantic_type *lval, Language::location* loc)
   {
      yylval = lval; 
      yyloc = loc;
      return( yylex() );
   }

private:
   int yylex();

   Parser::semantic_type *yylval;
   Language::location* yyloc;
};

}

#endif // __LEXER_HPP__
