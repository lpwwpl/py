#ifndef PYFUNCTIONCALLNODE_H
#define PYFUNCTIONCALLNODE_H

#include "astnode.h"

namespace PyLanguage
{
    class RobotAbbExport FunctionCallNode: public ASTNode
    {
    public:
        FunctionCallNode(ASTNode* indent, ListNode<ASTNode> * expressionList=NULL);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitFuncCall(this); }
    public:
            ASTNode* _indent;
            ListNode<ASTNode> * _expressionList;
    };
}

#endif // FUNCTIONCALLNODE_H
