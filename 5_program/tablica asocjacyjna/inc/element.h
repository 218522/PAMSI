#ifndef ELEMENT_H
#define ELEMENT_H
#include "string"

class element
{
    friend class list_head;
    public:
        std::string name;
        int value;
        element();
    private:
        element* next;
};

#endif // ELEMENT_H
