#ifndef STATEMENTLISTNODE_H
#define STATEMENTLISTNODE_H

#include "astnode.h"
#include "listnode.h"

namespace Language
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
