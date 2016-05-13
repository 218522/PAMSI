#ifndef LIST_TABLE_H
#define LIST_TABLE_H
#include <list>

class list_table
{
    public:
        list_table();
        int Vertex_number;
    private:
        std::list<int>* table;
};

#endif // LIST_TABLE_H
