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
  int size;
  cout<<"Size: ";
  cin>>size;
  int* help = new int[size];

  stoper stoper_1;
  stoper stoper_2;

  Test_lista Test_1;
  Test_lista Test_2;

  Test_1.przygotuj(size);
  stoper_1.Wlacz();
  cout<<"	Mergesort"<<endl;
  Test_1.Mergesort(1,size,help);
  stoper_1.Wylacz();
  stoper_1.Czas_trwania();

  Test_2.przygotuj(size);
  stoper_2.Wlacz();
  cout<<"	Quicksort"<<endl;
  Test_2.Quicksort(1,size);
  stoper_2.Wylacz();
  stoper_2.Czas_trwania();

    return 0;
}
