////////////////////////////////////////////////////////////////////////////

// ExampleClass.h 长方形数据结构C++类声明和实现(基类)

////////////////////////////////////////////////////////////////////////////
// 长方形数据结构C++类声明(基类)
template <typename ElemType>
class Rectangle
{
public:
    class RectangleNo
    {
    public:
        int no;          //存放长方形的序号
    };
    ElemType length;                   // 长方形的长
    ElemType width;                    // 长方形的宽
    RectangleNo myNo;                  // 长方形的序号
    // 重载赋值运算符的定义
    Rectangle operator = (Rectangle rightR);

    // 设置长方形的长
    void setLength(ElemType l);

    // 设置长方形的序号
    void setNo(int i);

    // ****** 下面为系统自动调用的构造函数及析构函数声明 ******
    // 长方形构造函数
    Rectangle();

    // 长方形拷贝初始化构造函数
    Rectangle(const Rectangle <ElemType> & otherD);

    // 长方形析构函数
    virtual ~Rectangle();

};

////////////////////////////////////////////////////////////////////////////
// 长方形数据结构C++类实现(基类)

// 功能:重载赋值运算符的定义
// 输入:函数的值参rightR的赋值运算符右边的长方形
// 输出:赋值运算符左边长方形(即当前长方形)被赋值为rightR
// 步骤:
//     (1)判断左边长方形是否等于rightR. 如果相等则转步骤(3),否则继续步骤(2)的操作
//     (2)把rightR的长宽等赋值给左边长方形
//     (3)通过函数的返回值返回左边长方形,返回
template <typename ElemType>
Rectangle<ElemType> Rectangle<ElemType>::operator = (Rectangle<ElemType> rightR)
{
    if(this != &rightR)
    {
        length = rightR.length;
        width = rightR.width;
        myNo = rightR.myNo;
        //
    }
    return *this;
}

// 功能:设置长方形的长
// 输入:函数的值参l为待设置的长
template <typename ElemType>
void Rectangle<ElemType>::setLength(ElemType l)
{
    length = l;
}

// 功能:设置长方形的序号
// 输入:函数的值参i为待设置的序号
template <typename ElemType>
void Rectangle<ElemType>::setNo(int i)
{
    myNo = i;
}

// ****** 下面为系统自动调用的构造函数及析构函数的实现 ******

// 功能:长方形的构造函数
// 说明:构造函数一般初始化为空对象
template <typename ElemType>
Rectangle<ElemType>::Rectangle()
{
    length = width = 0;
    //
}

// 功能:长方形拷贝初始化函数
// 输入:函数的参数otherD用于拷贝初始化的长方形
// 步骤:把otherD的长宽等赋值给当前长方形
template <typename ElemType>
Rectangle<ElemType>::Rectangle(const Rectangle<ElemType> & otherD)
{
    length = otherD.length;
    width = otherD.width;
    myNo = otherD.myNo;
    //
}

// 功能:长方形的析构函数
// 说明:对象生存期结束时,系统自动调用该对象所属类的析构函数
template <typename ElemType>
Rectangle<ElemType>::~Rectangle()
{
    //
}
