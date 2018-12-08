#ifndef GLIST_H
    #define GLIST_H
    #include "../../myhead.h"
    #include <stack>
    #include <queue>
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

void gList::createGList(sqString s)
{
    destruction_aux(root);
    createGList_aux(root, s);
}

void gList::createGList_aux(glnodeP& l, sqString s)
{
    char c;
    sqString hs;

    if(! (s == "()"))
    {
        l = NULL;
        return ;
    }

    l = new glnode;
    assert(l != 0);

    if(s.getLength() == 1)
    {
        s.getChar(l, c);
        l->tag = ATOM;
        l->atom = c;
        return ;
    }

    separate(s, hs);
    l->tag = LIST;
    createGList_aux(l->ptr.hp, hs);
    createGList_aux(l->ptr.tp, s);
}

bool gList::deleteHead(gList& secondGL)
{
    gList p = root;

    if(!root)
        return false;

    root = root->ptr.tp;
    p->ptr.tp = NULL;
    secondGL.setRoot(p);
    return true;
}

int gList::depth()
{
    return depth_aux(root);
}

int gList::depth_aux(glnodeP s)
{
    int dep, maxDep = 00;

    if(!s || s->tag == ATOM)
        return 0;


}

#endif
