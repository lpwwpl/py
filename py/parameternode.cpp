#include "parameternode.h"

#include "symboltable.h"

namespace PyLanguage
{
    ParameterNode::ParameterNode(ASTNode* param, ASTNode * initializer)
            : 
                _param(param),
            _initializer(initializer)
    {
        if (nullptr == initializer)
        {

        }
        //SymbolTable::Instance().DefineVariable(&param->_name, type->getType(), type->getVariablenTypeName());
    }

    QVariant ParameterNode::Execute()
    {
        SymbolTable::Instance().GetActivationRecord()->DeclareVariable(_name);
        if (nullptr != _initializer)
            SymbolTable::Instance().GetActivationRecord()->AssignVariable(_name, _initializer->Execute());
        return ASTNode::Execute();
    }

    QString ParameterNode::Name()
    {
        return "";// _param->_name;
    }

    QString ParameterNode::toRaw(uint level)
    {
        QString ret;
        ret += " ";

        //IdentifierNode* s_type = (IdentifierNode*)(expr->_type);
        //str += s_type->getTypeName();
        //str += " ";
        //IdentifierNode* s_param = (IdentifierNode*)(expr->_param);
        //str += s_param->getTypeName();

        //IdentifierNode* s_type = (IdentifierNode*)(_type);
        //ret += s_type->getName();
        //ret += " ";
        IdentifierNode* s_param = (IdentifierNode*)(_param);
        ret += s_param->getName();
        return ret;
    }

}

