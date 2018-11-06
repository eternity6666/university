#include "../../myhead.h"
template<typename ElemType>
class doubleLinkList
{
public:
    class linkNode
    {
        ElemType data;
        linkNode *next;
        linkNode *prior;
    };
    typedef linkNode * nodeP;

    void clear();

    Status getElem(int i, ElemType & e);

    Status deleteElem(ElemType e);

    nodeP getHead();

    int getLength();

    Status insert(int i, ElemType e);

    bool isEmpty();

    Status locateElem(ElemType find_e, nodeP &r);

    Status nextElem(ElemType e, ElemType &next_e);
    
    doubleLinkList<ElemType> operator = (doubleLinkList<ElemType> rightL);

    Status priorElem(ElemType e, ElemType &prior_e);

    doubleLinkList();

    ~doubleLinkList();

    doubleLinkList(const doubleLinkList<ElemType> &otherL);
};

template <typename elemtype>
void doubleLinkList<elemtype>::clear()
{
    nodeP r,p;
    
    if(!head)
        return ;

    p = head->prior;

    while(p!=head)
    {
        r = p->prior;
        delete p;
        p = r;
    }
    delete p;

    head = NULL;
}

template <typename elemtype>
Status doubleLinkList<elemtype>::deleteElem(elemtype e)
{
    nodeP p;
    
    if(!locateElem(e,p))
        return ERROR;

    if(head->next == head)
        head = NULL;
    else
    {
        if(p == head)
            head = p->next;

        p->prior->next = p->next;
        p-next->prior = p->prior;
    }
    delete p;
    return OK;
}

template <typename elemtype>
Status doubleLinkList<elemtype>::getElem(int i, elemtype &e)
{
    int j = 1;
    nodeP p = head;

    while(p && p->next != head && j < i)
    {
        p = p->next;
        ++j;
    }

    if(j == i)
    {
        e = p->data;
        return OK;
    }

    return ERROR;
}

template <typename elemtype>
typename doubleLinkList<elemtype>::nodeP doubleLinkList<elemtype>::getHead()
{
    return head;
}

template <typename elemtype>
int doubleLinkList<elemtype>::getLength()
{
    int length = 0;
    nodeP p = head;

    while(p)
    {
        ++length;
        p = p->next;
        if(p == head)
            break;
    }

    return length;
}

template <typename elemtype>
Status doubleLinkList<elemtype>::insert(int i, elemtype &e)
{
    int j = 1;
    nodeP p = head;
    nodeP s;

    while(p && p->next != head && j < i)
    {
        p = p->next;
        ++j;
    }

    if(!head && i != 1 || j < i)
        return ERROR;

    s = new linkNode;
    assert(s != 0);

    s->data = e;

    if(i == 1)
    {
        if(!head)
        {
            head = s->prior = s->next = s;
            return OK;
        }
        head = s;
    }

    p->prior->next = s;
    s->prior = p->prior;
    p->prior = s;
    s->next = p;
    
    return OK;
}

template <typename elemtype>
bool doubleLinkList<elemtype>::isEmpty()
{
    return head ? false : true;
}

template <typename elemtype>
Status doubleLinkList<elemtype>::locateElem(elemtype e, nodeP &r)
{
    nodeP p = head;

    while(p && p->next != head && p->data != e)
        p = p->next;

    if(p->data == e)
    {
        r = p;
        return OK;
    }
    else
        return ERROR;
}

template <typename elemtype>
Status doubleLinkList<elemtype>::nextElem(elemtype e, elemtype &next_e)
{
    nodeP p;
    if(locateElem(e, p))
    {
        next_e = p->next->data;
        return OK;
    }
    else
        return false;
}

template <typename elemtype>
doubleLinkList<elemtype> doubleLinkList<elemtype>::operator = (doubleLinkList<elemtype> rightL)
{
    nodeP p = NULL;
    nodeP rp = rightL.getHead();

    nodeP s;

    if(this != &rightL)
    {
        clear();
        while(rp)
        {
            s = new linkNode;
            assert(s != 0);

            s->data = rp->data;
            
            if(!head)
                head = p = s;
            
            p->next = s;
            s->prior = p;
            p = s;
            rp = rp->next;
            
            if(rp == rightL.head)
                break;
        }
        
        if(head)
        {
            head->prior = p;
            p->next = head;
        }
    }
    return *this;
}

template <typename elemtype>
Status doubleLinkList<elemtype>::priorElem(elemtype e, elemtype &prior_e)
{
    nodeP p;
    if(locateElem(e, p))
    {
        prior_e = p->prior->data;
        return OK;
    }
    else
        return ERROR;
}

template <typename elemtype>
doubleLinkList<elemtype>::doubleLinkList()
{
    head = NULL;
}

template <typename elemtype>
doubleLinkList<elemtype>::~doubleLinkList()
{
    clear();
}

template <typename elemtype>
doubleLinkList<elemtype>::doubleLinkList(const doubleLinkList &otherL)
{
    nodeP p;
    nodeP op = otherL.head;
    nodeP s;
    head = p = NULL;

    while(op)
    {
        s = new linkNode;
        assert(s != 0);
        
        s->data = op->data;
        
        if(!head)
            head = p = s;

        p->next = s;
        s->prior = p;

        p = s;
        op = op->next;

        if(op == otherL.head)
            break;
    }

    if(head)
    {
        head->prior = p;
        p->next = head;
    }
}

