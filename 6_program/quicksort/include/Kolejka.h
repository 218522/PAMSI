#ifndef KOLEJKA_H
#define KOLEJKA_H
#include "IKolejka.h"

class Kolejka: public IKolejka
{
private:

public:
   virtual void push(int x);
   virtual int pop();
   virtual int Rozmiar();

};


#endif // KOLEJKA_HH
