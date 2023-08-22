#ifndef PYRETURNNODE_H
#define PYRETURNNODE_H

#include "astnode.h"

namespace PyLanguage
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
            PyLanguage::location _location;
    };
}

#endif // RETURNNODE_H
