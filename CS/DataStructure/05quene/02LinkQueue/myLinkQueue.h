#ifndef MYLINKQUEUE_H
    #define MYLINKQUEUE_H
    #include "linkQueue.h"
template <typename elemtype>
class myLinkQueue:public linkQueue<elemtype>
{
public:
    void display(ostream& out);

    void getByRand(int display);

    // void read(istream& in);
};

template <typename elemtype>
void myLinkQueue<elemtype>::getByRand(int display)
{

}

template <typename elemtype>
void myLinkQueue<elemtype>::display(ostream& out)
{
    int n = 0;
    out << " ";
    typename nodeP tmp = this->front;
    while(tmp != this->rear)
    {
        n++;
        out << tmp->data;
        out << "";
        tmp = tmp->next;
    }
    out << tmp->data;
    n++;

    out << "    ";
    fei(0, n - 2)
        out << "    ";
    out << "  front";
    fei(0, n - 2)
        out << "    ";
    out << "rear" << endl;
}

ostream& operator <<(ostream& out, const myLinkQueue<elemtype>& x)
{
    x.display(out);
    return out;
}
/*
template <typename elemtype>
void myLinkQueue<elemtype>::read(istream& in)
{

}

istream& operator >>(istream& in, const myLinkQueue<elemtype>& x)
{
    x.read(in);
    return in;
}
*/
#endif

