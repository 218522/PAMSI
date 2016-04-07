#ifndef ELEMENT_H
#define ELEMENT_H


class element
{
    public:
        element();
    private:
        friend class stos_head;
        element* next;
        int value;
};

#endif // ELEMENT_H
