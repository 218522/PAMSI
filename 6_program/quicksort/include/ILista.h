#ifndef ILISTA_H
#define ILISTA_H
#include <iostream>
#include <cstdlib>

using namespace std;

struct Element
{
    int dana;
    Element *nastepny;

    Element(int x)
    {
        dana=x;
        nastepny=NULL;
    }
};

class ILista
{
private:

public:
    virtual void dodaj(int x,int nr)=0;
    virtual void usun(int pozycja)=0;
    virtual int get(int nr)=0;
    virtual int get_size()=0;
    virtual Element* get_address(int position)=0;
    virtual int how_far(Element* pointer)=0;
    virtual void show_list()=0;
    virtual void Quicksort(int left_counter, int right_counter)=0;
    virtual void przeszukaj(int a)=0;
};

#endif // LISTA_HH
