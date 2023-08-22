#include "statementlistnode.h"
#include "returnnode.h"
#include "symboltable.h"
namespace Language
{
    StatementListNode::StatementListNode(ASTNode * parameter)
    {
        if(parameter)
          push_back(parameter);
    }
    void StatementListNode::compute()
    {
        for (auto statement : *this)
        {
            if (!statement)continue;
            //statement->Execute();
            statement->compute();

            if (dynamic_cast<ReturnNode*>(statement))
                break;
        }
    }
    QVariant StatementListNode::Execute()
    {
        QString str = "";
        for (auto statement: *this)
        {
            if (!statement)continue;
                //statement->Execute();
                SymbolTable::Instance().GetActivationRecord()->SetCurNode(statement);
                str.append(statement->Execute().toString());

            if (dynamic_cast<ReturnNode *>(statement))
                break;
        }
        SymbolTable::Instance().GetActivationRecord()->SetCurNode(NULL);
        return ASTNode::Execute();
    }
    QString StatementListNode::toRaw(uint level)
    {
        QString str = "";

        for (auto statement : *this)
        {

            if (!statement)continue;
            //statement->Execute();
            str.append(statement->toRaw(level));

            IfNode* ifNode = dynamic_cast<IfNode*>(statement);
            ForNode* forNode = dynamic_cast<ForNode*>(statement);
            if (!ifNode && !forNode)
                str.append("\n");
            //if (dynamic_cast<ReturnNode*>(statement))
            //    break;
        }

        return str;
    }
}
