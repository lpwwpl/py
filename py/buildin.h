#ifndef BUILDINNODE_H
#define BUILDINNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport BuildInNode : public ASTNode
    {
    public:
        BuildInNode(QString*, ASTNode*);
        QVariant Execute() override;
        void Accept(Visitor& v) override {}
    private:
        QString _name;
        ASTNode* _expression;
        int _type;
    };
}

#endif // FUNCTIONCALLNODE_H
