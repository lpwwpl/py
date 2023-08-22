#ifndef Visitor_h__
#define Visitor_h__



namespace Language {
	class IdentifierNode;
	class ArrayIndexNode;
	class AssignmentNode;	
	class DeclareListNode;
	class DimNumsNode;
	class ElseIfNode;
	class ForNode;
	class FunctionCallNode;
	class VariableNode;
	class IfNode;
	class WhileNode;
	class StructDescNode;
	class StructIndexNode;
	class StatementListNode;
	class FunctionNode;	
	class ReturnNode;
	class Boolean;
	class Integer;
	class StringLiteralNode;
	class ParameterNode;
	class OperatorNode;	
	class NumberLiteralNode;
	class ForExprNode;
	class BreakNode;
	class ContinueNode;
	class PassNode;
	class Visitor
	{
	public:
		virtual void VisitIdentifier(IdentifierNode* expr) = 0;
		virtual void VisitArrayIndex(ArrayIndexNode* expr) = 0;
		virtual void VisitAssignment(AssignmentNode* expr) = 0;
		virtual void VisitDeclarelist(DeclareListNode* retstmt) = 0;
		virtual void VisitDimnum(DimNumsNode* fndecl) = 0;
		virtual void VisitElseIf(ElseIfNode* expr) = 0;
		virtual void VisitFor(ForNode* expr) = 0;
		virtual void VisitFuncCall(FunctionCallNode* expr) = 0;
		virtual void VisitVariable(VariableNode* expr) = 0;
		virtual void VisitIf(IfNode* expr) = 0;
		virtual void VisitWhileLoop(WhileNode* expr) = 0;
		virtual void VisitStructDeclaration(StructDescNode* expr) = 0;
		virtual void VisitInteger(Integer* expr) = 0;
		virtual void VisitBoolean(Boolean* expr) = 0;
		virtual void VisitStructindex(StructIndexNode* expr) = 0;
		virtual void VisitStatementList(StatementListNode* expr) = 0;
		virtual void VisitStringLiteral(StringLiteralNode* expr) = 0;
		virtual void VisitDouble(NumberLiteralNode* expr) = 0;
		virtual void VisitReturn(ReturnNode* expr) = 0;
		virtual void VisitParamNode(ParameterNode* expr) = 0;
		virtual void VisitOpera(OperatorNode* expr) = 0;

		virtual void VisitFunc(FunctionNode* expr) = 0;

		virtual void VisitForExpr(ForExprNode* expr) = 0;
		virtual void VisitBreak(BreakNode* expr) = 0;
		virtual void VisitContinue(ContinueNode* expr) = 0;
		virtual void VisitPass(PassNode* expr) = 0;
	};

}
#endif // Visitor_h