#include "fornode.h"
#include "assignmentnode.h"
#include "symboltable.h"
namespace Language
{
    ForNode::ForNode(ASTNode * assignment, ASTNode* from_expression,ASTNode * to_expression, ASTNode* step, ASTNode * function_body)
        : ASTNode(),_assignment(assignment),_from_expression(from_expression),
          _to_expression(to_expression),
         _step(step),
         _function_body(function_body)
    {

    }

    QVariant ForNode::Execute()
    {
        IdentifierNode* iden = dynamic_cast<IdentifierNode*>(_assignment);
        //assign->Execute();

        int stepInt = 1;
        if(_step)
         stepInt = _step->Execute().toInt();

        QString realName = iden->_name;   

        int from = _from_expression->Execute().toInt();
        int v_int = from;
        int to = _to_expression->Execute().toInt();
        for(; v_int <=to;)
        {
            if(_function_body)
                _function_body->Execute();
            v_int = v_int + stepInt;
            //SymbolTable::Instance().GetActivationRecord()->AssignVariable(name, v_int, dim);
        }
        return ASTNode::Execute();
    }
    QString ForNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("for");
        str.append(" ");
        //AssignmentNode* assign = dynamic_cast<AssignmentNode*>(_assignment);
        str.append(_assignment->toRaw());
        str.append(" ");
        str.append("from");
        str.append(" ");
        str.append(_from_expression->toRaw());
        str.append(" ");
        str.append("to");
        str.append(_to_expression->toRaw());
        str.append(" ");
        str.append("do");
        str.append("\n");
        level = level + 1;
        str.append(_function_body->toRaw(level));
        str.append("endfor");
        str.append("\n");
        return str;
    }
}
