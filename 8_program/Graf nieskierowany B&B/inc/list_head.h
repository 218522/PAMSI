#ifndef LIST_HEAD_H
#define LIST_HEAD_H
#include "element.h"

class list_head
{
    friend class list_table;
    friend class Graf;
    public:
        list_head();
        int find_in_list(int value);
        void add(int position, int vertex_number, int edge_value);
        int size();
        element* get(int position);
        void remove(int position);
        void show_list();
    private:
        element * first;
};

#endif // LIST_HEAD_H
