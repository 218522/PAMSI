#ifndef IASSOCTAB_H
#define IASSOCTAB_H
#include <string>
#include "element.h"

class IAssocTab
{
    public:
       virtual void add(element n_element)=0;
       virtual int how_many_elements_in_bucket(int bucket_number)=0;
       virtual int how_many_elements()=0;
       virtual void find_by_name(std::string name)=0;
};

#endif // IASSOCTAB_H
