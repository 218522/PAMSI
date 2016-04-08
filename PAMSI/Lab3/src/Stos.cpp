#include "Stos.hh"
    void Stos::push(int x){
        this->dodaj(x,0);

    }
    int Stos::pop(){
        if(this->Rozmiar()>0)
        {
        int tmp=this->get(0);
        this->usun(0);
        return tmp;
        }
        else
        {
        cout<<"LISTA JEST PUSTA!"<<endl;
        exit(0);
        }
    }
    int Stos::Rozmiar(){
        return this->get_size();
    }
