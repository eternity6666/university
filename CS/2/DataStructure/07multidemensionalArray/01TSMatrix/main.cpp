#include <iostream>
#include "myTSMatrix.h"

myTSMatrix a;

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
        cout << "   =============== && 测试稀疏矩阵的操作 && ================ " << endl;
        cout << " ===================== (采用三元组储存) ====================== " << endl;
        cout << "    1. 求稀疏矩阵的转置矩阵" << endl
             << "    2. 快速求稀疏矩阵的转置矩阵" << endl
             << "    3. 计算稀疏矩阵各行第一个非零元素在三元组表中的下标" << endl
             << "    4. 稀疏矩阵的赋值运算" << endl
             << "    5. 求稀疏矩阵的加法" << endl
             << "    6. 求稀疏矩阵的乘积" << endl
             << "    7. 显示稀疏矩阵的三元组表示" << endl
             << "    8. 随机生成稀疏矩阵" << endl
             << "    9. 用已有的稀疏矩阵初始化一个新矩阵" << endl
             << "   10. 输入稀疏矩阵的三元组表" << endl
             << " 其他. 结束" << endl;
        cout << " ============================================================= " << endl;
        if(a.isEmpty())
            cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
        else
        {
            cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
            cout << a << endl;
        }
        // if(a.isEmpty())
        cout << " ============================================================= " << endl;
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
                return;
        }
        cout << " 还继续吗<Y.继续\tN.结束>?";
        char c;
        while(cin >> c)
        {
            if(c == 'y' || c == 'Y' || c == 'n' || c == 'N')
                break;
            else
                cout << " 还继续吗<Y.继续\tN.结束>?"; 
        }
        if(c == 'y' || c == 'Y')
            continue;
        else
            return;
    }
}

void code1()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }
    cout << " ================ && 求稀疏矩阵的转置矩阵 && ================= " << endl;
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
	myTSMatrix b;
        a.transposeMatrix(b);
        cout << " 当前稀疏矩阵的转置矩阵为: " << endl;
        cout << b << endl;
	a = b;
    }
    cout << " ============================================================= " << endl;
}

void code2()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }

    cout << " =============== && 快速求稀疏矩阵的转置矩阵 && ============== " << endl;
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
	myTSMatrix b;
        a.fastTransposeMatrix(b);
        cout << " 当前稀疏矩阵的转置矩阵为: " << endl;
	a = b;
        cout << a << endl;
    }
    cout << " ============================================================= " << endl;
}

void code3()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }

    cout << " == && 计算稀疏矩阵各行第一个非零元素在三元组表中的下标 && === " << endl;
    int sz[1000];
    a.calculate_rpos(sz, 1);
    cout << " ============================================================= " << endl;
}

void code4()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }

    cout << " ================ && 求稀疏矩阵的赋值运算 && ================= " << endl;
    myTSMatrix b;
    b.getByRand(0);
    cout << " 另一个稀疏矩阵赋值给当前稀疏矩阵为: " << endl;
    cout << b << endl;
    a = b;
    cout << " ============================================================= " << endl;
}

void code5()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }

    cout << " ================== && 求稀疏矩阵的加法 && =================== " << endl;
    myTSMatrix b, c;
    while(1)
    {
	    b.getByRand(0);
	    if(b.getColNum() == a.getColNum() && b.getRowNum() == a.getRowNum())
		    break;
	    else
		    continue;
    }
    cout << b << endl;
    cout << " 下面的稀疏矩阵加以上面稀疏矩阵" << endl;
    c = a + b;
    if(!c.isEmpty())
    {
        cout << " 得到的和为: " << endl;
        cout << c << endl;
    }
    cout << " ============================================================= " << endl;
}

void code6()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }

    cout << " ================== && 求稀疏矩阵的乘法 && =================== " << endl;
    myTSMatrix b, c;
    while(1)
    {
	    b.getByRand(0);
	    if(b.getColNum() == a.getColNum() && b.getRowNum() == a.getRowNum())
		    break;
	    else
		    continue;
    }
    cout << b << endl;
    cout << " 下面的稀疏矩阵乘以上面稀疏矩阵" << endl;
    c = b * a;
    if(!c.isEmpty())
    {
        cout << " 得到乘积的稀疏矩阵为: " << endl;
        cout << c << endl;
    }
    cout << " ============================================================= " << endl;
}

void code7()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }

    cout << " ============= && 显示稀疏矩阵的三元组表表示 && ============== " << endl;
    a.displayTriple();
    cout << " ============================================================= " << endl;
}

void code8()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }

    cout << " ================== && 随机生成稀疏矩阵 && =================== " << endl;
    cout << "   ==============  (数据元素的值在100以内)   ============== " << endl;
    a.getByRand(1);
    cout << " ============================================================= " << endl;
}

void code9()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }

    cout << " ========== && 用已有的稀疏矩阵初始化一个新矩阵 && =========== " << endl;
    myTSMatrix b(a);
    if(b.isEmpty())
        cout << " 已有的稀疏矩阵为空, 因此初始化后当前矩阵为空." << endl;
    else
    {
        cout << " 当前稀疏矩阵初始化另一个新矩阵为: " << endl;
        cout << b << endl;
    }
    cout << " ============================================================= " << endl;
}

void code10()
{
    system("clear");
    if(a.isEmpty())
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)为空. " << endl;
    else
    {
        cout << " 当前稀疏矩阵(采用三元组表顺序存储)如下: " << endl;
        cout << a << endl;
    }

    cout << " ================ && 输入稀疏矩阵的三元组表 && =============== " << endl;
    cin >> a;
    cout << " ============================================================= " << endl;
}

