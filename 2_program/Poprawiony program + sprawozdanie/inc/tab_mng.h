#ifndef TAB_MNG_H
#define TAB_MNG_H
#include "Interfejs.h"
#include<iostream>

class tab_mng : public Interfejs
{
    int start_size; //poczatkowy rozmiar tablicy
    int size;       //aktualny rozmiar tablicy
    int * table; //wskaznik na tablice dynamiczna

    public:
        void set_tab();     //Poczatkowe ustawienia tablicy
        void reset_tab();   //Wyczyszczene i ponowne utworzenie tablicy
        void give_size(); //Zwraca rozmiar tablicy
        void fill_tab();  //Wypelnia tablice jej indeksami
        void show_tab();  //Wypisuje zawartosc tablicy
        void reduce_tab(int n_size);   //Pomniejsza tablice do zadanej wartosci n_size
        void enlarge_by1(int n_size);  //Powieksza tablice o 1 az do zadanej wartosci n_size
        void enlarge_byx2(int n_size); //Powieksza tablice x2 az size > n_size
        void enlarge_by_power2(int n_size); //Powieksza tablice ^2 az size > n_size
};

#endif // TAB_MNG_H
