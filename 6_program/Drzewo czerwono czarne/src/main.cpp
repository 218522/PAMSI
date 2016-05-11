#include <iostream>
#include "Tree_red_black.h"
#include "value_generator.h"
#include "Stoper.h"

using namespace std;


int main()
{
  Tree_red_black * Tree_RB = new Tree_red_black;
  value_generator generator;
  Stoper timer;
  int i = 0;

  timer.start_clock();
  for(i = 0; i < generator.elements; i++)
  {
    Tree_RB->add(generator.value_array[i]);
  }
  timer.stop_clock();

  cout<<endl<<"- Tree created in time: "<<timer.get_time()<<" [ms]"<<endl;
  cout<<"- Looking for last added Node"<<endl;

  timer.start_clock();
  Node* found_element = Tree_RB->search_for_value(generator.value_array[i-1]);
  timer.stop_clock();

  cout<<"- Finished in: "<<timer.get_time()<<" [ms]"<<endl;
  return 0;
}
