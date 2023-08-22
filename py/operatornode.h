#ifndef OPERATORNODE_H
#define OPERATORNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport OperatorNode: public ASTNode
    {
    public:
        OperatorNode(token::yytokentype type, ASTNode * op1, ASTNode * op2 = nullptr);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitOpera(this); }
        //QString toPython(uint level = 0)override;
    public:
        ASTNode * _op1;
        ASTNode * _op2;
        int _operator;
    };
}

#endif // OPERATORNODE_H
