#include "Element.h"
#include <iostream>

// Constructor sets new element as red, all pointers point NULL
Element::Element()
{
    right=NULL;
    left=NULL;
    color = 'r';
}

