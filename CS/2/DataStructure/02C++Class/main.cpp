#include <iostream>
using namespace std;
#include "./eg2.h"
int main()
{
    float al = (float)8.2;

    MyRectangle<int> d1;
    MyRectangle<float> d2,d3;

    cout << endl;

    d1.setNo(1);
    d2.setNo(2);
    d3.setNo(3);
    cout << d1 << d2 << d3;

    cin >> d1 >> d2;

    cout << " 把第二个长方形对象赋值给第三个长方形对象" << endl;
    d3 = d2;
    cout << " 设置第二个长方形对象的长为" << al << endl;
    d2.setLength(al);

    cout << d1 << d2 << d3;

    cout << endl;
    cout << " ****************************************************** " << endl;
    cout << " 各对象按声明时相反的顺序逐一自动析构，结束各自的生存期 " << endl;
    return 0;
}
