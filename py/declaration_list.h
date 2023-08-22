#ifndef PYDECLARELISTNODE_H
#define PYDECLARELISTNODE_H

#include "astnode.h"
#include "listnode.h"
namespace PyLanguage
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
