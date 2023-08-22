#ifndef PYNULLNODE_H
#define PYNULLNODE_H

#include "astnode.h"

namespace PyLanguage
{
    class RobotAbbExport NullNode : public ASTNode
    {
    public:
        NullNode();
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override {}
    private:

    };
}

#endif // FUNCTIONCALLNODE_H
