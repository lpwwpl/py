#ifndef PYSTATEMENTLISTNODE_H
#define PYSTATEMENTLISTNODE_H

#include "astnode.h"
#include "listnode.h"

namespace PyLanguage
{
class RobotAbbExport StatementListNode: public ListNode<ASTNode>
{
    public:
        StatementListNode(ASTNode * parameter=nullptr);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void compute() override;
        void Accept(Visitor& v) override { v.VisitStatementList(this); }
    };
}

#endif // STATEMENTLISTNODE_H
