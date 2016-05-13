#ifndef ELEMENT_H
#define ELEMENT_H

class element
{
    friend class list_head;
    int value;
    element* next;
public:
    element();
};

#endif // ELEMENT_H
