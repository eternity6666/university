#include <bits/stdc++.h>
#include <iostream>
#include <random>
#include "SqStack_test.h"
#include "myExpress.h"
#include "mg.h"
using namespace std;
const int maxn = 1000 + 5;

SqStack<int> a, b;
string x, y; 
mg mg1, mg2;

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
void code101();
void code102();
void code103();
void code11();
void code111();
void code112();
void code113();
void code114();

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
    x = y = "";
    while(1)
    {
        system("clear");
        cout << " ======= && 表达式求解(顺序表的应用) && ======== " << endl;
        cout << " 10.1. 中缀表达式转换为后缀表达式\n"
             << " 10.2. 后缀表达式的计算\n"
             << " 10.3. 输入中缀表达式\n"
             << " 其他. 结束 " << endl;
        cout << " =============================================== " << endl;
        if(x == "")
            cout << " 当前未输入中缀表达式." << endl;
        else
        {
            cout << " 当前中缀表达式为: " << x << endl;
        }
        cout << " =============================================== " << endl;
        cout << " 请选择你要操作的代码<1-3>: ";
        int n;
        cin >> n;
        switch(n)
        {
            case 1:
                code101();
                break;
            case 2:
                code102();
                break;
            case 3:
                code103();
                break;
            default:
                cout << " 结束" << endl;
                return ;
        }
        cout << " 还继续吗<Y.继续\tN.结束>?";
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y')
            continue;
        else
            break;
    }
}

void code101()
{
    cout << " ======= && 中缀表达式转换为后缀表达式 && ====== " << endl;
    cout << " 当前中缀表达式对应的后缀表达式为: " << endl;
    y = transform(x);
    cout << " " << y << endl;
    cout << " =============================================== " << endl;
}

void code102()
{
    cout << " =========== && 后缀表达式的计算 && ============ " << endl;
    if(y == "")
        cout << " 后缀表达式为空, 无法进行计算" << endl;
    else
    {
        cout << " 当前后缀表达式" << y << endl;
        cout << " 的结果为: " << evaluation(y) << endl;
    }
    cout << " =============================================== " << endl;
}

void code103()
{
    cout << " ============ && 输入中缀表达式 && ============= " << endl;
    cout << " 请输入一个中缀表达式: ";
    cin >> x; 
    cout << " =============================================== " << endl;
}

void code11()
{

    while(1)
    {
        system("clear");
        cout << " ======== && 迷宫求解(顺序表的应用) && ========= " << endl;
        cout << " 11.1. 走迷宫\n"
             << " 11.2. 把一个迷宫赋值给另一个迷宫\n"
             << " 11.3. 随机生成迷宫\n"
             << " 11.4. 输入迷宫\n"
             << " 其他. 结束" << endl;
        cout << " =============================================== " << endl;
        cout << " 当前迷宫为: " << endl;
        cout << mg1 << endl;
        cout << " =============================================== " << endl;
        cout << " 请选择你要操作的代码<1-4>: ";
        int n;
        cin >> n;
        switch(n)
        {
            case 1:
                code111();
                break;
            case 2:
                code112();
                break;
            case 3:
                code113();
                break;
            case 4:
                code114();
                break;
            default:
                cout << " 结束" << endl;
                return ;
        }
        cout << " 还继续吗<Y.继续\tN.结束>?";
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y')
            continue;
        else
            break;
    }
}

void code111()
{
    cout << " ================ && 走迷宫 && ================= " << endl;
    if(mg1.isEmpty())
    {
        cout << " 当前迷宫为空, 无法继续操作" << endl;
    }
    else
    {
        int lx, ly;
        lx = mg1.getx();
        ly = mg1.gety();
        cout << " 请输入起始点的坐标: " << endl;
        cout << "    x: ";
        int sx;
        while(cin >> sx)
        {
            if(sx < 0 || sx > lx)
                cout << " 请注意: x的范围为<0-" << lx << ">";
            else
                break;
        }
        cout << "    y: ";
        int sy;
        while(cin >> sy)
        {
            if(sy < 0 || sy > ly)
                cout << " 请注意: y的范围为<0-" << ly << ">";
            else
                break;
        }
        cout << " 请输入终点的坐标: " << endl;
        cout << "    x: ";
        int ex;
        while(cin >> ex)
        {
            if(ex < 0 || ex > lx)
                cout << " 请注意: x的范围为<0-" << lx << ">";
            else
                break;
        }
        cout << "    y: ";
        int ey;
        while(cin >> ey)
        {
            if(ey < 0 || ey > ly)
                cout << " 请注意: y的范围为<0-" << ly << ">";
            else
                break;
        }
        cout << " 从起点<" << sx << "," << sy << ">到终点<" << ex << "," << ey << ">";
        if(mg1.findRoad(sx, sy, ex, ey))
        {
            cout << "有通路, 现用2标注如下: " << endl;
        }
        else
            cout << "无通路" << endl;
    }
    cout << " =============================================== " << endl;
}

void code112()
{
    cout << " ====== && 把一个迷宫赋值给另一个迷宫 && ======= " << endl;
    mg1 = mg2;

    if(mg2.isEmpty())
        cout << " 由于另一个迷宫当前为空，所有当前迷宫为空" << endl;
    else
    {
        cout << " 把另一个迷宫赋值给当前迷宫" << endl;
        cout << mg1;
    }
    cout << " =============================================== " << endl;
}

void code113()
{
    cout << " ============= && 随机生成迷宫 && ============== " << endl;
    cout << " 随机生成的迷宫为: " << endl;
    mg1.getByRand(true);
    cout << " =============================================== " << endl;
}

void code114()
{
    cout << " ================ && 输入迷宫 && =============== " << endl;
    cin >> mg1;
    cout << " 矫正后的迷宫为: " << endl;
    cout << mg1;
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

