#include "variable.h"
#include "symboltable.h"
#include "errors.h"
#include "arrayindex.h"


namespace PyLanguage
{
    VariableNode::VariableNode(int e_scope, IdentifierNode* e_type, ASTNode* src, ASTNode* expression, location& loc) :ASTNode(), _e_scope(e_scope), _e_type(e_type), _src(src), _expression(expression), _location(loc)
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
            SymbolTable::Instance().DefineVariable(&_name, enum_v_type::variable, typeActual);
        }

        if (typeActual != typeExpected)
        {


            //std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(typeExpected).toStdString() << " (line: " << lineNumber << ")" << std::endl;
            //exit(EXIT_FAILURE);
        }

    }

    VariableNode::VariableNode(int e_scope, IdentifierNode* e_type, ASTNode* expression, location& loc) :ASTNode(), _e_scope(e_scope), _e_type(e_type), _src(expression), _expression(nullptr), _location(loc)
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
        QString typeExpected = SymbolTable::Instance().VariableType(_name);

        if (typeExpected == "")
        {
            
            //std::cerr << UNDEFINED_VARIABLE << " var:"  << _name.toStdString() << std::endl;
            return;
        }

    }
    

    QVariant VariableNode::Execute()
    {

        return SymbolTable::Instance().GetActivationRecord()->GetVariableValue(_name);
    }
    QString VariableNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        //AssignmentNode* assign = dynamic_cast<AssignmentNode*>(_expression);
        switch (_e_scope)
        {
        case  PERS:
        {
            str.append("PERS");
        }
        break;
        case   TASK_PERS:
        {
            str.append("TASK PERS");
        }
        break;

        case   eCONST:
        {
            str.append("CONST");
        }
        break;
        case    VAR:
        {
            str.append("VAR");
        }
        break;
        default:
            break;
        }
        str.append(" ");


        IdentifierNode* type = dynamic_cast<IdentifierNode*>(_e_type);
        if (type)
        {
            str.append(type->_name);

            str.append(" ");
        }
        if (_src)
        {
            str.append(_src->toRaw());
            if (_expression)
            {
                str.append(":=");
                str.append(_expression->toRaw());
            }
        }
        else
        {
            if (_expression)
            {
                str.append(_expression->toRaw());
            }
        }
        str.append(";");
        str.append("\n");
        return str;
    } 
}
