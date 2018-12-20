#include <iostream>
using namespace std;
typedef int elementType;
struct treeNode
{
    elementType data;
    treeNode *right;
    treeNode *left;
};
typedef struct treeNode *BinTree;

struct stackNode
{
    treeNode *tNode;
    stackNode *next;
};
typedef struct stackNode *Stack;

bool isEmpty(BinTree BT)
{
    if (BT == NULL)
    {
        return true;
    }
    else
        return false;
}

//使用堆栈实现先序遍历
void preOrderTraversal(BinTree BT)
{
    
}