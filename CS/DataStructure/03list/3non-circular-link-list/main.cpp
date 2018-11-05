#include <iostream>
#include "ncll.h"
using namespace std;

linkList<int> a,b;

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
void code14();
void code15();
void menu();

int main()
{

    menu();
    while(1)
    {
        system("clear");
        cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
        if(a.getLength() == 0)
            cout << " 当前非循环单链表为空 " << endl;
        else
        {
            cout << " 当前非循环单链表为: " << endl;
            a.display();
        };
        cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
        cout << " 请输入: <1-15>为操作, 0为操作菜单 " << endl;
        int n;
        cin >> n;
        if(n == 0)
        {
            menu();
            cout << " 请输入: <1-15>为操作 " << endl;
            cin >> n;
        }
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
        case 14:
            code14();
            break;
        case 15:
            code15();
            break;
        default:
            cout << "请输入1-15之间的整数" << endl;
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

void code1(){}
void code2(){}
void code3(){}
void code4(){}
void code5(){}
void code6(){}
void code7(){}
void code8(){}
void code9(){}
void code10(){}
void code11(){}
void code12(){}

void code13()
{
    a.randList();
}

void code14(){}

void code15()
{
    cout << " ××××××××××××××××× && 输入非循环单链表 && ××××××××××××××××× " << endl;
    cout << " ";
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
    
}

void menu()
{
    cout << " ×××××××××××××× && 测试非循环单链表的操作 && ×××××××××××××× " << endl
         << " 1.  取非循环单链表的第i个结点" << endl
         << " 2.  在第1个结点之前插入一个数据域为e的结点" << endl
         << " 3.  判断非循环单链表是否为空" << endl
         << " 4.  求非循环单链表中结点的个数" << endl
         << " 5.  查找第1个与e满足compare()关系的结点" << endl
         << " 6.  返回某结点前驱的数据域" << endl
         << " 7.  返回某结点后继的数据域" << endl
         << " 8.  删除非循环单链表中数据域为e的第一个结点" << endl
         << " 9.  删除非循环单链表中的重复值" << endl
         << " 10. 非循环单链表的逆置" << endl
         << " 11. 把一个非循环单链表赋值给另一个非循环单链表" << endl
         << " 12. 把非循环单链表置空" << endl
         << " 13. 随机生成非循环单链表" << endl
         << " 14. 用已有的非循环单链表初始化另一个非循环单链表" << endl
         << " 15. 输入非循环单链表" << endl
         << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}
