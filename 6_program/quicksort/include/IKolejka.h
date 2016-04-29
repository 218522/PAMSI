#ifndef IKOLEJKA__H
#define IKOLEJKA_H
#include "Lista.h"

class IKolejka:public Lista
{
private:

public:
   virtual void push(int x)=0;
   virtual int pop()=0;
   virtual int Rozmiar()=0;

};


#endif // IKOLEJKA__HH
