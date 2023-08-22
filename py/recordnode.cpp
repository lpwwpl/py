#include "recordnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    RecordNode::RecordNode(ASTNode* dim/*dimListType* dim*/) :_expression(dim)
    {

    }

    QVariant RecordNode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString RecordNode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("Set ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
