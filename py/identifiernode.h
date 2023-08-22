#ifndef PYIDENTIFIERNODE_H
#define PYIDENTIFIERNODE_H

#include "astnode.h"
#include "listnode.h"
namespace PyLanguage
{
    class RobotAbbExport IdentifierNode : public ASTNode
    {
    public:
        IdentifierNode(QString * name);
        QVariant Execute() override;
        QString toRaw(uint level = 0);
        enum_v_type getType() override { return enum_v_type::identifier; }
        QString getVariablenTypeName() const override { return _name; }
        virtual void Accept(Visitor& v) { v.VisitIdentifier(this); }
        QString getName() override { return _name; }
    public:
        QString _name;
        PyLanguage::location location;
        //bool isType = false;
    };
}

#endif // IDENTIFIERNODE_H
