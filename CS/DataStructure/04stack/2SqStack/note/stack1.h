/* 
 * 这是堆栈的顺序存储结构 
 */
#include <iostream>
using namespace std;

const int MaxSize = 100005;
typedef union {
    char c;
    int i;
} ElementType;
ElementType ERROR;
typedef struct stackNode *Stack;
struct stackNode
{
    ElementType Data[MaxSize];//数据域
    int Top;//记录栈顶元素位置
};

Stack CreateStack(int MaxSize);
int IsFull(Stack PtrS, int MaxSize);
void Push(Stack PtrS, ElementType item);//入栈的操作
ElementType Pop(Stack PtrS);//出栈的操作
int IsEmpty(Stack PtrS);
int main()
{
    return 0;
}

Stack CreateStack(int MaxSize)
{
    Stack PtrS;
    return PtrS;
}

int IsFull(Stack PtrS, int MaxSize)
{
    if(PtrS->Top==MaxSize-1)
    {
        cout<<"堆栈满了"<<endl;
        return true;
    }
    else return false;
}

void Push(Stack PtrS, ElementType item)
{
    if (IsFull(PtrS,MaxSize))
    {
        return;
    }
    else
    {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}

int IsEmpty(Stack PtrS)
{
    if(PtrS->Top == -1)
    {
        cout<<"堆栈空"<<endl;
        return true;
    }
    else return false;
}

ElementType Pop(Stack PtrS)
{
    if(IsEmpty(PtrS))
    {
        return ERROR;
    }
    else
    {
        return (PtrS->Data[(PtrS->Top)--]);
    }
}
