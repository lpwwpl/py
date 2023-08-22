#include "assignmentnode.h"
#include "symboltable.h"
#include "errors.h"
#include "listnode.h"
#include "arrayindex.h"
#include "structindexnode.h"


namespace Language
{

    AssignmentNode::AssignmentNode(ASTNode* src, ASTNode* expression) :_src(src),_expression(expression), _name("")        
    {
        StructIndexNode* structIndex = dynamic_cast<StructIndexNode*>(_src);
        ArrayIndexNode* array = dynamic_cast<ArrayIndexNode*>(_src);
        IdentifierNode* iden = dynamic_cast<IdentifierNode*>(_src);
        //AssignmentNode* ass = dynamic_cast<AssignmentNode*>(_src);
        if (array)
        {
            _name = array->m_ident->_name;
            //*_name = array->_name;
        }
        else if (structIndex)
        {
            _name = structIndex->_name;
        }
        else if (iden)
        {
            _name = iden->_name;
        }
        QString typeActual = _expression->getTypeName();


        QString typeExpected = SymbolTable::Instance().VariableType(_name);

        if (typeExpected == "")
        {
            ///
            //SymbolTable::Instance().DefineVariable(&_name, typeActual, _expression.);
        }

        if (typeActual != typeExpected)
        {


            //std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(typeExpected).toStdString() << " (line: " << lineNumber << ")" << std::endl;
            //exit(EXIT_FAILURE);
        }
    }

    QString AssignmentNode::toRaw(uint level)
    {
        QString str;    
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }

        str.append(_src->toRaw());
        str.append(":=");
        str.append(_expression->toRaw());
        //BuildInNode* buildIn = dynamic_cast<BuildInNode*>(_expression);
        //if (buildIn)
        //{
        //    str.append(buildIn->toString());
        //    return str;
        //}

        //ListNode<ASTNode*>* lists_ = dynamic_cast<ListNode<ASTNode*>*>(_expression);
        //if (lists_)
        //    str.append(_expression->toRaw());
        //else
        //    str.append(_expression->toRaw());
        return str;
    }
    QVariant AssignmentNode::Execute()
    {     

        SymbolTable::Instance().GetActivationRecord()->AssignVariable(_name, _expression->Execute());

        return ASTNode::Execute();
    } 
}
