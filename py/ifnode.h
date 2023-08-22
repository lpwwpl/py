#ifndef IFNODE_H
#define IFNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport IfNode: public ASTNode
    {
    public:
        IfNode(ASTNode * expression, ASTNode * bodyTrue, ASTNode * bodyFalse = nullptr);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitIf(this); }
    public:
            ASTNode * _bodyTrue;
            ASTNode * _bodyFalse;
            ASTNode * _expression;
    };
}

#endif // IFNODE_H
