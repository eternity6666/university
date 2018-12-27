#ifndef THREADTREE_H
#define THREADTREE_H

#include "../../myhead.h"
#include "mySeqTree.h"

typedef enum PointerTag {LINK, THREAD};

template <typename elemtype>
class threadTree
{
public:
    class node
    {
    public:
        threadTree():ltag(LINK), lchild(NULL), rtag(LINK), rchild(NULL){};
        ~threadTree();

    public:
        elemtype data;
        class node *lchild, *rchild;
        PointerTag ltag, rtag;
    };
    typedef node* nodeP;

public:
    void clear();

    int depth();

    nodeP getRoot();

    void inOrderTraverse_ThreadTree();

    bool isEmpty();

    void randomCreate();

    bool searchPriorNode(elemtype key, elemtype& prior);

    bool searchNextNode(elemtype key, elemtype& next);

    bool searchNode(elemtype key, nodeP &p);

    void sequentialToThreadTree(mySeqTree<elemtype> t);

    void threadTreeToSequential();

private:
    void deleteNode_aux(nodeP p);

    int depth_aux(nodeP p);

    void sequentialToThreadTree_aux1(int index, nodeP& p);

    void sequentialToThreadTree_aux2(nodeP p);

    void threadTreeToSequential_aux(mySeqTree<elemtype>& tmpT, nodeP p, int index);

    void threadTree_aux(nodeP &p, nodeP otherp);

public:
    threadTree();

    virtual ~threadTree();

    threadTree(const threadTree<elemtype>& otherT);

    void read(istream& in);

    void display(ostream& out);

private:
    nodeP root;
    mySeqTree<elemtype> seqT;
};

template <typename elemtype>
void threadTree<elemtype>::clear()
{
    seqT.clear();
    deleteNode_aux(root);
    root = NULL;
}

template <typename elemtype>
void threadTree<elemtype>::deleteNode_aux(nodeP p)
{
    if(p)
    {
        if(p->ltag == NULL)
            deleteNode_aux(p->lchild);
        if(p->rtag == NULL)
            deleteNode_aux(p->rchild);
        delete p;
    }
}

template <typename elemtype>
int threadTree<elemtype>::depth()
{
    return depth_aux(root);
}

template <typename elemtype>
int threadTree<elemtype>::depth_aux(nodeP p)
{
    int ldep, rdep;

    if(!p)
        return 0;
    else
    {
        if(p->ltag == LINK)
            ldep = depth_aux(p->lchild);
        else
            ldep = 0;

        if(p->rtag == LINK)
            rdep = depth_aux(p->rchild);
        else
            rdep = 0;

        return (ldep > rdep ? ldep : rdep) + 1;
    }
}

template <typename elemtype>
typename threadTree<elemtype>::nodeP threadTree<elemtype>::getRoot()
{
    return root;
}

template <typename elemtype>
void threadTree<elemtype>::inOrderTraverse_ThreadTree()
{
    nodeP p = root;

    while(p)
    {
        while(p->ltag == LINK)
            p = p->lchild;
        
        cout << p->data;

        while(p->rtag == THREAD && p->rchild)
        {
            p = p->rchild;
            cout << p->data;
        }
        p = p->rchild;
    }
}

template <typename elemtype>
bool threadTree<elemtype>::isEmpty()
{
    return root ? false : true;
}

template <typename elemtype>
void threadTree<elemtype>::randomCreate()
{
    clear();

    seqT.randomCreateSeq_tree(1);

    sequentialToThreadTree_aux1(0, root);

    sequentialToThreadTree_aux2(root);
}

template <typename elemtype>
bool threadTree<elemtype>::searchPriorNode(elemtype key, elemtype& prior)
{
    nodeP p;

    if(searchNode(key, p))
    {
        if(p->ltag == THREAD)
        {
            if(!p->lchild)
                return false;
            else
                prior = p->lchild->data;
        }
        else
        {
            p = p->lchild;
            while(p->rtag == LINK)
                p = p->rchild;
            prior = p->data;
        }
    }
    return true;
}

template <typename elemtype>
bool threadTree<elemtype>::searchNextNode(elemtype key, elemtype& next)
{
    nodeP p;

    if(searchNode(key, p))
    {
        if(p->rtag == THREAD)
        {
            if(!p->rchild)
                return false;
            else
                next = p->rchild->data;
        }
        else
        {
            p = p->rchild;
            while(p->ltag == LINK)
                p = p->lchild;
            next = p->data;
        }
    }
    return true;
}

