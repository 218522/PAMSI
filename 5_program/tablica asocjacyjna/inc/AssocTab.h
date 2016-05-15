#ifndef ASSOCTAB_H
#define ASSOCTAB_H
#include "IAssocTab.h"
#include "HashTab.h"
#include "list_head.h"

class AssocTab
: public IAssocTab
, public IHashTab
{
    public:
        int uncode(string key);
        void set_table_size(int n);
        void add(element n_element);
        int how_many_elements_in_bucket(int bucket_number);
        int how_many_elements();
        void find_by_name(std::string name);
    private:
        // last array index created for unappropriate names
        list_head table[26];
};

#endif // ASSOCTAB_H
