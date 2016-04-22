#include "Binary_tree.h"
#include <iostream>
#include "Element.h"

using namespace std;

// Constructor creates root, sets root color as black
Binary_tree::Binary_tree()
{
    Element* n_element = new Element;
    root=n_element;
    root->color = 'b';
    cout<<"Set ROOT value: ";
    cin>>root->value;
}

void Binary_tree::add(Element* n_element){

}

void Binary_tree::find(Element* target){

}
