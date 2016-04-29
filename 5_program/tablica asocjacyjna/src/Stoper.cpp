#include "Stoper.h"
#include <fstream>

using namespace std;

void Stoper::Wlacz()
{
    start=clock();
}

void Stoper::Wylacz()
{
    stop=clock();
}

void Stoper::Czas_trwania()
{
    fstream plik_1;
    trwanie=(double)(stop-start)/CLOCKS_PER_SEC;
    plik_1.open("wyniki.txt", ios::out | ios::app);
            if(plik_1.good() == true)
            {
                plik_1 << "Execution time: "<<trwanie<<endl;
                plik_1.close();
            }
}

void Stoper::Zliczaj_do_sumy()
{
    suma=suma+trwanie;
}
void Stoper::przygotuj()
{
    start=0;
    stop=0;
    trwanie=0;
    suma=0;
}
