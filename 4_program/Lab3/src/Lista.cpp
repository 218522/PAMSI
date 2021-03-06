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
    cout<<endl;
}

int Lista::how_far(Element* pointer){
  Element *tmp = poczatek;
  int i=1;
    while(tmp!=pointer)
    {
        tmp=tmp->nastepny;
	i++;    
    }
    return i;
}

//Quicksort algoritm
void Lista::Quicksort(int left_counter, int right_counter){
  Element* pivot;
  int pivot_value;
  int list_size = left_counter+right_counter-1;

  //Pivot to srodkowy element listy
  if(list_size%2==0){
    pivot = get_address(list_size/2);
  }
  else{
    pivot = get_address((list_size+1)/2);
  }
  pivot_value=pivot->dana;
  

  Element* left = get_address(left_counter);
  Element* right = get_address(right_counter);
  int c=0;
  int d=0;

  while(1){

    while(pivot_value>(left=get_address(how_far(left)+d))->dana){d=1;}
    while(pivot_value<(right=get_address(how_far(right)-c))->dana){c=1;}
    c=1;
    d=1;
    if(how_far(left)+(list_size-how_far(right))<=list_size){
      //Swapping elements
      int help;
      help = left->dana;
      left->dana = right->dana;
      right->dana = help;
    }
    else{
      break;
    }
  }
  if(how_far(right)>left_counter){
    Quicksort(left_counter,how_far(right));
  }
  if(how_far(left)<right_counter){
    Quicksort(how_far(left), right_counter);
  }
}

// Mergesort
void Lista::Merge(int left, int new_line, int right, int* help)
{
	int i,j,q;
	// Copy from list to help array
	for (i=left; i <= right; i++){
		help[i] = get_address(i)->dana;  
	}
	// Set pointers
	i = left;
	j = new_line + 1;
	q = left;
	// Sort elements and move from help array to list
	while (i <= new_line && j <= right) {
		if (help[i] < help[j]){
			get_address(q++)->dana = help[i++];
		}
		else
			get_address(q++)->dana = help[j++];
	}
	while (i <= new_line){
		get_address(q++)->dana = help[i++];
	}

}

void Lista::Mergesort(int left, int right, int* help)
{
	int new_line;
	if (left < right) {
		new_line = (left + right)/2;
		Mergesort(left, new_line, help);
		Mergesort(new_line + 1, right, help);
		Merge(left, new_line, right, help);     // Merge left part, right part
	}
}

//********************modifications bottom***************

