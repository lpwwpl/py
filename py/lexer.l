%{
#include <QString>
#include <string>
#include <stack>
#include <iostream>
#include <cerrno>
#include <climits>
#include <stdio.h>
#include <fstream>
#include "lexer.hpp"
typedef Language::Parser::token token;
#define yyterminate() return( token::END )
#define YY_NO_UNISTD_H // For msvc





using namespace Language;

#define YYERROR_VERBOSE 1
Language::location loc;//ÉùÃ÷Î»ÖÃÊµÀý

std::string cur_yytext;
std::string g_str;
int yycolumn = 1;
int yylineno = 1;
int current_line_indent = 0;   /* indentation of the current line */
int indent_level = 0;          /* indentation level passed to the parser */
std::stack<int> curr_indents;
int first_time = 1 ;

int parsing_error = 0;

std::stack<std::string> fileNames;
std::stack<int> lineNo;
std::vector<std::string> libPaths;



#define YY_USER_ACTION do { \
    if( loc.end.line < yylineno ) yycolumn = 1 ; \
    loc.begin.line = loc.end.line = yylineno; \
    loc.begin.column = yycolumn; loc.end.column = yycolumn + (int)yyleng - 1; \
    yycolumn += (int)yyleng; \
    loc.end.filename = &(fileNames.top()); \
    } while(0) ;

int yyerror(char const * s )
{
    printf("ERROR %s  at line %d col %d\n", s,  yylineno, yycolumn);
    printf("parsed %s %d.%d-%d.%d\n", loc.end.filename->c_str(), loc.begin.line, loc.begin.column, loc.end.line, loc.end.column);
    return 1;
}

%}



%option debug
%option yyclass="Lexer"

%option caseless c++
%option yylineno noyywrap
%option prefix="P_yy"

%x indent 
%s normal 
%x str qstr
%x comment
%x incl




dig     [0-9]
lnum    {dig}+([eE][-+]?{dig}+)?
num1    {dig}+\.([eE][-+]?{dig}+)?
num2    {dig}*\.{dig}+([eE][-+]?{dig}+)?
number  {num1}|{num2}|{lnum}


SPACE       [ \f\n\r\t\v]+
CONTINUE    CONTINUE
PASS    PASS
NOT NOT
SELF        SELF
IF          IF
ELSE        ELSE
ELIF        ELIF
RETURN      RETURN
DEF         DEF
CLASS       CLASS
AND         AND
OR          OR
NONE        NULL
TRUE        TRUE
FALSE       FALSE
FROM        FROM
RANGE          RANGE
IN          IN
WHILE       WHILE
FOR         FOR
MOD         MOD
BREAK       BREAK


%%
            if( first_time ) {
                first_time = 0;
                curr_indents.push(0);
                lineNo.push(yylineno);
                BEGIN indent;
            }

            
import              BEGIN(incl);
<incl>[ \t]*        /* eat the whitespace */
<incl>[^ \t\n\r]+   { /* got the include file name */
                    std::string fileName = yytext;
                    std::size_t pos = fileName.find(".liq");
                    if( pos == std::string::npos ) {
                        fileName += ".liq";
                    }
                    std::string filePath="";
                    for( auto libpath : libPaths ) {
                       filePath = libpath + fileName;
                       std::ifstream file(filePath.c_str());
                       if(file.good())
                          break;
                    }
                    std::filebuf fb;
                    if (fb.open (filePath,std::ios::in))
                    {
                         std::istream is(&fb);
                         //yyin = is;
                         fileNames.push(std::string(yytext));
                         lineNo.push(yylineno);
                         yylineno = yycolumn = 1;
                         loc.begin.line = loc.begin.column = loc.end.line = loc.end.column = 1;
                         yypush_buffer_state(yy_create_buffer( is, YY_BUF_SIZE ));
                         fb.close();
                    }
                    else
                    {
                         printf( "%s in %s line %d\n", (std::string("Failed to load import file ") + fileName).c_str(), fileNames.top().c_str(), yylineno );
                         parsing_error = 1;
                         yyterminate();
                    }

                    BEGIN(normal);
                    }


