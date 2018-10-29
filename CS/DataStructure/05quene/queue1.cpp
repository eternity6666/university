/*
 * 这是队列的顺序存储实现
 */

#include <iostream>
using namespace std;
const int maxSize = 100005;
typedef struct QNode *Queue;
typedef int elementType;
const elementType Null = -1;
struct QNode
{
    elementType data[maxSize];
    int front;
    int rear;
};

void addQ(Queue PtrQ, elementType item);
elementType deleteQ(Queue PtrQ);

int main()
{
    return 0;
}

void addQ(Queue PtrQ, elementType item)
{
    if ((PtrQ->rear + 1) % maxSize == PtrQ->front)
    {
        cout << "队列满" << endl;
        return;
    }
    PtrQ->rear = (PtrQ->rear + 1) % maxSize;
    PtrQ->data[PtrQ->rear] = item;
}

elementType deleteQ(Queue PtrQ)
{
    if (PtrQ->front == PtrQ->rear)
    {
        cout << "队列空" << endl;
        return Null;
    }
    else
    {
        PtrQ->front = (PtrQ->front + 1) % maxSize;
        return PtrQ->data[PtrQ->front];
    }
}
