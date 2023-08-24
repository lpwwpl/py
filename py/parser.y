%code requires {

# define YYLTYPE_IS_DECLARED 1 /* alert the parser that we have our own definition */

}
%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%start program
%verbose 
%locations /* track locations: @n of component N; @$ of entire range */

%output  "PParser.cpp"
%defines "PParser.h"

%define api.prefix {P_yy}
%define api.namespace {PyLanguage}
%define parser_class_name {Parser}
%define parse.error verbose


%code requires{

   namespace PyLanguage {
      class Translator;
      class Lexer;
      class ASTNode;
      class ParameterNode;
      class FunctionNode;
      class OperatorNode;
      class StatementListNode;
      class ForNode;
      class ElseIfNode;
      class DeclareNode;
      class FunctionCallNode;
      class VariableNode;
      class DeclareListNode;
      class NullNode;
      class SWitchNode;
      class StructDescNode;
      class StructIndexNode;
      class ModifierNode;
      class DimNumsNode;
      class IdentifierNode;
      class BreakNode;
      class ContinueNode;
      class FuncCallsNode;
      class PassNode;
      template <class T> class ListNode;
   }
   class QString;
}


%lex-param   { Lexer  &lexer  }

%parse-param { Lexer  &lexer  }



%code{
    #include "translator.hpp"
    #include "ast.h"
    #include <stack>
    
    static int yylex(PyLanguage::Parser::semantic_type *yylval, PyLanguage::location* loc,PyLanguage::Lexer  &lexer);

    std::string err;
    extern std::string cur_yytext;
    extern std::stack<std::string> fileNames;
    extern PyLanguage::location loc;//ÉùÃ÷Î»ÖÃÊµÀý
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

}


/* token types */
%union {
   QString *sval;
   double dval;
   int ival;
   ASTNode * pNode;
   ParameterNode * parameterNode;
   FunctionNode * functionNode;
   VariableNode* variableNode;
   ListNode<ASTNode> * listNode;
   ListNode<ParameterNode> * parameterListNode;
   ListNode<ElseIfNode>* elseifListNode;
   StatementListNode * statementListNode;

   ElseIfNode* elseif_stmNode;
   DimNumsNode*     dim_num_stmNode;

   FuncCallsNode* func_call_listNode;

}
%right ASS

%left EQ 
%left AND OR 
%left GE LE  NE GT LT
%left  ADD SUB 
%left MUL DIVIDE MOD 
%left LBRACE RBRACE LC RC  
/// -d --report="cex" 
%nonassoc IF 
%nonassoc ELSE
%nonassoc NOT 
%nonassoc UMINUS
%nonassoc POSITIVE 
%nonassoc PREFIX

//DIV
%token GE LE EQ NE IF ADD SUB MUL LT GT RETURN NumberType TextType VoidType SPACES THEN DOLAR UMINUS  CLASS SELF PIN RANGE BREAK DEF DOT PASS CONTINUE POSITIVE
%token ASS LR RR COMMA LC RC LESS GREATER COLON FNULL DEVCOLON NOT UNINDENT INDENT
%token FTRUE FFALSE FOR FROM SEMICOLON  LBRACE RBRACE WHILE
%token AND OR MOD ELIF    
%token  END    0     "end of file"
%token <dval> Number 
%token <ival> LNumber 
%token <sval> Identifier
%token <sval> String 

//struct_index splash_func_call_parameter
%type<pNode> Class_declare   array_index  var_assignment op_expr 
%type<pNode> program  expression assignment statement if while_loop return for  for_expression declaration   function_call    var_expression  struct_index

//inst_expr_ass
%type <parameterNode> parameter_declaration 
%type <parameterListNode> parameter_declaration_list 

%type <ival> /*type*/ NumberType TextType VoidType   
%type <functionNode> function_declaration
%type <listNode>  declaration_list  
%type <dim_num_stmNode> dim_num_stm
%type <func_call_listNode> func_call_list
%type <statementListNode> statement_list block
%type <listNode> func_call_parameter_list   
//inst_expr_ass_list
%type <elseifListNode> elseif_statment_list
%type <elseif_stmNode> elseif_statment




%%


