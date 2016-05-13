#include "element.h"
#include <iostream>

element::element(){
    next=0;
    std::cout<<"Value for new element: ";
    std::cin>>this->value;
}
