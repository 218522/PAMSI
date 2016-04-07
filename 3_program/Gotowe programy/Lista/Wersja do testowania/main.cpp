#include <iostream>
#include "element.h"
#include "list_head.h"
#include "interface.h"
#include "timer.h"
using namespace std;
/*Wersja do testowania.
    Zmiany:
    - initiate_list funkcja inicjacji listy o zadanej liczbie elementow
    - list_head::find_in_list funkcja wyszukujaca element o danej 'value'
    - value jest przydzielana dla elementu w sekcji list_head::add i value=position (wczesniej w konstruktorze element() wczytywana z klawiatury)
    */
void initiate_list(list_head& List, int list_size){
    for(int i=1; i<=list_size; i++){
        List.add(i);
    }
}

int main()
{
    list_head List;
    initiate_list(List,10);
    List.find_in_list(5);
    return 0;
}
