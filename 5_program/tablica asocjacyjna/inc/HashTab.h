#ifndef HASHTAB_H
#define HASHTAB_H
#include "IHashTab.h"

class HashTab
: public IHashTab
{
    public:
        int operator[] (string key);

};

#endif // HASHTAB_H
