#include "astnode.h"

#include "listnode.h"

namespace Language
{

    ASTNode::ASTNode()
        : _prefix(true)
    {
    }
    
    QVariant ASTNode::Execute()
    {
        return QVariant();
    }


    ASTNode::~ASTNode()
    {
    }



    ForExprNode::ForExprNode(ASTNode* expression) :ASTNode(), _var_expr(expression)
    {
   

    }

    QVariant ForExprNode::Execute()
    {
        QString str;// = toString();
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return str;
    }

    QString ForExprNode::toRaw(uint level)
    {
        QString str = "";
        str += _var_expr->toRaw(level);
        return str;
    }



    BreakNode::BreakNode() :ASTNode()
    {


    }

    QVariant BreakNode::Execute()
    {
        QString str;// = toString();
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return str;
    }

    QString BreakNode::toRaw(uint level)
    {
        QString str = "break";
        return str;
    }
    ContinueNode::ContinueNode() :ASTNode()
    {


    }

    QVariant ContinueNode::Execute()
    {
        QString str;// = toString();
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return str;
    }

    QString ContinueNode::toRaw(uint level)
    {
        QString str = "continue";
        return str;
    }

    PassNode::PassNode() :ASTNode()
    {


    }

    QVariant PassNode::Execute()
    {
        QString str;// = toString();
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return str;
    }

    QString PassNode::toRaw(uint level)
    {
        QString str = "pass";
        return str;
    }
}
