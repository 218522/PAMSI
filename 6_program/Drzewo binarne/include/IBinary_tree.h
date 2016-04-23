#ifndef IBINARY_TREE_H
#define IBINARY_TREE_H
#include "Element.h"

class IBinary_tree
{
    public:
        virtual void add(Element* n_element)=0;
        virtual void find(Element* target)=0;
};

#endif // IBINARY_TREE_H
