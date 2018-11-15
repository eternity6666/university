#include <iostream>
#include "cll.h"
using namespace std;

circularLinkList<int> a,b;
void code1();
void code2();
void code3();
void code4();
void code5();
void code6();
void code7();
void code8();
void menu();

int main()
{

    while(1)
    {
        system("clear");
        menu();
        if(a.getLength() == 0)
            cout << " 当前循环单链表为空 " << endl;
        else
        {
            cout << " 当前循环单链表为:" << endl;
            a.display();
        }
        cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
        cout << " 请输入操作代码<1-8>: ";
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
        default:
            cout << " 结束" << endl;
            return 0;
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
    cout << " ××××××××××××××× && 判断循环单链表是否为空 && ××××××××××××× " << endl;
   if(a.isEmpty())
   {
	   cout<<"当前循环单链表为空"<<endl;
   }
   else
   {
	   cout<<"当前循环单链表不为空"<<endl;
   }
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code2()
{
    cout << " ×××××××× && 把循环单链表的头指针后移至第i个结点 && ××××××× " << endl;
    cout << " 请输入头指针后移到的结点的序号:";
	int n;
	cin >> n;
    if(n < 1 || n > a.getLength())
    {
        cout << " 您的输入不合法" << endl;
        return ;
    }
	cout << endl;
    cout << " 移动后，头指针所指的结点的数据域为：";
	a.moveHead(n);
    int e;
    a.getHeadElem(e);
    cout << e << endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code3()
{
    cout << " ××××× && 删除第i个结点，头指针后移至其下一个结点 && ×××××× " << endl;
   cout << " 请输入欲删除的结点的序号：";
   int n;
   cin >> n;
   if(n < 1 || n > a.getLength())
   {
       cout << " 您的输入不合法" << endl;
       return ;
   }
   cout<<endl;
   int e;
   a.deleteElem(n,e);
   cout << " 删除第"<<n<<"个结点"<<e<<"后,循环单链表为："<<endl;
   a.display();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code4()
{
    cout << " ×××××× && 把一个循环单链表赋值给另一个循环单链表 && ×××××× " << endl;
	cout << " 另一个循环单链表赋值给当前循环单链表为："<<endl;
	b = a;
	b.display();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code5()
{
    cout << " ××××× && 把循环单链表置空 && ×××××× "<< endl;
	a.clear();
	cout << " 当前循环单链表已置空！"<<endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code6()
{
    cout << " ××××××××××××××× && 随机生成循环单链表 && ××××××××××××××××× " << endl;
    a.randList();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code7()
{
    cout << " ××××× && 用已有的循环单链表初始化另一个循环单链表 && ××××× " << endl;
    cout << " 当前循环单链表初始化另一个循环单链表为:" << endl;
    circularLinkList<int> c(a);
    c.display();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code8()
{
    cout << " ××××××××××××××××××× && 输入循环单链表 && ××××××××××××××××× " << endl;
	a.input();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void menu()
{
    cout << " ××××××××××××××× && 测试循环单链表的操作 && ××××××××××××××× " << endl
         << "    1. 判断循环单链表是否为空" << endl
         << "    2. 把循环单链表的头指针后移至第i个结点" << endl
         << "    3. 删除第i个结点，头指针后移至其下一个结点" << endl
         << "    4. 把一个循环单链表赋值给另一个循环单链表" << endl
         << "    5. 把循环单链表置空" << endl
         << "    6. 随机生成循环单链表" << endl
         << "    7. 用已有的循环单链表初始化另一个循环单链表" << endl
         << "    8. 输入循环单链表" << endl
         << " 其他. 结束" << endl
         << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

