#include "arrayindex.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    ArrayIndexNode::ArrayIndexNode(IdentifierNode* name,  ASTNode* elem):m_ident(name), m_exprs(elem)
    {
        
        ListNode<ASTNode>* tempDimRawList = dynamic_cast<ListNode<ASTNode>* >(elem);
        QString str = m_ident->_name;

        if (tempDimRawList)
        {

            str.append("[");
            int count = tempDimRawList->size();
            for (int i = 0; i < count; i++)
            {
                str.append(tempDimRawList->at(i)->toRaw());
                str.append(",");
            }
            if (str.endsWith(","))
            {
                str = str.mid(0, str.size() - 1);
            }
            str.append("]");
        }
        _name = str;
        //name,a{0,2}
    }

    QVariant ArrayIndexNode::Execute()
    {
      
        QVariant v = SymbolTable::Instance().GetActivationRecord()->GetVariableValue(_name);

        //std::cout << toString().toStdString() ;
        return v;
        //return ASTNode::Execute();
    }
    QString ArrayIndexNode::toRaw(uint level)
    {
        QString str = "";
      

        return str;
    }
}
