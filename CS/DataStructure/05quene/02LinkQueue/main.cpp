#include <iostream>
#include "../../myhead.h"
#include "myLinkQueue.h"
#include "park.h"
using namespace std;

myLinkQueue<int> a, b;
park x;

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
void code101tmp();
void code1011();
void code1012();
void code102();
void code103();
void code104();

int main()
{
    while(1)
    {
        system("clear");
        menu();
        if(a.isEmpty())
            cout << " 当前非循环链队为空" << endl;
        else
        {
            cout << " 当前非循环链队为:" << endl;
            cout << a;
        }
        cout << " ---------------------------------------------------- " << endl;
        cout << " 请选择你要操作的代码<1-10>: ";
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
    cout << " ------ && 进队列(在非循环链队队尾插入结点) && ------ " << endl;
    cout << " 请输入你想要入队的结点的数据域:";
    int e;
    cin >> e;
    a.enQueue(e);
    cout << " 在当前非循环链队的队尾插入结点" << e << "后如下:" << endl;
    cout << a;
    cout << " ---------------------------------------------------- " << endl;
}

void code2()
{
    cout << " ------- && 出队列(删除非循环链队队头结点) && ------- " << endl;
    if(a.isEmpty())
        cout << " 当前队列为空，无法进行出队操作" << endl;
    else
    {
        int e;
        a.deQueue(e);
        cout << " 删除当前非循环链队队头的结点" << e << "后,";
        if(a.isEmpty())
            cout << "非循环链队为空" << endl;
        else
        {
            cout << "非循环链队为:" << endl;
            cout << a;
        }
    }
    cout << " ---------------------------------------------------- " << endl;
}

void code3()
{
    cout << " -------- && 读非循环链队队头结点的数据域 && -------- " << endl;
    if(a.isEmpty())
        cout << " 当前队列为空，无法进行此次操作" << endl;
    else
    {
        int e;
        a.getFront(e);
        cout << " 读取当前非循环链队队头结点的数据域" << e << "后,非循环链队为:" << endl;
        cout << a;
    }
    cout << " ---------------------------------------------------- " << endl;
}

void code4()
{
    cout << " ----------- && 判断非循环链队是否为空 && ----------- " << endl;
    if(a.isEmpty())
        cout << " 当前非循环链队为空" << endl;
    else
        cout << " 当前非循环链队不为空" << endl;
    cout << " ---------------------------------------------------- " << endl;
}

void code5()
{
    cout << " ----------- && 求非循环链队中结点的个数 && --------- " << endl;
    cout << " 当前非循环链队中结点的个数为: " << a.getLength() << endl;
    cout << " ---------------------------------------------------- " << endl;
}

void code6()
{
    cout << " --- &&  把一个非循环链队赋值给另一个非循环链队 && -- " << endl;
    cout << " 另一个非循环链队赋值给当前非循环链队为: " << endl;
    b.getByRand(0);
    a = b;
    cout << a;
    cout << " ---------------------------------------------------- " << endl;
}

void code7()
{
    cout << " ------------ && 把非循环链队置空 && ---------------- " << endl;
    a.clear();
    cout << " 当前非循环链队置空后，结点的个数为: " << a.getLength() << endl;
    cout << " ---------------------------------------------------- " << endl;
}

void code8()
{
    cout << " ------------- && 随机生成非循环链队 && ------------- " << endl;
    cout << " 依次在队尾插入:\n";
    a.getByRand(1);
    cout << " 随机生成非循环链队为:\n";
    cout << a;
    cout << " ---------------------------------------------------- " << endl;
}

void code9()
{
    cout << " -- && 用已有非循环链队初始化另一个新非循环链队 && -- " << endl;
    cout << " 当前非循环链队初始化另一个非循环链队为:" << endl;
    b = a;
    cout << b;
    cout << " ---------------------------------------------------- " << endl;
}

void code10()
{
    while(1)
    {
        system("clear");
        cout << " --------- && 停车场管理(栈和队列的应用) && --------- " << endl;
        cout << " 10.1. 模拟车辆调度\n"
             << " 10.2. 设置停车场可停车辆的最大数目\n"
             << " 10.3. 设置单位时间的收费值\n"
             << " 10.4. 随机生成停车的车辆\n"
             << " 其他. 结束 " << endl;
        cout << " ---------------------------------------------------- " << endl;
        
        cout << " ---------------------------------------------------- " << endl;
        cout << " 请选择你要操作的代码<1-4>: ";
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
            case 4:
                code104();
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
        cout << " ---------------------------------------------------- " << endl;
    }
}

void code101()
{
    while(1)
    {
        system("clear");
        cout << " ---------------- && 模拟车辆调度 && ---------------- " << endl;
        cout << " 请选择调度方式<1.离开\t2.进入\t0.结束>: ";
        int way;
        while(cin >> way)
        {
            if(way >=0 && way <= 2)
                break;
            else
            {
                cout << " 您的输入非法" << endl;
                cout << " 请选择调度方式<1.离开\t2.进入\t0.结束>: ";
            }
        }
        switch(way)
        {
            case 1:
                code1011();
                break;
            case 2:
                code1012();
                break;
            default:
                cout << " 结束" << endl;
                return ;
        }
        if(way)
            code101tmp();
        cout << " ---------------------------------------------------- " << endl;
        cout << " 还继续模拟停车场调度吗<Y.继续\tN.结束>? ";
        char c;
        cin >> c;
        if(c == 'y' || c == 'Y')
            continue;
        else
            break;
    }
}

void code1011()
{
    
}

void code1012()
{
    cout << " 请输入哪个位置上的车辆准备离开";
    int n;
    cin >> n;
    cout << " 停车场停放在" << n << "号位置上车辆准备离开. " << endl;

}

void code101tmp()
{
}

void code102()
{
    cout << " -------- && 设置停车场可停车场的最大数目 && -------- " << endl;
    cout << " 请输入最多可容纳的车辆数: ";
    int n;
    while(cin >> n)
    {
        if(n >= 0)
            break;
        else
            cout << " 请输入非负整数: ";
    }
    x.setSize(n);
    cout << " ---------------------------------------------------- " << endl;
}

void code103()
{
    cout << " ------------ && 设置单位时间的收费值 && ------------ " << endl;
    cout << " 请输入停车场单位时间的收费率: ";
    int fee;
    while(cin >> fee)
    {
        if(fee >= 0)
            break;
        else
            cout << " 请输入非负整数: ";
    }
    x.setFee(fee);
    cout << " 已经设置停车场单位时间的收费率为: " << x.outputFee() << endl;
    cout << " ---------------------------------------------------- " << endl;
}

void code104()
{
    cout << " ------------ && 随机生成停车场的车辆 && ------------ " << endl;
    x.getByRand(1);
    cout << " ---------------------------------------------------- " << endl;
}

void menu()
{
    cout << " ------------ && 测试非循环链队的操作 && ------------ " << endl;
    cout << "    1. 进队列(在非循环链队列队尾插入结点)\n"
         << "    2. 出队列(删除非循环链队列队头结点)\n"
         << "    3. 读非循环链队队头结点的数据域\n"
         << "    4. 判断非循环链队是否为空\n"
         << "    5. 求非循环链队中元素的个数\n"
         << "    6. 把一个非循环链队赋值给另一个非循环链队\n"
         << "    7. 把非循环链队置空\n"
         << "    8. 随机生成非循环链队\n"
         << "    9. 用已有的非循环链队初始化另一个新非循环链队\n"
         << "   10. 停车场管理(栈和队列的应用)\n"
         << " 其他. 结束 " << endl;
    cout << " ---------------------------------------------------- " << endl;
}

