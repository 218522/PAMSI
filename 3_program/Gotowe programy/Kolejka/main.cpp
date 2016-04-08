#include <iostream>
#include "element.h"
#include "kolejka_head.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    kolejka_head Kolejka;
    Kolejka.move_out_first();
    Kolejka.get_at_back();
    Kolejka.get_at_back();
    Kolejka.get_at_back();
    Kolejka.get_at_back();
    cout<<"Size: "<<Kolejka.size()<<endl;
    Kolejka.move_out_first();
    cout<<"Size: "<<Kolejka.size()<<endl;
    return 0;
}
