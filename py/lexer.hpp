#ifndef PY__LEXER_HPP__
#define PY__LEXER_HPP__

#if ! defined(yyFlexLexerOnce)
#undef yyFlexLexer
#define yyFlexLexer P_yyFlexLexer
#include <FlexLexer.h>
#endif

//#if ! defined(yyFlexLexerOnce)
//#include <FlexLexer.h>
//#endif

#undef  YY_DECL
#define YY_DECL int  PyLanguage::Lexer::yylex()

#include "parser.tab.hpp"
#include "location.hh"
namespace PyLanguage
{

class Lexer : public yyFlexLexer{
public:

   Lexer(std::istream *in) : yyFlexLexer(in),
                                  yylval( nullptr ), yyloc(nullptr){};



   int yylex(Parser::semantic_type *lval, PyLanguage::location* loc)
   {
      yylval = lval; 
      yyloc = loc;
      return( yylex() );
   }

private:
   int yylex();

   Parser::semantic_type *yylval;
   PyLanguage::location* yyloc;
};

}

#endif // __LEXER_HPP__
