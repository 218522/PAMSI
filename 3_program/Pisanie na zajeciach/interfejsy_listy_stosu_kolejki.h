#ifndef INTERFEJSY_LIST_STOSU_KOLEJKI_H
#define INTERFEJSY_LIST_STOSU_KOLEJKI_H
#include "element.h"
#include<iostream>


//!! Interfejsy dla listy, stosu, kolejki !!

class Interfejs_lista{
    public:
        virtual int add(element &n_element, int n_value) =0;
        virtual void remove(int position) =0;
        virtual element get() =0;
        virtual int size() =0;
}

class Interfejs_stos{
    public:
        virtual element pop() =0;
        virtual int push() =0;
        virtual int size() =0;
}

class Interfejs_kolejka{
    public:
        virtual int move_out_first() =0;
        virtual int get_at_back() =0;
        virtual int size() =0;
}
#endif
