#include "value_generator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void value_generator::set_generator(){
   cout<<"Number of Nodes: ";
   cin>>this->elements;
   this->value_array = new int[elements];
}

value_generator::value_generator()
{
  set_generator();
  srand(time(NULL));
  int i,i1,i2,help;
  for(i = 0; i < elements; i++){
    value_array[i] = i + 1;
  }
  // Mixing the table of values for elements
  for(i = 0; i < 10000; i++)
  {
    i1 = rand() % elements;
    i2 = rand() % elements;

    help = value_array[i1];
    value_array[i1] = value_array[i2];
    value_array[i2] = help;
  }
}
