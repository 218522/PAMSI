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
    void QS();
    virtual void dodaj(int x,int nr);
    virtual void usun(int pozycja);
    virtual int get(int nr);
    virtual int get_size();
    virtual void przeszukaj(int a);

};

#endif
