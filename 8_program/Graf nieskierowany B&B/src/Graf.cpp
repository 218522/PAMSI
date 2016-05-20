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

/*void Graf::BFS(int vertex_number){
    Visit(vertex_number);
    queue.add(0,vertex_number, -1);


        while(queue.size()!=0)
        {
            vertex_number = queue.first->connected_vertex;
            queue.remove(1);
            element* pointer = get_Neighbours(vertex_number).first;

                while(1){
                    if(check_if_Visited(pointer->connected_vertex)==-1){
                        Visit(pointer->connected_vertex);
                        cout<<"->"<<pointer->connected_vertex;
                        queue.add(0,pointer->connected_vertex, -1);
                    }
                    if(pointer->next != 0){
                    pointer = pointer->next;
                    }
                    else
                        break;
                }
        }
}
*/
/*
void Graf::DFS(int vertex_number){
    Visit(vertex_number);

    element* pointer = connection_list.table[vertex_number].first;
    for(pointer = connection_list.table[vertex_number].first; pointer!=0; pointer=pointer->next){
            vertex_number = pointer->connected_vertex;
        if(check_if_Visited(vertex_number) == -1){
            //cout<<pointer->value<<endl;
            DFS(vertex_number);
        }
    }
}
*/

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

void Graf::Branch_and_Bound(int start, int stop){
    list_head queue;
    element* pointer;
    int static grph_size = graph_size();
    int* final_cost = new int[grph_size];      //table including final costs of getting from start to point i
    int* predecessor = new int[grph_size];     //table including predecessors with the "shortest" way to i
    
    for(int i=0; i<graph_size(); i++){
        final_cost[i] = 2147483647;     //Initializing tables 27483647 <- max int size
        predecessor[i] = -1;		//-1 <- no predecessor found
    }

    int a,b;
    final_cost[start] = 0;
    for(int i=0; i<graph_size(); i++){
    // Search for unvisited vertex with lowest "get to" costs
        for(a=0; check_if_Visited(a)==1; a++ ); //Search for unvisited vertex
        //Search for lowest costs to get to
        for(b=a++; a<graph_size(); a++){
            if((check_if_Visited(a) == -1)&&(final_cost[a]<final_cost[b])){
                b = a;
            }
        }
        Visit(b); //Set found vertex as visited
        // Check if found vertex neighbours
        pointer = get_Neighbours(b).first;
        while(1){
            if((check_if_Visited(pointer->connected_vertex)==-1)&&(final_cost[pointer->connected_vertex]>final_cost[b]+pointer->edge_value)){
                final_cost[pointer->connected_vertex] = final_cost[b] + pointer->edge_value;
                predecessor[pointer->connected_vertex] = b;
            }
            if(pointer->next!=0){
                pointer = pointer->next;
            }
            else
                break;
        }
    }
    //find path and lowest costs to get there from 'start' to 'stop'
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
        cout<<"->"<<pointer->connected_vertex;
        if(pointer->next!=0){
            pointer = pointer->next;
        }
        else
            break;
    }
    cout<<endl<<"Total cost: "<<final_cost[stop]<<endl;
}
