#ifndef PYVARIABLERECORD_H
#define PYVARIABLERECORD_H
#include "PreCompiled.h"

namespace PyLanguage
{


    enum class enum_v_type
    {
        Not_found = 0,
        expression,
        variable,
        klass,
        function,
        integer,
        decimal,
        string,
        boolean,
        identifier,
    };

    typedef RobotAbbExport struct VR
    {
        QVariant value;
        //_type
        QString var_type;
        //variableType
        enum_v_type type;

    } VariableRecord;
}

#endif // VARIABLERECORD_H
