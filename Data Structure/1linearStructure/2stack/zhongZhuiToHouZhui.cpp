/*
 * 这是一个用于将中缀表达式转换为后缀表达式的程序
 * 测试数据:
 * 输入:
 * 2*(9+6/3-5)+4
 * 输出:
 * 2963/+5-*4+
 */
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef struct SNode *Stack;
struct SNode{
    char fh;//fh:符号
    Stack next;
};
bool isEmpty(Stack PtrS);
void Push(char x,Stack PtrS);
char Pop(Stack PtrS);

int main()
{
    string ZZ,HZ;//ZZ:中缀,HZ:后缀
    while(cin>>ZZ)
    {
        cout<<ZZ<<"=";
    }
}