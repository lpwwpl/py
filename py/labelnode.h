#ifndef LABELNODE_H
#define LABELNODE_H

#include "astnode.h"
#include "listnode.h"

namespace Language
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
