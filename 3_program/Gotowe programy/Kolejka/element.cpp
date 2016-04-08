#include "element.h"
#include <iostream>

using namespace std;

element::element()
{
    this->next=0;
    cout<<"Value for new element: ";
    cin>>this->value;
}
