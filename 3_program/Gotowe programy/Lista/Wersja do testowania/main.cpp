#include <iostream>
#include "element.h"
#include "list_head.h"
#include "interface.h"
#include "timer.h"
using namespace std;
/*Wersja do testowania.
    Zmiany:
    - dodano timer 
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
    timer time_counter;
    initiate_list(List,10);
    time_counter.start_clock();
    List.find_in_list(10);
    time_counter.stop_clock();
    time_counter.get_time();
    return 0;
}
