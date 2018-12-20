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
void code11();
void code12();
void code13();
void code14();

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
        cout << " ===================== && 测试排序操作 && ===================== " << endl;
        cout << "    1. 直接插入排序" << endl
             << "    2. 折半插入排序" << endl
             << "    3. 静态链表插入排序" << endl
             << "    4. 希尔排序" << endl
             << "                     " << endl
             << "    5. 冒泡排序" << endl
             << "    6. 快速排序" << endl
             << "                     " << endl
             << "    7. 直接选择排序" << endl
             << "    8. 堆排序" << endl
             << "                     " << endl
             << "    9. 归并排序" << endl
             << "                     " << endl
             << "   10. 基数排序(采用静态链表存储)" << endl
             << "                     " << endl
             << "   11. 随机生成顺序表" << endl
             << "   12. 随机生成静态链表" << endl
             << "   13. 输入顺序表" << endl
             << "   14. 学生信息排序(排序的应用)" << endl
             << " 其他. 结束" << endl;
        cout << " ============================================================== " << endl;
        // cout << a << endl;
        cout << " ============================================================== " << endl;
        cout << " 请选择你要操作的代码<1-14>: ";
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
            case 14:
                code14();
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

void code11()
{

    cout << " ============================================================== " << endl;
}

void code12()
{

    cout << " ============================================================== " << endl;
}

void code13()
{

    cout << " ============================================================== " << endl;
}

void code14()
{

    cout << " ============================================================== " << endl;
}

