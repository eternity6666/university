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
    while(1)
    {
        system("clear");
        menu();
        display(a);
        cout << " -------------------------------------------------------------------------" << endl;
        cout << " 请选择你要操作的代码<1-11>: ";
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

}

void code2()
{

}

void code3()
{

}

void code4()
{

}

void code5()
{

}

void code6()
{

}

void code7()
{

}

void code8()
{

}

void code9()
{

}

void code10()
{

}

void menu()
{
    cout << " 其他. 结束 " << endl;
    cout << " -------------------------------------------------------------------------" << endl;
}

