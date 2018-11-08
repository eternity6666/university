#include "../../myhead.h"
#include <iomanip>

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

    void display();
    
    void randList();

    void input();

    void clear();

    int getLength();

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
void circularLinkList<elemtype>::input()
{
    cout << " 请输入循环双链表中结点的个数:";
    clear();

    int n;
    cin >> n;
    int array[10000];
    for(int i = 0; i < n; i++)
        cin >> array[i];

    nodeP p, s;
    p = head;
    for(int i = 1; i <= n; i++)
    {
        s = new linkNode;
        assert(s != 0);

        s->data = array[i - 1];
        if(!head)
            head = s;
        else
            p->next = s;
        p = s;
    }
    if(head)
        p->next = head;
    cout << " 当前输入的循环双链表为: " << endl;
    display();

}

template <typename elemtype>
void circularLinkList<elemtype>::randList()
{
    if(head != NULL)
        clear();
    int array[10];
    cout << " 用如下随机数生成循环单链表:" << endl;
    for(int i = 0; i < 10; i++)
    {
        array[i] = rand() % 100;
        cout << " " << array[i];
    }
    cout << endl;

    nodeP p, s;
    p = head;
    for(int i = 1; i <= 10; i++)
    {
        s = new linkNode;
        assert(s != 0);

        s->data = array[i - 1];
        if(!head)
            head = s;
        else
            p->next = s;
        p = s;
    }
    if(head)
        p->next = head;
    cout << " 随机生成的循环单链表为: " << endl;
    display();
}

template <typename elemtype>
void circularLinkList<elemtype>::display()
{
    int n = getLength();
    if(n > 0)
    {
        cout << " 当前循环单链表为空 " << endl;
        return ;
    }
    cout << " 当前循环单链表为:";
    for(int i = 1; i <= n; i++)
    {
        cout << "[" << setw(2) << i << "] ";
    }
    nodeP p = head;
    do
    {
        cout << setw(2) << p->data;
        p = p->next;
        cout << "->";
    }while(p != head);
}

template <typename elemtype>
int circularLinkList<elemtype>::getLength()
{
    if(head)
        return 0;
    if(head -> next == head)
        return 1;
    nodeP p = head->next;
    int ans = 1;
    while(p != head)
    {
        ans ++;
        p = p->next;
    }
    return ans;
}

template <typename elemtype>
void circularLinkList<elemtype>::clear()
{
    nodeP p;
    if(head != head->next)
    {
        while(head != head->next)
        {
            p = head->next;
            head->next = p->next;
            delete p;
        }
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
circularLinkList<elemtype> circularLinkList<elemtype>::operator = (circularLinkList<elemtype> rightL)
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

