#ifndef PYIFNODE_H
#define PYIFNODE_H

#include "astnode.h"

namespace PyLanguage
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
