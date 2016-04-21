#include <iostream>
#include <string>
#include "AssocTab.h"
#include <fstream>
#include <file_service.h>
#include "Stoper.h"

using namespace std;

int main()
{
    file_service f_service;
    element Name_Number;
    Stoper stoper;
    AssocTab Associative_Array;
    std::ifstream plik("dane100k.txt");
    stoper.przygotuj();
    stoper.Wlacz();
    while(plik>>Name_Number.name){
        plik>>Name_Number.value;
        Associative_Array.add(Name_Number);
    }
    stoper.Wylacz();
    stoper.Czas_trwania();
    Associative_Array.how_many_elements();
    stoper.przygotuj();
    stoper.Wlacz();
    Associative_Array.find_by_name("astra");
    stoper.Wylacz();
    stoper.Czas_trwania();
    return 0;
}
