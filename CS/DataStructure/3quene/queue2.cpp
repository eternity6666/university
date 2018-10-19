/*
 *这是队列的链式存储实现
 */
#include <iostream>
using namespace std;

typedef int elementType;
typedef struct Node *pNode;
struct Node
{
    elementType data;
    struct Node *next;
};

typedef struct
{
    struct Node *rear;
    struct Node *front;
} *Queue;

const elementType ERROR = -1;

elementType deleteQ(Queue PtrQ)
{
    pNode frontCell = new Node;
    elementType frontElem;

    if (PtrQ->front == NULL)
    {
        cout << "队列空" << endl;
        return ERROR;
    }
    frontCell = PtrQ->front;
    if (PtrQ->front == PtrQ->rear)
    {
        PtrQ->front = PtrQ->rear = NULL;
    }
    else
    {
        PtrQ->front = PtrQ->front->next;
    }
    frontElem = frontCell->data;
    delete frontCell;
    return frontElem;
}

void addQ(elementType x,Queue PtrQ)
{
    pNode newNode=new Node;
    newNode->data=x;
    newNode->next=PtrQ->rear->next;
    PtrQ->rear->next=newNode;
    PtrQ->rear=newNode;
}