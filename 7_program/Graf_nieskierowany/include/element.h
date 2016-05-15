#ifndef ELEMENT_H
#define ELEMENT_H

class element
{
    public:
        friend class list_head;
        int value;
        element* next;
        element();
};

#endif // ELEMENT_H
