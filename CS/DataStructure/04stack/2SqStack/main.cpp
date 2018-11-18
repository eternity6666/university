#include <iostream>
#include <random>
#include "SqStack_test.h"
using namespace std;

SqStack<int> a, b;

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
void code10();
void code11();

int main()
{
    while(1)
    {
        system("clear");
        menu();
        display(a);
        cout << " ===============================================" << endl;
        cout << " 请选择你要操作的代码<1-11>: ";
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
            case 10:
                code10();
                break;
            case 11:
                code11();
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
    cout << " ============ && 在栈顶压入元素e && ============ " << endl;
    cout << " 请输入你要在栈顶压入的元素: ";
    int e;
    cin >> e;
    a.push(e);
    cout << " 压入元素" << e << "后，新顺序栈如下所示: " << endl;
    display(a);
    cout << " =============================================== " << endl;
}

void code2()
{
    cout << " ========== && 弹出栈顶的元素到e && ============ " << endl;
    int e;
    if(a.pop(e))
    {
        cout << " 弹出的栈顶元素为: " << e << endl;
        if(a.getLength() != 0)
        {
            cout << " 弹出后顺序栈中的元素为: " << endl;
            display(a);
        }
        else
            cout << " 弹出后顺序栈为空" << endl;
    }
    else
        cout << " 当前顺序栈为空，无元素可弹出" << endl;
    cout << " =============================================== " << endl;
}

void code3()
{
    cout << " ============== && 读栈顶的元素 && ============= " << endl;
    int e;
    if(a.getTop(e))
    {
        cout << " 该栈顶元素为: " << e << endl;
        cout << " 读该栈顶元素后，顺序栈中的元素为: " << endl;
        display(a);
    }
    else
        cout << " 当前顺序栈为空" << endl;
    cout << " =============================================== " << endl;
}

void code4()
{
    cout << " ========== && 判断顺序栈是否为空 && =========== " << endl;
    if(a.isEmpty())
        cout << " 当前顺序栈为空" << endl;
    else
        cout << " 当前顺序栈不为空" << endl;
    cout << " =============================================== " << endl;
}

void code5()
{
    cout << " ========= && 求顺序栈中元素的个数 && ========== " << endl;
    cout << " 当前顺序栈中的元素的个数为: ";
    cout << a.getLength() << endl;
    cout << " =============================================== " << endl;
}

void code6()
{
    cout << " ===== && 把一个顺序栈赋值给另一个顺序栈 && ==== " << endl;
    cout << " 另一个顺序栈赋值给当前顺序栈为: " << endl;
    getByRand(b);
    a = b;
    display(a);
    cout << " =============================================== " << endl;
}

void code7()
{
    cout << " ============= && 把顺序栈置空 && ============== " << endl;
    a.clear();
    cout << " 当前顺序栈置空后,元素的个数为: " << a.getLength() << endl;
    cout << " =============================================== " << endl;
}

void code8()
{
    cout << " ============ && 随机生成顺序栈 && =============" << endl;
    cout << " 随机生成顺序栈中的一些元素如下: " << endl;
    getByRand(a, 1);
    cout << " 随机生成的顺序栈<采用顺序储存>如下: \n";
    display(a);
    cout << " =============================================== " << endl;
}

void code9()
{
    cout << " ==== && 用已有顺序栈初始化另一个新顺序栈 && === " << endl;
    cout << " 当前顺序栈初始化另一个顺序栈为:\n";
    SqStack<int> c(a);
    display(c);
    cout << " =============================================== " << endl;
}

void code10()
{
    system("clear");
    cout << " ======= && 表达式求解(顺序表的应用) && ======== " << endl;
    cout << " 10.1. 中缀表达式转换为后缀表达式\n"
         << " 10.2. 后缀表达式的计算\n"
         << " 10.3. 输入中缀表达式\n"
         << " 其他. 结束 " << endl;
    cout << " =============================================== " << endl;
}

void code11()
{
    system("clear");
    cout << " ======== && 迷宫求解(顺序表的应用) && ========= " << endl;
    cout << " 11.1. 走迷宫\n"
         << " 11.2. 把一个迷宫赋值给另一个迷宫\n"
         << " 11.3. 随机生成迷宫\n"
         << " 11.4. 输入迷宫\n"
         << " 其他. 结束" << endl;
    cout << " =============================================== " << endl;
}

void menu()
{
    cout << " =========== && 测试顺序栈的操作 && ============ " << endl;
    cout << "    1. 在栈顶压入元素e\n"
         << "    2. 弹出栈顶的元素到e\n"
         << "    3. 读栈顶的元素\n"
         << "    4. 判断顺序栈是否为空\n"
         << "    5. 求顺序栈中元素的个数\n"
         << "    6. 把一个顺序栈赋值给另一个顺序栈\n"
         << "    7. 把顺序栈置空\n"
         << "    8. 随机生成顺序栈\n"
         << "    9. 用已有的顺序栈初始化另一个顺序栈\n"
         << "   10. 表达式求解(顺序表的应用)\n"
         << "   11. 迷宫求解(顺序栈的应用)\n"
         << " 其他. 结束 " << endl;
    cout << " =============================================== " << endl;
}

