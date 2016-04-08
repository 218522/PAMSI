#ifndef KOLEJKA_HEAD_H
#define KOLEJKA_HEAD_H
#include "element.h"

class kolejka_head
{
    public:
        kolejka_head();
        void move_out_first();
        void get_at_back();
        int size();
    private:
        element* first; //pointer to first element
        element* last;  //pointer to last element
};

#endif // KOLEJKA_HEAD_H
