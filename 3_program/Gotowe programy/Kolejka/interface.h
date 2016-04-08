#ifndef INTERFACE_H
#define INTERFACE_H


class interface
{
    public:
        virtual void move_out_first() =0;
        virtual void get_at_back() =0;
        virtual int size() =0;
};

#endif // INTERFACE_H
