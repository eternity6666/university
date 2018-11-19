#include "../../myhead.h"

const int firstSize = 100;
const int addSize = 10;

template <typename elemtype>
class SqList{
protected:
    elemtype *elem;
    int listSize;
    int n;

public:
    
    // 顺序表元素个数
    int getLength();

    // 输出顺序表
    void output();

    //　输入顺序表
    void input(int x);

    // 顺序表是否已满
    bool isFull();

    // 顺序表是否为空
    bool isEmpty();

    // 查找某个元素
    int searchElem(elemtype a);
    
    // 有序顺序表折半查找
    int bin_Search(elemtype key);

    // 把顺序表置为空
    void clear();

    // 删除第i个元素
    Status deleteElem(int i, elemtype & a);

    // 取第i个元素
    Status getElem(int i, elemtype & a);

    // 顺序表存储空间大小
    int getListSize();

    // 在第i个元素之前添加某个元素
    Status addElem(elemtype a, int i);

    // 查找第1个与a元素满足某个关系的元素序号
    int locateElem(elemtype a, Status (*compare)(elemtype, elemtype));
    
    // 返回某个元素的后继
    bool nextElem(elemtype a, elemtype & next_a);

    // 返回某个元素的前驱
    bool priorElem(elemtype a, elemtype & prior_a);

    // 重载"="运算符
    SqList operator = (const SqList & otherL);

    // 构造函数
    SqList();

    void newList();

    // 拷贝初始化构造函数
    SqList(const SqList<elemtype>& otherL);

    // 析构函数
    ~SqList();
};

template <typename elemtype>
void SqList<elemtype>::newList()
{
    int tmp[10];
    cout << " ";
    for(int i = 0; i < 10; i++)
    {
        elem[i] = rand() % 100;
        cout << elem[i] << " ";
    }
    n = 10;
    cout << endl;
}

template <typename elemtype>
void SqList<elemtype>::input(int x)
{
    elemtype *newbase;

    if(x >= listSize)
    {
        newbase = new elemtype[x + addSize];
        assert(newbase != 0);
        
        delete[] elem;
        elem = newbase;
        listSize = x +addSize;
    }

    cout << " ";
    for(int i = 1; i <= x; i++)
        cin >> elem[i - 1];
    n = x;
}

// 输出顺序表
template <typename elemtype>
void SqList<elemtype>::output()
{
    for(int i = 1; i <= n ; i++)
        cout << " [" << setw(2) << i << "]";
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << setw(5) << elem[i];
    cout << endl;
}

// 有序顺序表折半查找
template <typename elemtype>
int SqList<elemtype>::bin_Search(elemtype key)
{
    int low, mid, high;

    low = 0, high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(elem[mid] == key)
            return mid + 1;
        else if(elem[mid] < key)
            low = mid + 1;
        else
            high = mid - 1; 
    }
    return -1;
}

// 把顺序表置为空
template <typename elemtype>
void SqList<elemtype>::clear()
{
    n = 0;
}

// 删除第i个元素
template <typename elemtype>
Status SqList<elemtype>::deleteElem(int i, elemtype & a)
{
    if(i < 1 || i > n)
        return ERROR;
    
    a = elem[i - 1];

    for(int j = i + 1; j <= n; ++j)
        elem[j - 2] = elem[j - 1];
    --n;
    return OK;
}

// 取第i个元素
template <typename elemtype>
Status SqList<elemtype>::getElem(int i, elemtype & a)
{
    if(i < 1 || i > n)
        return ERROR;
    
    a = elem[i - 1];

    return OK;
}

// 顺序表存储空间大小
template <typename elemtype>
int SqList<elemtype>::getListSize()
{
    return listSize;
}

// 在第i个元素之前添加某个元素
template <typename elemtype>
Status SqList<elemtype>::addElem(elemtype a, int i)
{
    if(i < 1 || i > n)
        return ERROR;
    elemtype *newbase;

    if(n >= listSize)
    {
        newbase = new elemtype[listSize + addSize];
        assert(newbase != 0);

        for(int j = 1; j <= n; j++)
            newbase[j - 1] = elem[j - 1];
        
        delete[] elem;
        elem = newbase;
        listSize += addSize;
    }

    for(int j = n; j >= i; j--)
        elem[j] = elem[j - 1];
    elem[i - 1] = a;
    n++;
    return OK;
}

// 查找第1个与a元素满足某个关系的元素序号
template <typename elemtype>
int SqList<elemtype>::locateElem(elemtype a, Status (*compare)(elemtype, elemtype))
{
    int i;
    for(i = 1; i <= n && !(*compare)(elem[i - 1], a); i++);
    if(i <= n)
        return i;
    else
        return -1;
}

// 返回某个元素的后继
template <typename elemtype>
bool SqList<elemtype>::nextElem(elemtype a, elemtype & next_a)
{
    int i = locateElem(a, equal);

    if(i < 1 || i == n)
        return false;
    else
        getElem(i + 1, next_a);
    return true;
}
    
// 返回某个元素的前驱
template <typename elemtype>
bool SqList<elemtype>::priorElem(elemtype a, elemtype & prior_a)
{
    int i = locateElem(a, equal);

    if(i <= 1)
        return false;
    else
        getElem(i - 1, prior_a);
    return true;
}

// 重载"="运算符
template <typename elemtype>
SqList<elemtype> SqList<elemtype>::operator = (const SqList & otherL)
{
    if(this != &otherL)
    {
        if(listSize < otherL.listSize)
        {
            delete[] elem;
            elem = new elemtype[otherL.listSize];

            assert(elem != 0);
            listSize = otherL.listSize;
        }
        n = otherL.n;
        for(int i = 1; i <= n; i++)
            elem[i - 1] = otherL.elem[i - 1];
    }
    return *this;
}

// 析构函数
template <typename elemtype>
SqList<elemtype>::~SqList()
{
    delete[] elem;
}

// 顺序表元素个数
template <typename elemtype>
int SqList<elemtype>::getLength()
{
    return n;
}

// 构造函数
template <typename elemtype>
SqList<elemtype>::SqList()
{
    elem = new elemtype[firstSize];
    assert(elem != 0);
    listSize = firstSize;
    n = 0;
}

// 拷贝初始化构造函数
template <typename elemtype>
SqList<elemtype>::SqList(const SqList<elemtype>& otherL)
{
    listSize = otherL.listSize;
    n = otherL.n;
    
    elem = new elemtype[listSize];
    assert(elem != 0);

    for(int i = 0; i < n; i++)
        elem[i] = otherL.elem[i];
}

// 顺序表是否已满
template <typename elemtype>
bool SqList<elemtype>::isFull()
{
    if(n == listSize)
        return true;
    else
        return false;
}

// 顺序表是否为空
template <typename elemtype>
bool SqList<elemtype>::isEmpty()
{
    if(n == 0)
        return true;
    else
        return false;
}

// 查找某个元素
template <typename elemtype>
int SqList<elemtype>::searchElem(elemtype a)
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

