const int firstSize = 100;
const int addSize = 10;

template <typename ElemType>
class SqList{
protected:
    ElemType *elem;
    int listSize;
    int n;

public:
    // 顺序表是否已满
    bool isFull();

    // 顺序表是否为空
    bool isEmpty();
    
    // 顺序表元素个数
    int getLength();

    // 顺序表存储空间大小
    int getListSize();

    // 查找某个元素
    int searchElem(ElemType a);

    // 在第i个元素之前添加某个元素
    Status addElem(ElemType a, int i);

    // 删除某个元素
    Status deleteElem(int i);

    // 查找第1个与a元素满足某个关系的元素序号
    int locateElem(ElemType a, Status (*compare)(ElemType, ElemType));
    
    // 返回某个元素的后继
    Status nextElem(ElemType a, ElemType & next_a);

    // 返回某个元素的前驱
    Status priorElem(ElemType a, ElemType & prior_a);

    // 重载"="运算符
    SqList operator = (const SqList & otherL);
    
    // 构造函数
    SqList();

    //拷贝初始化构造函数
    SqList(const SqList<ElemType>& otherL);

    // 析构函数
    ~SqList();
};

// 顺序表元素个数
template <typename ElemType>
int SqList<ElemType>::getLength()
{
    return n;
}

// 构造函数
template <typename ElemType>
SqList<ElemType>::SqList()
{
    elem = new ElemType[firstSize];
    assert(elem != 0);
    listSize = firstSize;
    n = 0;
}
// 拷贝初始化构造函数
template <typename ElemType>
SqList<ElemType>::SqList(const SqList<ElemType>& otherL)
{
    listSize = otherL.listSize;
    n = otherL.n;
    
    elem = new ElemType[listSize];
    assert(elem != 0);

    for(int i = 0; i < n; i++)
        elem[i] = otherL.elem[i];
}

// 顺序表是否已满
template <typename ElemType>
bool SqList<ElemType>::isFull()
{
    if(n == listSize)
        return true;
    else
        return false;
}

// 顺序表是否为空
template <typename ElemType>
bool SqList<ElemType>::isEmpty()
{
    if(n == 0)
        return true;
    else
        return false;
}

// 查找某个元素
template <typename ElemType>
int SqList<ElemType>::searchElem(ElemType a)
{
    if(isEmpty())
        return -1;
    for(int i = 0; i < n; i++)
    {
        if(elem[i] == a)
            return i;
    }
    return -1;
}

// 在第i个元素之前添加某个元素
template <typename ElemType>
Status addElem(ElemType a, int i)
{

}

// 删除某个元素
template <typename ElemType>
Status deleteElem(int i)
{

}

// 查找第1个与a元素满足某个关系的元素序号
template <typename ElemType>
int locateElem(ElemType a, Status (*compare)(ElemType, ElemType))
{
}

// 返回某个元素的后继
template <typename ElemType>
Status nextElem(ElemType a, ElemType & next_a)
{
}

// 返回某个元素的前驱
template <typename ElemType>
Status priorElem(ElemType a, ElemType & prior_a)
{

}
