#ifndef PYLISTNODE_H
#define PYLISTNODE_H

#include "astnode.h"

namespace PyLanguage
{

    template <class T >
    class ListNode: public ASTNode, public std::vector<T *>
    {
    public:
        ListNode() {}
        ListNode(T * node) { this->push_back(node); }
    };
}

#endif // LISTNODE_H
