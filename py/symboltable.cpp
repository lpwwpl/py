#include "symboltable.h"
#include <map>
#include "ast.h"
#include "errors.h"
#include <memory>
#include <iostream>
#include <thread>
#include <mutex>
using namespace Language;



std::unique_ptr<SymbolTable> SymbolTable::_instance = nullptr;
std::once_flag SymbolTable::_onceFlag;


SymbolTable::SymbolTable()
    : _entrypoint(nullptr)
{
    //DefineTypes("int");
    //DefineTypes("boolean");
    //DefineTypes("string");
    //DefineTypes("double");
    DefineTypes("ROBTARGET");
    DefineTypes("JOINTTARGET");
    DefineTypes("WOBJDATA");
    DefineTypes("ZONEDATA");
    DefineTypes("SPEEDDATA");
    DefineTypes("TOOLDATA");
    DefineTypes("SEAMDATA");
    DefineTypes("WELDDATA");
}

SymbolTable & SymbolTable::Instance()
{
    std::call_once(_onceFlag,
            [] {
                _instance.reset(new SymbolTable);
        });
        return *_instance.get();
}

Language::FunctionNode * SymbolTable::Function(QString * name)
{
    auto fp = _functions[*name];
    if (nullptr == fp)
    {
        //std::cerr << UNDEFINED_FUNCTION << "(" << name->toStdString() << ")\n";
        //exit(EXIT_FAILURE);
    }
    return fp;
}

 bool SymbolTable::DefineFunction(QString * name, Language::FunctionNode *node)
 {
     if (_functions.count(*name) != 0)
     {
         //std::cerr << FUNCTION_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
         //exit(EXIT_FAILURE);
     }

     if ("main" == *name)
         _entrypoint = node;

     _functions[*name] = node;

     return true;
 }

 bool SymbolTable::DefineStructTypes(QString* name, Language::StructDescNode* node)
 {
     if (_structTypes.count(*name) != 0)
     {
         //std::cerr << FUNCTION_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
         //exit(EXIT_FAILURE);
     }

     _structTypes[*name] = node;

     return true;
 }

 bool SymbolTable::DefineTypes(QString name)
 {
    if (TypeNames.count(name.toStdString()) != 0)
    {
        //std::cerr << FUNCTION_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
        //exit(EXIT_FAILURE);
    }

    TypeNames.insert(name.toStdString());

    return true;
 }
 //QString SymbolTable::toString()
 //{
 //    //std::map<QString, Language::FunctionNode*>
 //    QString str = "";
 //    for (auto it : _modules)
 //    {
 //        QString funName = it.first;
 //        Language::ModuleNode* module = it.second;
 //        if (!module)continue;
 //        str += module->toString(1);
 //        str += "\n";
 //    }
 //    //for (auto it: _functions)
 //    //{
 //    //    QString funName = it.first;
 //    //    Language::FunctionNode* func = it.second;
 //    //    if (!func)continue;
 //    //    str += func->toString(1);
 //    //    str += "\n";
 //    //}
 //    return str;
 //}
Language::FunctionNode * SymbolTable::EntryPoint()
{
    if (nullptr == _entrypoint)
    {
        std::cerr << "Dang ! No entrypoint. Bailing out..." << std::endl;
        exit(1);
    }
    return _entrypoint;
}

ActivationRecord * SymbolTable::GetActivationRecord()
{
    if (_activationRecordStack.size() == 0)
        return NULL;
    return _activationRecordStack.top();
}

void SymbolTable::PushAR()
{
    _activationRecordStack.push(new ActivationRecord());
}

void SymbolTable::PopAR()
{
    _activationRecordStack.pop();
}

QVariant SymbolTable::PopArgument()
{
    QVariant retVal = _argumentStack.top();
    _argumentStack.pop();
    return retVal;
}

void SymbolTable::PushArgument(QVariant argument)
{
    _argumentStack.push(argument);
}

void SymbolTable::PushCommandLineArguments(const int argc, char **argv)
{
    for (int i=0; i<argc; i++)
    {
        _argumentStack.push(QVariant(argv[i]));
    }
    _argumentStack.push(argc);
}




void SymbolTable::AssignVariable(QString realVar, enum_v_type type, QString var_type, QVariant value)
{
    VariableRecord v;
    v.value = value;
    v.type = type;
    v.var_type = var_type;
    _variables[realVar] = v;
}


void SymbolTable::DeclareVariable(QString name)
{
    bool isDefinedVar = isDefined(name);
    if (!isDefinedVar)
    {
        _variables[name] = VariableRecord();
    }
}


VariableRecord SymbolTable::GetVariableValue(QString name)
{
    return _variables[name];
}

QString SymbolTable::VariableType(QString name)
{
    if (_variables.count(name) == 0)
    {
        return "";
    }
    VariableRecord vr = _variables[name];
    return getVarType(vr);
}

bool SymbolTable::DefineVariable(QString * name, enum_v_type type, QString var_type)
{
    if (_variables.count(*name) != 0)
    {
        return true;
    }

    VariableRecord r;
    r.type = type;
    r.var_type = var_type;
    _variables[*name] = r;

    return true;
}

void SymbolTable::ClearVariables()
{
    _variables.clear();
}

void SymbolTable::addStructMember(QString structName, QString memType, QString memName) {
    if (this->_structMembers.find(structName) == this->_structMembers.end())
    {
        //LogError("Unknown struct name");
    }
    this->_structMembers[structName].push_back(std::make_pair(memType, memName));
}

long SymbolTable::getStructMemberIndex(QString structName, QString memberName) {
    if (this->_structMembers.find(structName) == this->_structMembers.end()) {
        //LogError("Unknown struct name");
        return 0;
    }
    auto& members = this->_structMembers[structName];
    for (auto it = members.begin(); it != members.end(); it++) {
        if (it->second == memberName) {
            return std::distance(members.begin(), it);
        }
    }

    //LogError("Unknown struct member");

    return 0;
}

QString SymbolTable::getVarType(VariableRecord& vr) 
{
    QString ret = "";

    switch (vr.type)
    {
    case enum_v_type::variable:
        ret = vr.var_type;
        break;
    case enum_v_type::integer:
        ret = "int";
        break;
    case enum_v_type::decimal:
        ret = "double";
        break;
    case enum_v_type::string:
        ret = "string";
        break;
    case enum_v_type::boolean:
        ret = "boolean";
        break;
    case enum_v_type::function:
        ret = vr.var_type;
        break;
    case enum_v_type::identifier:
        ret = vr.var_type;
        break;
    default:break;
    }
    return ret;
}

