#ifndef LIST_HEAD_H
#define LIST_HEAD_H
#include "IList.h"
#include "element.h"
#include <string>

class list_head: public IList
{
    public:
        friend class AssocTab;
        list_head();
        int how_many_elements();
        void find_in_list(std::string name);
        int add(int position, std::string name, int value);
        int size();
        element* get(int position);
        void remove(int position);
    private:
        element * first;
};

#endif // LIST_HEAD_H
