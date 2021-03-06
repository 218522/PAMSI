#ifndef GRAF_H
#define GRAF_H
#include "IGraf.h"
#include "list_table.h"

class Graf
:public IGraf
{
    public:
        void BFS(int vertex_number);
        void DFS(int vertex_number);
        void add_Edge(int vertex_number_1, int vertex_number_2);
        void add_Vertex(int vertex_number_1);
        list_head get_Neighbours(int vertex_number); //return list of neighbours
        int is_Connected(int vertex_number_1, int vertex_number_2); // Check if vertex_1 - vertex_2 are connected| return 1 = yes, -1 = no, 0 = problem detected
        void Visit(int vertex_number); // Set vertex_number as visited
        int check_if_Visited(int vertex_number); // Check if vertex has been visited before| return 1 = yes, -1 = no
        int graph_size();
        void clear();
    private:
        list_table connection_list;
        list_head visited_list;
        list_head queue;
};

#endif // GRAF_H
