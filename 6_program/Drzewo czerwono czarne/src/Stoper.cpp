#include "Stoper.h"
#include<iostream>
#include<time.h>

using namespace std;

void Stoper::start_clock(){
    start_time=clock();
}

void Stoper::stop_clock(){
    stop_time=clock();
}

long Stoper::get_time(){
    this->time = stop_time - start_time;
    return time;
}
