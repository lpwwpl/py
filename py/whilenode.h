#ifndef WHILENODE_H
#define WHILENODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport WhileNode: public ASTNode
    {
    public:
        WhileNode(ASTNode * expression, ASTNode * body);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitWhileLoop(this); }
    public:
            ASTNode * _body;
            ASTNode * _expression;
    };
}

#endif // WHILENODE_H
