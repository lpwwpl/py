#ifndef STRUCTINDEXNODE_H
#define STRUCTINDEXNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class StructIndexNode: public ASTNode
    {
    public:
        StructIndexNode(ASTNode* left, IdentifierNode* right);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitStructindex(this); }
    public:
        ASTNode* _left;
        IdentifierNode* _right;
        QString _name;
    };
}

#endif // ASSIGNMENTNODE_H
