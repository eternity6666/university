#include <iostream>
using namespace std;

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

int main()
{
    menu();
    return 0;
}

void menu()
{
    while(1)
    {
        system("clear");
        cout << " ========== && 测试广义表(采用头尾链表存储)的操作 && ========== " << endl;
        cout << "    1. 求广义表的深度" << endl
             << "    2. 广义表的赋值运算" << endl
             << "    3. 求广义表的长度" << endl
             << "    4. 判断广义表是否为空" << endl
             << "    5. 取广义表的表头" << endl
             << "    6. 取广义表的表尾" << endl
             << "    7. 删除广义表的表头" << endl
             << "    8. 插入一个广义表作为广义表的表头" << endl
             << "    9. 用已有的广义表初始化一个新广义表" << endl
             << "   10. 用字符串形式输入广义表" << endl
             << " 其他. 结束" << endl;
        cout << " ============================================================== " << endl;
        // cout << a << endl;
        cout << " ============================================================== " << endl;
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
                return ;
        }
        cout << " 还继续吗<Y.继续	N.结束>?";
        char c;
        while(cin >> c)
        {
            if(c == 'y' || c == 'Y' || c == 'n' || c == 'N')
                break;
            else
                cout << " 还继续吗<Y.继续	N.结束>?";
        }
        if(c == 'y' || c == 'Y')
            continue;
        else
            return;
    }
}
void code1()
{

    cout << " ============================================================== " << endl;
}

void code2()
{

    cout << " ============================================================== " << endl;
}

void code3()
{

    cout << " ============================================================== " << endl;
}

void code4()
{

    cout << " ============================================================== " << endl;
}

void code5()
{

    cout << " ============================================================== " << endl;
}

void code6()
{

    cout << " ============================================================== " << endl;
}

void code7()
{

    cout << " ============================================================== " << endl;
}

void code8()
{

    cout << " ============================================================== " << endl;
}

void code9()
{

    cout << " ============================================================== " << endl;
}

void code10()
{

    cout << " ============================================================== " << endl;
}

