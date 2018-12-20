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
void code15();
void code16();
void code17();
void code18();
void code19();

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
        cout << " ===================== && 测试查找操作 && ===================== " << endl;
        cout << "    1. 顺序查找" << endl
             << "    2. 随机生成查找" << endl
             << "                " << endl
             << "    3. 折半查找" << endl
             << "    4. 随机生成有序顺序表" << endl
             << "                " << endl
             << "    5. 二叉排序树的查找" << endl
             << "    6. 二叉排序树的插入" << endl
             << "    7. 二叉排序树的删除" << endl
             << "    8. 随机生成二叉排序树" << endl
             << "    9. 输入二叉排序树" << endl
             << "                " << endl
             << "   10. 平衡二叉排序树的查找和插入" << endl
             << "   11. 随机生成平衡二叉排序树" << endl
             << "   12. 输入平衡二叉排序树" << endl
             << "                " << endl
             << "   13. B-树的查找" << endl
             << "   14. B-树的插入" << endl
             << "   15. 随机生成B-树" << endl
             << "                " << endl
             << "   16. 开放地址哈希表的查找" << endl
             << "   17. 开放地址哈希表的插入" << endl
             << "   18. 随机生成开放地址哈希表" << endl
             << "                " << endl
             << "   19. 通讯簿的查询(查找的应用)" << endl
             << " 其他. 结束" << endl;
        cout << " ============================================================== " << endl;
        // cout << a << endl;
        cout << " ============================================================== " << endl;
        cout << " 请选择你要操作的代码<1-19>: ";
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
            case 15:
                code15();
                break;
            case 16:
                code16();
                break;
            case 17:
                code17();
                break;
            case 18:
                code18();
                break;
            case 19:
                code19();
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

void code15()
{

    cout << " ============================================================== " << endl;
}

void code16()
{

    cout << " ============================================================== " << endl;
}

void code17()
{

    cout << " ============================================================== " << endl;
}

void code18()
{

    cout << " ============================================================== " << endl;
}

void code19()
{

    cout << " ============================================================== " << endl;
}

