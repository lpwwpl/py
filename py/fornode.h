#ifndef FORNODE_H
#define FORNODE_H

#include "astnode.h"

namespace Language
{

    class ForNode: public ASTNode
    {
    public:

        ForNode(ASTNode* identify, ASTNode* from_expression,ASTNode * to_expression,ASTNode* step= nullptr,ASTNode * function_body = nullptr);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitFor(this); }
    public:
            ASTNode * _function_body;
            ASTNode * _to_expression;
            ASTNode* _from_expression;
            ASTNode* _assignment;
            ASTNode* _step;
    };
}

#endif // IFNODE_H
