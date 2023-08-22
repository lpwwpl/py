#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include "astnode.h"
#include "dimnumnode.h"
#include "identifiernode.h"
//#include "location.hh"
enum enum_v_scope
{
    PERS = 0,
    TASK_PERS = 1,

    eCONST =2,
    VAR=3,

};


namespace Language
{
    class RobotAbbExport VariableNode: public ASTNode
    {
    public:
        //QString* name
        VariableNode(int e_scope, IdentifierNode* e_type, ASTNode* expression, location& loc);
        VariableNode(int e_scope, IdentifierNode* e_type, ASTNode* src, ASTNode* expression, location& loc);
        //VariableNode(int e_scope, int e_type, QString* name, ASTNode*);
        //VariableNode(int e_scope, ASTNode* e_type, ASTNode*,ASTNode*);
        virtual QString getName() override { return _name; }
        enum_v_type getType() override { return enum_v_type::variable; }
        QString getVariablenTypeName() const override  { return _e_type->_name; }
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitVariable(this); }
    public:
        int _e_scope;
        IdentifierNode* _e_type{ nullptr };
        ASTNode* _src{ nullptr };
        //ASTNode* _dim_num_stm;
        ASTNode* _expression{ nullptr };
        QString _name;
        location _location;
        
    };
}

#endif // ASSIGNMENTNODE_H
