#include "tab_mng.h"
#include "Interfejs.h"
#include<iostream>

using namespace std;

void tab_mng::set_tab(){
  cout<<"Poczatkowy rozmiar tablicy:"<<endl;
  tab_mng::give_size();
  cout<<"Wprowadz nowy rozmiar tablicy: ";
  cin>>this->n_size;
}

void tab_mng::give_size(){
cout<<"Table size: "<<this->size<<endl;
}

void tab_mng::reduce_tab(){
    this->size=this->n_size;
    int * tab = new int[this->n_size];
    for(int i=0; i<this->n_size; i++){
     tab[i]=this->table[i];
     }
    delete [] this->table;
    this->table=tab;
}

void tab_mng::fill_tab(){
    for(int i=0;i<this->size;i++){
        this->table[i]=i;
    }
}

void tab_mng::show_tab(){
    cout<<"|Table:"<<endl;
    for(int i = 0;this->size>i;i++){
        cout<<this->table[i]<<" ";
    }
    cout<<endl;
}

void tab_mng::enlarge_by1(){
  while(this->size<this->n_size){
     this->size++;
     int * tab = new int[this->size];
     for(int i=0; i<this->size; i++){
      tab[i]=this->table[i];
      }
     delete [] this->table;
     this->table = tab;
    }
}

void tab_mng::enlarge_byx2(){
    int a=2;
    while(this->size<this->n_size){
        this->size=this->size*2;
        int * tab = new int[this->size];
        for(int i=0; i<=(this->size)/a; i++){
        tab[i]=this->table[i];
        }
       delete [] this->table;
       this->table = tab;
       a=a*2;
    }
    if(n_size<this->size){
    tab_mng::reduce_tab();
   }
}


void tab_mng::enlarge_by_power2(){
    int b = this->size;
    int c = this->size;
    while(this->size<this->n_size){
        this->size=this->size*this->size;
        b=this->size/c;
        int * tab = new int[this->size];
        for(int i=0; i<=(this->size)/b; i++){
        tab[i]=this->table[i];
        }
       delete [] this->table;
       this->table=tab;
   }
   if(n_size<this->size){
    tab_mng::reduce_tab();
   }
}
