#ifndef PYASSIGNMENTNODE_H
#define PYASSIGNMENTNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace PyLanguage
{
    class RobotAbbExport AssignmentNode: public ASTNode
    {
    public:
        AssignmentNode(ASTNode* ,  ASTNode* expression);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitAssignment(this); }
        //QString VarStr();
        QString getName() { return _name; }

    public:
            QString _name;
            ASTNode * _expression;
            ASTNode* _src;
    };
}

#endif // ASSIGNMENTNODE_H
