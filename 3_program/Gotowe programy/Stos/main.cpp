#include <iostream>
#include "element.h"
#include "stos_head.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    stos_head Stos;
    Stos.add();
    Stos.add();
    Stos.add();
    Stos.add();
    cout<<"Stos size: "<<Stos.size()<<endl;
    Stos.remove();
    cout<<"Stos size: "<<Stos.size()<<endl;
    return 0;
}
