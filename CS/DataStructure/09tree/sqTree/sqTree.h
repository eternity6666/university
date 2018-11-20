#ifndef MYHEAD_H
    #define MYHEAD_H
    #include "../../myhead.h"
#endif

template <typename elemtype>
class sqTree
{
public:
    void clear();

    int getFinalIndex();

    elemtype* getInitialAddress();

    elemtype getNode(int i);

    sqTree<elemtype> operator = (sqTree<elemtype> rightT);

    void setFinalIndex(int i);

    void setNode(int i, elemtype value);

    sqTree();

    virtual ~sqTree();

    sqTree(const sqTree<elemtype>& seqT);

protected:
    elemtype* initialAddress;

    int finalIndex;
};

template <typename elemtype>
void sqTree<elemtype>::clear()
{
    if(initialAddress)
        delete[] initialAddress;

    initialAddress = NULL;
    finalIndex = -1;
}

template <typename elemtype>
int sqTree<elemtype>::getFinalIndex()
{
    return finalIndex;
}

template <typename elemtype>
elemtype* sqTree<elemtype>::getInitialAddress()
{
    return initialAddress;
}

template <typename elemtype>
elemtype sqTree<elemtype>::getNode(int i)
{
    if(i < 0 || i > finalIndex)
    {
        cerr << OVERFLOW;
        exit(1);
    }
    return initialAddress[i];
}

template <typename elemtype>
sqTree<elemtype> sqTree<elemtype>::operator = (sqTree<elemtype> rightT)
{
    if(this != &rightT)
    {
        finalIndex = rightT.finalIndex;
        if(finalIndex != -1)
        {
            initialAddress = new elemtype [finalIndex + 1];
            assert(initalAddress != 0);
            fei(0, finalIndex - 1)
                initialAddress[i] = rightT.initialAddress[i];
        }
    }
}

template <typename elemtype>
void sqTree<elemtype>::setFinalIndex(int i)
{
    finalIndex = i;
}

template <typename elemtype>
void sqTree<elemtype>::setNode(int i, elmetype value)
{
    initialAddress[i] = value;
    if(i > finalIndex)
        finalIndex = i;
}

template <typename elemtype>
sqTree<elemtype>::sqTree()
{
    initialAddress = NULL;
    finalIndex = -1;
}

template <typename elemtype>
sqTree<elemtype>::~sqTree()
{
    clear();
}

template <typename elemtype>
sqTree<elemtype>::sqTree(const sqTree& otherT)
{
    initialAddress = NULL;
    finalIndex = otherT.finalIndex;

    if(finalIndex != -1)
    {
        initialAddress = new elemtype[finalIndex + 1];
        assert(initialAddress != 0);

        fei(0, finalIndex)
            initialAddress[i] = otherT.initialAddress[i];
    }
}

