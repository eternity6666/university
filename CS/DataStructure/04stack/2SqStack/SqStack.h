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


