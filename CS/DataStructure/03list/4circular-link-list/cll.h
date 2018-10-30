template <typename ElemType>
class circularLinkList
{
public:
    class linkNode
    {
    public:
        ElemType data;
        linkNode *next;
    };
    typedef linkNode * nodeP;

    void clear();

    Status deleteElem(int i, ElemType & e);

    Status getHeadElem(ElemType & e);

    bool isEmpty();

    Status moveHead(int i);

    circularLinkList<ElemType> operator = (circularLinkList<ElemType> rightL);
    circularLinkList();

    ~circularLinkList();
    
    circularLinkList(const circularLinkList & otherL);

protected:
    nodeP head;
};


