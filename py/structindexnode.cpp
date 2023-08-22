#include "structindexnode.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    StructIndexNode::StructIndexNode(ASTNode* left, IdentifierNode* right/*dimListType* dim*/):_left(left),  _right(right)
    {
        //DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        //dimListType* dimList=NULL;
        //if (dimNode)
        //    dimList = &(dimNode->tempDimList);
        //_realVar = SymbolTable::Instance().CalcRealVarName(*name, dimList);
        //int typeExpected = SymbolTable::Instance().VariableType(_realVar);
        //if (typeExpected == -1)
        //{
        //    return;
        //}
        _name += left->toRaw();
        _name += ".";
        _name += right->toRaw();
    }

    QVariant StructIndexNode::Execute()
    {
        //DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        //dimListType* dimList = NULL;
        //if (dimNode)
        //    dimList = &(dimNode->tempDimList);
        //QString realVar = SymbolTable::Instance().CalcRealVarName(_name, dimList);
        QVariant v;// = SymbolTable::Instance().GetActivationRecord()->GetVariableValue(_realVar);

        //std::cout << toString().toStdString() ;
        return QVariant();
        //return ASTNode::Execute();
    }
    QString StructIndexNode::toRaw(uint level)
    {
       
        QString ret = _name;
        return ret;
    }
}
