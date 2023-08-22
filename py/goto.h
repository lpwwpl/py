#ifndef PYGOTONODE_H
#define PYGOTONODE_H

#include "astnode.h"

namespace PyLanguage
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
