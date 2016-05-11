#ifndef ITREE_RED_BLACK_H
#define ITREE_RED_BLACK_H
#include "Node.h"

class ITree_red_black
{
    public:
        virtual void add(int value)=0;          // Add new Node
        virtual void rot_left(Node * point)=0;  // Rotate left
        virtual void rot_right(Node * point)=0; // Rotate right
};

#endif // ITREE_RED_BLACK_H
