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
  - int Lista::how_far(Element* pointer) zwraca odleglosc wskazanego elementu od poczatku listy
*/

int main()
{
  stoper stoper;
  Test_lista Test;
  Test.przygotuj(20000);
  //Test.show_list();
  stoper.Wlacz();
  Test.Quicksort(1,20000);
  stoper.Wylacz();
  stoper.Czas_trwania();
  //Test.show_list();
  cout<<"Done"<<endl;
    return 0;
}
