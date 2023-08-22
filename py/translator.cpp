#include <cctype>
#include <fstream>
#include <cassert>

#include <sstream>
#include "translator.hpp"
#include "ast.h"
#include "symboltable.h"
#include "errors.h"
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>

#include "VisitorPyPrint.h"

extern std::stack<std::string> fileNames;
extern std::vector<std::string> libPaths;
namespace Language
{

Translator::Translator()
{
}

void Translator::PrepareCommandLineArguments(const int argc, char **argv)
{
    int expectedArgumentCount = SymbolTable::Instance().EntryPoint()->Arguments()->size();

    if (expectedArgumentCount != argc-2)
    {
        std::cerr << WRONG_NUMBER_OF_ARGUMENTS << "script entry point\n";
        exit(EXIT_FAILURE);
    }

    SymbolTable::Instance().PushCommandLineArguments(argc-2, &argv[2]);
}

int Translator::parse(const QString& codestr)
{    
    QFileInfo fileInfo(codestr);
    if (!fileInfo.exists())
        return -1;
    libPaths.push_back("./"); // current path
    std::ifstream in_file(codestr.toStdString().c_str());
    if (!in_file.good())
    {
        std::cerr << BAD_SCRIPT_FILE << std::endl;
        exit(EXIT_FAILURE);
    }
    //fileNames.push("");       // Add the empty file name after last EOF.
    fileNames.push(codestr.toStdString()); // Add the top level file name.
    Lexer lexer(&in_file);
    Parser parser(lexer);

    if (parser.parse() != 0)
    {
        std::cerr << "Parse failed!!\n";
        return 0;
    }
    
    DeclareListNode*  declares = SymbolTable::Instance()._declares;
    int count = declares->size();
    QString str = "";
    for (auto elem : *declares)
    {
        str += elem->toRaw();  
    }
    //std::map<QString, Language::ModuleNode*> modules = SymbolTable::Instance().Modules();
    //int count = modules.size();



    //VisitorPyPrint visitor;
    //for (auto elem : modules)
    //{
    //    Language::ModuleNode* module = elem.second;

    //    module->Accept(visitor);

    //   
    //}
    //str.append(visitor.str);
    str.append("\n");
    std::cout << str.toStdString() << std::endl;
    std::cout << "------RunTime Info:------" << std::endl;
    int expectedArgumentCount = SymbolTable::Instance().EntryPoint()->Arguments()->size();
    ////SymbolTable::Instance().PushCommandLineArguments(0,NULL);
    ////SymbolTable::Instance().EntryPoint()->Execute().toInt();
    //QFile file("D:/_testlpw.txt");
    //bool isOK = file.open(QIODevice::WriteOnly);
    //file.write(str.toStdString().data());
    //file.flush();
    //file.close();
    //QString baseName = fileInfo.baseName();
    //QDir dir=fileInfo.absoluteDir();
    //QString dst = QString("%1/%2.py").arg(dir.absolutePath()).arg(baseName);
    //QFile file(dst);
    // bool isOK = file.open(QIODevice::WriteOnly);
    //file.write(str.toStdString().data());
    //file.flush();
    //file.close();
    return 1;
}
int Translator::parse(int argc, char **argv)
{

   const char* filename = "D:/MainModule1-a.txt";// argv[1];
   libPaths.push_back("./"); // current path
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
   {
       std::cerr << BAD_SCRIPT_FILE << std::endl;
       exit( EXIT_FAILURE );
   }
   //fileNames.push("");       // Add the empty file name after last EOF.
   fileNames.push(filename); // Add the top level file name.
   Lexer lexer(&in_file);
   Parser parser(lexer);

   if( parser.parse() != 0 )
   {
      std::cerr << "Parse failed!!\n";
   }

   PrepareCommandLineArguments(argc, argv);
   std::cout << "------compile Info:------" << std::endl;
  
   QString str = "";
  
   str.append("\n");
   std::cout << str.toStdString() << std::endl;
   std::cout << "------RunTime Info:------" << std::endl;
   QFile file("D:/_testlpw.txt");
   bool isOK = file.open(QIODevice::WriteOnly);
   file.write(str.toStdString().data());
   file.flush();
   file.close();
   return 1;

   //return SymbolTable::Instance().EntryPoint()->Execute().toInt();
}
}
