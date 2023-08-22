#ifndef PYELSEIFNODE_H
#define PYELSEIFNODE_H

#include "astnode.h"

namespace PyLanguage
{
    class RobotAbbExport ElseIfNode: public ASTNode
    {
    public:
        ElseIfNode(ASTNode* body);
        ElseIfNode(ASTNode * expression, ASTNode * body);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitElseIf(this); }
    public:
            ASTNode * _body;
            ASTNode * _expression;
    };
}

#endif // IFNODE_H
