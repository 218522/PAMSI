#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
    friend class Binary_tree;
    public:
            Element();
            void set_value(int value);
    private:
            int value;
            Element* right;
            Element* left;
            Element* parent;
            char color;   // black (b) or red (r) only
};

#endif // ELEMENT_H
