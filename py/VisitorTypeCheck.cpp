
#include "VisitorTypeCheck.h"
using namespace PyLanguage;

#include "ast.h"

void VisitorTypeCheck::VisitIdentifier(IdentifierNode* expr)
{}

void VisitorTypeCheck::VisitArrayIndex(ArrayIndexNode* expr)
{
	//ListNode<ASTNode>* tempDimRawList = dynamic_cast<ListNode<ASTNode>*>(expr->m_exprs);
	//if (tempDimRawList)
	//{
	//	int count = tempDimRawList->size();
	//	for (int i = 0; i < count; i++)
	//	{
	//		tempDimRawList->at(i)->Accept(*this);
	//	}
	//}
}
void VisitorTypeCheck::VisitAssignment(AssignmentNode* expr)
{



}

void VisitorTypeCheck::VisitDeclarelist(DeclareListNode* retstmt)
{}
void VisitorTypeCheck::VisitDimnum(DimNumsNode* fndecl)
{}
void VisitorTypeCheck::VisitElseIf(ElseIfNode* expr)
{}
void VisitorTypeCheck::VisitFor(ForNode* expr)
{}
void VisitorTypeCheck::VisitFuncCall(FunctionCallNode* expr)
{}
void VisitorTypeCheck::VisitVariable(VariableNode* expr)
{
	//if (TypeNames.count(expr->_name.toStdString()) == 0) 
	//{
	//	ASTNode::printError(expr->_location, "Unknown type for decalration of " + expr->_name.toStdString());
	//	++syntaxErrors;
	//}

}
void VisitorTypeCheck::VisitIf(IfNode* expr)
{}
void VisitorTypeCheck::VisitWhileLoop(WhileNode* expr)
{

}
void VisitorTypeCheck::VisitStructDeclaration(StructDescNode* expr)
{
	//TypeNames.emplace(expr->_name);
	//if (_structTypes.count(expr->_name) != 0)
	//{
	//}

	//_structTypes[expr->_name] = expr;
	//if (TypeNames.count(expr->_name.toStdString()) == 0)
	//{
	//	TypeNames.emplace(expr->_name);
	//}
	//expr->_arguments->Accept(*this);
}

void VisitorTypeCheck::VisitInteger(Integer* expr)
{}
void VisitorTypeCheck::VisitBoolean(Boolean* expr)
{}

void VisitorTypeCheck::VisitStructindex(StructIndexNode* expr)
{}

void VisitorTypeCheck::VisitStatementList(StatementListNode* expr)
{
	for (auto stmt : *expr) {
		stmt->Accept(*this);
	}
}
void VisitorTypeCheck::VisitStringLiteral(StringLiteralNode* expr)
{

}

void VisitorTypeCheck::VisitReturn(ReturnNode* expr)
{
	ReturnStatementLocations.push_back(expr->_location);
}
void VisitorTypeCheck::VisitParamNode(ParameterNode* expr)
{

}
void VisitorTypeCheck::VisitOpera(OperatorNode* expr)
{

}

void VisitorTypeCheck::VisitFunc(FunctionNode* expr)
{
	ReturnStatementLocations.clear();
	StatementListNode* body = expr->_body;

	for (auto stmt : *body) {
		stmt->Accept(*this);
	}
	auto retType = expr->getRetType();
	if (ReturnStatementLocations.size() > 1 && retType->_name == "var")
	{
		QString errMsg = QString("Too many return statement in function '%1()' for return type deduction.\nThe possible statements are:").arg( expr->_name);
		ASTNode::printError(expr->_location, errMsg.toStdString());
		std::stringstream s;
		for (auto loc : ReturnStatementLocations) {
			s << "    " << loc.end.filename << ":" << loc.begin.line << ":" << loc.begin.column << " return ...\n";
		}
		ASTNode::printError(s.str());
		syntaxErrors++;
	}
}

void VisitorTypeCheck::VisitDouble(NumberLiteralNode* expr)
{

}

void VisitorTypeCheck::VisitForExpr(ForExprNode* expr)
{

}
void VisitorTypeCheck::VisitBreak(BreakNode* expr)
{

}
void VisitorTypeCheck::VisitContinue(ContinueNode* expr)
{

}
void VisitorTypeCheck::VisitPass(PassNode* expr)
{

}