#include <iostream>
#include "Stos.hh"
#include "Kolejka.hh"
#include "Test_lista.hh"
#include "stoper.hh"

using namespace std;

//QUICK-SORT
/*

*/
/*
  Moje modyfikacje:
  - void List::show_list() wypisuje liste na cout
  - Element* List::get_address(int position) zwraca wskaznik na element z position
*/

int main()
{

  Test_lista Test;
  Test.przygotuj(14);
  Test.show_list();
  Test.Quicksort();
  Test.show_list();
  //Test.get(4);
  //Test.get_address(0);
  //cout<<Test.get_size();
  cout<<"Done"<<endl;
    return 0;
}
