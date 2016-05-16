#include "element.h"
#include "list_head.h"
#include <iostream>

using namespace std;

list_head::list_head()
{
    this->first=0;
    //cout<<"List created"<<endl;
}

void list_head::show_list(){
    element* pointer = first;
    for(int i=0; i < size(); i++){
        cout<<pointer->value<<endl;
        pointer = pointer->next;
    }
}

int list_head::find_in_list(int value){
    element* pointer = first;
    if(first != 0){
        while(pointer->value != value){

            if(pointer->next != 0){
                pointer = pointer->next;
            }
            else
                break;
        }
        if(pointer->value == value)
            return (1);
        else
            return (-1);
    }
    else
        return (-1);
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
void list_head::add(int position, int vertex_number){
    element * n_element = new element;
    n_element->value=vertex_number;
    // If list is empty
    if(first==0){
        first = n_element;
        //cout<<"*List empty"<<endl<<"*Added element at position: 1"<<endl;
    }
    // Add element at the beginning of the list
    else if(position == 1){
        element* pointer = first;
        first = n_element;
        n_element->next=pointer;
    }
    else if(position == 0){
        element* pointer = first;
        while(pointer->next != 0){
            pointer = pointer->next;
        }
        pointer->next = n_element;
    }
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
    // remove element from the end beginning
    if(position==1){
            if(list_size == 1){
                delete first;
                first = 0;
            }
            else{
                element* pointer = first->next;
                delete first;
                first = pointer;
            }
    }
}
