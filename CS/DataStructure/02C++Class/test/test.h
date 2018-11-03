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

