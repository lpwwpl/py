#ifndef DECLARELISTNODE_H
#define DECLARELISTNODE_H

#include "astnode.h"
#include "listnode.h"
namespace Language
{
    class RobotAbbExport DeclareListNode : public ListNode<ASTNode>
    {
    public:
        DeclareListNode(ASTNode* caseexpr);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitDeclarelist(this); }
    private:

    };
}

#endif // FUNCTIONCALLNODE_H
