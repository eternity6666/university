#include <iostream>
using namespace std;
typedef struct LNode *List;
typedef int ElementType;
struct LNode
{
    ElementType Data;
    List Next;
};
struct LNode L;
List Ptrl;

int Length(List Ptrl);
List FindKth(int k, List Ptrl);
List Find(ElementType x, List Ptrl);
List Insert(ElementType x, int i, List Ptrl);
List Delete(int i, List Ptrl);

int main()
{
    return 0;
}

int Length(List Ptrl)
{
    List p = Ptrl;
    int j = 0;
    while (p)
    {
        p = p->Next;
        j++;
    }
    return j;
}

List FindKth(int k, List Ptrl)
{
    List p = Ptrl;
    int i = 1;
    while (p != NULL && i < k)
    {
        p = p->Next;
        i++;
    }
    if (i == k)
    {
        return p;
    }
    else
        return NULL;
}

List Find(ElementType x, List Ptrl)
{
    List p = Ptrl;
    while (p != NULL && p->Data != x)
    {
        p = p->Next;
    }
    return p;
}

List Insert(ElementType x, int i, List Ptrl)
{
    if (i == 1)
    {
        List newLNode = new LNode;
        newLNode->Data = x;
        newLNode->Next = Ptrl;
        return newLNode;
    }
    List p = FindKth(i - 1, Ptrl);
    if (p == NULL)
    {
        cout << "参数i错误" << endl;
        return NULL;
    }
    else
    {
        List newLNode = new LNode;
        newLNode->Data = x;
        newLNode->Next = p->Next;
        p->Next = newLNode;
        return Ptrl;
    }
}

List Delete(int i, List Ptrl)
{
    if (i == 1)
    {
        List newLNode = Ptrl;
        if (Ptrl != NULL)
        {
            Ptrl = Ptrl->Next;
        }
        else
        {
            return NULL;
        }
        delete newLNode;
        return Ptrl;
    }
    List p = FindKth(i - 1, Ptrl);
    if (p == NULL)
    {
        cout << "第" << i - 1 << "个结点不存在" << endl;
        return NULL;
    }
    else if (p->Next == NULL)
    {
        cout << "第" << i << "个结点不存在" << endl;
        return NULL;
    }
    else
    {
        List newLNode = p->Next;
        p->Next = newLNode->Next;
        delete newLNode;
        return Ptrl;
    }
}