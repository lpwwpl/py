#ifndef GOTONODE_H
#define GOTONODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport GotoNode : public ASTNode
    {
    public:
        GotoNode(ASTNode* expression);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override {}
    private:
        ASTNode* _expression;
        ASTNode* _topParent;
    };
}

#endif // FUNCTIONCALLNODE_H
