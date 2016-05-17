#ifndef LIST_TABLE_H
#define LIST_TABLE_H
#include "list_head.h"

class list_table
{
    public:
        list_table();
        int size;
        void modify_table(int new_size);
        list_head* table;
};

#endif // LIST_TABLE_H
