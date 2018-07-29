/*
 * 这是二叉树(Binary Tree)链式存储
 */
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

const int maxSize=100005;
typedef struct {
    treeNode data[maxSize];
} SNode;

bool isEmpty(BinTree BT);            //is binary tree empty or not
void traversal(BinTree BT);          //traversal a binary tree
BinTree creatBinTree();              //creat a binary tree
void preOrderTraversal(BinTree BT);  //先序遍历
void inOrderTraversal(BinTree BT);   //中序遍历
void postOrderTraversal(BinTree BT); //后序遍历
void levelOrderTraversal(BinTree BT);

int main()
{
    return 0;
}

bool isEmpty(BinTree BT)
{
    if (BT == NULL)
    {
        return true;
    }
    else
        return false;
}

/*
void traversal(BinTree BT)
{
}
*/

/*
BinTree creatBinTree()
{
}
*/
//递归实现先序遍历
void preOrderTraversal1(BinTree BT)
{
    if (BT)
    {
        cout << BT->data << endl;
        preOrderTraversal(BT->left);
        preOrderTraversal(BT->right);
    }
}

//堆栈实现先序遍历
void preOrderTraversal12(BinTree BT)
{
    
}

//递归实现中序遍历
void inOrderTraversal1(BinTree BT)
{
    if (BT)
    {
        inOrderTraversal(BT->left);
        cout << BT->data << endl;
        inOrderTraversal(BT->right);
    }
}

//堆栈实现中序遍历
void inOrderTraversal2(BinTree BT)
{

}

//递归实现后序遍历
void postOrderTraversal1(BinTree BT)
{
    if (BT)
    {
        postOrderTraversal(BT->left);
        postOrderTraversal(BT->right);
        cout << BT->data << endl;
    }
}

//堆栈实现后序遍历
void postOrderTraversal2(BinTree BT)
{
    
}

//队列实现层序遍历
void levelOrderTraversal(BinTree BT)
{
}

