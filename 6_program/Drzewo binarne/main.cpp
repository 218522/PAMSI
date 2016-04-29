#include <iostream>
#include "Element.h"
#include "Binary_tree.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Binary_tree Tree;
    Tree.add(4);
    Tree.add(7);
    Tree.show_tree();
    return 0;
}
