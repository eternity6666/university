#ifndef SQSTACK_H
    #define SQSTACK_H


#include "../../myhead.h"
#include <iomanip>

const int addSize = 10;
const int firstSize = 100;

template<typename elemtype>
class SqStack
{
public:
    void clear();

    int getLength();

    int getStackSize();

    bool getTop(elemtype &e);

    bool isEmpty();

    SqStack<elemtype> operator = (SqStack<elemtype> rightS);

    bool pop(elemtype &e);

    void push(elemtype e);

    SqStack();

    ~SqStack();

    SqStack(const SqStack<elemtype> &otherS);

protected:
    elemtype *base;
    elemtype *top;
    int stackSize;
};

template<typename elemtype>
void SqStack<elemtype>::clear()
{
    top = base;
}

template<typename elemtype>
int SqStack<elemtype>::getLength()
{
    return top - base;
}

template<typename elemtype>
int SqStack<elemtype>::getStackSize()
{
    return stackSize;
}

template<typename elemtype>
bool SqStack<elemtype>::getTop(elemtype &e)
{
    if(isEmpty())
        return ERROR;
    else
        e = *(top - 1);
    return OK;
}

template<typename elemtype>
bool SqStack<elemtype>::isEmpty()
{
    return (top == base ? true : false);
}

template<typename elemtype>
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
        top = base + length;
    }
    return *this;
}

template<typename elemtype>
bool SqStack<elemtype>::pop(elemtype &e)
{
    if(isEmpty())
        return ERROR;
    else
        e = *--top;
    return OK;
}

template<typename elemtype>
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

template<typename elemtype>
SqStack<elemtype>::SqStack()
{
    base = new elemtype[firstSize];
    assert(base != 0);
    stackSize = firstSize;
    top = base;
}

template<typename elemtype>
SqStack<elemtype>::~SqStack()
{
    if(base)
        delete []base;
    stackSize = 0;
    top = base = NULL;
}

template<typename elemtype>
SqStack<elemtype>::SqStack(const SqStack &others)
{
    int length = others.top - others.base;
    base = new elemtype[others.stackSize];
    assert(base != 0);
    stackSize = others.stackSize;
    for(int i = 0; i < length; i++)
        *(base + i) = *(others.base + i);
    top = base + length;
}
#endif

