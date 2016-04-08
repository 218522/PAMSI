#ifndef TABLICA_DYNAMICZNA_HH
#define TABLICA_DYNAMICZNA_HH
#include <iostream>
#include <fstream>
#include "Interfejs.hh"
#include "stoper.hh"

using namespace std;

class tablica_dyn: public Interfejs
{
private:
    int rozmiar;
    int licznik;
    int *tablica;
    void wypisz();
    void powieksz(int o_ile);
    void powieksz2();
    void dopisz();
    bool czy_miejsce();
    void suma();
    void zapisz();
    int get_licznik();
    int get_rozmiar();
    void Algorytm1(int ile);
    void Algorytm2(int ile);
    void Algorytm3(int ile);
public:
    tablica_dyn(int x=10, int y=0)
    {
        rozmiar=x;
        licznik=y;
        tablica=new int [rozmiar];
    }
    ~tablica_dyn()
    {
        delete [] tablica;
    }

    tablica_dyn(const tablica_dyn *Tablica)
    {
        this->tablica=Tablica->tablica;
    }
virtual void przygotuj();
virtual void wykonaj();
};

#endif
