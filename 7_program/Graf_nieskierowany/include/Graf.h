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
        void add_Edge();
        void add_Vertex(int vertex_number);
        void get_Neighbours(int vertex_number);
        void is_Connected(int vertex_number_1, int vertex_number_2);
    private:
        list_table connection_list;
        list_table visited_list;
};

#endif // GRAF_H
