#ifndef LISTA_H
#define LISTA_H
#include "ILista.h"
#include "stoper.h"

class Lista: public ILista
{
private:
    Element *poczatek;
    Element *koniec;
public:
    Lista()
    {
        poczatek=NULL;
        koniec=NULL;
    }
    virtual Element* get_address(int position);
    virtual int how_far(Element* pointer);
    virtual void show_list();
    virtual void Quicksort(int left_counter, int right_counter);
    virtual void dodaj(int x,int nr);
    virtual void usun(int pozycja);
    virtual int get(int nr);
    virtual int get_size();
    virtual void przeszukaj(int a);
};

#endif
