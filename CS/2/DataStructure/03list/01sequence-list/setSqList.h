#ifndef SETSQLIST_H
    #define SETSQLIST_H

    #include "mySqList.h"

template <typename elemtype>
mySqList<elemtype> unionSet(mySqList<elemtype> firstL, mySqList<elemtype> secondL)
{
    elemtype e;
    mySqList<elemtype> thirdL(firstL);
    
    fei(1, secondL.getLength())
    {
        secondL.getElem(i, e);
        if(firstL.locateElem(e, equal) == -1)
            thirdL.addElem(e, thirdL.getLength());
    }
    return thirdL;
}

template <typename elemtype>
mySqList<elemtype> intersectionSet(mySqList<elemtype> firstL, mySqList<elemtype> secondL)
{
    int k = 0;
    elemtype e;
    
    mySqList<elemtype> thirdL;

    fei(1, firstL.getLength())
    {
        firstL.getElem(i, e);
        if(secondL.locateElem(e, equal))
            thirdL.addElem(e, ++k);
    }
    return thirdL;
}

template <typename elemtype>
mySqList<elemtype> dirfferenceSet(mySqList<elemtype> firstL, mySqList<elemtype> secondL)
{
    int k = 0;
    elemtype e;
    
    mySqList<elemtype> thirdL;

    fei(1, firstL.getLength())
    {
        firstL.getElem(i, e);
        if(secondL.locateElem(e, equal) == -1)
            thirdL.addElem(e, ++k);
    }
    return thirdL;
}
#endif

