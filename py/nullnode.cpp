#include "nullnode.h"

#include "symboltable.h"
#include "errors.h"

namespace PyLanguage
{
    NullNode::NullNode()
    {
    }

    QVariant NullNode::Execute()
    {


        return ASTNode::Execute();
    }

    QString NullNode::toRaw(uint level )
    {
        return "NULL";
    }
}
