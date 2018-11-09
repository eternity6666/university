#include <iostream>
#include "eg2.h"

MyRectangle<int> a,b;

void menu();

int main()
{
    while(1)
    {
        system("clear");
        menu();

    }
}

void menu()
{
    cout << " ******** && 测试长方形的操作 && ******** " << endl;
    cout << "    1. 设置长方形的序号 " << endl
         << "    2. 设置长方形的长 " << endl
         << "    3. 重载赋值运算符的定义 " << endl
         << " 其他. 结束 " << endl;
    cout << " **************************************** " << endl;
}

