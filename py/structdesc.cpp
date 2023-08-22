#include "structdesc.h"
#include "symboltable.h"
#include "errors.h"



namespace PyLanguage
{
    StructDescNode::StructDescNode(IdentifierNode* id, ASTNode * body)
            : ASTNode(),
              _id(id), _parent(nullptr),
              _body(body)
    {
         SymbolTable::Instance().DefineTypes(_id->_name);
    }
    StructDescNode::StructDescNode(IdentifierNode* id, ASTNode* parent, ASTNode* body) : ASTNode(),
        _id(id),_parent(parent),
        _body(body)
    {
        SymbolTable::Instance().DefineTypes(_id->_name);
    }

    void StructDescNode::compute()
    {

    }
    QVariant StructDescNode::Execute()
    {


        return QVariant();
    }

    QString StructDescNode::toRaw(uint level)
    {
        QString str = QString::fromLatin1("");
        for (int i = 0; i < level; i++)
        {
            str.append(QString::fromLatin1("    "));
        }
        str += QString::fromLatin1("RECORD");
        str += QString::fromLatin1(SPACE);
        str += _id->_name;
        str += QString::fromLatin1("\n");
        //str += INTENT;
        //str += _arguments->toString();
        str.append(_body->toRaw(level + 1));
        for (int i = 0; i < level; i++)
        {
            str.append(QString::fromLatin1("    "));
        }
        str += QString::fromLatin1("ENDRECORD");
        str += QString::fromLatin1("\n");
        return str;
    }
}

