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
        void check_black_red_properties(Element* just_added);
        Element* check_black_red_properties_met_1(Element* just_added);
        Element* check_black_red_properties_met_2(Element* just_added);
        Element* check_black_red_properties_met_3(Element* just_added);
    private:
        Element* root;
};

#endif // BINARY_TREE_H
