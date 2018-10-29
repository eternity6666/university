template <typename ElemType>
class rectangle
{
public:
    ElemType width;
    ElemType length;
    
    rectangle();
};

template<typename ElemType>
rectangle<ElemType>::rectangle()
{
    width = 0;
    length = 0;
}

template <typename ElemType>
class myRectangle:public rectangle<ElemType>
{
public:
    // myRectangle();
    // ~myRectangle();
    ElemType a;
};

/*
template <typename ElemType>
myRectangle<ElemType>::myRectangle()
{
    a = 0;
}

*/
