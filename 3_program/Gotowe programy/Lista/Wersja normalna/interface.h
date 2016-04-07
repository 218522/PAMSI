#ifndef INTERFACE_H
#define INTERFACE_H
#include "element.h"

class interface
{
    public:
        virtual int add(int position) =0;
        virtual void remove(int position) =0;
        virtual element* get(int position) =0;
        virtual int size() =0;
};

#endif // INTERFACE_H
