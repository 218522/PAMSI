#include <iostream>
#include <string>
#include "AssocTab.h"
#include <fstream>
#include "Stoper.h"

using namespace std;

int main()
{
    element Name_Number;
    Stoper stoper,stoper2;
    AssocTab Associative_Array;
    std::ifstream plik("dane1m.txt");
    stoper.start_clock();
    while(plik>>Name_Number.name){
        plik>>Name_Number.value;
        Associative_Array.add(Name_Number);
    }
    stoper.stop_clock();
    cout<<"Czas dodawania: "<<stoper.get_time()<<endl;
    //Associative_Array.how_many_elements();
    stoper2.start_clock();
    Associative_Array.find_by_name("astra");
    stoper2.stop_clock();
    cout<<"Czas wyszukiwania: "<<stoper2.get_time()<<endl;
    return 0;
}
