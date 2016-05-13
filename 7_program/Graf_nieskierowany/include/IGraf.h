#ifndef IGRAF_H
#define IGRAF_H


class IGraf
{
    public:
        virtual void add_Vertex()=0;
        virtual void add_Edge()=0;
        virtual void get_Neighbours()=0;
        virtual void is_Connected()=0;
};

#endif // IGRAF_H
