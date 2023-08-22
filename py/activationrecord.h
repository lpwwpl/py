#ifndef ACTIVATIONRECORD_H
#define ACTIVATIONRECORD_H

#include "ast.h"
#include "variablerecord.h"

#include <QVariant>
#include <QString>
#include <map>
#include "astnode.h"
#include "PreCompiled.h"
//struct Variant
//{
//    QVariant value;
//    int type;
//};

//    multi_array<int, 5, 2, 2, 2, 2> mygrid;
//std::vector<uint> dims;
using namespace Language;

class RobotAbbExport GlobalRecord
{
public:
    GlobalRecord();
    static std::unique_ptr<GlobalRecord> _instance;
    static std::once_flag _onceFlag;

    void AssignVariable(QString name, QVariant value);
    void DeclareVariable(QString name);
    QVariant GetVariableValue(QString name);

    bool isDefined(QString varName);
public:
    static GlobalRecord& Instance();

public:
    QMap<QString, QVariant> _variables;
};

class RobotAbbExport ActivationRecord
{
public:
    ActivationRecord();
    void AssignVariable(QString name,  QVariant value);
    void DeclareVariable(QString name);
    QVariant GetVariableValue(QString name);
    void SetReturnValue(QVariant value);
    QVariant GetReturnValue();
    QVariant accessOperator(QString varName)
    {
        return _variables[varName];
    }

    bool isDefined(QString varName) {
        if (_variables.find(varName) == _variables.end()) return false;
        else return true;//return _variables[varName];
    }
    Language::FunctionNode* GetCurFunctionNode() { return _curFunc; }
    void SetCurFunctionNode(Language::FunctionNode* curFunc)
    {
        _curFunc = curFunc;
    }
    void SetCurNode(ASTNode* node) { _curNode = node; }
    ASTNode* GetCurNode() { return _curNode; }
private:
    QMap<QString, QVariant> _variables;
    QVariant _returnValue;
    Language::FunctionNode* _curFunc;
    ASTNode* _curNode;
};

#endif // ACTIVATIONRECORD_H
