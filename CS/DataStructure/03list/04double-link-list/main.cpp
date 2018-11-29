#include <iostream>
#include "test.h"
using namespace std;

mydll<int> a, b;

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
void code12();
void code13();

void menu();

int main()
{

    while(1)
    {
        system("clear");
        menu();
        // cout << " ********************************************************** " << endl;
        if(a.getLength() == 0)
            cout << " 当前非循环双链表为空 " << endl;
        else
        {
            cout << " 当前非循环双链表为: " << endl;
            a.display();
        };
        cout << " ********************************************************** " << endl;
        cout << " 请选择你要操作的代码<1-13>: ";
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
        case 12:
            code12();
            break;
        case 13:
            code13();
            break;
        default:
            cout << "请输入1-13之间的整数" << endl;
            break;
        }
        cout << " 还继续吗<Y.继续\tN.结束>? ";
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
    cout << " *********** && 取循环双链表第i个结点的数据域 && ********** " << endl;
    int n = a.getLength();
    if(n)
    {
        cout << " 请输入你要取的结点的序号: ";
        int i;
        while(cin >> i)
        {
            if(i < 1 || i > n)
                cout << " 请输入序号<1-" << n << ">: ";
            else
                break;
        }
        int e;
        a.getElem(i, e);
        cout << " 你要取循环双链表的第" << i << "个结点的数据域为: " << e << endl; 
    }
    else
        cout << " 当前循环双链表为空, 无法进行本次操作" << endl;
    cout << " ********************************************************** " << endl;
}

void code2()
{
    cout << " ****** && 在第i个结点之前插入一个数据域为e的结点 && ****** " << endl;
    int n = a.getLength();
    if(n)
    {
        cout << " 请输入你要在它之前插入结点的序号: ";
        int i;
        while(cin >> i)
        {
            if(i < 1 || i > n)
                cout << " 请输入序号<1-" << n << ">: ";
            else
                break;
        }
        int e;
        cout << " 请输入你要插入结点的数据域: ";
        cin >> e;
        a.insert(i, e);
        cout << " 你已经在第" << i << "个结点之前插入数据域为" << e << "的结点" << endl;
        a.display();
    }
    else
        cout << " 当前循环双链表为空, 无法进行本次操作" << endl;
    cout << " ********************************************************** " << endl;
}

void code3()
{
    cout << " ×××××××××××××× && 判断循环双链表是否为空 && ×××××××××××××× " << endl;
    if(a.isEmpty())
    {
       cout << " 当前循环双链表为空"<<endl;
    }
    else
    {
       cout << " 当前循环双链表不为空"<<endl;
    }
    cout << " ********************************************************** " << endl;
}

void code4()
{
    cout << " ************* && 求循环双链表中结点的个数 && ************* " << endl;
    cout << " 当前循环双链表中结点的个数为: " << a.getLength() << endl;
    cout << " ********************************************************** " << endl;
}

void code5()
{
    cout << " ×××× && 返回循环双链表中数据域为e的第一个结点的指针 && ××× " << endl;
    cout << " 请输入你想查找结点的数据域: ";
    int e;
    cin >> e;
    mydll<int>::nodeP p;
    if(a.locateElem(e, p))
        cout << " 你想查找第一个数据域等于" << e << "的结点的数据域为: " << p->data << endl;
    else
        cout << " 未查找到你想要查找的结点" << endl;
    cout << " ********************************************************** " << endl;
}

void code6()
{
    cout << " ************** && 返回某结点前驱的数据域 && ************** " << endl;
    cout << " 请输入你想查找结点的数据域: ";
    int e; 
    cin >> e;
    int tmp;
    if(a.priorElem(e, tmp))
    {
        cout << " 你想查找" << e << "前驱的数据域为: " << tmp << endl;
    }
    else
        cout << " 您的输入有误" << endl;
    cout << " ********************************************************** " << endl;
}

