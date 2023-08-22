#ifndef RETURNNODE_H
#define RETURNNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport ReturnNode: public ASTNode
    {
    public:
        ReturnNode(ASTNode * expression);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitReturn(this); }
    public:
            ASTNode * _expression;
            Language::location _location;
    };
}

#endif // RETURNNODE_H
