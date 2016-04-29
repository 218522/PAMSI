#ifndef STOPER_H
#define STOPER_H

#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

class Stoper
{
private:
    time_t start, stop;
    double trwanie, suma;
public:

    double get_trwanie()
    {
        return trwanie;
    }
    double get_suma()
    {
        return suma;
    }
    void Wlacz();
    void Wylacz();
    void Czas_trwania();
    void Zliczaj_do_sumy();
    void przygotuj();
};

#endif
