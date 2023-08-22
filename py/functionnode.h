#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include "astnode.h"
#include "identifiernode.h"
namespace Language
{
    class RobotAbbExport FunctionNode: public ASTNode
    {
    public:
        FunctionNode(ASTNode* type, QString * name, ListNode<ParameterNode> * arguments, StatementListNode * body);
        QVariant Execute() override;
        ListNode<ParameterNode> * Arguments() const ;
        QString toRaw(uint level = 0) override;
        virtual QString getName() override  { return _name; }
        QString getVariablenTypeName() const override { return _ret_type->getTypeName(); }

        enum_v_type getType() override { return enum_v_type::function; }
        void Accept(Visitor& v) override { v.VisitFunc(this); }
        StatementListNode* GetBody() { return _body; }
        ListNode<ParameterNode>* GetArguments() { return _arguments; }
        QString GetName() { return _name; }
        void compute() override;
        IdentifierNode* getRetType() const { return _ret_type; }

    public:
        ListNode<ParameterNode> * _arguments;
        StatementListNode * _body;
        IdentifierNode* _ret_type{ nullptr };
        QString _name;
        ASTNode* _type;
        Language::location _location;
    };
}

#endif // FUNCTIONNODE_H
