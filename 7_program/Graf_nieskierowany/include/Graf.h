#ifndef GRAF_H
#define GRAF_H
#include "IGraf.h"
#include "list_table.h"

class Graf
:public IGraf
{
    public:
        Graf();
        void BFS();
        void DFS();
        void add_Edge(int vertex_number_1, int vertex_number_2);
        void add_Vertex(int vertex_number_1);
        void get_Neighbours(int vertex_number);
        int is_Connected(int vertex_number_1, int vertex_number_2);
        void Visit(int vertex_number);
        int check_if_Visited(int vertex_number);
    private:
        list_table connection_list;
        list_head visited_list;
};

#endif // GRAF_H
