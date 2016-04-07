#ifndef LIST_HEAD_H
#define LIST_HEAD_H
#include "interface.h"
#include "element.h"

class list_head: public interface
{
    public:
        list_head();
        int add(int position);
        int size();
        element* get(int position);
        void remove(int position);
    private:
        element * first;
};

#endif // LIST_HEAD_H
