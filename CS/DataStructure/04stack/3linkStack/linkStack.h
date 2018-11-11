#include "../../myhead.h"
#include <iomanip>
template<typename ElemType>
class linkStack
{
private:
    class linkNode
    {
    public:
        ElemType data;
        linknode *next;
    };
    typedef linkNode * nodeP;

public:
    void clear();

    int getLength();

    Status getTop(ElemType &e);

    bool isEmpty();

    linkStack<ElemType> operator = (linkStack<ElemType> rightS);

    bool pop(ElemType &e);

    void push(ElemType e);

    linkStack();
    
    ~linkStack();

    linkStack(const linkStack<ElemType> &otherS);

protected:
    nodeP top;
};

template<typename ElemType>
void linkStack<elemtype>::clear()
{
    nodeP s;
    while(top)
    {
        s = top;
        top = top->next;
        delete s
    }
    top = NULL;
}

template<typename ElemType>
int linkStack<elemtype>::getLength()
{
    int length = 0;
    nodeP p = top;
    while(p)
    {
        ++length;
        p = p->next;
    }
    return 0;
}

template<typename ElemType>
bool linkStack<elemtype>::getTop(elemtype &e)
{
    if(!top)
        return false;
    e = top->data;
    return true;
}

template<typename ElemType>
bool linkStack<elemtype>::isEmpty()
{
    return (top ? false : true);
}

template<typename ElemType>
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

template<typename ElemType>
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

template<typename ElemType>
void linkStack<elemtype>::push(elemtype e)
{
    nodeP s;
    s = new linkNode;
    assert(s != 0);

    s->data = e;
    s->next = top;
    top = s;
}

template<typename ElemType>
linkStack<elemtype>::linkStack()
{
    top = NULL;
}

template<typename ElemType>
linkStack<elemtype>::~linkStack()
{
    clear();
}

template<typename ElemType>
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

