#ifndef PYNUMBERLITERALNODE_H
#define PYNUMBERLITERALNODE_H

#include "astnode.h"

namespace PyLanguage
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
