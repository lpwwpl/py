#ifndef PYPARAMETERNODE_H
#define PYPARAMETERNODE_H

#include "astnode.h"

namespace PyLanguage
{
    class RobotAbbExport ParameterNode: public ASTNode
    {
    public:
        ParameterNode(ASTNode* param, ASTNode * initializer );
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        QString Name();
        void Accept(Visitor& v) override { v.VisitParamNode(this); }
    public:
        QString  _name;
        ASTNode* _param;
        ASTNode * _initializer;
    };
}

#endif // PARAMETERNODE_H
