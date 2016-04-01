#ifndef LIST_HEAD_H
#define LIST_HEAD_H
#include "element.h"

class list_head
{
    public:
        list_head();
        element * first;
        void add_element();
};

#endif // LIST_HEAD_H
