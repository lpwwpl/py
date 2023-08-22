#ifndef PYSTRINGLITERALNODE_H
#define PYSTRINGLITERALNODE_H

#include "astnode.h"

namespace PyLanguage
{
    class RobotAbbExport StringLiteralNode : public ASTNode
    {
    public:
        StringLiteralNode(QString * value);
        QString toRaw(uint level = 0) override;
        enum_v_type getType() override { return enum_v_type::string; }
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitStringLiteral(this); }
    public:
        QString _value;
        //bool bIsType;
    };
}


#endif // STRINGLITERALNODE_H
