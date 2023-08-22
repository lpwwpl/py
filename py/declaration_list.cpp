#include "declaration_list.h"

#include "symboltable.h"
#include "errors.h"


namespace Language
{
    DeclareListNode::DeclareListNode(ASTNode* caseexpr)
    {
        SymbolTable::Instance()._declares = this;
        push_back(caseexpr);
    }

    QVariant DeclareListNode::Execute()
    {
        //for (auto statement : *this)
        //{
        //    statement->Execute();
        //    if (dynamic_cast<NumberLiteralNode*>(statement))
        //        break;
        //}

        return ASTNode::Execute();
    }
    QString DeclareListNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        for (auto statement : *this)
        {

            if (!statement)continue;
            //statement->Execute();
            str.append(statement->toRaw(level));
        }


        return str;
    }
}
