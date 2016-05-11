#include <iostream>
#include "Element.h"
#include "Binary_tree.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Binary_tree Tree;
    Tree.add(10);
    Tree.add(11);
    cout<<"DUPA"<<endl;
    Tree.add(6);
    cout<<"DUPA"<<endl;
    Tree.add(8);
    cout<<"DUPA"<<endl;
    Tree.add(15);
    Tree.add(14);
    Tree.add(16);
    cout<<"DUPA"<<endl;
    Tree.add(40);
    Tree.add(30);
    Tree.add(29);
    Tree.add(31);
    Tree.add(60);
    Tree.add(61);
    Tree.add(59);
    //Tree.add(5);
    /*
    for(int i=1; i<50; i++){
            cout<<i<<endl;
            if(i!=25){Tree.add(i);}
    }
    //Tree.add(i);
*/

    Tree.show_tree();
    return 0;
}
