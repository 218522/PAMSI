#ifndef STOS_HEAD_H
#define STOS_HEAD_H
#include "element.h"

class stos_head
{
    public:
        stos_head();
        int add();
        void remove();
        int size();
    private:
        element* last;
};

#endif // STOS_HEAD_H
