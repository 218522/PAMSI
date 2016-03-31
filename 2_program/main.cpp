#include <iostream>
#include "timer.h"
#include "tab_mng.h"

using namespace std;

int main()
{
    int n_size=100;
    timer time_counter; // timer do pomiaru czsu
    tab_mng d1_table;   // tablica dynamiczna jako obiekt do wykonywania pomiarow
    tab_mng d2_table;   // tablica dynamiczna jako obiekt do wykonywania pomiarow
    tab_mng d3_table;   // tablica dynamiczna jako obiekt do wykonywania pomiarow

    cout<<"Poczatkowy rozmiar tablicy tablicy:"<<endl;
    d1_table.give_size();
    cout<<"Wprowadz nowy wymiar tablicy: ";
    cin>>n_size;
    
    cout<<"# Czas wykonywania algorytmu #"<<endl;
    cout<<"Zwiekszanie rozmiaru tablicy o 1 miejsce: ";
    time_counter.start_clock();
    d1_table.enlarge_by1(n_size);
    time_counter.stop_clock();
    time_counter.get_time();
    cout<<"Zwiekszanie rozmiaru tablicy dwukrotnie: ";
    time_counter.start_clock();
    d2_table.enlarge_byx2(n_size);
    time_counter.stop_clock();
    time_counter.get_time();
    cout<<"Zwiekszanie rozmiaru tablicy do kwadratu obecnego rozmiaru: ";
    time_counter.start_clock();
    d3_table.enlarge_by_power2(n_size);
    time_counter.stop_clock();
    time_counter.get_time();

    return 0;
}
