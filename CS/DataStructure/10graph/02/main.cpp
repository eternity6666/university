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
        cout << " ============= && 测试图(采用邻接表存储)的操作 && ============= " << endl;
        cout << "    1. 从某顶点开始对图做深度优先遍历" << endl
             << "    2. 从某顶点开始对图做广度优先遍历" << endl
             << "    3. 判断并输出图的一个拓扑序列" << endl
             << "    4. 输出图的关键活动" << endl
             << "    5. 随机输出图的邻接表" << endl
             << "    6. 输入图的邻接表" << endl
             << "    7. 课程表的排课(图的拓扑排序应用)" << endl
             << " 其他. 结束" << endl;
        cout << " ============================================================== " << endl;
        // cout << a << endl;
        cout << " ============================================================== " << endl;
        cout << " 请选择你要操作的代码<1-7>: ";
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

