#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        Node * left;
        Node * right;
        Node * parent;
        int value;
        char color;
};

#endif // NODE_H
