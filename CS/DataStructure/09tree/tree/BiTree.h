#ifndef BITREE_H
#define BITREE_H

#include "mytree.h"
#include<stack>
#include<cassert>
#include<queue>
#include<cstring>

#define LH 1		//左高
#define EH 0		//等高
#define RH -1		//右高

template<typename T>
class BiTree
{
public:
    class node
    {
    public:
        node() :lchild(NULL), rchild(NULL) {};			//!!!!!!????????
        T data;
        class node *lchild, *rchild;
    };
    typedef node*nodepointer;
    void clear();
    int countleaf();		//求叶子数
    int countnode();		//求节点数
    int depth();		//递归求深度
    void displayseqtree();		//显示顺序存储
    void exchangelrchild();		//交换所有左右子树
    nodepointer getroot();		//取根指针
    void inordertraverse();		//中序递归遍历
    bool isempty();
    void layordertraverse();		//层次顺序遍历
    void linktosequential();		//二叉链表转换顺序存储
    void norecursioninordertraverse();		//非递归中序遍历
    void postordertraverse();		//后序递归遍历
    void preordertraverse();		//前序递归遍历
    void randomcreate(int n=-1);		//随机生成一颗二叉树
    void sequentialtolink(myseqtree<T> t);		//顺序转换二叉树链式存储
    void bitree_aux(nodepointer &p, nodepointer otherp);		//拷贝初始化辅助函数
    int countleaf_aux(nodepointer p);	//求叶子辅助
    int countnode_aux(nodepointer p);		//求结点数辅助
    void deletenode_aux(nodepointer p);		//回收结点空间辅助
    int depth_aux(nodepointer p);		//递归求深度辅助
    void exchangelrchild_aux(nodepointer p);		//交换左右子树辅助
    void inordertraverse_aux(nodepointer p);		//中序递归遍历辅助
    void linktosequential_aux(myseqtree<T>&tempt, nodepointer p, int i);		//二叉链表转顺序存储辅助
    void preordertraverse_aux(nodepointer p);		//前序递归辅助
    void postordertraverse_aux(nodepointer p);		//后序递归辅助
    void sequentialtolink_aux(int i, nodepointer& subroot);		//顺序转二叉链表存储辅助
    BiTree();
    ~BiTree();
    BiTree(const BiTree<T>&othert);
    void read(istream& in);
    void display(ostream& ot);
protected:
    nodepointer root;
    myseqtree<T>seqt;		//二叉树对应的顺序存储数
};

template<typename T>
void BiTree<T>::clear()
{
    seqt.clear();
    deletenode_aux(root);
    root = NULL;
}
template<typename T>
int BiTree<T>::countleaf()
{
    return countleaf_aux(root);
}
template<typename T>
int BiTree<T>::countleaf_aux(nodepointer p)
{
    int num = 0;
    static int i = 0;
    if (p)
    {
        if (!p->lchild&&!p->rchild)
            i++;
        countleaf_aux(p->lchild);
        countleaf_aux(p->rchild);
    }
    if (p == root)
    {
        num = i;
        i = 0;
    }
    return num;
}
template<typename T>
int BiTree<T>::countnode()
{
    return countnode_aux(root);
}
template<typename T>
int BiTree<T>::countnode_aux(nodepointer p)
{
    int num = 0;
    static int i = 0;
    if (p)
    {
        i++;
        countnode_aux(p->lchild);
        countnode_aux(p->rchild);
    }
    if (p == root)
    {
        num = i;
        i = 0;
    }
    return num;
}
template<typename T>
void BiTree<T>::deletenode_aux(nodepointer p)
{
    if (p)
    {
        deletenode_aux(p->lchild);
        deletenode_aux(p->rchild);
        delete p;
    }
}
template<typename T>
int BiTree<T>::depth()
{
    return depth_aux(root);
}
template<typename T>
int	BiTree<T>::depth_aux(nodepointer p)
{
    int ldep = 0, rdep = 0;
    if (!p)
        return 0;
    else
    {
        ldep = depth_aux(p->lchild);
        rdep = depth_aux(p->rchild);
        return (ldep > rdep ? ldep : rdep) + 1;
    }
}
template<typename T>
void BiTree<T>::displayseqtree()
{
    seqt.display();
}
template<typename T>
void BiTree<T>::exchangelrchild()
{
    exchangelrchild_aux(root);
    linktosequential();
}
template<typename T>
void BiTree<T>::exchangelrchild_aux(nodepointer p)
{
    nodepointer s;
    if (p)
    {
        exchangelrchild_aux(p->lchild);
        exchangelrchild_aux(p->rchild);
        s = p->lchild;
        p->lchild = p->rchild;
        p->rchild = s;
    }
}
//!!!!
template<typename T>
typename BiTree<T>::nodepointer BiTree<T>::getroot()			//!!!!!
{
    return root;
}

