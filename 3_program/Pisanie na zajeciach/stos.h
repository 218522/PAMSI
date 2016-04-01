#ifndef STOS_H
#define STOS_H
#include "interfejsy_listy_stosu_kolejki.h"
#include "element.h"
#include <iostream>

class stos: public Interfejs_lista{
 public:
   element* top=0;
   //dodaje element na gore stosu
   int add(element n_element,int position){
     if(position != (size()+1)){
       cout<<"Stos przyjmuje argumenty tylko na swoj poczatek, domyslnie ustawiono pozycje "<<size()+1<<endl;
     }
     if(top==0){
       n_element.next=top;
     }
     else{
       element* pointer = top;
       while(pointer->next){
	 pointer = pointer->next;
       }
       pointer->next=n_element.next;
       n_element->next=0;
     }
     return 0;
   }
   //usuwa gorny element ze stosu
   void remove(int position){
     if(position != (size()+1)){
       cout<<"Stos usuwa argumenty tylko z wierzcholka, domyslnie ustawiono pozycje "<<size()+1<<endl;
     }
     element* pointer; //wskaznik pomocniczy
     pointer = top;
     pointer = pointer->next; //wskazuje na element #2 od gory
     delete top;     //usuwa adres elementu z gory
     top = pointer;  //drogi element zostaje topem
   }
   //zwraca rozmiar stosu
   int size(){
     int size=0;
     element* pointer = top;
     while(pointer->next){
       pointer = pointer->next;
       size++;
     }
     return size;
   }
}
