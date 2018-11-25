#ifndef LINKLIST_H
    #define LINKLIST_H
    #include "ncll.h"
#endif

#ifndef MYTERM_H
    #define MYTERM_H
    #include "myTerm.h"
#endif

template <typename elemtype>
class myPolynomialLinkList:public linkList<elemtype>
{
public:
    myPolynomialLinkList<elemtype> operator + (myPolynomialLinkList<elemtype> l);

    myPolynomialLinkList<elemtype> operator - (myPolynomialLinkList<elemtype> l);
    void randomInitialFill(int display = 0);

    void read(istream& in);

    void display(ostream& out) const;

protected:
    myTerm data;
};

template <typename elemtype>
myPolynomialLinkList<elemtype> myPolynomialLinkList<elemtype>::operator + (myPolynomialLinkList<elemtype> l)
{
    typename linkList<elemtype>::nodeP p1 = this->head;
    typename linkList<elemtype>::nodeP p2 = l->head;

    myPolynomialLinkList<elemtype> l3;

    typename linkList<elemtype>::nodeP r3 = NULL, p3 = NULL;

    while(p1 && p2)
    {
        if(p1->data.expn == p2->data.expn && p1->data.coef + p2->data.coef == 0)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            p3 = new typename linkList<elemtype>::linkNode;
            assert(p3 != 0);

            if(p1->data.expn > p2->data.expn)
            {
                p3->data.coef = p1->data.coef;
                p3->data.expn = p1->data.expn;
                p1 = p1->next;
            }
            else if(p1->data.expn == p2->data.expn)
            {
                p3->data.coef = p1->data.coef + p2->data.coef;
                p3->data.expn = p1->data.expn;
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                p3->data.coef = p2->data.coef;
                p3->data.expn = p2->data.expn;
                p2 = p2->next;
            }
            if(!l3->head)
                l3->head = p3;
            else
                r3->next = p3;
            r3 = p3;
        }
    }
    
    while(p1)
    {
        p3->data.coef = p1->data.coef;
        p3->data.expn = p1->data.expn;
        p1 = p1->next;

        if(!l3->head)
            l3->head = p3;
        else
            r3->next = p3;
        r3 = p3;
    }

    while(p2)
    {
        p3->data.coef = p2->data.coef;
        p3->data.expn = p2->data.expn;
        p2 = p2->next;

        if(!l3->head)
            l3->head = p3;
        else
            r3->next = p3;
        r3 = p3;
    }

    if(p3)
        p3->next = NULL;
    return l3;
}

template <typename elemtype>
myPolynomialLinkList<elemtype> myPolynomialLinkList<elemtype>::operator -(myPolynomialLinkList<elemtype> l)
{
    typename linkList<elemtype>::nodeP p2 = l->head;
    myPolynomialLinkList<elemtype> l3;

    while(p2)
    {
        p2->data.coef =- p2->data.coef;
        p2 = p2->next;
    }

    l3 = (*this) + l;
    return l3;
}

template <typename elemtype>
void myPolynomialLinkList<elemtype>::randomInitialFill(int display)
{
    int n;
    typename linkList<elemtype>::nodeP r, p;
    typename linkList<elemtype>::nodeP s;
    
    this->clear();

    n = rand() % 8 + 1;

    if(display)
    {
        cout << " 依次生成多项式如下" << n << "个项:" << endl;
        cout << " ";
    }

    fei(0, n - 1)
    {
        s = new typename linkList<elemtype>::linkNode;
        assert(s != 0);

        if(rand() % 2)
            s->data.coef = rand() % 100 + 1;
        else
            s->data.coef = -(rand() % 100 + 1);

        while(1)
        {
            s->data.expn = rand() % 10;
            r = NULL, p = this->head;

            while(p && s->data.expn < p->data.expn)
            {
                r = p;
                p = p->next;
            }

            if(p && s->data.expn == p->data.expn)
                continue;
            else
                break;
        }
        if(!r)
            this->head = s;
        else
            r->next = s;
        s->next = p;
        
        if(display)
            cout << s->data << " ";
    }

    if(display)
        cout << endl;
}

template <typename elemtype>
void myPolynomialLinkList<elemtype>::read(istream& in)
{
    int n;
    typename linkList<elemtype>::nodeP r, p;
    typename linkList<elemtype>::nodeP s;

    this->clear();

    cout << " 请输入多项式的项数: ";
    in >> n;

    cout << " 请输入多项式中的项: " << endl;
    fei(0, n - 1)
    {
        cout << "\t第" << i + 1 << "项";
        
        s = new typename linkList<elemtype>::linkNode;
        assert(s != 0);

        while(1)
        {
            in >> s->data;
            r = NULL, p = this->head;
            while(p && s->data.expn < p->data.expn)
            {
                r = p;
                p = p->next;
            }

            if(p && s->data.expn == p->data.expn)
            {
                cout << " 该指数的项已存在，重新生成该项" << endl;
                continue;
            }
            else
                break;
        }
        if(!r)
            this->head = s;
        else
            r->next = s;

        s->next = p;
    }
    cout << "\n 已输入了多项式的" << n << "个项" << endl;
}

template <typename elemtype>
istream& operator >> (istream& in, myPolynomialLinkList<elemtype>& l)
{
    l.read(in);
    return in;
}

template <typename elemtype>
void myPolynomialLinkList<elemtype>::display(ostream& out) const 
{
    typename linkList<elemtype>::nodeP p = this->head;
    if(!this->head)
    {
        out << " 该多项式为空!" << endl;
        return ;
    }
    out << " ";
    while(p)
    {
        if(p != this->head && p->data.coef > 0)
            out << "+";
        out << p->data;

        p = p->next;
    }
    out << endl;
}

template <typename elemtype>
ostream& operator << (ostream& out, const myPolynomialLinkList<elemtype>& l)
{
    l.display(out);
    return out;
}

