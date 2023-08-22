#include "identifiernode.h"
#include "symboltable.h"

namespace PyLanguage
{
    IdentifierNode::IdentifierNode(QString * name) : _name(*name)
    {
        //_type = SymbolTable::Instance().VariableType(*name);
    }

    QVariant IdentifierNode::Execute()
    {
        return SymbolTable::Instance().GetActivationRecord()->GetVariableValue(_name);      
    }
    QString IdentifierNode::toRaw(uint level)
    {
        QString str = "";
        str.append(_name);
        return str;
    }
}
