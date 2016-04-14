#ifndef LISTA_HH
#define LISTA_HH
#include "ILista.hh"
#include "stoper.hh"

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
    virtual void show_list();
    virtual void Quicksort();
    virtual void dodaj(int x,int nr);
    virtual void usun(int pozycja);
    virtual int get(int nr);
    virtual int get_size();
    virtual void przeszukaj(int a);
};

#endif
