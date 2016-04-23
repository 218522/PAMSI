#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "IBinary_tree.h"
#include "Element.h"

class Binary_tree
: public IBinary_tree
{
    public:
        Binary_tree();
        void find(Element* target);
        void add(Element* new_element);
    private:
        Element* root;
};

#endif // BINARY_TREE_H
