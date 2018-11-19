#include "../../myhead.h"
#include <iomanip>
template<typename elemtype>
class linkStack
{
private:
    class linkNode
    {
    public:
        elemtype data;
        linkNode *next;
    };
    typedef linkNode * nodeP;

public:
    void clear();

    int getLength();

    bool getTop(elemtype &e);

    bool isEmpty();

    linkStack<elemtype> operator = (linkStack<elemtype> rightS);

    bool pop(elemtype &e);

    void push(elemtype e);

    linkStack();
    
    ~linkStack();

    linkStack(const linkStack<elemtype> &otherS);

protected:
    nodeP top;
};

template<typename elemtype>
void linkStack<elemtype>::clear()
{
    nodeP s;
    while(top)
    {
        s = top;
        top = top->next;
        delete s;
    }
    top = NULL;
}

template<typename elemtype>
int linkStack<elemtype>::getLength()
{
    int length = 0;
    nodeP p = top;
    while(p)
    {
        ++length;
        p = p->next;
    }
    return length;
}

template<typename elemtype>
bool linkStack<elemtype>::getTop(elemtype &e)
{
    if(!top)
        return false;
    e = top->data;
    return true;
}

template<typename elemtype>
bool linkStack<elemtype>::isEmpty()
{
    return (top ? false : true);
}

template<typename elemtype>
linkStack<elemtype> linkStack<elemtype>::operator = (linkStack<elemtype> rightS)
{
    nodeP p;
    nodeP rp = rightS.top;
    nodeP s;
    if(this != &rightS)
    {
        clear();

        while(rp)
        {
            s = new linkNode;
            assert(s != 0);

            s->data = rp->data;

            if(!top)
                top = s;
            else
                p->next = s;
            p = s;
            rp = rp->next;
        }
        if(p)
            p->next = NULL;
    }
    return *this;
}

template<typename elemtype>
bool linkStack<elemtype>::pop(elemtype &e)
{
    nodeP s = top;
    if(!top)
        return false;
    e = top->data;
    top = top->next;
    delete s;
    return true;

}

template<typename elemtype>
void linkStack<elemtype>::push(elemtype e)
{
    nodeP s;
    s = new linkNode;
    assert(s != 0);

    s->data = e;
    s->next = top;
    top = s;
}

template<typename elemtype>
linkStack<elemtype>::linkStack()
{
    top = NULL;
}

template<typename elemtype>
linkStack<elemtype>::~linkStack()
{
    clear();
}

template<typename elemtype>
linkStack<elemtype>::linkStack(const linkStack<elemtype> &otherS)
{
    nodeP p = NULL, op = otherS.top, s;

    top = NULL;

    while(op)
    {
        s = new linkNode;
        assert(s != 0);

        s->data = op->data;
        if(!top)
            top = s;
        else
            p->next = s;
        p = s;
        op = op->next;
    }
    if(p)
        p->next = NULL;
}

