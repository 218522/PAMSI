#include <iostream>
#include <time.h>


/* Nie wiem dla czego nie moglem zmodyfikowac poprzedniego pliku (main.cpp) przez commit,
wiec wrzucam przez upload */


using namespace std;
// klasa zawierajaca tablice dynamiczna i metody do jej powiekszania/pomniejszania
class c_tablica {

public:
  int wymiar = 50;
  int * tablica = new int[wymiar];
// powiekszanie tablicy o jedno miejsce az do momentu dopasowania
  int * powiekszanie_o1(int* T){
    wymiar++;
    int * tab = new int[wymiar];
    for(int i=0; i<wymiar; i++){
     tab[i]=T[i];
     }
    delete [] T;
    return tab;
  }
// powiekszanie tablicy dwukrotnie
  int * powiekszanie_x2(int* T,int a){
    wymiar=wymiar*2;
    int * tab = new int[wymiar];
    for(int i=0; i<=(wymiar)/a; i++){
     tab[i]=T[i];
     }
    delete [] T;
    return tab;
  }
// powiekszanie tablicy potegowo
  int * powiekszanie_potega2(int* T,int b){
    wymiar=wymiar*wymiar;
    int * tab = new int[wymiar];
    for(int i=0; i<=(wymiar)/b; i++){
     tab[i]=T[i];
     }
    delete [] T;
    return tab;
  }
//pomniejszanie tablicy do zadanego wymiaru
  int * pomniejsz(int* T, int n_wymiar){
    wymiar=n_wymiar;
    int * tab = new int[wymiar];
    for(int i=0; i<wymiar; i++){
     tab[i]=T[i];
     }
    delete [] T;
    return tab;
}
};



int main()
{
 // zmienne potrzebne do pomiaru czasu
 clock_t start, stop;
 // zmienna okreslajaca ile elementow chcemy wpisac #na sztywno
 int n_wymiar;
 // pomocnicza do menu
 c_tablica t_d_1;
 int cykl_1=0;
 c_tablica t_d_2;
 int cykl_2=0;
 int a=2;
 c_tablica t_d_3;
 int cykl_3=0;
 int b=t_d_3.wymiar;
 int c=t_d_3.wymiar;

cout<<"Poczatkowy rozmiar tablicy tablicy:"<<t_d_1.wymiar<<endl;
cout<<"Wprowadz nowy wymiar tablicy: ";
cin>>n_wymiar;
//Zwiekszanie rozmiaru tablicy o 1 miejsce
  start = clock();
  while(n_wymiar>t_d_1.wymiar){
   t_d_1.tablica=t_d_1.powiekszanie_o1(t_d_1.tablica);
   cykl_1++;}
  stop = clock();
  long czas_1 = stop-start;
//Zwiekszanie rozmiaru tablicy dwukrotnie
  start = clock();
  while(n_wymiar>t_d_2.wymiar){
   t_d_2.tablica=t_d_2.powiekszanie_x2(t_d_2.tablica,a);
   a=a*2;
   cykl_2++;}
  if(n_wymiar<t_d_2.wymiar){
    t_d_2.tablica=t_d_2.pomniejsz(t_d_2.tablica,n_wymiar);
   }
  stop = clock();
  long czas_2 = stop-start;
  //Zwiekszanie rozmiaru tablicy do kwadratu obecnego rozmiaru
  start = clock();
  while(n_wymiar>t_d_3.wymiar){
   t_d_3.tablica=t_d_3.powiekszanie_potega2(t_d_3.tablica,b);
   b=t_d_3.wymiar;
   b=b*b/c;
   cykl_3++;}
  if(n_wymiar<t_d_3.wymiar){
    t_d_3.tablica=t_d_3.pomniejsz(t_d_3.tablica,n_wymiar);
   }
  stop = clock();
  long czas_3 = stop-start;


    cout<<"Czas wykonywania algorytmu :"<<endl
<<"Zwiekszanie rozmiaru tablicy o 1 miejsce: "<<czas_1<<endl<<"Zwiekszanie rozmiaru tablicy dwukrotnie: "<<czas_2<<endl<<"Zwiekszanie rozmiaru tablicy do kwadratu obecnego rozmiaru: "<<czas_3<<endl<<endl;
    cout<<"Ilosc wykonanych cykli powiekszenia:"<<endl<<"(1) "<<cykl_1<<endl<<"(2) "<<cykl_2<<endl<<"(3) "<<cykl_3<<endl;
    return 0;
}
