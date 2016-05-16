#include "list_table.h"
#include<iostream>

using namespace std;

list_table::list_table(){
    cout<<"Define size of graph: ";
    //cin>>size;
    size = 100000;
    table = new  list_head[size];
}

void list_table::modify_table(int new_size){
    list_head* new_table = new  list_head[new_size];
    for(int i=0; i<= size; i++){
        new_table[i].first = table[i].first;
    }
    delete table;
    table = new_table;
}