void code7()
{
    cout << " ************** && 返回某结点后继的数据域 && ************** " << endl;
    cout << " 请输入你想查找结点的数据域: ";
    int e; 
    cin >> e;
    int tmp;
    if(a.nextElem(e, tmp))
    {
        cout << " 你想查找" << e << "后继的数据域为: " << tmp << endl;
    }
    else
        cout << " 您的输入有误" << endl;
    cout << " ********************************************************** " << endl;
}

void code8()
{
    cout << " ****** && 删除循环双链表中数据域为e的第一个结点 && ******* " << endl;
    cout << " 请输入你想删除结点的数据域: ";
    int e;
    cin >> e;
    if(a.deleteElem(e))
    {
        if(a.isEmpty())
            cout << " 删除后的循环双链表为空" << endl;
        else
        {
            cout << " 删除后的循环双链表为: " << endl;
            a.display();
        }
    }
    else
        cout << " 你的输入有误" << endl;
    cout << " ********************************************************** " << endl;
}

void code9()
{
    cout << " ****** && 把一个循环双链表赋值给另一个循环双链表 && ****** " << endl;
    b.getByRand(0);
    a = b;
    if(a.isEmpty())
        cout << " 由于另一个循环双链表为空, 赋值后, 当前循环双链表为空" << endl;
    else
    {
        cout << " 另一个循环双链表赋值给当前循环双链表为: " << endl;
        a.display();
    }
    cout << " ********************************************************** " << endl;
}

void code10()
{
    cout << " ***************** && 把循环双链表置空 && ***************** " << endl;
    a.clear();
    cout << " 当前循环双链表置空后, 数据元素的个数为: " << a.getLength() << endl;
    cout << " ********************************************************** " << endl;
}

void code11()
{
    cout << " ***************** && 随机生成循环双链表 && *************** " << endl;
    cout << " 用如下的随机数生成循环双链表: " << endl;
    a.getByRand(1);
    if(a.isEmpty())
        cout << " 随机生成了一个空的循环双链表" << endl;
    else
    {
        cout << " 随机生成的循环双链表为: " << endl;
        a.display();
    }
    cout << " ********************************************************** " << endl;
}

void code12()
{
    cout << " ***** && 用已有的循环双链表初始化另一个循环双链表 && ***** " << endl;
    cout << " 当前循环双链表初始化另一个循环双链表为: " << endl;
    b = a;
    b.display();
    cout << " ********************************************************** " << endl;
}

void code13()
{
    cout << " ****************** && 输入循环双链表 && ****************** " << endl;
    cout << " 请输入循环双链表中结点的个数: ";
    int n;
    cin >> n;
    if(n > 0)
    {
        a.input(n);
    }
    else if(n == 0)
    {
        a.clear();
        cout << " 您输入后的循环双链表为空" << endl;
    }
    else
    {
        cout << " 您的输入非法" << endl;
        return ;
    }
    cout << " ********************************************************** " << endl;
}

void menu()
{
    cout << " *************** && 测试循环双链表的操作 && *************** " << endl
         << "    1. 取循环双链表的第i个结点的数据域" << endl
         << "    2. 在第1个结点之前插入一个数据域为e的结点" << endl
         << "    3. 判断循环双链表是否为空" << endl
         << "    4. 求循环双链表中结点的个数" << endl
         << "    5. 返回循环双链表中数据域为e的第一个结点的指针" << endl
         << "    6. 返回某结点前驱的数据域" << endl
         << "    7. 返回某结点后继的数据域" << endl
         << "    8. 删除循环双链表中数据域为e的第一个结点" << endl
         << "    9. 把一个循环双链表赋值给另一个循环双链表" << endl
         << "   10. 把循环双链表置空" << endl
         << "   11. 随机生成循环双链表" << endl
         << "   12. 用已有的循环双链表初始化另一个循环双链表" << endl
         << "   13. 输入循环双链表" << endl
         << " 其他. 结束" << endl
         << " ********************************************************** " << endl;
}

