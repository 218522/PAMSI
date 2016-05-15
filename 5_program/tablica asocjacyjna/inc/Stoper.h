#ifndef STOPER_H
#define STOPER_H
#include<iostream>
#include <time.h>

class Stoper
{
    clock_t start_time;
    clock_t stop_time;
    long time;

    public:
        void start_clock(); //startuje Stoper
        void stop_clock();  //stopuje Stoper
        long get_time();    //oblicza i wypisuje zmierzony czas
};

#endif // STOPER_H

