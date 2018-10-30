template<typename ElemType>
class SqQueue
{
public:
    void clear();

    Status deQueue(ElemType &e);

    Status enQueue(ElemType e);

    Status getFront(ElemType &e);

    int getLength();

    bool isEmpty();

    bool isFull();

    SqQueue<ElemType> operator = (SqQueue<ElemType> rightQ);

    SqQueue(int size = 0);

    virtual ~SqQueue();

    SqQueue(const SqQueue<ElemType> &otherQ);

protected:
    int rear;
    int front;
    int queueSize;
    ElemType *base;
};

