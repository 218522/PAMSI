#ifndef IHASHTAB_H
#define IHASHTAB_H
#include <string>
#include<iostream>
using namespace std;

class IHashTab
{
    public:
       virtual int uncode(string key)=0;
};

#endif // IHASHTAB_H
