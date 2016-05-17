#include <iostream>
#include "timer.h"
#include "tab_mng.h"

using namespace std;

int main()
{
    int n_size=1000;
    cout<<"Nowy rozmiar: "<<n_size<<endl;

    timer stoper; // timer do pomiaru czsu
    tab_mng tablica;

    tablica.set_tab();
    stoper.start_clock();
    tablica.enlarge_by1(n_size);
    stoper.stop_clock();
    cout<<"Powiekszanie o 1: "<<stoper.get_time()<<"[ms]"<<endl;

    tablica.reset_tab();
    stoper.start_clock();
    tablica.enlarge_byx2(n_size);
    stoper.stop_clock();
    cout<<"Powiekszanie x2: "<<stoper.get_time()<<"[ms]"<<endl;

    tablica.reset_tab();
    stoper.start_clock();
    tablica.enlarge_by_power2(n_size);
    stoper.stop_clock();
    cout<<"Powiekszanie ^2: "<<stoper.get_time()<<"[ms]"<<endl;

    return 0;
}
