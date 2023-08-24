#ifndef PYVisitorTypeCheck_h__
#define PYVisitorTypeCheck_h__

#include <vector>

#include "location.hh"
#include <map>
#include "symboltable.h"
#include "Visitor.h"
namespace PyLanguage {

	class VisitorTypeCheck : public Visitor
	{
	public:
		int syntaxErrors{ 0 };
		std::vector<location> ReturnStatementLocations;

	public:
		VisitorTypeCheck(){}
	public:
		void VisitIdentifier(IdentifierNode* expr);
		void VisitArrayIndex(ArrayIndexNode* expr);
		void VisitAssignment(AssignmentNode* expr);
		void VisitDeclarelist(DeclareListNode* retstmt);
		void VisitDimnum(DimNumsNode* fndecl);
		void VisitElseIf(ElseIfNode* expr);
		void VisitFor(ForNode* expr);
		void VisitFuncCall(FunctionCallNode* expr);
		void VisitVariable(VariableNode* expr);
		void VisitIf(IfNode* expr);
		void VisitWhileLoop(WhileNode* expr);
		void VisitStructDeclaration(StructDescNode* expr);
		void VisitInteger(Integer* expr);
		void VisitBoolean(Boolean* expr);
		void VisitStructindex(StructIndexNode* expr);
		void VisitStatementList(StatementListNode* expr);
		void VisitStringLiteral(StringLiteralNode* expr);
		void VisitDouble(NumberLiteralNode* expr);

		void VisitReturn(ReturnNode* expr);
		void VisitParamNode(ParameterNode* expr);
		void VisitOpera(OperatorNode* expr);
		void VisitFunc(FunctionNode* expr);
		void VisitPass(PassNode* expr);
		void VisitForExpr(ForExprNode* expr);
		void VisitBreak(BreakNode* expr);
		void VisitContinue(ContinueNode* expr);
		void VisitFuncCallList(FuncCallsNode* expr);
	};

}
#endif // Visitor_h