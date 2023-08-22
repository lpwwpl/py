
#include "VisitorPyPrint.h"
using namespace PyLanguage;

#include "ast.h"

#define INTENT "    "

void VisitorPyPrint::VisitIdentifier(IdentifierNode* expr)
{
    str.append(expr->_name);
}
void VisitorPyPrint::VisitArrayIndex(ArrayIndexNode* expr)
{
    str += expr->m_ident->_name;
    ListNode<ASTNode>* tempDimRawList = dynamic_cast<ListNode<ASTNode>*>(expr->m_exprs);
    if (tempDimRawList)
    {

        str.append("[");
        int count = tempDimRawList->size();
        for (int i = 0; i < count; i++)
        {
            tempDimRawList->at(i)->Accept(*this);
            str.append(",");
        }
        if (str.endsWith(","))
        {
            str = str.mid(0, str.size() - 1);
        }
        str.append("]");
    }
}
void VisitorPyPrint::VisitAssignment(AssignmentNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    int curIndent = indent;
    indent = 0;
    expr->_src->Accept(*this);
    str.append("=");
    expr->_expression->Accept(*this);
    indent = curIndent;
}

void VisitorPyPrint::VisitDeclarelist(DeclareListNode* retstmt)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    for (auto statement : *retstmt)
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);
    }
}
void VisitorPyPrint::VisitDimnum(DimNumsNode* fndecl)
{
    str.append("[");
    int count = fndecl->tempDimRawList.size();
    for (int i = 0; i < count; i++)
    {
        fndecl->tempDimRawList[i]->Accept(*this);
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append("]");
}
void VisitorPyPrint::VisitElseIf(ElseIfNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }

    if (!expr->_expression)
    {
        str.append("else:");
        str.append("\n");
    }
    else if (expr->_expression)
    {
        str.append("elif ");
        expr->_expression->Accept(*this);
        str.append(":");
        str.append("\n");

    }
    indent++;
    expr->_body->Accept(*this);
    indent--;
}
void VisitorPyPrint::VisitFor(ForNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("for");
    str.append(" ");
    //AssignmentNode* assign = dynamic_cast<AssignmentNode*>(_assignment);
    expr->_assignment->Accept(*this);
    str.append(" ");
    str.append("in");
    str.append(" ");
    str.append("range");
    str.append("(");
    expr->_from_expression->Accept(*this);
    str.append(",");
    expr->_to_expression->Accept(*this);
    str.append(")");
    str.append(":");
    str.append("\n");
    indent = indent + 1;
    expr->_function_body->Accept(*this);
    indent = indent - 1;
}
void VisitorPyPrint::VisitFuncCall(FunctionCallNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    //str.append("self.");
    str.append(expr->_name);
    str.append("(");
    int expr_count = expr->_expressionList->size();
    for (size_t i = 0; i < expr_count; i++)
    {
        ASTNode* arg = expr->_expressionList->at(i);
        ListNode<ASTNode>* list_arg = dynamic_cast<ListNode<ASTNode>*>(arg);
        if (list_arg)
        {
            int count = list_arg->size();
            for (int j = 0; j < count;j++) //auto item : *list_arg
            {
                auto item = list_arg->at(j);
                str.append("\"");
                item->Accept(*this);
                str.append("\"");

                if(j<count-1)
                    str.append(",");
            }
        }
        else
        {
            arg->Accept(*this);
            if (i < expr_count - 1)
                str.append(",");
        }

    }
    //if (str.endsWith(","))
    //{
    //    str = str.mid(0, str.size() - 1);
    //}
    str.append(")");
}
//int,double,string..
//var name
void VisitorPyPrint::VisitVariable(VariableNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
 
    IdentifierNode* type = dynamic_cast<IdentifierNode*>(expr->_e_type);

    QString typeName = type->getTypeName();
    
    //if(typeName == "")

    int curIndent = indent;
    indent = 0;
    if (expr->_src && expr->_expression)
    {
        expr->_src->Accept(*this);
        str.append("=");
        expr->_expression->Accept(*this);
        str.append("\n");
    }
    else
    {
    }
    indent = curIndent;

}
void VisitorPyPrint::VisitIf(IfNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("if");
    str.append(" ");
    expr->_expression->Accept(*this);

    str.append(":");
    str.append("\n");
    if (!expr->_bodyTrue)
    {
        str.append("\n");
        for (int i = 0; i < indent+1; i++)
        {
            str.append(INTENT);
        }

        str.append("pass");
        str.append("\n");
    }
    else
    {
        indent++;
        expr->_bodyTrue->Accept(*this);
        indent--;
    }

    if (expr->_bodyFalse)
    {
        ListNode<ElseIfNode>* elseifs = dynamic_cast<ListNode<ElseIfNode>*>(expr->_bodyFalse);

        for (auto statement : *elseifs)
        {

            if (!statement)continue;
            ElseIfNode* elseif = dynamic_cast<ElseIfNode*>(statement);
            //statement->Execute();
            elseif->Accept(*this);
        }
        indent++;
        expr->_bodyFalse->Accept(*this);
        indent--;
    }
    str.append("\n");
}
void VisitorPyPrint::VisitWhileLoop(WhileNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("while");
    str.append(" ");
    expr->_expression->Accept(*this);
    str.append(" ");
    str.append(":");
    str.append("\n");

    indent = indent + 1;
    expr->_body->Accept(*this);
    indent = indent - 1;
}
void VisitorPyPrint::VisitStructDeclaration(StructDescNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(QString::fromLatin1(INTENT));
    }
    str += QString::fromLatin1("class");
    str += QString::fromLatin1(SPACE);
    str += expr->_name;
    str += QString::fromLatin1(":");
    str += INTENT;
    str += QString::fromLatin1("def __init__(self):");
    str += QString::fromLatin1("\n");
    indent = indent + 2;
    expr->_body->Accept(*this);
    indent = indent - 2;
    str += QString::fromLatin1("\n");
}

