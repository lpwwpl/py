#include "elseifnode.h"

namespace Language
{
    ElseIfNode::ElseIfNode(ASTNode * expression, ASTNode * bodyTrue)
        : _body(bodyTrue),
          _expression(expression)
    {
    }
    ElseIfNode::ElseIfNode( ASTNode* bodyTrue)
        : _body(bodyTrue), _expression(NULL)
    {
    }


    QVariant ElseIfNode::Execute()
    {
            if (!_expression || _expression->Execute().toBool())
            {
                _body->Execute();
            }
            else
            {
               
            }

        return ASTNode::Execute();
    }
    QString ElseIfNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
       
        if (!_expression)
        {
            str.append("ELSE");
            str.append("\n");
        }
        else if (_expression)
        {
            str.append("ELSEIF");
            str.append(" ");
            str.append(_expression->toRaw());
            str.append(" ");
            str.append("THEN");
            str.append("\n");
        }
        str.append(_body->toRaw(level+1));

        return str;
    }
}
