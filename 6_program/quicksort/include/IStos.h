#ifndef ISTOS_H
#define ISTOS_H
#include "Lista.h"

class IStos:public Lista{
private:

public:

   virtual void push(int x)=0;
   virtual int pop()=0;
   virtual int Rozmiar()=0;

};

#endif // ISTOS_HH
