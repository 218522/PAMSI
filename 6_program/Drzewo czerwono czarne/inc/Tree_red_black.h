#ifndef TREE_RED_BLACK_H
#define TREE_RED_BLACK_H
#include "Node.h"
#include "ITree_red_black.h"

using namespace std;

class Tree_red_black
:public ITree_red_black
{
  private:
    Node guard;
    Node * root;
  public:
    Tree_red_black();
    void add(int value);          // Add new Node
    void rot_left(Node * point);  // Rotate left
    void rot_right(Node * point); // Rotate right
    Node* search_for_value(int value);
};

#endif // TREE_RED_BLACK_H
