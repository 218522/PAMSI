#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
    friend class Binary_tree;
    public:
            Element();
    private:
            int value;
            Element* right;
            Element* left;
            char color;   // black (b) or red (r) only
};

#endif // ELEMENT_H
