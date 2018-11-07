#include <iostream>
using namespace std;

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
        cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
        if(a.getLength() == 0)
            cout << " 当前非循环单链表为空 " << endl;
        else
        {
            cout << " 当前非循环单链表为: " << endl;
            a.display();
        };
        cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
        cout << endl;
        cout << " 请选择你要操作的代码<1-13>:" << endl;
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

void menu()
{
    cout << " ×××××××××××××× && 测试循环双链表的操作 && ×××××××××××××× " << endl
         << " 1.  取循环双链表的第i个结点的数据域" << endl
         << " 2.  在第1个结点之前插入一个数据域为e的结点" << endl
         << " 3.  判断循环双链表是否为空" << endl
         << " 4.  求循环双链表中结点的个数" << endl
         << " 5.  返回循环双链表中数据域为e的第一个结点的指针" << endl
         << " 6.  返回某结点前驱的数据域" << endl
         << " 7.  返回某结点后继的数据域" << endl
         << " 8.  删除循环双链表中数据域为e的第一个结点" << endl
         << " 9.  把一个循环双链表赋值给另一个循环双链表" << endl
         << " 10. 把循环双链表置空" << endl
         << " 11. 随机生成循双单链表" << endl
         << " 12. 用已有的循环双链表初始化另一个循环双链表" << endl
         << " 13. 输入循环双链表" << endl
         << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

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

void code13()
{
    cout << " ×××××××××××××××× && 输入非循环单链表 && ×××××××××××××××××× " << endl;
    cout << " 请输入循环双链表中结点的个数:";
    int n;
    cin >> n;

    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}
