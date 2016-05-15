#include "Graf.h"
#include <iostream>

using namespace std;

void Graf::BFS(){

}

void Graf::Visit(int vertex_number){

}

void Graf::add_Vertex(int vertex_number){
    if(vertex_number<=this->connection_list.size){
        cout<<"! Element represented by number: "<<vertex_number<<" already exist"<<endl;
    }
    else{
            this->connection_list.modify_table(vertex_number);
    }
}

void Graf::add_Edge(int vertex_number_1, int vertex_number_2){
    if((vertex_number_1 <= this->connection_list.size)&&(vertex_number_2 <= this->connection_list.size)){
            this->connection_list.table[vertex_number_1].add(1, vertex_number_2);
            this->connection_list.table[vertex_number_2].add(1, vertex_number_1);
    }
    else{
        cout<<"add_Edge: one of selected vertex numbers doesn't exist";
    }
}

void Graf::get_Neighbours(int vertex_number){
    if(vertex_number <= connection_list.table[vertex_number].size()){
            cout<<"Vertex: "<<vertex_number<<endl<<"Neighbours: "<<endl;
            element* pointer = connection_list.table[vertex_number].first;
            while(pointer != 0){
                cout<<pointer->value<<endl;
            }
    }
    else{
        cout<<"get_Neighbours: vertex_number doesn't exist"<<endl;
    }
}

int Graf::is_Connected(int vertex_number_1, int vertex_number_2){
    if((vertex_number_1 <= this->connection_list.size)&&(vertex_number_2 <= this->connection_list.size)){
        if((connection_list.table[vertex_number_2].find_in_list(vertex_number_1)==1) && (connection_list.table[vertex_number_1].find_in_list(vertex_number_2)==1))
            return (1);
        else
            return (-1);
    }
    else{
        return (0);
        cout<<"is_Connected: one of selected vertex numbers doesn't exist"<<endl;
    }
}

int Graf::check_if_Visited(int vertex_number){
    if(visited_list.find_in_list(vertex_number)==1)
        return (1);
    else
        return (-1);
}