program:
    declaration_list {}
    ;

declaration_list:
     declaration {$$ = new DeclareListNode($1);}
     | declaration_list declaration  {$1->push_back($2);}
	 ;

declaration: 
    function_declaration {$$=$1;} 
    | var_assignment{$$=$1;} 
    | Class_declare {$$=$1;}
	;


Class_declare:
    CLASS Identifier COLON  declaration { IdentifierNode* id = new IdentifierNode($2);$$ = new StructDescNode(id, $4); }
    | 
    CLASS Identifier LC struct_index RC COLON  declaration { IdentifierNode* id = new IdentifierNode($2);$$ = new StructDescNode(id, $4,$7); }
    ;



function_declaration:
    DEF Identifier LC parameter_declaration_list RC COLON block  
    {
        $$ = new FunctionNode(NULL, $2, $4, $7); 
    }
    ;

parameter_declaration_list:
    parameter_declaration { $$ = new ListNode<ParameterNode>($1); }
    | parameter_declaration_list COMMA parameter_declaration {$1->push_back($3);}
    | {$$ = new ListNode<ParameterNode>();}
    ;

parameter_declaration:
    expression {$$ = new ParameterNode($1,nullptr);}
    |     expression ASS expression {$$ = new ParameterNode($1,$3);}
    ;

func_call_parameter_list:
    expression 	
    {
        $$ = new ListNode<ASTNode>($1); 
    }
    | func_call_parameter_list  COMMA  expression 
	{
        $1->push_back($3);   
	}
	;

block :  statement_list  { $$ = $1; }
      ;

statement_list:
    statement {$$ = new StatementListNode($1);}
    | statement_list statement {$1->push_back($2);}
    ;

function_call:
     var_expression LC func_call_parameter_list RC  { $$ = new FunctionCallNode($1, $3);}
     | var_expression LC RC  { $$ = new FunctionCallNode($1, NULL);}
    ;

statement:
     assignment  {$$ = $1;}
    | if { $$ = $1; }
    | while_loop { $$ = $1; }
    | for { $$ = $1; }
    | return  { $$ = $1;}
    | func_call_list  { $$ = $1;}
    | BREAK {$$ = new BreakNode();}  
    | CONTINUE  {$$ = new ContinueNode();}  
    | PASS {$$ = new PassNode();}
    ;

return:
 RETURN {$$ = new ReturnNode(NULL); }
|    RETURN expression {$$ = new ReturnNode($2); }
;

while_loop:
    WHILE /*LC*/ expression /*RC*/ COLON block { $$ = new WhileNode($2, $4); }
    ;


for_expression:
    RANGE LC dim_num_stm RC { $$ = new ForExprNode($3);}
    |
    Identifier { IdentifierNode* id = new IdentifierNode($1);$$ = new ForExprNode(id);}
    | 
    LR dim_num_stm RR { $$ = new ForExprNode($2);}
    ;

for:
    FOR Identifier PIN for_expression COLON block  {  IdentifierNode* id = new IdentifierNode($2);$$ = new ForNode(id,$4,$6);}
    ;

if:
    IF  expression  COLON block  { $$ = new IfNode($2, $4); }
    | IF expression COLON block elseif_statment_list  { $$ = new IfNode($2, $4, $5); }
;

elseif_statment_list:
     elseif_statment {$$ = new ListNode<ElseIfNode>($1);}
    | elseif_statment_list elseif_statment {$1->push_back($2);}
    ;     

elseif_statment:
    ELSE  COLON block { $$ = new ElseIfNode($3); }
    | ELIF expression COLON block { $$ = new ElseIfNode($2, $4); }
    ;


var_expression:
    Identifier { $$ = new IdentifierNode($1); }
    | array_index { $$ = $1; }
    | struct_index {$$ = $1; }
    //| inst_modifer { $$ = $1;}
    ;

var_assignment:
    Identifier ASS expression  { IdentifierNode* id = new IdentifierNode($1);$$ = new VariableNode(0,nullptr,id,$3,loc);}
    | array_index ASS expression   { $$ = new VariableNode(0,nullptr,$1,$3,loc);}  
    | struct_index ASS expression  { $$ = new VariableNode(0,nullptr,$1,$3,loc);}
    ;

