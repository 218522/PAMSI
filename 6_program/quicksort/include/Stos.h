#ifndef STOS_H
#define STOS_H
#include "IStos.h"

class Stos: public IStos
{
private:
    Element *poczatek;
public:
   virtual void push(int x);
   virtual int pop();
   virtual int Rozmiar();

};


#endif // STOS_HH
