#include "returnnode.h"
#include "symboltable.h"

namespace Language
{
    ReturnNode::ReturnNode(ASTNode * expression)
        : _expression(expression)
    {
        _type = enum_v_type::Not_found;
        if(expression)
        _type = _expression->getType();
    }

    QVariant ReturnNode::Execute()
    {
        //std::cout << QString("%1").arg("return").toStdString() << std::endl;

        QVariant returnValue;
        if(!_expression)
            return ASTNode::Execute();
        returnValue = _expression->Execute();
        SymbolTable::Instance().GetActivationRecord()->SetReturnValue(returnValue);
        return ASTNode::Execute();
    }
    QString ReturnNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("return");
        str.append(" ");
        if (_expression)
            str +=_expression->toRaw();
        return str;
    }

}
