#include "../../myhead.h"
#include <iomanip>
template<typename ElemType>
class SqStack
{
public:
    void clear();

    int getLength();

    int getStackSize();

    Status getTop(ElemType &e);

    bool isEmpty();

    SqStack<ElemType> operator = (SqStack<ElemType> rightS);

    Status pop(ElemType &e);

    void push(ElemType e);

    SqStack();

    ~SqStack();

    SqStack(const SqStack<ElemType> &otherS);

protected:
    ElemType *base;
    ElemType *top;
    int stackSize;
};

template<typename ElemType>
void SqStack<ElemType>::clear()
{
    top = base;
}

template<typename ElemType>
int SqStack<elemtype>::getLength()
{
    return top - base;
}

template<typename ElemType>
int SqStack<elemtype>::getStackSize()
{
    return stackSize;
}

template<typename ElemType>
Status SqStack<elemtype>::getTop(elemtype &e)
{
    if(isEmpty())
        return ERROR;
    else
        e = *(top - 1);
    return OK;
}

template<typename ElemType>
bool SqStack<elemtype>::isEmpty()
{
    return (top == base ? true : false);
}

template<typename ElemType>
SqStack<elemtype> SqStack<elemtype>::operator = (SqStack rights)
{
    int length = rights.getLength();
    if(this != &rights)
    {
        if(stackSize < rights.stackSize)
        {
            delete[] base;
            base = new elemtype[rights.stackSize];
            assert(base != 0);
            stackSize = rights.stackSize;
        }
        
        for(int i = 0; i < length; i++)
            *(base + i) = *(rights.base + i);
        top = base + length();
    }
    return *this;
}

template<typename ElemType>
Status SqStack<elemtype>::pop(elemtype &e)
{
    if(isEmpty())
        return ERROR;
    else
        e = *--top;
    return OK;
}

template<typename ElemType>
void SqStack<elemtype>::push(elemtype e)
{
    int length = top - base;
    elemtype *newbase;
    if(top - base >= stackSize)
    {
        newbase = new elemtype[stackSize + addSize];
        assert(newbase != 0);

        for(int j = 0; j < length; j ++)
            *(newbase + j) = *(base + j);
        delete []base;
        stackSize += addSize;
        base = newbase;
        top = base + length;
    }
    *top = e;
    ++top;
}

template<typename ElemType>
SqStack<elemtype>::SqStack()
{
    base = new elemtype[firstSize];
    assert(base != 0);
    stackSize = firstSize;
    top = base;
}

template<typename ElemType>
SqStack<elemtype>::~SqStack()
{
    if(base)
        delete []base;
    stackSize = 0;
    top = base = NULL;
}

template<typename ElemType>
SqStack<elemtype>::SqStack(const SqStack &others)
{
    int length;
    base = new elemtype[others.stackSize];
    assert(base != 0);
    stackSize = others.stackSize;
    for(int i = 0; i < length; i++)
        *(base + i) = *(othes.base + i);
    top = base + length;
}

