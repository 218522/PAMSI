#include "stos_head.h"
#include <iostream>

using namespace std;

stos_head::stos_head()
{
    this->last=0;
    cout<<"Stos created"<<endl;
}
//Dodaje element na wierzch stosu
int stos_head::add(){
    element* n_element = new element;
    if(last==0){
        last=n_element;
    }
    else{
        element* pointer = last;
        while(pointer->next!=0){
            pointer=pointer->next;
        }
        pointer->next=n_element;
    }
}

//Zwraca i wypisuje rozmiar listy
int stos_head::size(){
    int stos_size=0;
    if (last!=0){
        stos_size++;
        element* pointer = last;
        while(pointer->next!=0){
            pointer = pointer->next;
            stos_size++;
        }
    }
    return stos_size;
}
//Usuwa element z wierzchu stosu
void stos_head::remove(){
    if(last==0){
        cout<<"Stos is empty!"<<endl;
    }
    else{
        element* pointer=last;
        int s_size = size()-1;
        int set=1;
        while(s_size>set){
            pointer = pointer->next;
            set++;
        }
        delete pointer->next;
        pointer->next=0;
	cout<<"Element removed"<<endl;
    }
}
