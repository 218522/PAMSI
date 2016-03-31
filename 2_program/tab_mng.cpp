#include "tab_mng.h"
#include<iostream>

using namespace std;

void tab_mng::give_size(){
cout<<"Table size: "<<this->size<<endl;
}

void tab_mng::reduce_tab(int n_size){
    this->size=n_size;
    int * tab = new int[n_size];
    for(int i=0; i<n_size; i++){
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

void tab_mng::enlarge_by1(int n_size){
    while(this->size<n_size){
     this->size++;
     int * tab = new int[this->size];
     for(int i=0; i<this->size; i++){
      tab[i]=this->table[i];
      }
     delete [] this->table;
     this->table = tab;
    }
}

void tab_mng::enlarge_byx2(int n_size){
    int a=2;
    while(this->size<n_size){
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
    tab_mng::reduce_tab(n_size);
   }
}


void tab_mng::enlarge_by_power2(int n_size){
    int b = this->size;
    int c = this->size;
    while(this->size<n_size){
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
    tab_mng::reduce_tab(n_size);
   }
}
