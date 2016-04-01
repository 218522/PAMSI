#include "list_head.h"
#include "element.h"
#include  <iostream>
using namespace std;

list_head::list_head()
{
this->first=0;
}

void list_head::add_element(){
    int n_value;
    cout<<"Enter vlue for new element:";
    cin>>n_value;
    element* n_element = new element;
    n_element->value = n_value;

    if(first==0){
        first = n_element;
    }
    else{
        element* pointer = first;
        while(pointer->next){
            pointer = pointer->next;
        }
        pointer->next=n_element;
        n_element->next=0;
    }

}
