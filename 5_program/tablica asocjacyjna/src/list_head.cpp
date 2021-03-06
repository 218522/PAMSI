#include "element.h"
#include "IList.h"
#include "list_head.h"
#include <iostream>
#include <string>

using namespace std;

list_head::list_head()
{
    this->first=0;
    //cout<<"List created"<<endl;
}
// Search element by 'name'
void list_head::find_in_list(string name){
    int position_counter = 0;
    int elements_counter = 0;
    element* pointer = first;
    while(pointer->next != 0){
        position_counter++;
        if(pointer->name == name){
            elements_counter++;
            cout<<"Element found at position: "<<position_counter<<endl;
        }
        pointer = pointer->next;
    }
        position_counter++;
        if(pointer->name == name){
            elements_counter++;
            cout<<"Element found at position: "<<position_counter<<endl;
        }
        if(elements_counter!=0){
            cout<<"Total number of elements found under '"<<name<<"': "<<elements_counter<<endl;
        }
        else{
            cout<<"Cant find any elements under phrase '"<<name<<"'"<<endl;
        }
}

//Zwraca i wypisuje rozmiar listy
int list_head::size(){
    int list_size=0;
    if (first!=0){
        list_size++;
        element* pointer = first;
        while(pointer->next!=0){
            pointer = pointer->next;
            list_size++;
        }
    }
    //cout<<"List size:"<<list_size<<endl; //Smieci w terminalu
    return list_size;
}

//Adds element at 'position' at the list
int list_head::add(int position, string name, int value){

    //int list_size = size();
    element * n_element = new element;
    n_element->value=value;
    n_element->name=name;
    // If list is empty
    if(first==0){
        first = n_element;
        //cout<<"*List empty"<<endl<<"*Added element at position: 1"<<endl;
    }
    // Add element at the beginning of the list
    else if(position == 1){
        element* whos_after = get(position);
        first = n_element;
        n_element->next=whos_after;
        //cout<<"*Added element at position: "<<position<<endl;
    }
    /*
    // Add element at the end of the list
    else if(list_size+1==position){
        element * whos_before = get(position-1);
        whos_before->next = n_element;
        cout<<"*Added element at position: "<<position<<endl;
    }
    // Add element at the beginning of the list
    else if(position == 1){
        element* whos_after = get(position+1);
        first = n_element;
        n_element->next=whos_after;
        cout<<"*Added element at position: "<<position<<endl;
    }
    // Add element inside the list
    else{
        element* whos_before = get(position-1);
        element* who_was_there = whos_before->next;
        n_element->next = who_was_there;
        whos_before->next=n_element;
        cout<<"*Added element at position: "<<position<<endl;
    }*/
    return 0;
}
// Returns pointer to element at 'position'
element* list_head::get(int position){
    int current_position = 0;
    if(first!=0){
        element* pointer = first;
        current_position++;
        while(current_position<position){
            pointer = pointer->next;
            current_position++;
        }
    return pointer;
    }
    else
        cout<<"List is empty!"<<endl;
}
// Removes element from the list
void list_head::remove(int position){
    int list_size=size();
    int value;
    // remove element from the end of the list
    if(list_size==position){
        element* whos_before = get(position-1);
        value=whos_before->next->value;
        delete whos_before->next;
        whos_before->next=0;
    }
    // remove element at the beginning of the list
    else if (position==1){
        element* whos_after = get(position+1);
        value=first->value;
        delete first;
        first = whos_after;
    }
    // remove element from list
    else{
        element* whos_before = get(position-1);
        value=whos_before->next->value;
        element* whos_after = whos_before->next->next;
        delete whos_before->next;
        whos_before->next=whos_after;
    }
    cout<<endl<<"*element:"<<endl<<"*position: "<<position<<endl<<"*value: "<<value<<endl<<"REMOVED!"<<endl<<endl;
}
