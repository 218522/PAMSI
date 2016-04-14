#include <iostream>
#include "Stos.hh"
#include "Kolejka.hh"
#include "Test_lista.hh"
#include "stoper.hh"

using namespace std;

/*
  Moje modyfikacje:
  - void List::show_list() wypisuje liste na cout
  - Element* List::get_address(int position) zwraca wskaznik na element z position
*/

int main()
{

  Test_lista Test;
  Test.przygotuj(20);
  Test.show_list();
  Test.Quicksort(1,20);
  //Test.Quicksort(1,1);
  //Test.Quicksort(1,1);
  Test.show_list();
  cout<<"Done"<<endl;
    return 0;
}
