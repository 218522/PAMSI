#ifndef INTERFEJS_H
#define INTERFEJS_H


class Interfejs
{
    public:
    virtual void set_tab() =0;
    virtual void reset_tab() =0;
    virtual void show_tab() =0;
    virtual void give_size() =0;
};

#endif // INTERFEJS_H
