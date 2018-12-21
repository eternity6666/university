/*
 * 这是堆栈的链式存储
 */
#include <iostream>
using namespace std;

#define Null -1
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode
{
    ElementType Data;
    Stack Next;
};

Stack CreatStack();
void Push(ElementType x, Stack PtrS);
ElementType Pop(int i, Stack PtrS);
bool IsEmpty(Stack Ptrs);

int main()
{
    return 0;
}

Stack CreatStack()
{
    Stack s = new SNode;
    s->Next = NULL;
    return s;
}

void Push(ElementType x, Stack PtrS)
{
    Stack s = new SNode;
    s->Next = PtrS->Next;
    s->Data = x;
    PtrS->Next = s;
}

ElementType Pop( Stack PtrS)
{
    Stack s=new SNode;
    ElementType topElem;
    if(IsEmpty(PtrS))
    {
        cout<<"堆栈空"<<endl;
        return Null;
    }
    else
    {
        s=PtrS->Next;
        PtrS->Next=s->Next;
        topElem=s->Data;
        delete s;
        return topElem;
    }
}

bool IsEmpty(Stack Ptrs)
{
    return (Ptrs->Next == NULL);
}