#include "numberliteralnode.h"

namespace PyLanguage
{
    NumberLiteralNode::NumberLiteralNode(double value)
        : ASTNode(),
          _value(value)
    {
    }

    QVariant NumberLiteralNode::Execute()
    {
        return QString("%1").arg(_value);
    }

    QString NumberLiteralNode::toRaw(uint level)
    {
        return QString::number(_value,'g');
    }
}

