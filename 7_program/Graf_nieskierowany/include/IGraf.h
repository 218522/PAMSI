#ifndef IGRAF_H
#define IGRAF_H


class IGraf
{
    public:
        virtual void add_Vertex(int vertex_number_1, int vertex_number_2)=0;
        virtual void add_Edge(int vertex_number_1)=0;
        virtual void get_Neighbours(int vertex_number)=0;
        virtual int is_Connected(int vertex_number_1, int vertex_number_2)=0;
};

#endif // IGRAF_H