<indent>" "      { current_line_indent++; }
<indent>"\t"     { current_line_indent = (current_line_indent + 4) ; }
<indent>"\n"     { current_line_indent = 0; yycolumn = 1;/*ignoring blank line */ }
<indent>"\r"     { current_line_indent = 0; yycolumn = 1;/*ignoring blank line */ }
<indent>.        {
     
                   unput(*yytext);
                   yycolumn--;
                   if (current_line_indent > curr_indents.top()) {
                       curr_indents.push(current_line_indent);
                       return token::INDENT;
                   } else if (current_line_indent < curr_indents.top()) {
                       curr_indents.pop();
                       return token::UNINDENT;
                   } else {
                       BEGIN(normal);
                   }
                 }

<normal>"\n"     { current_line_indent = 0; BEGIN( indent); printf("xxx");yycolumn = 1; }
<<EOF>>          {
                   if( curr_indents.size() > 1 ) {
                        curr_indents.pop();
                        return token::UNINDENT;
                   }
                   if(lineNo.size() > 1 ) {
                       yypop_buffer_state();
                       fileNames.pop();
                       yylineno = lineNo.top();
                       lineNo.pop();
                   } else {
                        yyterminate();
                   }
                 }			 
				 



\"      g_str = ""; BEGIN(str);
'       g_str = ""; BEGIN(qstr);

<str>\" {   BEGIN(normal);
            yylval->sval = new QString(QString::fromStdString(g_str));
            return token::String;
        }
<qstr>' {   BEGIN(normal);
            yylval->sval = new QString(QString::fromStdString(g_str));
            return token::String;
        }

<str,qstr>\\n   {g_str += "\n";}
<str,qstr>\\t   g_str += "\t";
<str,qstr>\\r   g_str += "\r";
<str>\\\"       g_str += "\"";
<qstr>\\\'      g_str += "'";

<str,qstr>\\(.|\n)  {g_str += yytext[1]; cur_yytext=yytext[1];}

<str>[^\\\"]+  {g_str += std::string(yytext);cur_yytext=yytext;}
<qstr>[^\\']+  {g_str += std::string(yytext);cur_yytext=yytext;}






{number}	{
                                                        yylval->dval = atof(yytext);
                                                        cur_yytext=yytext;
                                                        return token::Number;
                                                }

                                


"number"					{ return token::NumberType; }
"text"	 					{ return token::TextType; }
"void" 						{ return token::VoidType; }
{CONTINUE}              return token::CONTINUE;
{PASS}                  return token::PASS;
{SELF}                  return token::SELF;
{BREAK}                 return token::BREAK;
{RANGE}                 return token::RANGE;
{IN}                    return token::IN;
{DEF}                  return token::DEF;
{NOT}           { return token::NOT; }
{IF}						{ return token::IF; }
{ELSE} 						{ return token::ELSE; }
{ELIF} 						{ return token::ELIF; }
{RETURN}  					{ return token::RETURN; }
{WHILE}                       {return token::WHILE;}
{AND}                       {return token::AND;}
{OR}                        {return token::OR;}
{MOD}                       { return token::MOD;}
{SPACE}      {}
{TRUE}   {return token::FTRUE;}
{FALSE}  {return token::FFALSE;}
{FOR}           {return token::FOR;}
{FROM}          {return token::FROM;}

{NONE}                      {return token::FNULL;}


{CLASS}          {return token::CLASS;}

\r                      /* cr are ignored */
[ \t\n]                 /* ignore */;
"\."                          {return token::DOT;}
"="                         {return token::ASS;}
"=="                         {return token::EQ;}
";" 						{ return token::SEMICOLON; }
">=" 						{ return token::GE; }
"<>" 						{ return token::NE; }
"<=" 						{ return token::LE; }
"["                    { return token::LR; }
"]"                    { return token::RR; }
","                     { return token::COMMA; }
"("                     { return token::LC; }
")"                     { return token::RC; }
"{"                      { return token::LBRACE; }
"}"                      { return token::RBRACE; }

"+"  { return token::ADD; }
"-"  { return token::SUB; }
"/"  { return token::DIVIDE; }
"*"  { return token::MUL; }
":"    { return token::COLON; }  
"<"     {return token::LT;}
">"     {return token::GT;}
"$"     {return token::DOLAR;}
#.*                     /* comments one line til nl */

[a-z|A-Z]([a-z|A-Z|0-9|_]+)?			{
                                                    
                                                        yylval->sval = new QString( yytext );
                                                        cur_yytext=yytext;
                                                        return( token::Identifier );
                                             }





%%




