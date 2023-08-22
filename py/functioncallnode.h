#ifndef FUNCTIONCALLNODE_H
#define FUNCTIONCALLNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport FunctionCallNode: public ASTNode
    {
    public:
        FunctionCallNode(QString * name, ListNode<ASTNode> * expressionList=NULL);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitFuncCall(this); }
    public:
            QString * _name;
            ListNode<ASTNode> * _expressionList;
    };
}

#endif // FUNCTIONCALLNODE_H
