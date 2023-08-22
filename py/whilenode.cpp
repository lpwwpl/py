#include "whilenode.h"

namespace Language
{
    WhileNode::WhileNode(ASTNode * expression, ASTNode * body)
            :  _body(body),
             _expression(expression)
    {
    }

    QVariant WhileNode::Execute()
    {
        while (_expression->Execute().toBool())
        {
            _body->Execute();
        }
        return ASTNode::Execute();
    }
    QString WhileNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("WHILE");
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(" ");
        str.append("DO");
        str.append("\n");


        str.append(_body->toRaw(level + 1));
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("ENDWHILE");
        return str;
    }
}
