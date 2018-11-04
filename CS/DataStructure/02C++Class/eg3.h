#include "eg1.h"
#include <iostream>
using namespace std;

template <typename ElemType>
class myRectangle:public Rectangle<ElemType>
{
public:
    void read();
    ElemType a;
    void display();
};

template <typename ElemType>
void myRectangle<ElemType>::read()
{
    a = 1;
    cout << a << endl;
    cout << "请输入第" << this->myNo.no << "个长方形对象" << endl;
    cout << "长方形的长为";
    cin >> this->length;
    cout << endl << "长方形的宽为";
    cin >> this->width;
    cout << endl;
}

template <typename ElemType>
void myRectangle<ElemType>::display()
{
    cout << "第" << this->myNo.no << "个长方形对象:\n长＝" << this->length << "\t　宽=" << this->width << endl;
}

