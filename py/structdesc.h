#ifndef PYSTRUCTDESCNODE_H
#define PYSTRUCTDESCNODE_H

#include "astnode.h"

namespace PyLanguage
{
    class RobotAbbExport StructDescNode: public ASTNode
    {
    public:
        StructDescNode(IdentifierNode* id, ASTNode * body);
        StructDescNode(IdentifierNode* id, ASTNode* parent,ASTNode* body);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        enum_v_type getType() override { return enum_v_type::klass; }
        void Accept(Visitor& v) override { v.VisitStructDeclaration(this); }
        QString GetName() { return _name; }
        void compute() override;
    public:
        ASTNode* _body;
        ASTNode* _parent;
        IdentifierNode* _id;
        QString _name;
    };
}

#endif // FUNCTIONNODE_H
