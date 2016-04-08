#include <iostream>
#include "Stos.hh"
#include "Kolejka.hh"
#include "Test_lista.hh"
#include "stoper.hh"

using namespace std;

//QUICK-SORT
/*

*/


int main()
{

  Test_lista Test;
  Test.przygotuj(10);
  Test.get(10);
  cout<<Test.get_size();
  cout<<"Done"<<endl;



//Kolejka kol;
    //int tab[]={10,100,1000,10000,100000,1000000,1000000000};

    /*
    for(int i=0;i<7;i++)
    {
    Test.przygotuj(tab[i]);
    Test.wykonaj(tab[i]);
    }
    */
    return 0;
}
