#include "stringliteralnode.h"

namespace PyLanguage
{
    StringLiteralNode::StringLiteralNode(QString * value)
        : ASTNode()
    {
        _value = *value;// ->mid(1, value->length() - 2);
    }

    QVariant StringLiteralNode::Execute()
    {
        return _value;
    }
    QString StringLiteralNode::toRaw(uint level)
    {
        QString str = "";
        str.append("\"");
        str.append(_value);
        str.append("\"");
        return str;
    }
}

