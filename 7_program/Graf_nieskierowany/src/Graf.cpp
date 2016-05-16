#include "Graf.h"
#include <iostream>

using namespace std;

int Graf::graph_size(){
    return connection_list.size;
}

void Graf::clear(){
    delete visited_list.first;
    visited_list.first = 0;
}

void Graf::BFS(int vertex_number){
    Visit(vertex_number);
    queue.add(0,vertex_number);

        while(queue.size()!=0)
        {
            vertex_number = queue.first->value;
            queue.remove(1);
            element* pointer = get_Neighbours(vertex_number).first;
                while(1){
                    if(check_if_Visited(pointer->value)==-1){
                        Visit(pointer->value);
                        queue.add(0,pointer->value);
                }
                if(pointer->next != 0){
                    pointer = pointer->next;
                }
                else
                    break;
                }
        }
}
/*
void Graf::BFS(int vertex_number){
    int vertex;
    cout<<"Operating on: "<<vertex_number<<endl;
    cout<<"Queue size: "<<queue.size()<<endl;
    list_head neighbours_List = get_Neighbours(vertex_number);
    element* pointer = neighbours_List.first;
    if(check_if_Visited(vertex_number)==-1){
        Visit(vertex_number);}
    while(1){
        if(check_if_Visited(pointer->value)==-1){
            Visit(pointer->value);
            queue.add(0,pointer->value);
        }
        if(pointer->next != 0)
            pointer = pointer->next;
        else
            break;
    }
    if(queue.size()!=0){
        vertex = queue.first->value;
        queue.remove(1);
        BFS(vertex);
    }
}*/
void Graf::DFS(int vertex_number){
    Visit(vertex_number);

    element* pointer = connection_list.table[vertex_number].first;
    for(pointer = connection_list.table[vertex_number].first; pointer!=0; pointer=pointer->next){
            vertex_number = pointer->value;
        if(check_if_Visited(vertex_number) == -1){
            //cout<<pointer->value<<endl;
            DFS(vertex_number);
        }
    }/*
    }
    while(1){
        if(check_if_Visited(pointer->value) == -1){
                cout<<pointer->value<<endl;
            DFS(pointer->value);
        }
        if(pointer->next != 0){
            pointer = pointer->next;
        }
        else
            break;
    }
*/
}
/*
void Graf::DFS(int vertex_number){
    //cout<<"Operating on: "<<vertex_number<<endl;
    //list_head neighbours_List = get_Neighbours(vertex_number);
    element* pointer = get_Neighbours(vertex_number).first;
    Visit(vertex_number);
    while(1){
        if(check_if_Visited(pointer->value)==-1){
            //cout<<"a"<<pointer->value<<endl;
            int value = pointer->value;
            delete pointer;
            //DFS(pointer->value);
            DFS(value);
        }
        if(pointer->next != 0)
            pointer = pointer->next;
        else
            break;
    }
}
*/

void Graf::Visit(int vertex_number){
    visited_list.add(1,vertex_number);
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

list_head Graf::get_Neighbours(int vertex_number){
    list_head neighbours_List;
    if(vertex_number <= connection_list.size){
            element* pointer = connection_list.table[vertex_number].first;
            while(pointer != 0){
                neighbours_List.add(1,pointer->value);
                pointer = pointer->next;
            }
    }
    else{
        cout<<"get_Neighbours: vertex_number doesn't exist"<<endl;
    }
    return neighbours_List;
}

// Check if vertex_1 - vertex_2 are connected| return 1 = yes, -1 = no, 0 = problem detected
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
// Chcek if vertex has been visited before| return 1 = yes, -1 = no
int Graf::check_if_Visited(int vertex_number){
    if(visited_list.find_in_list(vertex_number)==1)
        return (1);
    else
        return (-1);
}