void VisitorPyPrint::VisitInteger(Integer* expr)
{
    str.append(QString::number(expr->value));
}

void VisitorPyPrint::VisitBoolean(Boolean* expr)
{
    int boolValue = expr->boolVal;
    if (boolValue)
        str.append("True");
    else
        str.append("False");
}
//switch:switchcase:case

void VisitorPyPrint::VisitStructindex(StructIndexNode* expr)
{
    str.append(expr->_name);
}


void VisitorPyPrint::VisitStatementList(StatementListNode* expr)
{
    for (auto statement : *expr)
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);

        IfNode* ifNode = dynamic_cast<IfNode*>(statement);
        ForNode* forNode = dynamic_cast<ForNode*>(statement);
        if (!ifNode && !forNode)
            str.append("\n");
        //if (dynamic_cast<ReturnNode*>(statement))
        //    break;
    }
}
void VisitorPyPrint::VisitStringLiteral(StringLiteralNode* expr)
{
    str.append("\"");
    str.append(expr->_value);
    str.append("\"");
}

void VisitorPyPrint::VisitDouble(NumberLiteralNode* expr)
{
    str.append(QString::number(expr->_value));
}
void VisitorPyPrint::VisitReturn(ReturnNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("return");
    str.append(" ");
    if (expr->_expression)
        expr->_expression->Accept(*this);
}
void VisitorPyPrint::VisitParamNode(ParameterNode* expr)
{
    //IdentifierNode* s_type = (IdentifierNode*)(expr->_type);
    //str += s_type->getName();
    //str += " ";
    IdentifierNode* s_param = (IdentifierNode*)(expr->_param);
    //str += "\"";
    str += s_param->getName();
    //str += "\"";
}

void VisitorPyPrint::VisitOpera(OperatorNode* expr)
{
    switch (expr->_operator)
    {
    case token::ASS:
    {
        expr->_op1->Accept(*this);
        str += " = ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::LC:
    {
        str += "(";
        expr->_op1->Accept(*this);
        str += ")";
    }
    case token::UMINUS:
    {
        str += "-";
        expr->_op1->Accept(*this);
    }
    break;
    case token::ADD:
    {
        expr->_op1->Accept(*this);
        str += " + ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::SUB:
    {
        expr->_op1->Accept(*this);
        str += " - ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::MUL:
    {
        expr->_op1->Accept(*this);
        str += " * ";
        expr->_op2->Accept(*this);
    }
    break;
    //case token::DIV: 
    //{
    //    QString temp = QString("%1 / %2").arg(_op1->toString()).arg(_op2->toString());
    //    str = temp;
    //}
    //    break;
    case token::LT:
    {
        expr->_op1->Accept(*this);
        str += " < ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::GT:
    {
        expr->_op1->Accept(*this);
        str += " > ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::GE:
    {
        expr->_op1->Accept(*this);
        str += " >= ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::LE:
    {
        expr->_op1->Accept(*this);
        str += " <= ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::NE:
    {
        expr->_op1->Accept(*this);
        str += " != ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::EQ:
    {
        expr->_op1->Accept(*this);
        str += " == ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::AND:
    {
        expr->_op1->Accept(*this);
        str += " and ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::OR:
    {
        expr->_op1->Accept(*this);
        str += " or ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::MOD:
    {
        expr->_op1->Accept(*this);
        str += " % ";
        expr->_op2->Accept(*this);
    }
    break;
    case token::NOT:
    {
        str += "not";
        expr->_op1->Accept(*this);
    }
        break;
    default: std::cerr << "Damn ! Looks like we forgot to implement something..." << std::endl;
        break;
        //exit(EXIT_FAILURE);
    }
}

void VisitorPyPrint::VisitFunc(FunctionNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(QString::fromLatin1(INTENT));
    }
    str += QString::fromLatin1("@allow_goto");
    str += QString::fromLatin1("\n");
    for (int i = 0; i < indent; i++)
    {
        str.append(QString::fromLatin1(INTENT));
    }
    str += QString::fromLatin1("def");
    str += QString::fromLatin1(SPACE);
    str += expr->_name;
    str += QString::fromLatin1("(");
    int count = expr->_arguments->size();
    for (int i = 0; i < count; i++)
    {
        ParameterNode* node = expr->_arguments->at(i);
        node->Accept(*this);
        if (i < (count - 1))
        {
            str += ",";
        }
    }
    expr->_arguments->Accept(*this);
    str += QString::fromLatin1(")");
    str += QString::fromLatin1(":");
    str += QString::fromLatin1("\n");
    //str += INTENT;
    //str += _arguments->toString();
    indent = indent + 1;
    expr->_body->Accept(*this);
    indent = indent - 1;
}

void VisitorPyPrint::VisitForExpr(ForExprNode* expr)
{

}

void VisitorPyPrint::VisitBreak(BreakNode* expr)
{

}
void VisitorPyPrint::VisitContinue(ContinueNode* expr)
{

}
void VisitorPyPrint::VisitPass(PassNode* expr)
{

}