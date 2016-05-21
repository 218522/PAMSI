#include "Graf.h"
#include <iostream>

using namespace std;

Graf::Graf(){
    int size = graph_size();
    visited_table = new int[size];
    for(int i=0; i<size; i++){
        visited_table[i]=-1;
    }
}

int Graf::graph_size(){
    return connection_list.size;
}

void Graf::clear(){
    for(int i=0; i<graph_size(); i++){
        visited_table[i]=-1;
    }
}

void Graf::Visit(int vertex_number){
    visited_table[vertex_number]=1;
}

void Graf::add_Vertex(int vertex_number){
    if(vertex_number<=this->connection_list.size){
        cout<<"! Element represented by number: "<<vertex_number<<" already exist"<<endl;
    }
    else{
            this->connection_list.modify_table(vertex_number);
    }
}

void Graf::add_Edge(int vertex_number_1, int vertex_number_2, int edge_value){
    if((vertex_number_1 <= this->connection_list.size)&&(vertex_number_2 <= this->connection_list.size)){
            this->connection_list.table[vertex_number_1].add(1, vertex_number_2, edge_value);
            this->connection_list.table[vertex_number_2].add(1, vertex_number_1, edge_value);
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
                neighbours_List.add(1,pointer->connected_vertex, pointer->edge_value);
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
    if(visited_table[vertex_number]==1)
        return (1);
    else
        return (-1);
}

void Graf::Branch_and_Bound_extended_list(int start, int stop){
    int* final_cost = new int[graph_size()];      //table including final costs of getting from start to point i
    int* predecessor = new int[graph_size()];     //table including predecessors with the "shortest" way to i
    for(int i=0; i<graph_size(); i++){
        final_cost[i]=27483647;
        predecessor[i]=-1;
    }
    final_cost[0]=0;
    char found = 'n';   //stop element found ? n = no, y = yes
    int vertex;
    element* pointer;
    list_head queue;

    queue.add(1,start,-1);
    //Search for stop vertex and save paths in predecessor, save costs of getting to path in final_costs
    while(1){
        if(found == 'n'){
            vertex = queue.first->connected_vertex;
            if(vertex!=stop){
                pointer = get_Neighbours(vertex).first;
                while(1){
                    if(check_if_Visited(pointer->connected_vertex)==-1){
                        Visit(pointer->connected_vertex);
                        if(final_cost[pointer->connected_vertex] > final_cost[vertex] + pointer->edge_value){
                            predecessor[pointer->connected_vertex] = vertex;
                            final_cost[pointer->connected_vertex] = final_cost[vertex] + pointer->edge_value;
                            queue.add(0,pointer->connected_vertex,-1);
                        }
                    }
                    if(pointer->next != 0){
                        pointer = pointer->next;
                    }
                    else
                        break;
                    }
            }
            else
                found = 'y';
            queue.remove(1);
        }
        else
            break;
    }
/*
    //Find path
    int u = stop;
    queue.add(1,stop,0);
    while(1){
        if(predecessor[u]!=start){
            queue.add(1,predecessor[u],0);
            u=predecessor[u];
        }
        else
            break;
    }
    //print path and total cost
    queue.add(1,start,0);
    pointer = queue.first;
    while(1){
        //cout<<"->"<<pointer->connected_vertex;
        if(pointer->next!=0){
            pointer = pointer->next;
        }
        else
            break;
    }*/
    cout<<endl<<"Total cost: "<<final_cost[stop]<<endl;
}


void Graf::Branch_and_Bound(int start, int stop){
    int* final_cost = new int[graph_size()];      //table including final costs of getting from start to point i
    int* predecessor = new int[graph_size()];     //table including predecessors with the "shortest" way to i
    for(int i=0; i<graph_size(); i++){
        final_cost[i]=27483647;
        predecessor[i]=-1;
    }
    final_cost[0]=0;
    char found = 'n';   //stop element found ? n = no, y = yes
    int vertex;
    element* pointer;
    list_head queue;

    queue.add(1,start,-1);
    //Search for stop vertex and save paths in predecessor, save costs of getting to path in final_costs
    while(1){
        if(found == 'n'){
            vertex = queue.first->connected_vertex;
            if(vertex!=stop){
                pointer = get_Neighbours(vertex).first;
                while(1){
                    if(final_cost[pointer->connected_vertex] > final_cost[vertex] + pointer->edge_value){
                        predecessor[pointer->connected_vertex] = vertex;
                        final_cost[pointer->connected_vertex] = final_cost[vertex] + pointer->edge_value;
                        queue.add(0,pointer->connected_vertex,-1);
                    }
                    if(pointer->next != 0){
                        pointer = pointer->next;
                    }
                    else
                        break;
                }
            }
            else
                found = 'y';
            queue.remove(1);


        }
        else
            break;
    }
    queue.add(0,vertex,-1);
    //If stop vertex found, search for other possibilities. Check if there is shorter path. Search until queue != empty, and shortest path in queue < actual path to stop vertex
    while(queue.size()!=0){
        vertex = queue.first->connected_vertex;
        pointer = get_Neighbours(vertex).first;
        if(final_cost[vertex]<final_cost[stop]){
            while(1){
            if(final_cost[pointer->connected_vertex] > final_cost[vertex] + pointer->edge_value){
                predecessor[pointer->connected_vertex] = vertex;
                final_cost[pointer->connected_vertex] = final_cost[vertex] + pointer->edge_value;
                queue.add(0,pointer->connected_vertex,-1);
            }
            if(pointer->next != 0){
                pointer = pointer->next;
            }
            else
                break;
            }
        }
        queue.remove(1);
    }
/*
    //Find path
    int u = stop;
    queue.add(1,stop,0);
    while(1){
        if(predecessor[u]!=start){
            queue.add(1,predecessor[u],0);
            u=predecessor[u];
        }
        else
            break;
    }
    //print path and total cost
    queue.add(1,start,0);
    pointer = queue.first;
    while(1){
        //cout<<"->"<<pointer->connected_vertex;
        if(pointer->next!=0){
            pointer = pointer->next;
        }
        else
            break;
    }*/
    cout<<endl<<"Total cost: "<<final_cost[stop]<<endl;
}
