#include<iostream>
using namespace std;
 
struct liczba
{
int wartosc;
liczba *next;
 
};
 
int main()
{
char warunek;
liczba *root=NULL, *nowa = NULL, *end=NULL, *temp=NULL;
while (cin>>warunek)
{
switch (warunek)
{
case 'd': //dodaj nowy element do kolejki
nowa=new liczba;
cin>>nowa->wartosc;
if (root==NULL) //dodaj pierwszy element do kolejki
{
root=nowa;
end=nowa;
nowa->next=NULL;
 
}
else //dodaj kolejny element do kolejki
{
nowa->next=root;
root=nowa;
}
break;
 
case 'z': //zabierz element z kolejki
if (end && end == root) //zabierz ostatni element z kolejki
{
cout<<end->wartosc<<endl;
delete end;
end = root = NULL;
}
else if (end) //zabierz element z kolejki
{
temp=root;
while (temp->next!=end)
temp=temp->next;
cout<<end->wartosc<<endl;
delete end;
end=temp;
}
break;
 
case 'k': //zakoncz program
return 0;
}
}
 
 
return 0;
}
