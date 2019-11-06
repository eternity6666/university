#ifndef TEST_H
    #define TEST_H
    
#include "dll.h"    

template <typename elemtype>
class mydll:public doubleLinkList<elemtype>
{
public:
    void getByRand(int display);
};

template <typename elemtype>
void mydll<elemtype>::getByRand(int display)
{
    this->clear();
    typename doubleLinkList<elemtype>::nodeP p, s;
    this->head = p = NULL;
    int n = rand() % 10 + 1;
    fei(1, n)
    {
        int tmp = rand() % 100;
        
        if(display == 1)
            cout << " " << tmp;
        
        s = new typename doubleLinkList<elemtype>::linkNode;
        assert(s != 0);

        s->data = tmp;

        if(!this->head)
            p = this->head = s;

        p->next = s;
        s->prior = p;
    
        p = s;
    }

    if(this->head)
    {
        this->head->prior = p;
        p->next = this->head;
    }
    if(display)
        cout << endl;
}

#endif

