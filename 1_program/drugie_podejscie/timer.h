#ifndef TIMER_H
#define TIMER_H
#include<iostream>
#include <time.h>

class timer
{
    clock_t start_time;
    clock_t stop_time;
    long time;

    public:
        void start_clock(); //startuje timer
        void stop_clock();  //stopuje timer
        void get_time();    //oblicza i wypisuje zmierzony czas
};

#endif // TIMER_H
