#include <iostream>

using namespace std;

class tablica_dyn
{
public:
    int licznik=0;
    int rozmiar;
    int *tablica=new int [rozmiar];


    tablica_dyn(int x=10)
    {
        rozmiar=x;
    }
    void Zapisz()
    {
        for(licznik=0; licznik<rozmiar; licznik++)
        {
            cin>>tablica[licznik];
        }
    }

    void wypisz()
    {
        for(int i=0; i<rozmiar; i++)
        {
            cout<<tablica[i];
        }
        cout<<endl;
    }
    int *powieksz(int *tablica)
    {
        rozmiar++;
        int *nowa=new int [rozmiar];

        for(int i=0; i<rozmiar-1; i++)
        {
            nowa[i]=this->tablica[i];
        }
        delete [] tablica;
        return nowa;

    }

    void dopisz()
    {
    cout<<"Jaka liczbe dopisac"<<endl;
        if(licznik<=rozmiar)
        {
            cin>>tablica[licznik];
            licznik++;
        }
    }
};
int main()
{
    tablica_dyn Pierwsza;
    Pierwsza.Zapisz();
    Pierwsza.tablica=Pierwsza.powieksz(Pierwsza.tablica);
    Pierwsza.dopisz();
    Pierwsza.wypisz();
    return 0;

}
