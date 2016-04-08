#ifndef ISTOS_HH
#define ISTOS_HH
#include "Lista.hh"

class IStos:public Lista{
private:

public:

   virtual void push(int x)=0;
   virtual int pop()=0;
   virtual int Rozmiar()=0;

};

#endif // ISTOS_HH