template<typename T>
void BiTree<T>::inordertraverse()
{
    inordertraverse_aux(root);
}
template<typename T>
void BiTree<T>::inordertraverse_aux(nodepointer p)
{
    if (p)
    {
        inordertraverse_aux(p->lchild);
        cout << p->data;
        inordertraverse_aux(p->rchild);
    }
}
template<typename T>
bool BiTree<T>::isempty()
{
    return root ? false : true;
}
template <typename T>
void BiTree<T>::layordertraverse()
{
    nodepointer p;
    queue<nodepointer> q;
    if (root != NULL)
        q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->data;
        if (p->lchild)
            q.push(p->lchild);
        if (p->rchild)
            q.push(p->rchild);
    }
}
template <typename T>
void BiTree<T>::linktosequential()
{
    int max_total = 0;
    myseqtree<T> tempt;
    if (!root)
    {
        seqt.clear();
        return;
    }
    max_total = 1;
    for (int d = 1; d <= depth(); d++)
        max_total *= 2;
    max_total -= 1;
    tempt.setfinalindex(max_total - 1);		//!!!!!!!!!!!!!!
    linktosequential_aux(tempt, root, 0);
    seqt = tempt;
}
template<typename T>
void BiTree<T>::linktosequential_aux(myseqtree<T>&tempt, nodepointer p, int i)
{
    if (!p || i > tempt.getfinalindex())
        return;
    tempt.setnode(i, p->data);
    if (p->lchild != NULL)
        linktosequential_aux(tempt, p->lchild, 2 * i + 1);
    if (p->rchild != NULL)
        linktosequential_aux(tempt, p->rchild, 2 * i + 2);
}
template<typename T>
void BiTree<T>::norecursioninordertraverse()
{
    nodepointer p = root;
    stack<nodepointer> s;
    while (p || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p=s.top();
            s.pop();
            cout << p->data;
            p = p->rchild;
        }
    }
}
template<typename T>
void BiTree<T>::postordertraverse()
{
    postordertraverse_aux(root);
}
template<typename T>
void BiTree<T>::postordertraverse_aux(nodepointer p)
{
    if (p)
    {
        postordertraverse_aux(p->lchild);
        postordertraverse_aux(p->rchild);
        cout << p->data;
    }
}
template<typename T>
void BiTree<T>::preordertraverse()
{
    preordertraverse_aux(root);
}
template<typename T>
void BiTree<T>::preordertraverse_aux(nodepointer p)
{
    if (p)
    {
        cout << p->data;
        preordertraverse_aux(p->lchild);
        preordertraverse_aux(p->rchild);
    }
}
template <typename T>
void BiTree<T>::randomcreate(int n)
{
    seqt.randsqt(n);
    sequentialtolink_aux(0, root);
}
template<typename T>
void BiTree<T>::sequentialtolink(myseqtree<T> t)
{
    seqt = t;
    sequentialtolink_aux(0, root);
}
template<typename T>
void BiTree<T> ::sequentialtolink_aux(int i, nodepointer&p)
{
    int n = seqt.getfinalindex();
    if (n == -1)
    {
        p = NULL;
        return;
    }
    p = new BiTree<T>::node;
    assert(p != 0);
    p->data = seqt.getnode(i);
    if (2 * i + 1 > n || seqt.getnode(2 * i + 1) == ' ')
        p->lchild = NULL;
    else
        sequentialtolink_aux(2 * i + 1, p->lchild);
    if (2 * i + 2 > n || seqt.getnode(2 * i + 2) == ' ')
        p->rchild = NULL;
    else
        sequentialtolink_aux(2 * i + 2, p->rchild);
}
template <typename T>
BiTree<T>::BiTree()
{
    root = NULL;
    seqt.clear();
}
template<typename T>
BiTree<T>::BiTree(const BiTree<T>& othert)
{
    if (!othert.root)
    {
        root = NULL;
        seqt.clear();
    }
    else
    {
        bitree_aux(root, othert.root);
        linktosequential();
    }
}
template<typename T>
void BiTree<T>::bitree_aux(nodepointer& p, nodepointer otherp)
{
    if (!otherp)
    {
        p = NULL;
        return;
    }
    p = new node;
    assert(p != 0);
    p->data = otherp->data;
    if (!otherp->lchild)
        p->lchild = NULL;
    else
        bitree_aux(p->lchild, otherp->lchild);
    if (!otherp->rchild)
        p->rchild = NULL;
    else
        bitree_aux(p->rchild, otherp->rchild);
}
template<typename T>
BiTree<T>::~BiTree()
{
    clear();
}
template<typename T>
void BiTree<T>::read(istream& in)
{
    cout << "采用顺序存储方式创建一棵二叉树" << endl << endl;
    in >> seqt;
    sequentialtolink_aux(0, root);
}
template<typename T>
istream& operator >> (istream&in, BiTree<T>&bt)
{
    bt.read(in);
    return in;
}
template<typename T>
void BiTree<T>::display(ostream& out)
{
    out << seqt << endl;
}
template<typename T>
ostream& operator<<(ostream&out, BiTree<T>& bt)
{
    bt.display(out);
    return out;
}
#endif

