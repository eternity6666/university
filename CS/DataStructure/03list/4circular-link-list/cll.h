#include "../../myhead.h"

template <typename elemtype>
class circularLinkList
{
public:
    class linkNode
    {
    public:
        elemtype data;
        linkNode *next;
    };
    typedef linkNode * nodeP;

    void clear();

    Status deleteElem(int i, elemtype & e);

    Status getHeadElem(elemtype & e);

    bool isEmpty();

    Status moveHead(int i);

    circularLinkList<elemtype> operator = (circularLinkList<elemtype> rightL);
    
    circularLinkList();

    ~circularLinkList();
    
    circularLinkList(const circularLinkList & otherL);

protected:
    nodeP head;
};

template <typename elemtype>
void circularLinkList<elemtype>::clear()
{
    nodeP p;
    while(head != head->next)
    {
        p = head->next;
        head->next = p->next;
        delete p;
    }
    delete head;
    head = NULL;
}

template <typename elemtype>
Status circularLinkList<elemtype>::deleteElem(int i, elemtype &e)
{
    int j = 1;
    nodeP r;
    nodeP p = head;

    if(!head)
        return ERROR;

    while(j < i)
    {
        r = p;
        p = p->next;
        ++j;
    }

    e = p->data;

    if(p == p->next)
        head = NULL;
    else
        head = r->next = p->next;

    delete p;
    return OK;
}

template <typename elemtype>
Status circularLinkList<elemtype>::getHeadElem(elemtype &e)
{
    if(!head)
        return ERROR;
    e = head->data;
    return OK;
}

template <typename elemtype>
bool circularLinkList<elemtype>::isEmpty()
{
    return head ? false : true;
}

template <typename elemtype>
Status circularLinkList<elemtype>::moveHead(int i)
{
    int j = 1;
    if(!head)
        return ERROR;

    while(j < i)
    {
        head = head->next;
        ++j;
    }

    return OK;
}

template <typename elemtype>
circularLinkList<elemtype> circularLinkList<elemtype>::operaotr = (circularLinkList<elemtype> rightL)
{
    nodeP p = NULL;
    nodeP rp = rightL.head;
    nodeP s;
    
    if(this != &rightL)
    {
        clear();

        while(rp->next != rightL.head)
        {
            s = new linkNode;
            assert(s != 0);
            
            s->data = rp->data;

            if(!head)
                head = s;
            else
                p->next = s;
            p = s;
            rp = rp->next;
        }

        if(head)
            p->next = head;
    }
    return *this;
}

template <typename elemtype>
circularLinkList<elemtype>::circularLinkList()
{
    head = NULL;
}

template <typename elemtype>
circularLinkList<elemtype>::~circularLinkList()
{
    clear();
}

template <typename elemtype>
circularLinkList<elemtype>::circularLinkList(const circularLinkList &otherL)
{
    nodeP p;
    nodeP op = otherL.head;
    nodeP s;
    head = p = NULL;

    while(op != otherL.head)
    {
        s = new linkNode;
        assert(s != 0);

        s->data = op->data;

        if(!head)
            head = s;
        else
            p->next = s;
        p = s;
        op = op->next;
    }

    if(head)
        p->next = head;
}

