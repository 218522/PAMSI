#include "timer.h"
#include<iostream>
#include<time.h>

using namespace std;

void timer::start_clock(){
    start_time=clock();
}

void timer::stop_clock(){
    stop_time=clock();
}

void timer::get_time(){
this->time = stop_time - start_time;
cout<<this->time<<endl;
}
