#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "IBinary_tree.h"
#include "Element.h"
#include <string>

class Binary_tree
: public IBinary_tree
{
    public:
        Binary_tree();
        void find(Element* target);
        void add(int value);
        void moving_pre_order(Element* start_element);
        void show_tree();
        void check_black_red_properties1(Element* just_added);
        void check_black_red_properties2(Element* just_added);
        void check_black_red_properties3(Element* just_added);
    private:
        Element* root;
};

#endif // BINARY_TREE_H
