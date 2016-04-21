#ifndef ILIST_H
#define ILIST_H
#include "element.h"
#include<string>

class IList
{
    public:
        virtual int add(int position, std::string name, int value) =0;
        virtual void remove(int position) =0;
        virtual element* get(int position) =0;
        virtual int size() =0;
};

#endif // INTERFACE_H
