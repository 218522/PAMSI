#include <iostream>
#include <string>
#include "AssocTab.h"
#include <fstream>
#include "Stoper.h"

using namespace std;

int main()
{
    element Name_Number;
    Stoper stoper_1;
    AssocTab Associative_Array;
    std::ifstream plik("dane10.txt");
    stoper_1.przygotuj();
    stoper_1.Wlacz();
    while(plik>>Name_Number.name){
        plik>>Name_Number.value;
        Associative_Array.add(Name_Number);
    }
    stoper_1.Wylacz();
    stoper_1.Czas_trwania();
    Associative_Array.how_many_elements();
    stoper_1.przygotuj();
    stoper_1.Wlacz();
    Associative_Array.find_by_name("astra");
    stoper_1.Wylacz();
    stoper_1.Czas_trwania();
    return 0;
}
