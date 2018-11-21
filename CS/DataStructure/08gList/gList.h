#ifndef MYHEAD_H
    #define MYHEAD_H
    #include "../../myhead.h"
#endif

#ifndef STACK_H
    #define STACK_H
    #include <stack>
#endif

#ifndef QUEUE_H
    #define QUEUE_H
    #include <queue>
#endif

typedef enum {ATOM, LIST} elemTag;

void separte(sqString& str, sqString& hstr);

class gList
{
public:
    class node
    {
    public:
        elemTag tag;
        union
        {
            char atom;
            struct
            {
                class node *hp;
                class node *tp;
            }ptr;
        };
    };
    typedef node* glnodeP;

    void createglist(sqString s);

    bool deleteHead(gList& s);

    int depth();

    bool getHead(gList& headGL);

    glnodeP getRoot();

    bool getTail(gList& tailGL);

    void insertTail(gList& s);

    bool isEmpty();

    int length();

    gList operator = (gList rightGL);

    void setRoot(glnodeP p);

private:
    void copyGlist_aux(glnodeP& s, glnodeP& p);

    void createGlist_aux(glnodeP& l, sqString s);
    
    int depth_aux(glnodeP s);

    void destruction_aux(glnodeP& p);

public:
    gList();

    virtual ~gList();

    gList(const gList& s);

    void read(istream& in);

    void display(ostream& out);

private:
    glnodeP root;
};

void gList::copyGlist_aux(glnodeP& s, glnodeP p)
{
    if(!p)
        s = NULL;
    else
    {
        s = new node;
        assert(s != 0);

        s->tag = p->tag;

        if(p->tag == ATOM)
            s->atom = p->atom;
        else
        {
            copyGlist_aux(s->ptr.hp, p->ptr.hp);
            copyGlist_aux(s->ptr.tp, p->ptr.tp);
        }
    }
}

