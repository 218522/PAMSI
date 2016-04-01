#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

struct stack
{
    int x;
    struct stack *next;
};

typedef struct stack stack;


// Wrzucanie liczby na stos:
void push(stack **stos, int y)
{
    stack *e;

    e = new stack;
    e->x = y;
    e->next = *stos;

    *stos = e;
}


// Zdejmowanie liczby ze stosu:
void pop(stack **stos)
{
     stack *e;

     if (*stos == NULL) return;

     e = (*stos)->next;
     delete *stos;
     *stos = e;
}

// Funkcja zwraca wiercholek stosu:
stack* top(stack *stos)
{
    return stos;
}


// Czyszczenie stosu:
void empty(stack **stos)
{
     stack *e;

     if (*stos==NULL) return;

     while(*stos)
     {
         e = (*stos)->next;
         delete *stos;
         *stos = e;
     }
}


// Pomocnicza funkcja sluzaca do wyswietlania zawartosci stosu:
void display(stack *stos)
{
     while(stos)
     {
         cout << stos->x << " ";
         stos = stos->next;
     }
     cout << endl;
}


int main()
{
    stack *e;
    stack *stos=NULL;

    // Umieszczamy na stosie 4 elementy:
    push(&stos,3);
    push(&stos,8);
    push(&stos,13);
    push(&stos,2);


    // Wyswietlamy utworzony stos. Nalezy pamietac, ze elementy na stosie sa umieszczane w porzadku
    // FILO (first-in, last-out), czyli pierwszy na wejsciu, ostatni na wyjscu.
    // Oznacza to, ze ostatni element polozony na stosie bedzie na jego szczycie, a pierwszy natomiast na dnie.
    display(stos);


    // Pobieramy wierzcholek stosu:
    e = top(stos);
    cout << "Wierzcholek stosu: " << e->x << endl;

    // Zdejmujemy I element ze stosu:
    pop(&stos);
    display(stos);

    // Czyszczenie stosu:
    empty(&stos);

    return 0;
}
