#ifndef LINKLIST_H
    #define LINKLIST_H
    #include "../../myhead.h"
#endif

class myTerm
{
public:
    void read(istream& in);

    void display(ostream& out);

public:

    float coef;
    int expn;
};

void myTerm:read(istream& in)
{
    cout << "系数: ";

    while(!(in >> coef))
        cout << " 系数不能为零, 重新输入!" << endl;
    cout << "\t指数: ";
    in >> expn;
    cout << endl;
}

istream& operator >>(istream& in, myTerm& s)
{
    s.read(in);
    return in;
}

void myTerm::display(ostream& out)
{
    if(coef != 1)
        out << coef;
    if(expn)
        out << "x" << expn;
}

ostream& operator <<(ostream& out, myTerm& s)
{
    s.display(out);
    return out;
}


