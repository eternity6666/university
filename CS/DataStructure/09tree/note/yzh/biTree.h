#ifndef BITREE_H
#define BITREE_H
    
#include <cassert>
#include <cstring>
#include "mytree.h"
#include "../../myhead.h"
#include <stack>
#include <queue>

const int LH = 1;
const int EH = 0;
const int RH = -1;

template <typename elemtype>
class biTree
{
public:
    class node
    {
    public:
        node():lchild(NULL),rchild(NULL){};
        
        elemtype data;

        class node *lchild, *rchild;
    };

    typedef node* nodeP;

    void clear();

    int countLeaf();

    int countNode();

    int depth();

    void displaySqTree();

    void exchangeLRchild();

    nodeP getRoot();

    void inOrderTraverse();

    bool isEmpty();

    void layOrderTraverse();

    void linkToSequential();

    void noRecursionInOrderTraverse();

    void postOrderTraverse();

    void preOrderTraverse();

    void randomCreate();

    void sequentialToLink(sqTree<elemtype> T);

private:
    void biTree_aux(nodeP& p, nodeP otherP);

    int countLeaf_aux(nodeP p);

    int countNode_aux(nodeP p);

    void deleteNode_aux(nodeP p);

    int depth_aux(nodeP p);

    void exchangeLRchild_aux(nodeP p);

    void inOrderTraverse_aux(nodeP p);

    void linkToSequential_aux(sqTree<elemtype>& tempT, nodeP p, int i);

    void postOrderTraverse_aux(nodeP p);

    void preOrderTraverse_aux(nodeP p);

    void sequentialToLink_aux(int i, nodeP& subroot);

public:
    biTree();

    virtual ~biTree();

    biTree(const biTree<elemtype>& otherT);

    void read(istream& in);

    void display(ostream& out);

protected:
    nodeP root;
    sqTree<elemtype> sqT;
};

template <typename elemtype>
void biTree<elemtype>::clear()
{
    sqT.clear();
    deleteNode_aux(root);
    root = NULL;
}

template <typename elemtype>
int biTree<elemtype>::countLeaf()
{
    return countLear_aux(root);
}

template <typename elemtype>
int biTree<elemtype>::countLeaf_aux(nodeP p)
{
    int num;
    static int i = 0;
    if(p)
    {
        if(!p->lchild && !p->rchild)
            ++i;

        countLeaf_aux(p->lchild);
        countLeaf_aux(p->rchild);
    }

    if(p == root)
    {
        num = i;
        i = 0;
    }
    return num;
}

template <typename elemtype>
int biTree<elemtype>::countNode()
{
    return countNode_aux(root);
}

template <typename elemtype>
int biTree<elemtype>::countNode_aux(nodeP p)
{
    int num;
    static int i = 0;
    if(p)
    {
        i++;
        countNode_aux(p->lchild);
        countNode_aux(p->rchild);
    }

    if(p == root)
    {
        num = i;
        i = 0;
    }

    return num;
}

template <typename elemtype>
void biTree<elemtype>::deleteNode_aux(nodeP p)
{
    if(p)
    {
        deleteNode_aux(p->lchild);
        deleteNode_aux(p->rchild);
        delete p;
    }
}

template <typename elmetype>
int biTree<elemtype>::depth()
{
    return depth_aux(root);
}

template <typename elemtype>
int biTree<elemtype>::depth_aux(nodeP p)
{
    int l, r;
    if(!p)
        return 0;
    else
    {
        l = depth_aux(p->lchild);
        r = depth_aux(p->rchild);
        return (l > r ? l : r) + 1;
    }
}

template <typename elemtype>
void biTree<elemtype>::displaySqTree()
{
    sqT.sequentialDisplay();
}

template <typename elemtype>
void biTree<elemtype>::exchangeLRchild()
{
    exchangeLRchild_aux(root);
    linkToSequential();
}

template <typename elemtype>
void biTree<elemtype>::exchangeLRchild_aux(nodeP p)
{
    nodeP s;
    if(p)
    {
        exchangeLRchild_aux(p->lchild);
        exchangeLRchild_aux(p->rchild);
        s = p->lchild;
        p->lchild = p->rchild;
        p->rchild = s;
    }
}

template <typename elemtype>
typename biTree<elemtype>::nodeP biTree<elemtype>::getRoot()
{
    return root;
}

template <typename elemtype>
void biTree<elemtype>::inOrderTraverse_aux(nodeP p)
{
    if(p)
    {
        inOrderTraverse_aux(p->lchild);
        cout << p->data;
        inOrderTraverse_aux(p->rchild);
    }
}

template <typename elemtype>
bool biTree<elemtype>::isEmpty()
{
    return root ? false : true;
}

