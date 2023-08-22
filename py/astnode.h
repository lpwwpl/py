#ifndef PYASTNODE_H
#define PYASTNODE_H

#include <QVariant>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "PreCompiled.h"
#include <boost/signals2.hpp>
#include "Visitor.h"
#include "parser.tab.hpp"
#include "variablerecord.h"

typedef PyLanguage::Parser::token token;
#define SPACE " "
#define INTENT "    "


namespace PyLanguage
{


    struct SAstNodeType
    {
        char command[64];
        enum_v_type eType;
    };

    //class ASTNode;
    //template <class T >
    //class ListNode : public ASTNode, public std::vector<T*>
    //{
    //public:
    //    ListNode() {}
    //    ListNode(T* node) { this->push_back(node); }
    //};
    class RobotAbbExport ASTNode
    {
    public:
        ASTNode();
        virtual ~ASTNode();
        virtual QVariant Execute();
        virtual void compute() {}
        //name
        virtual QString getName() { return QString::fromLatin1(""); }

        //type: int,string,fun return type, var type
        virtual enum_v_type getType() { return _type; }
        //type's string: int,string,fun return type, var type
        virtual QString getVariablenTypeName() const { return QString::fromLatin1(""); }

        //type's string: int,string,fun return type, var type
        virtual QString getTypeName()
        {
            QString ret = QString::fromLatin1("");

            switch (_type)
            {
            case enum_v_type::variable:
                ret = getVariablenTypeName();
                break;
            case enum_v_type::integer:
                ret = QString::fromLatin1("int");
                break;
            case enum_v_type::decimal:
                ret = QString::fromLatin1("double");
                break;
            case enum_v_type::string:
                ret = QString::fromLatin1("string");
                break;
            case enum_v_type::boolean:
                ret = QString::fromLatin1("boolean");
                break;
            case enum_v_type::function:
                ret = getVariablenTypeName();
                break;
            case enum_v_type::identifier:
                ret = getVariablenTypeName();
                break;
            default:break;
            }
            return ret;
        }

        void SetPrefix(bool value) { _prefix = value; }
        virtual void Accept(Visitor& v) {}
        virtual QString toRaw(uint level = 0) { return QString::fromLatin1(""); }

        static void printError(PyLanguage::location location, std::string msg)
        {
            std::cerr
                << location.end.filename
                << ": line "
                << location.begin.line << " column "
                << location.begin.column << "-"
                << location.end.column << ":"
                << msg << std::endl;
        }

        /*! Prints an error message where no source location is available.
         * \param[in] msg      The message to print.
         */
        static void printError(std::string msg)
        {
            std::cerr << msg << std::endl;
        }

    public:
        bool _prefix;
        boost::signals2::signal<void()> signalRunInst;
        boost::signals2::signal<void(ASTNode*)> signalParseInst;
        enum_v_type _type = { enum_v_type::Not_found };
    };


    class RobotAbbExport Integer : public ASTNode
    {
    public:
        explicit Integer(long long value) : value(value) {}
        virtual ~Integer() = default;
        QVariant Execute() override
        {
            return QVariant::fromValue(value);
        }
        QString toRaw(uint level = 0) override { return QString::number(value); }
        enum_v_type getType() override { return enum_v_type::integer; }
        void Accept(Visitor& v) override { v.VisitInteger(this); }

    public:
        long long value{ 0 };
    };

    class RobotAbbExport Boolean : public ASTNode
    {
    public:
        explicit Boolean(int const value) : boolVal(value) {}
        virtual ~Boolean() = default;
        QVariant Execute() override
        {
            return QVariant::fromValue(boolVal);
        }
        QString toRaw(uint level = 0) override
        {
            if (boolVal)
                return QString::fromLatin1("TRUE");
            else
                return QString::fromLatin1("FALSE");
        }
        enum_v_type getType() override { return enum_v_type::boolean; }
        void Accept(Visitor& v) override { v.VisitBoolean(this); }

    public:
        int         boolVal{ 0 };
    };




    class RobotAbbExport ForExprNode : public ASTNode {
    public:
        //QString realName;
        ForExprNode(ASTNode* expression);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitForExpr(this); }
    public:
        ASTNode* _var_expr;
    };

    class RobotAbbExport BreakNode : public ASTNode {
    public:
        //QString realName;
        BreakNode();
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitBreak(this); }
    public:
        //ASTNode* _var_expr;
    };

    class RobotAbbExport ContinueNode : public ASTNode {
    public:
        //QString realName;
        ContinueNode();
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitContinue(this); }
    public:
        //ASTNode* _var_expr;
    };
    class RobotAbbExport PassNode : public ASTNode {
    public:
        //QString realName;
        PassNode();
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitPass(this); }
    public:
        //ASTNode* _var_expr;
    };
}

#endif // ASTNODE_H
