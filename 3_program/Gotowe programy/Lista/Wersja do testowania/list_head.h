#ifndef LIST_HEAD_H
#define LIST_HEAD_H
#include "interface.h"
#include "element.h"

class list_head: public interface
{
    public:
        list_head();
        void find_in_list(int value);
        int add(int positionint);
        int size();
        element* get(int position);
        void remove(int position);
    private:
        element * first;
};

#endif // LIST_HEAD_H
