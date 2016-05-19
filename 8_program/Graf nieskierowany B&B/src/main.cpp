#include <iostream>
#include "Graf.h"
#include "Stoper.h"
#include <cstdlib>

using namespace std;

int main()
{

    Graf Grafes;
    Stoper Timer_1;

    int g_size = Grafes.graph_size();
    for(int i=0;i<g_size-1;i++)
        Grafes.add_Edge(i,i+1,rand()%20);
    Grafes.add_Edge(0,g_size-1,rand()%20);
    for(int i=0;i<(g_size/10);i++)
        Grafes.add_Edge(rand()%g_size,rand()%g_size,rand()%20);

    Timer_1.start_clock();
    Grafes.Branch_and_Bound(0,5);
    Timer_1.stop_clock();
    cout<<endl<<" B&B time: "<<Timer_1.get_time()<<"[ms]"<<endl;
    return 0;
}
/*
    // Inicjowanie krawedzi grafu
    for(int i=0; i<(Grafes.graph_size()-1); i++){
        Grafes.add_Edge(i, i+1);
    }
    Grafes.add_Edge(Grafes.graph_size()-1, 0);
    Grafes.add_Edge(Grafes.graph_size()-1, Grafes.graph_size()/2);



    // Pomiary
    Timer_1.start_clock();
    Grafes.BFS(1);
    Timer_1.stop_clock();
    cout<<" BFS time: "<<Timer_1.get_time()<<"[ms]"<<endl;

    /*Grafes.clear();
    Timer_1.start_clock();
    Grafes.DFS(1);
    Timer_1.stop_clock();
    cout<<" DFS time: "<<Timer_1.get_time()<<"[ms]"<<endl;
*/
