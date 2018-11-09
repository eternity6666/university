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

    Status pop(ElemType &e);

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

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

template<typename ElemType>

