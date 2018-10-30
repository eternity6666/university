template<typename ElemType>
class linkQueue
{
private:
    class linkNode
    {
        ElemType data;
        linkNode *next;
    };
    typedef linkNode *nodeP;

public:
    void clear();

    Status deQueue(ElemType &e);

    Status enQueue(ElemType e);

    Status getFront(ElemType &e);

    int getLength();

    bool isEmpty();

    linkQueue<ElemType> operator = (linkQueue<ElemType> rightQ);

    linkQueue();

    virtual ~linkQueue();

    linkQueue(const linkQueue<ElemType> &otherQ);

protected:
    nodeP rear;
    nodeP front;
};

