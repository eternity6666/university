#ifndef MYHEAD_H
    #define MYHEAD_H
    #include "../../myhead.h"
#endif

#ifndef IOMANIP_H
    #define IOMANIP_H
    #include <iomanip>
#endif

template<typename elemtype>
class doubleLinkList
{
public:
    class linkNode
    {
    public:
        elemtype data;
        linkNode *next;
        linkNode *prior;
    };
    typedef linkNode * nodeP;

    void clear();

    bool getElem(int i, elemtype & e);

    bool deleteElem(elemtype e);

    nodeP getHead();

    int getLength();

    bool insert(int i, elemtype e);

    bool isEmpty();

    bool locateElem(elemtype find_e, nodeP &r);

    bool nextElem(elemtype e, elemtype &next_e);
    
    doubleLinkList<elemtype> operator = (doubleLinkList<elemtype> rightL);

    bool priorElem(elemtype e, elemtype &prior_e);

    doubleLinkList();

    ~doubleLinkList();

    doubleLinkList(const doubleLinkList<elemtype> &otherL);

    void input(int n);

    void display();

protected:
    nodeP head;
};

template <typename elemtype>
void doubleLinkList<elemtype>::display()
{
    int n = getLength();

    cout << "   ╭";
    fei(0, 5 * n - 3)
        cout << "─";
    cout << "╮" << endl;
    cout << "   ↓";
    fei(0, 5 * n - 3)
        cout << " ";
    cout << "│" << endl;
    cout << " ╭";
    nodeP p = head;
    do
    {
        cout << setw(3) << p->data << "->";
        p = p->next;
    }while(p != head);
    cout << endl;
    cout << " │  ";
    fei(0, n - 2)
        cout << "↑   │";
    cout << "↑" << endl;
    cout << " │  ";
    fei(0, n - 2)
        cout << "╰───╯";
    cout << "│" << endl;
    cout << " ╰";
    fei(0, 5 * (n - 1))
        cout << "─";
    cout << "─╯" << endl;
}

template <typename elemtype>
void doubleLinkList<elemtype>::input(int n)
{
    clear();
    cout << " 请输入循环双链表每个结点数据域的值: ";

    nodeP p, s;
    head = p = NULL;
    fei(1, n)
    {
        int tmp;
        cin >> tmp;

        s = new linkNode;
        assert(s != 0);
        
        s->data = tmp;

        if(!this->head)
            p = this->head = s;

        p->next = s;
        s->prior = p;

        p = s;
    }
    
    if(head)
    {
        head->prior = p;
        p->next = head;
    }

    cout << "\n 已经在当前循环双链表输入了" << n << "个结点\n\n";
    
    cout << " 输入的循环双链表如下:\n";

    display();
}

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
bool doubleLinkList<elemtype>::deleteElem(elemtype e)
{
    nodeP p;
    
    if(!locateElem(e,p))
        return false;

    if(head->next == head)
        head = NULL;
    else
    {
        if(p == head)
            head = p->next;

        p->prior->next = p->next;
        p->next->prior = p->prior;
    }
    delete p;
    return true;
}

template <typename elemtype>
bool doubleLinkList<elemtype>::getElem(int i, elemtype &e)
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
        return true;
    }

    return false;
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
bool doubleLinkList<elemtype>::insert(int i, elemtype e)
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
        return false;

    s = new linkNode;
    assert(s != 0);

    s->data = e;

    if(i == 1)
    {
        if(!head)
        {
            head = s->prior = s->next = s;
            return true;
        }
        head = s;
    }

    p->prior->next = s;
    s->prior = p->prior;
    p->prior = s;
    s->next = p;
    
    return true;
}

template <typename elemtype>
bool doubleLinkList<elemtype>::isEmpty()
{
    return head ? false : true;
}

template <typename elemtype>
bool doubleLinkList<elemtype>::locateElem(elemtype e, nodeP &r)
{
    nodeP p = head;

    while(p && p->next != head && p->data != e)
        p = p->next;

    if(p->data == e)
    {
        r = p;
        return true;
    }
    else
        return false;
}

template <typename elemtype>
bool doubleLinkList<elemtype>::nextElem(elemtype e, elemtype &next_e)
{
    nodeP p;
    if(locateElem(e, p))
    {
        next_e = p->next->data;
        return true;
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
bool doubleLinkList<elemtype>::priorElem(elemtype e, elemtype &prior_e)
{
    nodeP p;
    if(locateElem(e, p))
    {
        prior_e = p->prior->data;
        return true;
    }
    else
        return false;
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

