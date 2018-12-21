#include <iostream>
#include "linkStack_test.h"
using namespace std;

linkStack<int> a, b;

void menu();
void code1();
void code2();
void code3();
void code4();
void code5();
void code6();
void code7();
void code8();
void code9();

int main()
{
    while(1)
    {
        system("clear");
        menu();
        if(a.isEmpty())
            cout << " 当前链栈为空\n";
        else
        {
            cout << " 当前链栈中的结点为:"<< endl;
            display(a);
        }
        cout << " -----------------------------------------------" << endl;
        cout << " 请选择你要操作的代码<1-9>: ";
        int n;
        cin >> n;
        switch(n)
        {
            case 1:
                code1();
                break;
            case 2:
                code2();
                break;
            case 3:
                code3();
                break;
            case 4:
                code4();
                break;
            case 5:
                code5();
                break;
            case 6:
                code6();
                break;
            case 7:
                code7();
                break;
            case 8:
                code8();
                break;
            case 9:
                code9();
                break;
            default:
                cout << " 结束" << endl;
                return 0;
        }
        cout << " 还继续吗<Y.继续\tN.结束>?";
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y')
            continue;
        else
            break;
    }
    return 0;
}

void code1()
{
    cout << " ------------ && 在栈顶压入元素e && ------------ " << endl;
    cout << " 请输入你要在栈顶压入的元素: ";
    int e;
    cin >> e;
    a.push(e);
    cout << " 压入元素" << e << "后，新链栈如下所示: " << endl;
    display(a);
    cout << " ----------------------------------------------- " << endl;
}

void code2()
{   
    cout << " ---------- && 弹出栈顶的元素到e && ------------ " << endl;
    int e;
    if(a.pop(e))
    {
        cout << " 弹出的栈顶元素为: " << e << endl;
        if(a.getLength() != 0)
        {
            cout << " 弹出后链栈中的元素为: " << endl;
            display(a);
        }
        else
            cout << " 弹出后链栈为空" << endl;
    }
    else
        cout << " 当前链栈为空，无元素可弹出" << endl;
    cout << " ----------------------------------------------- " << endl;
}

void code3()
{
    cout << " -------------- && 读栈顶的元素 && ------------- " << endl;
    int e;
    if(a.getTop(e))
    {
        cout << " 该栈顶元素为: " << e << endl;
        cout << " 读该栈顶元素后，链栈中的元素为: " << endl;
        display(a);
    }
    else
        cout << " 当前链栈为空, 无法读取" << endl;
    cout << " ----------------------------------------------- " << endl;
}

void code4()
{
    cout << " ----------- && 判断链栈是否为空 && ------------ " << endl;
    if(a.isEmpty())
        cout << " 当前链栈为空" << endl;
    else
        cout << " 当前链栈不为空" << endl;
    cout << " ----------------------------------------------- " << endl;
}

void code5()
{
    cout << " ---------- && 求链栈中元素的个数 && ----------- " << endl;
    cout << " 当前链栈中的元素的个数为: ";
    cout << a.getLength() << endl;
    cout << " ----------------------------------------------- " << endl;
}

void code6()
{
    cout << " ------- && 把一个链栈赋值给另一个链栈 && ------ " << endl;
    cout << " 另一个链栈赋值给当前链栈为: " << endl;
    getByRand(b);
    a = b;
    display(a);
    cout << " ----------------------------------------------- " << endl;
}

void code7()
{
    cout << " -------------- && 把链栈置空 && --------------- " << endl;
    a.clear();
    cout << " 当前链栈置空后,元素的个数为: " << a.getLength() << endl;
    cout << " ----------------------------------------------- " << endl;
}

void code8()
{
    cout << " ------------- && 随机生成链栈 && -------------- " << endl;
    cout << " 依次在链栈的前面插入:" << endl;
    getByRand(a, 1);
    cout << " 随机生成的链栈如下:" << endl;
    display(a);
    cout << " ----------------------------------------------- " << endl;
}

void code9()
{
    cout << " ------- && 用已有链栈初始化另一个链栈 && ------ " << endl;
    cout << " 当前链栈初始化另一个链栈为:\n";
    linkStack<int> c(a);
    display(c);
    cout << " ----------------------------------------------- " << endl;
}

void menu()
{
    cout << " ----------- && 测试链栈的操作 && ------------ " << endl;
    cout << "    1. 在栈顶压入一个数据域为e的结点\n"
         << "    2. 弹出栈顶结点\n"
         << "    3. 读栈顶结点的数据域\n"
         << "    4. 判断是否为空\n"
         << "    5. 求链栈中结点的个数\n"
         << "    6. 把一个链栈赋值个另一个链栈\n"
         << "    7. 把链栈置空\n"
         << "    8. 随机生成链栈\n"
         << "    9. 用已有链栈初始化另一个链栈\n"
         << " 其他. 结束 " << endl;
    cout << " -----------------------------------------------" << endl;
}

