////////////////////////////////////////////////////////////////////////////
//
// MyExampleClass.h 长方形数据结构C++类声明和实现(派生类)
//
//////////////////////////////////////////////////////////////////////////////
// 
// eg1.h 长方形数据结构C++类声明和实现(基类)

#ifndef EG1_H
    #define EG1_H
    #include "./eg1.h"
#endif

// 长方形数据结构C++类声明(派生类)

template <typename ElemType>
class MyRectangle:public Rectangle<ElemType>
{
public:
    // ****** 类对象的输入输出函数 ******

    // 输入长方形
    void read(istream& in);

    // 输出长方形
    void display(ostream& out) const;

};

////////////////////////////////////////////////////////////////////////////
//
// 长方形数据结构C++类实现(派生类)
//
// 功能:输入长方形
// 说明:输入长方形的长和宽
template <typename ElemType>
void MyRecatangle<ElemType>::read(istream& in)
{
    cout << "请输入第" << myNo.no << "个长方形对象" << endl;
    cout << "长方形的长为";
    in >> length;
    cout << endl << "长方形的宽为";
    in >> width;
    cout << endl;
}

// 功能:重载输入运算符的定义
// 说明:通过本函数，可以使用C++中cin直接从键盘上输入长方形

template <typename ElemType>
istream& operator >> (istream& in, MyRectangle<ElemType>& iD)
{
    ID.read(in);
    return in;
}

// 功能:输出长方形
// 说明:输出长方形的长和宽
template <typename ElemType>
void MyRectangle<ElemType>::display(ostream& out) const
{
    out << "第" << myNo.no << "个长方形对象:\n长＝" << length << "\t　宽=" << width << endl;
}

// 功能:重载输出运算符的定义
// 说明:通过本函数，可以使用C++中cout直接在屏幕上输出长方形
template <typename ElemType>
ostream& operator << (ostream& out, const MyRectangle<ElemType>& oD)
{
    oD.display(out);
    return out;
}

