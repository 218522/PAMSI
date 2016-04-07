#include <iostream>
#include "element.h"
#include "list_head.h"
#include "interface.h"
using namespace std;

int main()
{
    list_head List;
    List.add(1);
    List.add(2);
    List.add(3);
    List.add(4);
    List.remove(2);
    List.size();
    return 0;
}
