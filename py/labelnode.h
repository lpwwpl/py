#ifndef PYLABELNODE_H
#define PYLABELNODE_H

#include "astnode.h"
#include "listnode.h"

namespace PyLanguage
{
class RobotAbbExport LabelNode: public ASTNode
{
public:
    ASTNode* _id;

    public:
        LabelNode(ASTNode * id);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override {}
    };
}

#endif // STATEMENTLISTNODE_H
