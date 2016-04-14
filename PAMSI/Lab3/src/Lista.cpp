#include "Lista.hh"
#include <math.h>


void Lista::dodaj(int x,int nr)
{
    Element *tmp=new Element(x);
    if(nr==0)
    {
        if(get_size()==0)
        {
            poczatek=koniec=tmp;
        }
        else
        {
            tmp->nastepny=poczatek;
            poczatek=tmp;
        }
    }
    else if(nr==get_size())
    {
        if(this->get_size()==0)
        {
            poczatek=koniec=tmp;
        }
        else
        {
            koniec->nastepny=tmp;
            koniec=tmp;
            koniec->nastepny=NULL;
        }
    }
    else
    {
        if(get_size()<nr)
        {
            cout<<"Nie da się dodac w wybrane miejsce! Za malo danych"<<endl;
        }
        else
        {
            int i=1;
            Element *q;
            Element *p;
            p=poczatek;
            while(i<nr)
            {
                p=p->nastepny;
                i++;
            }
            q=p->nastepny;
            p->nastepny=tmp;
            p=tmp;
            p->nastepny=q;
        }
    }

}
void Lista::usun(int pozycja)
{
    Element* tmp=poczatek;

    if(pozycja==0)
    {
        poczatek=poczatek->nastepny;
        delete tmp;
        tmp=poczatek;
    }

    else if(pozycja==get_size())
    {
        int i=0;

        while(i<(get_size()-2))
        {
            i++;
            tmp=tmp->nastepny;
        }
        koniec=tmp;
        koniec->nastepny=NULL;
    }
    else
    {
        if(get_size()<pozycja)
        {
            cout<<"Nie da się dodac w wybrane miejsce! Za malo danych"<<endl;
        }
        else
        {
            int i=0;

            Element *p=poczatek;
            Element *q=poczatek;
            while(i<pozycja)
            {
                i++;
                p=p->nastepny;

            }
            q=p->nastepny->nastepny;
            p->nastepny=q;
        }
    }
}
int Lista::get(int nr)
{
    int i=1;
    Element *tmp=poczatek;
    if(nr>this->get_size())
    {
        cout<<"NIE DA SIE SCIAGNAC TEGO ELEMENTU"<<endl;
    }
    if(nr==1)
    {
        tmp=tmp->nastepny;
        return tmp->dana;
    }
    while(i<nr)
    {
        i++;
        tmp=tmp->nastepny;
    }
   
    return tmp->dana;

}
int Lista::get_size()
{
    int i=0;
    Element *tmp=poczatek;
    while(tmp)
    {
        i++;
	
        tmp=tmp->nastepny;
    }
    return i;
}

void Lista::przeszukaj(int a)
{
    int x=0;
    Element *tmp=poczatek;
    while(tmp)
    {
        if(tmp->dana==a)
        {
            x++;
        }
        tmp=tmp->nastepny;
    }
    cout<<"Na liscie znajduje się "<<x<<" Takich wartosci"<<endl;
}


//********************modifications start****************
//Returns address to the 'Element' placed at 'position'
Element* Lista::get_address(int position){
  Element* pointer=poczatek;
  for(int i=1;position>i;i++){
    pointer=pointer->nastepny;
  }
  return pointer;
}
//Writes out values of lists elements in first-last order
void Lista::show_list(){
    Element *tmp=poczatek;
    while(tmp)
    {
	cout<<tmp->dana<<" ";
        tmp=tmp->nastepny;
    }
}

//Quicksort algoritm
void Lista::Quicksort(){
  int list_size=get_size();
  Element* pivot;
  //Pivot to srodkowy element listy
  if(list_size%2==0){
    pivot = get_address(list_size/2);
  }
  else{
    pivot = get_address((list_size+1)/2);
  }
  cout<<"Pivot: "<<pivot->dana<<endl;
  Element* left = poczatek;
  int left_counter = 1;
  Element* right = koniec;
  int right_counter = 1;
  while(1){
    while(pivot->dana>left->dana){
      left=left->nastepny;
      left_counter++;
      }
    while(pivot->dana<right->dana){
      //idziemy od prawej do lewej, a nie mamy wskaznika w te strone
      right=get_address(get_size()-right_counter);
      right_counter++;
      }
    cout<<left->dana<<" "<<left_counter<<" <-> "<<right_counter<<" "<<right->dana<<endl;
    if(right_counter+left_counter<=get_size()){
      //Swapping elements
      Element* pointer_1=get_address(left_counter);
      Element* pointer_2=get_address(get_size()+1-right_counter);/*
      int value_1 = pointer_1->dana;
      int value_2 = pointer_2->dana;
      cout<<pointer_1->dana<<endl;
      cout<<pointer_2->dana<<endl;
      usun(0);
      usun(get_size());
      dodaj(value_2,0);
      dodaj(value_1,get_size());
      //usun(get_size()+1-right_counter);
      */
      Element* pointer_1_after = pointer_1->nastepny;
      Element* pointer_2_after = pointer_2->nastepny;
      Element* help;
      cout<<pointer_1->dana<<endl;
      cout<<pointer_1_after->dana<<endl;
      cout<<pointer_2->dana<<endl;
      cout<<pointer_2_after->dana<<endl;
      help = pointer_1;
      pointer_1=pointer_2;
      pointer_2=help;
      help = pointer_1_after;
      pointer_1_after=pointer_2_after;
      pointer_2_after = help;
      cout<<pointer_1->dana<<endl;
      cout<<pointer_1_after->dana<<endl;
      cout<<pointer_2->dana<<endl;
      cout<<pointer_2_after->dana<<endl;
    }
      break;
}
  //Pivot = zaokraglona wartosc srednia
  /*
  float average=0;
  int pivot;
  Element *tmp=poczatek;
    while(tmp)
    {
      average+=tmp->dana;
      tmp=tmp->nastepny;
    }
    average = average/get_size();
    average=round(average);
    cout<<"Pivot: "<<average<<endl;
    pivot = average;*/
}
//********************modifications bottom***************

