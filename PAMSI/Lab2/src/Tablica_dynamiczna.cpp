#include "Tablica_dynamiczna.hh"

void tablica_dyn::zapisz()
{
    for(int i=0; i<rozmiar; i++)
    {
        tablica[i]=1;
        licznik++;
    }
}
int tablica_dyn::get_licznik()
{
    return licznik;
}
int tablica_dyn::get_rozmiar()
{
    return rozmiar;
}
void tablica_dyn::wypisz()
{
    for(int i=0; i<rozmiar; i++)
    {
        cout<<tablica[i];
    }
}
void tablica_dyn::powieksz(int o_ile)
{
    rozmiar=rozmiar+o_ile;
    int *nowa=new int [rozmiar];
    for(int i=0; i<rozmiar-o_ile; i++)
    {
        nowa[i]=tablica[i];
    }
    delete [] tablica;
    tablica=nowa;
}
void tablica_dyn::powieksz2()
{
    int nowy_rozmiar=2*rozmiar;
    int *nowa=new int [nowy_rozmiar];
    for(int i=0; i<nowy_rozmiar-rozmiar; i++)
    {
        nowa[i]=tablica[i];
    }
    delete [] tablica;
    rozmiar=nowy_rozmiar;
    tablica=nowa;
}
void tablica_dyn::dopisz()
{
    tablica[licznik]=1;
    licznik++;
}
bool tablica_dyn::czy_miejsce()
{
    if(licznik==rozmiar)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void tablica_dyn::suma()
{
    int suma=0;
    for(int i=0; i<rozmiar; i++)
    {
        suma=suma+tablica[i];
    }
    cout<<suma;
}
void tablica_dyn::Algorytm1(int ile)
{
    while(this->get_licznik()<ile+10)
    {
        if(this->czy_miejsce()==true)
        {
            this->dopisz();
        }
        else
        {
            this->powieksz(1);
        }
    }
}
void tablica_dyn::Algorytm2(int ile)
{
    while(this->get_licznik()<ile+10)
    {
        if(this->czy_miejsce()==true)
        {
            this->dopisz();
        }
        else
        {
            this->powieksz(100);
        }
    }
}
void tablica_dyn::Algorytm3(int ile)
{
    while(this->get_licznik()<ile+10)
    {
        if(this->czy_miejsce()==true)
        {
            this->dopisz();
        }
        else
        {
            this->powieksz2();
        }
    }
}
void tablica_dyn::przygotuj()
{
    delete [] tablica;
    rozmiar=10;
    licznik=0;
    tablica=new int [rozmiar];
    this->zapisz();

}
void tablica_dyn::wykonaj()
{
    stoper Czas;
    Czas.przygotuj();
    this->zapisz();
    int liczby[]= {100,1000,100000,1000000,1000000000};
    cout<<"Algorytm 3"<<endl;
    for(int j=0; j<5; j++)
    {
        for(int i=0; i<10; i++)
        {
            Czas.Wlacz();
            this->Algorytm3(liczby[j]);
            Czas.Wylacz();
            Czas.Czas_trwania();
            Czas.Zliczaj_do_sumy();
            this->przygotuj();
        }
        cout<<"Dopisanie "<<liczby[j]<<" elementow:\t"<<Czas.get_suma()/10<<endl;
        Czas.przygotuj();
    }
    this->przygotuj();
    Czas.przygotuj();
    cout<<"Algorytm 2"<<endl;
    for(int j=0; j<4; j++)
    {
        for(int i=0; i<10; i++)
        {
            Czas.Wlacz();
            this->Algorytm2(liczby[j]);
            Czas.Wylacz();
            Czas.Czas_trwania();
            Czas.Zliczaj_do_sumy();
            this->przygotuj();
        }
        cout<<"Dopisanie "<<liczby[j]<<" elementow:\t"<<Czas.get_suma()/10<<endl;
        Czas.przygotuj();
    }
    this->przygotuj();
    Czas.przygotuj();
    cout<<"Algorytm 1"<<endl;
    for(int j=0; j<4; j++)
    {
        for(int i=0; i<10; i++)
        {
            Czas.Wlacz();
            this->Algorytm1(liczby[j]);
            Czas.Wylacz();
            Czas.Czas_trwania();
            Czas.Zliczaj_do_sumy();
            this->przygotuj();
        }
        cout<<"Dopisanie "<<liczby[j]<<" elementow:\t"<<Czas.get_suma()/10<<endl;
        Czas.przygotuj();
    }
    this->przygotuj();

}
