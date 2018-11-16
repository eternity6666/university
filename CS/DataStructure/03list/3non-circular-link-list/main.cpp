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
        cout << " 请输入操作代码<1-15>: ";
        int n;
        cin >> n;
        /*
        if(n == 0)
        {
            menu();
            cout << " 请输入: <1-15>为操作 " << endl;
            cin >> n;
        }
        */
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
    cout << " ××××××××××××× && 取非循环单链表的第i个结点 && ×××××××××××× " << endl;
    cout << " 请输入你要取的结点的序号";
    int code;
    cin >> code;
    int e;
    a.getElem(code, e);
    cout << " 你要取非循环单链表的第" << code <<"个结点的数据域为:" << e << endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code2()
{
    cout << " ×××××× && 在第i个结点之前插入一个数据域为e的结点 && ×××××× " << endl;
    cout << " 请输入你要在它之前插入结点的序号:";
    int i;
    cin >> i;
    cout << " 请输入你要插入结点的数据域:";
    int e;
    cin >> e;
    cout << " 你已经在第" << i << "个结点之前插入数据域为" << e <<"的结点"<< endl;
    a.insert(i, e);
    a.display();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code3()
{
    cout << " ××××××××××××× && 判断非循环单链表是否为空 && ××××××××××××× " << endl;
    if(a.isEmpty())
        cout << " 当前非循环单链表为空" << endl;
    else
        cout << " 当前非循环单链表不为空" << endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code4()
{
    cout << " ×××××××××××× && 求非循环单链表中结点的个数 && ×××××××××××× " << endl;
cout << " 非循环单链表中结点的个数为:" << a.getLength() << endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code5()
{
    cout << " ××××× && 查找第1个与e满足compare()关系元素的结点 && ×××××× "<< endl;
    cout << " 查找等于某个结点的操作 " << endl;
	cout << " 请输入你想查找的结点: " << endl;
	int e,j;
	cin >> e;
	a.locateElem(e,equal,j);
	cout << " 数据域等于" << e << " 的第一个结点的的序号为 " << j << endl;
	cout << " 查找大于某个结点的操作 " << endl;
	cout << " 请输入你想查找的结点:" << endl;
	cin >> e;
	a.locateElem(e,great,j);
	cout << " 数据域大于" << e <<"的第一个结点的的序号为" << j <<endl;
	cout << " 查找小于某个元素的操作" << endl;
	cout << " 请输入你想查找的元素:" << endl;
	cin >> e;
	a.locateElem(e,Less,j);
	cout << " 数据域小于"<< e << "的第一个结点的的序号为 " << j <<endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code6()
{
    cout << " ×××××××××××××× && 返回某结点前驱的数据域 && ×××××××××××××× " << endl;
    cout << " 请输入你想查找结点的数据域:" << endl;
    int i;
    cin >> i;
    cout << " 你想查找" << i << "前驱的数据域为";
    int e;
    a.priorElem(i, e);
    cout << e << endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code7()
{
    cout << " ×××××××××××××× && 返回某结点后驱的数据域 && ×××××××××××××× " << endl;
    cout << " 请输入你想查找结点的数据域:" << endl;
    int i;
    cin >> i;
    cout << " 你想查找" << i << "后继的数据域为";
    int e;
    a.nextElem(i, e);
    cout << e << endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code8()
{
    cout << " ××××× && 删除非循环单链表中数据域为e的第一个结点 && ×××××× " << endl;
    cout << " 请输入你想删除结点的数据域:";
    int e;
    cin >> e;
    if(a.deleteElem(e))
    {
        cout << " 删除后的非循环单链表为" << endl;
        a.display();
    }
    else
        cout << " 您的输入非法" << endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code9()
{
    cout << " ××××××××××××× && 删除非循环单链表中的重复值 && ××××××××××× " << endl;
    a.deleteRepeat();
    a.display();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code10()
{
    cout << " ×××××××××××××××× && 非循环单链表的逆置 && ×××××××××××××××× " << endl;
    a.adverse();
    cout << " 非循环单链表的逆置后为:" << endl;
    a.display();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code11()
{
    cout << " ×××× && 把一个非循环单链表赋值给另一个非循环单链表 && ×××× " << endl;
    cout << " 把另一个非循环单链表赋值给当前非循环单链表为:" << endl;
    a = b;
    a.display();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code12()
{
    cout << " ×××××××××××××× && 把当前非循环单链表置空 && ×××××××××××××× " << endl;
    a.clear();
    cout << " 当前非循环单链表置空后，结点个数为:" << a.getLength() << endl;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;

}

void code13()
{
    cout << " ×××××××××××××× && 随机生成非循环单链表 && ×××××××××××××××× " << endl;
    a.randList();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code14()
{
    cout << " ××× && 用已有的非循环单链表初始化另一个非循环单链表 && ××× " << endl;
    cout << " 当前非循环单链表初始化另一个非循环单链表为: " << endl;
    a.display();
    b = a;
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

void code15()
{
    cout << " ××××××××××××××××× && 输入非循环单链表 && ××××××××××××××××× " << endl;
    a.input();
    cout << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
    
}

void menu()
{
    cout << " ×××××××××××××× && 测试非循环单链表的操作 && ×××××××××××××× " << endl
         << "    1. 取非循环单链表的第i个结点" << endl
         << "    2. 在第1个结点之前插入一个数据域为e的结点" << endl
         << "    3. 判断非循环单链表是否为空" << endl
         << "    4. 求非循环单链表中结点的个数" << endl
         << "    5. 查找第1个与e满足compare()关系的结点" << endl
         << "    6. 返回某结点前驱的数据域" << endl
         << "    7. 返回某结点后继的数据域" << endl
         << "    8. 删除非循环单链表中数据域为e的第一个结点" << endl
         << "    9. 删除非循环单链表中的重复值" << endl
         << "   10. 非循环单链表的逆置" << endl
         << "   11. 把一个非循环单链表赋值给另一个非循环单链表" << endl
         << "   12. 把非循环单链表置空" << endl
         << "   13. 随机生成非循环单链表" << endl
         << "   14. 用已有的非循环单链表初始化另一个非循环单链表" << endl
         << "   15. 输入非循环单链表" << endl
         << " 其他. 结束" << endl
         << " ×××××××××××××××××××××××××××××××××××××××××××××××××××××××××× " << endl;
}

