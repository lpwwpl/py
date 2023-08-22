#include "activationrecord.h"
#include "dimnumnode.h"

ActivationRecord::ActivationRecord()
{
    //_variables
    QMap<QString, QVariant> globals = GlobalRecord::Instance()._variables;
    for (QString key:globals.keys())
    {
        _variables.insert(key, globals.value(key));
    }
    _curFunc = NULL;
}


void ActivationRecord::AssignVariable(QString name, QVariant value)
{
    _variables[name] = value;
    //if (!name.startsWith("."))
    //{
    //    GlobalRecord::Instance().AssignVariable(name, value);
    //}
    //SymbolTable::Instance().AssignVariable(_name, typeActual,_expression->Execute(), dimList);
}
    


void ActivationRecord::DeclareVariable(QString name)
{
    bool isDefinedVar = isDefined(name);
    if (!isDefinedVar)
    {
        _variables[name] = QVariant(0);
    }
 }


QVariant ActivationRecord::GetVariableValue(QString name)
{
    return _variables[name];
}

void ActivationRecord::SetReturnValue(QVariant value)
{
    _returnValue = value;
}

QVariant ActivationRecord::GetReturnValue()
{
    return _returnValue;
}

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

std::unique_ptr<GlobalRecord> GlobalRecord::_instance = nullptr;
std::once_flag GlobalRecord::_onceFlag;

GlobalRecord::GlobalRecord()
{
   
}

GlobalRecord& GlobalRecord::Instance()
{
    std::call_once(_onceFlag,
        [] {
            _instance.reset(new GlobalRecord);
        });
    return *_instance.get();
}
void GlobalRecord::AssignVariable(QString name, QVariant value)
{
    _variables[name] = value;
}
QVariant GlobalRecord::GetVariableValue(QString name)
{
    return _variables[name];
}

void GlobalRecord::DeclareVariable(QString name)
{
    bool isDefinedVar = isDefined(name);
    if (!isDefinedVar)
    {
        _variables[name] = QVariant();
    }
}
bool GlobalRecord::isDefined(QString varName) {
    if (_variables.find(varName) == _variables.end()) return false;
    else return true;//return _variables[varName];
}
