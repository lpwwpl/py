#ifndef NUMBERLITERALNODE_H
#define NUMBERLITERALNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport NumberLiteralNode : public ASTNode
    {
    public:
        NumberLiteralNode(double value);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        enum_v_type getType() override { return enum_v_type::decimal; }
        void Accept(Visitor& v) override { v.VisitDouble(this); }
    public:
        double _value;
    };
}

#endif // NUMBERLITERALNODE_H
