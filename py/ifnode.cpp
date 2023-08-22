#include "ifnode.h"
#include "listnode.h"
#include "elseifnode.h"
namespace Language
{
    IfNode::IfNode(ASTNode * expression, ASTNode * bodyTrue, ASTNode * bodyFalse)
        : ASTNode(),_bodyTrue(bodyTrue),
          _bodyFalse(bodyFalse),
          _expression(expression)
    {
    }



    QVariant IfNode::Execute()
    {
        if (nullptr == _bodyFalse)
        {
            if ( _expression->Execute().toBool())
            {     
                _bodyTrue->Execute();
            }
        }
        else
        {
            if (_expression->Execute().toBool())
            {
                _bodyTrue->Execute();
            }
            else
            {
                _bodyFalse->Execute();
            }
        }
        return ASTNode::Execute();
    }


    QString IfNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("if");
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(" ");
        str.append("then");
        str.append("\n");
        if (!_bodyTrue)
        {
            str.append("\n");
        }
        else
        {
            str.append(_bodyTrue->toRaw(level + 1));
        }

        if (_bodyFalse)
        {
            ListNode<ElseIfNode>* elseifs = dynamic_cast<ListNode<ElseIfNode>*>(_bodyFalse);
            
            for (auto statement : *elseifs)
            {

                if (!statement)continue;
                ElseIfNode* elseif = dynamic_cast<ElseIfNode*>(statement);
                //statement->Execute();
                str.append(elseif->toRaw(level));
            }

            str.append(_bodyFalse->toRaw(level + 1));
        }
        str.append("\n");
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("endif");
        str.append("\n");
        return str;
    }
}