template <typename elemtype>
bool threadTree<elemtype>::searchNode(elemtype key, nodeP &p)
{
    p = root;
    while(p)
    {
        while(p->ltag == LINK)
            p = p->lchild;
        
        if(p->data == key)
            return true;

        while(p->rtag == THREAD && p->rchild)
        {
            p = p->rchild;
            if(p->data == key)
                return true;
        }
        p = p->rchild;
    }
    return false;
}

template <typename elemtype>
void threadTree<elemtype>::sequentialToThreadTree(mySeqTree<elemtype> t)
{
    seqT = t;
    
    sequentialToThreadTree_aux1(0, root);

    sequentialToThreadTree_aux2(root);
}

template <typename elemtype>
void threadTree<elemtype>::sequentialToThread_aux1(int index, nodeP &p)
{
    int n = seqT.getFinalIndex();

    if(n == -1)
    {
        p = NULL;
        return ;
    }

    p = new node;
    assert(p != 0);

    p->data = seqT.getNode(index);

    if(2 * index + 1 > n || seqT.getNode(2 * index + 1) == ' ')
        p->lchild = NULL;
    else
        sequentailToThreadTree_aux1(2 * index + 1, p->lchild);

    if(2 * index + 2 > n || seqT.getNode(2 * index + 2) == ' ')
        p->rchild = NULL;
    else
        sequentailToThreadTree_aux2(2 * index + 2, p->rchild);
}

template <typename elemtype>
void threadTree<elemtype>::sequentailToThreadTree_aux2(nodeP p)
{
    static nodeP pre = NULL;

    if(p)
    {
        sequentailToThreadTree_aux2(p->lchild);

        if(!p->lchild)
        {
            p->ltag = THREAD;
            p->lchild = pre;
        }

        if(pre && !pre->rchild)
        {
            pre->rtag = THREAD;
            pre->rchild = p;
        }

        pre = p;

        sequentailToThreadTree_aux2(p->rchild);
    }

    if(p == root)
    {
        if(pre)
        {
            pre->rtag = THREAD;
            pre->rchild = NULL;
        }
        pre = NULL;
    }
}

template <typename elemtype>
void threadTree<elemtype>::threadTreeToSequential()
{
    int max_total;
    mySeqTree<elemtype> tempT;

    if(!root)
    {
        seqT.clear();
        return;
    }

    max_total = 1;
    fei(1, depth())
        max_total *= 2;

    max_total -= 1;

    tempT.setSizeEmptyTree(max_total);

    threadTreeToSequential_aux(tempT, root, 0);

    seqT = tempT;
}

template <typename elemtype>
void threadTree<elemtype>::threadToSequential_aux(mySeqTree<elemtype> &tempT, nodeP p, int index)
{
    if(p)
    {
        tempT.setNode(index, p->data);

        if(p->ltag == LINK)
            threadTreeToSequential_aux(tempT, p->lchild, 2 * index + 1);

        if(p->rtag == LINK)
            threadTreeToSequential_aux(tempT, p->rchild, 2 * index + 2);
    }
}

template <typename elemtype>
threadTree<elemtype>::threadTree()
{
    root = NULL;
    seqT.clear();
}

template <typename elemtype>
threadTree<elemtype>::~threadTree()
{
    clear();
}

template <typename elemtype>
threadTree<elemtype>::threadTree(const threadTree<elemtype>& otherT)
{
    if(!otherT.root)
    {
        root = NULL;
        seqT.clear();
    }
    else
    {
        threadTree_aux(root, otherT.root);

        sequentialToThreadTree_aux2(root);

        threadTreeToSequential();
    }
}

template <typename elemtype>
void threadTree<elemtype>::threadTree_aux(nodeP& p, nodeP otherP)
{
    if(!otherP)
    {
        p = NULL;
        return ;
    }
    
    p = new node;
    assert(p != 0);

    p->data = otherP->data;

    if(otherP->ltag == THREAD)
        p->lchild = NULL;
    else
        threadTree_aux(p->lchild, otherP->lchild);

    if(otherP->rtag == THREAD)
        p->rchild = NULL;
    else
        threadTree_aux(p->rchild, otherP->rchild);
}

template <typename elemtype>
void threadTree<elemtype>::read(istream& in)
{
    cout << " 采用顺序存储方式创建一棵中序穿线二叉树" << endl << endl;
    in >> seqT;

    sequentialToThreadTree_aux1(0, root);

    sequentialToThreadTree_aux2(root);
}

template <typename elemtype>
istream& operator >> (istream& in, threadTree<elemtype>& t)
{
    t.read(in);
    return in;
}

template <typename elemtype>
void threadTree<elemtype>::display(ostream& out)
{
    out << seqT;
}

template <typename elemtype>
ostream& operator << (ostream& out, threadTree<elemtype> t)
{
    t.display(out);
    return out;
}
#endif

