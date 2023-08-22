#ifndef PY__TRANSLATOR_HPP__
#define PY__TRANSLATOR_HPP__

#include <string>
#include "lexer.hpp"
#include "parser.tab.hpp"

#include "PreCompiled.h"
namespace PyLanguage
{

class RobotAbbExport Translator
{
public:
   Translator();
   int parse(const int argc, char **argv);
   int parse(const QString&, QString& err);
private:
   void PrepareCommandLineArguments(const int argc, char **argv);
};

}
#endif // __TRANSLATOR_HPP__
