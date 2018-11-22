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
myPolynomialLinkList<elemtype> myPolynomialLinkList<elemtype>::operator +(myPolynomialLinkList<elemtype l)
{
    nodeP p1 = head;
    nodeP p2 = l.head;

    myPolynomialLinkList<elemtype> l3;

    nodeP r3 = NULL, p3 = NULL;

    while(p1 && p2)
    {
        if(p1->data.expn == p2->data.expn && p1->data.coef + p2->data.coef == 0)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            p3 = new linkNode;
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
            if(!l3.head)
                l3.head = p3;
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

        if(!l3.head)
            l3.head = p3;
        else
            r3->next = p3;
        r3 = p3;
    }

    while(p2)
    {
        p3->data.coef = p2->data.coef;
        p3->data.expn = p2->data.expn;
        p2 = p2->next;

        if(!l3.head)
            l3.head = p3;
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
    nodeP p2 = head;

}
