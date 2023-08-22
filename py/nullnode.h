#ifndef NULLNODE_H
#define NULLNODE_H

#include "astnode.h"

namespace Language
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
