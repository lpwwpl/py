#include "functioncallnode.h"


#include "errors.h"
#include "symboltable.h"

namespace PyLanguage
{
    FunctionCallNode::FunctionCallNode(QString * name, ListNode<ASTNode> * expressionList)
            :  ASTNode(), _name(name),
             _expressionList(expressionList)
    {
        auto function = SymbolTable::Instance().Function(name);
        if (!function) { return; }
        auto expectedArguments = function->Arguments();

        //_type = function->getRetType();


        if (expectedArguments->size()>0 && expectedArguments->size() != expressionList->size())
        {
            std::cerr << WRONG_NUMBER_OF_ARGUMENTS << "(" << name->toStdString() << ")\n";
            exit(EXIT_FAILURE);
        }

        for (size_t i=0; i<expectedArguments->size(); i++)
        {
            QString typeExpected = expectedArguments->at(i)->getTypeName();
            QString typeActual = expressionList->at(i)->getTypeName();
            if (typeExpected != typeActual)
            {
                std::cerr << TYPE_CONFLICT << typeActual.toStdString() << " to " << typeExpected.toStdString() << std::endl;
                std::cerr << "in function: " << name->toStdString() << std::endl;
                std::cerr << "argument: " << i << std::endl;
                exit(EXIT_FAILURE);
            }
        }


    }

    QVariant FunctionCallNode::Execute()
    {
        /// ////////////////////////////////////////

        // TODO: Maybe wrong order
        for (auto expression: *_expressionList)
            SymbolTable::Instance().PushArgument(expression->Execute());
        SymbolTable::Instance().PushArgument((int)_expressionList->size());
        PyLanguage::FunctionNode*  func = SymbolTable::Instance().Function(_name);
        if (func)
            return SymbolTable::Instance().Function(_name)->Execute();
        else
            return 0;
    }
    QString FunctionCallNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        //str.append("self.");
        str.append(_name);
        str.append(" ");
        if (_expressionList)
        {
            for (size_t i = 0; i < _expressionList->size(); i++)
            {
                ASTNode* arg = _expressionList->at(i);
                ListNode<ASTNode>* list_arg = dynamic_cast<ListNode<ASTNode>*>(arg);
                if (list_arg)
                {
                    for (auto item : *list_arg)
                    {
                        str.append(item->toRaw());
                    }
                }
                else
                {
                    str.append(arg->toRaw());
                    str.append(",");
                }

            }

            if (str.endsWith(","))
            {
                str = str.mid(0, str.size() - 1);
            }
        }
        str.append(" ;");
        return str;
    }
}
