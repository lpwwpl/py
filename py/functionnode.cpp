#include "functionnode.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    FunctionNode::FunctionNode(ASTNode* type, QString * name, ListNode<ParameterNode> * arguments, StatementListNode * body)
            : ASTNode(),
              _type(type),
              _name(*name),
              _arguments(arguments),
              _body(body)
    {
         SymbolTable::Instance().DefineFunction(name,this);

         for (auto statement: *body)
         {
             if (auto pReturn = dynamic_cast<ReturnNode *>(statement))
             {
                 //int typeActual = pReturn->Type();
                 //if (statement->Type() != _type)
                 //{
                 //    std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(_type).toStdString() << " (line: " << lineNumber << ")" << std::endl;
                 //    exit(EXIT_FAILURE);
                 //}
             }
         }
         //SymbolTable::Instance().ClearVariables();

    }
    void FunctionNode::compute()
    {
        _body->compute();
    }
    QVariant FunctionNode::Execute()
    {
        SymbolTable::Instance().PushAR();
        SymbolTable::Instance().GetActivationRecord()->SetCurFunctionNode(this);
        int argc = SymbolTable::Instance().PopArgument().toInt();
        if (argc != (int)_arguments->size())
        {
            std::cerr << STACK_CORRUPTED;
            exit(EXIT_FAILURE);
        }

        for (int i=0; i<argc; i++)
        {
            QVariant arg = SymbolTable::Instance().PopArgument();
            QString name = _arguments->at(argc-i-1)->Name();
            SymbolTable::Instance().GetActivationRecord()->AssignVariable(name, arg);
        }

        _body->Execute();

        QVariant retVal = SymbolTable::Instance().GetActivationRecord()->GetReturnValue();

        SymbolTable::Instance().GetActivationRecord()->SetCurFunctionNode(NULL);
        SymbolTable::Instance().PopAR();

        return retVal;
    }

    ListNode<ParameterNode> * FunctionNode::Arguments() const
    {
        return _arguments;
    }
    QString FunctionNode::toRaw(uint level)
    {
        QString str = QString::fromLatin1("");
        for (int i = 0; i < level; i++)
        {
            str.append(QString::fromLatin1("    "));
        }
        str += QString::fromLatin1("PROC");
        str += QString::fromLatin1(SPACE);
        str += _name;
        str += QString::fromLatin1("(");
        int count = _arguments->size();
        for (int i = 0; i < count; i++)
        {
            ParameterNode* node = _arguments->at(i);
            str += node->toRaw();
            if (i < (count -1))
            {
                str += ",";
            }
        }
        str += QString::fromLatin1(")");
        str += QString::fromLatin1("\n");
        //str += INTENT;
        //str += _arguments->toString();
        str.append(_body->toRaw(level + 1));
        for (int i = 0; i < level; i++)
        {
            str.append(QString::fromLatin1("    "));
        }
        str += QString::fromLatin1("ENDPROC");
        str += QString::fromLatin1("\n");
        return str;
    }
 
}

