#ifndef RECORDNODE_H
#define RECORDNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RecordNode : public ASTNode
    {
    public:
        RecordNode(ASTNode* expression = NULL);

        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitRecord(this); }
    private:
        //QString _name;
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
