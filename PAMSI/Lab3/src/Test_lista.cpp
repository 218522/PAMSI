#include "Test_lista.hh"

void Test_lista::przygotuj(int x)
{
    for(int i=0; i<x; i++)
        this->dodaj(rand()%10,0);
}

void Test_lista::wykonaj(int x)
{

    stoper Czas;
    Czas.przygotuj();
    for(int i=0; i<10; i++)
    {
        int a=rand()%10;
        Czas.Wlacz();
        this->przeszukaj(a);
        Czas.Wylacz();
        Czas.Czas_trwania();
        Czas.Zliczaj_do_sumy();
    }
    cout<<"Przeszukanie "<<this->get_size()<<" elementowej listy trwalo:"<<Czas.get_suma()/10<<endl;

    for(int i=0; i<x; i++)
    {
        this->usun(0);
    }
}