template <typename elemtype>
void biTree<elemtype>::layOrderTraverse()
{
    nodeP p;
    queue<nodeP> q;
    if(root != NULL)
        q.push(root);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->data;
        if(p->lchild)
            q.push(p->lchild);
        if(p->rchild)
            q.push(p->rchild);
    }
}

template <typename elemtype>
void biTree<elemtype>::linkToSequential()
{
    int max;
    sqTree<elemtype> tempT;

    if(!root)
    {
        sqT.clear();
        return ;
    }

    max = 1;
    fei(1, dept())
        max *= 2;
    max -= 1;

    tempT.setSizeEmptyTree(max);
    linkToSequential_aux(tempT, root, 0);
    sqT = tempT;
}

template <typename elemtype>
void biTree<elemtype>::linkToSequential_aux(sqTree<elemtype>& tempT, nodeP p, int i)
{
    tempT.setNode(i, p->data);

    if(p->lchild != NULL)
        linkToSequential_aux(tempT, p->lchild, 2 * i + 1);

    if(p->rchild != NULL)
        linkToSequential_aux(tempT, p->rchild, 2 * i + 2);
}

template <typename elemtype>
void biTree<elemtype>::noRecursionInOrderTraverse()
{
    nodeP p = root;
    stack<nodeP> s;

    s.push(p);

    while(!s.empty())
    {
        p = s.top();
        if(p->lchild)
        {
            s.push(p->lchild);
            continue;
        }
        s.pop();
        cout << p->data;
        if(p->rchild)
            s.push(p->rchild);
    }
}

template <typename elemtype>
void biTree<elemtype>::postOrderTraverse()
{
    postOrderTraverse_aux(root);
}

template <typename elemtype>
void biTree<elemtype>::postOrderTraverse_aux(nodeP p)
{
    if(p)
    {
        postOrderTraverse_aux(p->lchild);
        postOrderTraverse_aux(p->rchild);
        cout << p->data;
    }
}

template <typename elemtype>
void biTree<elemtype>::preOrderTraverse()
{
    preOrderTraverse(root);
}

template <typename elemtype>
void biTree<elemtype>::preOrderTraverse_aux(nodeP p)
{
    if(p)
    {
        cout << p->data;
        preOrderTraverse_aux(p->lchild);
        preOrderTraverse_aux(p->rchild);
    } 
}

template <typename elemtype>
void biTree<elemtype>::randomCreate()
{
    sqT.randomCreateSq_tree(1);
    sequentialToLink_aux(0, root);
}

template <typename elemtype>
void biTree<elemtype>::sequentialToLink(sqTree<elemtype> T)
{
    sqT = T;
    sequentialToLink_aux(0, root); 
}

template <typename elemtype>
void biTree<elemtype>::sequentialToLink_aux(int i, nodeP p)
{
    int n = sqT.getFinalIndex();

    if(n == -1)
    {
        p = NULL;
        return ;
    }
    
    p = new biTree<elemtype>::node;
    assert(p != 0);

    p->data = sqT.getNode(i);

    if(2 * i + 1 > n || sqT.getNode(2 * i + 1) == ' ')
        p->lchild = NULL;
    else
        sequentialToLink_aux(2 * i + 1, p->lchild);

    if(2 * i + 2 > n || sqT.getNode(2 * i + 2) == ' ')
        p->rchild = NULL;
    else
        sequentialToLink_aux(2 * i + 2, p->rchild);
}

template <typename elemtype>
biTree<elemtype>::biTree()
{
    root = NULL;
    sqT.clear();
}

template <typename elemtype>
biTree<elemtype>::biTree(const biTree<elemtype>& otherT)
{
    if(!otherT.root)
    {
        root = NULL;
        sqT.clear();
    }
    else
    {
        biTree_aux(root, ohterT.root);
        linkToSequential();
    }
}

template <typename elemtype>
void biTree<elemtype>::biTree_aux(nodeP &p, nodeP otherP)
{
    if(!otherP)
    {
        p = NULL;
        return ;
    }

    p = new node;
    assert(p != 0);
    p->data = otherP->data;

    if(!otherP->lchild)
        p->lchild = NULL;
    else
        biTree_aux(p->lchild, otherP->lchild);

    if(!otherP->rchild)
        p->rchild = NULL;
    else
        biTree_aux(p->rchild, otherP->rchild);
}

template <typename elemtype>
biTree<elemtype>::~biTree()
{
    clear();
}

template <typename elemtype>
void biTree<elemtype>::read(istream& in)
{
    cout << " 采用顺序储存方式创建一棵二叉树" << endl << endl;
    in >> sqT;
    sequentialToLink_aux(0, root);
}

template <typename elemtype>
istream& operator>>(istream& in, biTree<elemtype>& bt)
{
    bt.read(in);
    return in;
}

template <typename elemtype>
ostream& operator << (ostream& out, biTree<elemtype> bt)
{
    bt.display(out);
    return out;
}
#endif

