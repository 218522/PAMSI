#ifndef TAB_MNG_H
#define TAB_MNG_H
#include<iostream>
#include "Interfejs.h"

class tab_mng: public Interfejs
{
    int size = 10; //poczatkowy rozmiar tablicy
    int n_size;
    int * table = new int[size]; //wskaznik na tablice dynamiczna

    public:
        void set_tab();
        void give_size(); //Zwraca rozmiar tablicy
        void fill_tab();  //Wypelnia tablice jej indeksami
        void show_tab();  //Wypisuje zawartosc tablicy
        void reduce_tab();   //Pomniejsza tablice do zadanej wartosci n_size
        void enlarge_by1();  //Powieksza tablice o 1 az do zadanej wartosci n_size
        void enlarge_byx2(); //Powieksza tablice x2 az size > n_size
        void enlarge_by_power2(); //Powieksza tablice ^2 az size > n_size
};

#endif // TAB_MNG_H
