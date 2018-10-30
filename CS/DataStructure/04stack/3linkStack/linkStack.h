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

