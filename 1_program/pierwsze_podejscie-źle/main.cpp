#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// klasa zawierajaca tablice dynamiczna i metody do jej powiekszania/pomniejszania
class c_tablica {

public:
  int wymiar = 5;
  int * tablica = new int[wymiar];

  int * powiekszanie(int* T){
    wymiar++;
    int * tab = new int[wymiar];
    for(int i=0; i<wymiar; i++){
     tab[i]=T[i];
     }
    delete [] T;
    return tab;
  }

  int * pomniejsz(int* T, int n_wymiar){
    wymiar=n_wymiar;
    int * tab = new int[wymiar];
    for(int i=0; i<wymiar; i++){
     tab[i]=T[i];
     }
     return tab;
}
};



int main()
{

//zmienna okreslajaca ile elementow chcemy wpisac #na sztywno
 int n_wymiar;
 char a;
 c_tablica t_d;


cout<<"Wymiar tablicy:"<<t_d.wymiar<<endl;
cout<<"Zmienić wymiar tablicy [T/N] ?"<<endl;
cin>>a;
switch(a){
case 'T':
cout<<"Wprowadz nowy wymiar tablicy: ";
cin>>n_wymiar;
if(n_wymiar>t_d.wymiar){
cout<<"Zwiekszam wymiar tablicy"<<endl;
int a = t_d.wymiar;
while(n_wymiar>=a){
t_d.tablica=t_d.powiekszanie(t_d.tablica);
a++;
}
cout<<"sukces"<<endl;
}
else if(n_wymiar<t_d.wymiar){
cout<<"Zmniejszam wymiar tablicy"<<endl;
t_d.tablica=t_d.pomniejsz(t_d.tablica, n_wymiar);
cout<<"sukces"<<endl;
}
break;
case 'N':
cout<<"Brak opcji"<<endl;
default :
cout<<"blad wyboru";
break;
}
 /*if(n_wymiar<t_d.wymiar){
  t_d.tablica=t_d.pomniejsz(t_d.tablica,n_wymiar);
  cout<<"aktualny wymiar tablicy:"<<t_d.wymiar<<endl;
 }
 else if(n_wymiar>=t_d.wymiar){
  t_d.tablica=t_d.powiekszanie(t_d.tablica);
  cout<<"aktualny wymiar tablicy:"<<t_d.wymiar<<endl;
 }
 */
    return 0;
}
