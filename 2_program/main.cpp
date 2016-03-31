#include <iostream>
#include "timer.h"
#include "tab_mng.h"
#include "Interfejs.h"
using namespace std;

int main()
{
    timer time_counter; // timer do pomiaru czsu
    tab_mng d1_table;   // tablica dynamiczna jako obiekt do wykonywania pomiarow
    tab_mng d2_table;   // tablica dynamiczna jako obiekt do wykonywania pomiarow
    tab_mng d3_table;   // tablica dynamiczna jako obiekt do wykonywania pomiarow

     Interfejs *pt1 = &d1_table;
    Interfejs *pt2 = &d2_table;
    Interfejs *pt3 = &d3_table;

    pt1->set_tab();   
    cout<<"# Czas wykonywania algorytmu #"<<endl;
    cout<<"Zwiekszanie rozmiaru tablicy o 1 miejsce: ";
    time_counter.start_clock();
    d1_table.enlarge_by1();
    time_counter.stop_clock();
    time_counter.get_time();
    pt2->set_tab();
    cout<<"Zwiekszanie rozmiaru tablicy dwukrotnie: ";
    time_counter.start_clock();
    d2_table.enlarge_byx2();
    time_counter.stop_clock();
    time_counter.get_time();
    pt3->set_tab();
    cout<<"Zwiekszanie rozmiaru tablicy do kwadratu obecnego rozmiaru: ";
    time_counter.start_clock();
    d3_table.enlarge_by_power2();
    time_counter.stop_clock();
    time_counter.get_time();
   

    return 0;
}
