#ifndef STOS_HH
#define STOS_HH
#include "IStos.hh"

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