assignment:
    //var_expression ASS expression SEMICOLON {IdentifierNode* id = new IdentifierNode($1); $$ = new AssignmentNode(id, $3);}
    //|
    var_expression ASS expression 
    { 
        $$ = new AssignmentNode($1, $3);
    }

    ;

func_call_list:
    function_call { $$ = new FuncCallsNode($1); }
    | func_call_list DOT function_call {   $1->push_back($3);     }

dim_num_stm:
	expression 	
    {
        $$ = new DimNumsNode($1); 
    }
	| dim_num_stm  COMMA  expression 
	{
       $1->push_back($3);   
	}
	;

struct_index:
    var_expression DOT Identifier  { IdentifierNode* id = new IdentifierNode($3);$$ = new StructIndexNode($1,id); }
   ;

array_index: 
 Identifier LR expression RR {IdentifierNode* id = new IdentifierNode($1);$$ = new ArrayIndexNode(id, $3);}
 ;


op_expr:
   expression ADD expression { $$ = new OperatorNode(token::ADD, $1, $3); }
 | expression SUB expression { $$ = new OperatorNode(token::SUB, $1, $3); }
 | SUB expression  %prec UMINUS{ $$ = new OperatorNode(token::UMINUS, $2); }
 | ADD expression  %prec POSITIVE{ $$ = new OperatorNode(token::POSITIVE, $2); }
 | expression MUL expression { $$ = new OperatorNode(token::MUL, $1, $3); }
 | expression LT expression { $$ = new OperatorNode(token::LT, $1, $3); }
 | expression GT expression { $$ = new OperatorNode(token::GT, $1, $3); }
 | expression GE expression { $$ = new OperatorNode(token::GE, $1, $3); }
 | expression LE expression { $$ = new OperatorNode(token::LE, $1, $3); }
 | expression NE expression { $$ = new OperatorNode(token::NE, $1, $3); }
 | expression EQ expression { $$ = new OperatorNode(token::EQ, $1, $3); }
 | expression AND expression {$$ = new OperatorNode(token::AND, $1, $3);}
 | expression OR expression {$$ = new OperatorNode(token::OR, $1, $3);}
 | expression MOD expression {$$ = new OperatorNode(token::MOD, $1, $3);}
 | expression DIVIDE expression {$$ = new OperatorNode(token::DIVIDE, $1, $3);}
 //| expression ASS expression { $$ = new OperatorNode(token::ASS, $1, $3); }
 //| ADD expression  %prec PREFIX{ $$ = new OperatorNode(token::UMINUS, $2); }
 | NOT expression %prec PREFIX{$$ = new OperatorNode(token::NOT, $2);}  
 | LC expression RC {$$ = $$ = new OperatorNode(token::LC, $2);}
 ;


expression:
 //RAPID_NAN { $$ = new StringLiteralNode(true,&QString::fromLatin1("9E+09"));}
 String { $$ = new StringLiteralNode($1);}
 | FNULL { $$ = new NullNode();}
 | Number {$$ = new NumberLiteralNode($1); }
 | LNumber {$$ = new Integer($1); }
 | FTRUE {$$ = new Boolean(1);}
 | FFALSE {$$ = new Boolean(0);}
 | var_expression {$$ = $1;}
 | op_expr {$$ = $1;}
 | func_call_list  { $$ = $1;}
 | LR dim_num_stm RR {$$ = $2;}
 //| BREAK {}
 ;

%%


static int yylex( PyLanguage::Parser::semantic_type *yylval,PyLanguage::location* loc,PyLanguage::Lexer  &lexer)
{
   return( lexer.yylex(yylval,loc) );
}
void PyLanguage::Parser::error( const PyLanguage::location& location,const std::string &err_message )
{
    char format_str[128] = { 0 };
	snprintf(format_str, sizeof(format_str) - 1, "error parsed %s(%s)at %d.%d-%d.%d: %s\n",loc.end.filename->c_str(), err_message.c_str(),loc.begin.line, loc.begin.column, loc.end.line, loc.end.column,cur_yytext.c_str());
    
    err=std::string(format_str);
    printf("%s",format_str); 
}
