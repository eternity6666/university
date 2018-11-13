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

template <typename elemtype>
void linkQueue<elemtype>::clear()
{
    nodeP q;
    nodeP p = front;
    while(p)
    {
        q = p;
        p = p->next;
        delete q;
    }
    front = rear = NULL;
}

template <typename elemtype>
bool linkQueue<elemtype>::deQueue(elemtype & e)
{
    if(!front)
        return false;

    nodeP s = front;
    e = s->data;
    front = front->next;
    delete s;

    if(!front)
        rear = NULL;

    return true;
}

template <typename elemtype>
void linkQueue<elemtype>::enQueue(elemtype e)
{
    nodeP s;
    s = new linkNode;
    assert(s != 0);

    s->data = e;
    s->next = NULL;

    if(!front)
        front = rear = s;
    else
    {
        rear->next = s;
        rear = s;
    }
}

template <typename elemtype>
bool linkQueue<elemtype>::getFront(elemtype &e))
{
    if(!front)
        return false;

    e = front->data;
    return true;
}

template <typename elemtype>
bool linkQueue<elemtype>::isEmpty()
{
    return !front ? true : false;
}

template <typename elemtype>
int linkQueue<elemtype>::getLength()
{
    int length = 0;
    nodeP p = front;

    while(p)
    {
        ++length;
        p = p->next;
    }
    return length;
}

template <typename elemtype>
linkQueue<elemtype> linkQueue<elemtype>::operator = (linkQueue<elemtype> rightQ)
{
    nodeP s;
    nodeP rp = rightQ.front;

    if(this != &rightQ)
    {
        clear();

        while(rp)
        {
            s = new linkNode;
            assert(s != 0);

            s->data = rp->data;
            s->next = NULL;

            if(!front)
                front = rear = s;
            else
            {
                rear->next = s;
                rear = s;
            }
            rp = rp->next;
        }
    }
    return *this;
}

template <typename elemtype>
linkQueue<elemtype>::linkQueue()
{
    front = rear = NULL;
}

template <typename elemtype>
linkQueue<elemtype>::~linkQueue()
{
    clear();
}

template <typename elemtype>
linkQueue<elemtype>::linkQueue(const linkQueue<elemtype> &otherQ)
{
    nodeP s;
    nodeP op = otherQ.front;

    rear = front = NULL;

    while(op)
    {
        s = new linkNode;
        assert(s != 0);

        s->data = op->data;
        s->next = NULL;

        if(!front)
            front = rear = s;
        else
        {
            rear->next = s;
            rear = s;
        }

        op = op->next;
    }
}

