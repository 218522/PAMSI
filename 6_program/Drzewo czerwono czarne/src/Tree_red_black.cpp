#include "Tree_red_black.h"
#include "Node.h"
#include <iostream>

using namespace std;

Tree_red_black::Tree_red_black()
{
  guard.color = 'B';
  guard.parent = &guard;
  guard.left   = &guard;
  guard.right  = &guard;
  root = &guard;
}

Node * Tree_red_black::search_for_value(int value){

  Node * pointer;
  pointer = root;
  while((pointer != &guard) && (pointer->value != value))
    if(value < pointer->value) pointer = pointer->left;
    else           pointer = pointer->right;
  if(pointer == &guard) return NULL;
  return pointer;
}

// Rotate right
void Tree_red_black::rot_right(Node * rotate_point)
{
  Node * B, * p;

  B = rotate_point->left;
  if(B != &guard)
  {
    p = rotate_point->parent;
    rotate_point->left = B->right;
    if(rotate_point->left != &guard) rotate_point->left->parent = rotate_point;

    B->right = rotate_point;
    B->parent = p;
    rotate_point->parent = B;

    if(p != &guard)
    {
      if(p->left == rotate_point) p->left = B; else p->right = B;
    }
    else root = B;
  }
}
// Rotate left
void Tree_red_black::rot_left(Node * A)
{
  Node * B, * p;

  B = A->right;
  if(B != &guard)
  {
    p = A->parent;
    A->right = B->left;
    if(A->right != &guard) A->right->parent = A;

    B->left = A;
    B->parent = p;
    A->parent = B;

    if(p != &guard)
    {
      if(p->left == A) p->left = B; else p->right = B;
    }
    else root = B;
  }
}
//Procedure of adding new Node to the red/black tree, including exceptions
void Tree_red_black::add(int value)
{
  Node * Y;

  Node* n_Node = new Node;        // create new Node
  n_Node->left  = &guard;         // initiate Node
  n_Node->right = &guard;
  n_Node->parent = root;
  n_Node->value = value;
  if(n_Node->parent == &guard){   // n_Node becomes root
        root = n_Node;
  }
  else
  while(true)
  {
    if(value < n_Node->parent->value)
    {
      if(n_Node->parent->left == &guard)
      {
        n_Node->parent->left = n_Node;
        break;
      }
      n_Node->parent = n_Node->parent->left;
    }
    else
    {
      if(n_Node->parent->right == &guard)
      {
        n_Node->parent->right = n_Node;
        break;
      }
      n_Node->parent = n_Node->parent->right;
    }
  }
  n_Node->color = 'R';
  while((n_Node != root) && (n_Node->parent->color == 'R'))
  {
    if(n_Node->parent == n_Node->parent->parent->left)
    {
      Y = n_Node->parent->parent->right;
    // Pierwszy przypadek -> czarny dziadek i czerwony brat ojca
      if(Y->color == 'R')
      {
        n_Node->parent->color = 'B';
        Y->color = 'B';
        n_Node->parent->parent->color = 'R';
        n_Node = n_Node->parent->parent;
        continue;
      }
    // Drugi przypadek -> czarny dziadek i czarny brat ojca, dodany prawym synem
      if(n_Node == n_Node->parent->right)
      {
        n_Node = n_Node->parent;
        rot_left(n_Node);
      }
    // Trzeci przypadek -> czarny dziadek i czarny brat ojca, dodany lewym synem
      n_Node->parent->color = 'B';
      n_Node->parent->parent->color = 'R';
      rot_right(n_Node->parent->parent);
      break;
    }
    else
    {
      Y = n_Node->parent->parent->left;
      // Pierwszy przypadek -> odbicie lustrzane
      if(Y->color == 'R')
      {
        n_Node->parent->color = 'B';
        n_Node->color = 'B';
        n_Node->parent->parent->color = 'R';
        n_Node = n_Node->parent->parent;
        continue;
      }
      // Drugi przypadek -> odbicie lustrzane
      if(n_Node == n_Node->parent->left)
      {
        n_Node = n_Node->parent;
        rot_right(n_Node);
      }
      // Trzeci przypadek -> odbicie lustrzane
      n_Node->parent->color = 'B';
      n_Node->parent->parent->color = 'R';
      rot_left(n_Node->parent->parent);
      break;
    }
  }
  root->color = 'B';
}

