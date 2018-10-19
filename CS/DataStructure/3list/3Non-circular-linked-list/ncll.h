template<typename ElemType>
class linkList
{
public:

    class linkNode
    {
    public:
        ElemType data;
        linkNode *next;
    };
    typedef linkNode * nodeP;

    // 逆置非循环单链表
    void adverse();

    // 把非循环单链表置为空
    void clear();

    // 删除非循环单链表中数据域为e的第一个结点
    Status deleteElem(ElemType e);

    // 删除非循环单链表中的重复值
    void deleteRepeat();

    // 取非循环单链表的第i个结点
    status getElem(int i, ElemType & e);

    // 取第一个结点的指针
    nodeP getHead();

    // 求非循环单链表结点的个数
    int getLength();

    // 在第i个结点之前插入一个数据域为e的结点
    Status insert(int i, ElemType e);

    // 判断非循环单链表是否为空
    bool isEmpty();

    // 查找第1个与e满足compare()关系的结点
    Status locateElem(ElemType e, Status (*compare)(ElemType, ElemType), int & i);

    // 返回某结点后继的数据域
    Status nextElem(ElemType e, ElemType & next_e);

    // 重载赋值运算符的定义
    linkList<ElemType> operator = (LinkList<ElemType> rightL);

    // 返回某结点前驱的数据域
    Status priorElem(ElemType e, ElemType & prior_e);

    // 非循环单链表析构函数
    ~linkList();

    // 非循环单链表拷贝初始化构造函数
    linkList(const linkNode<ElemType> & linkNode);

    // 非循环单链表构造函数
    linkList();

protected:
    nodeP head;
};


// 逆置非循环单链表
void adverse()
{

}

    // 把非循环单链表置为空
    void clear();

    // 删除非循环单链表中数据域为e的第一个结点
    Status deleteElem(ElemType e);

    // 删除非循环单链表中的重复值
    void deleteRepeat();

    // 取非循环单链表的第i个结点
    status getElem(int i, ElemType & e);

    // 取第一个结点的指针
    nodeP getHead();

    // 求非循环单链表结点的个数
    int getLength();

    // 在第i个结点之前插入一个数据域为e的结点
    Status insert(int i, ElemType e);

    // 判断非循环单链表是否为空
    bool isEmpty();

    // 查找第1个与e满足compare()关系的结点
    Status locateElem(ElemType e, Status (*compare)(ElemType, ElemType), int & i);

    // 返回某结点后继的数据域
    Status nextElem(ElemType e, ElemType & next_e);

    // 重载赋值运算符的定义
    linkList<ElemType> operator = (LinkList<ElemType> rightL);

    // 返回某结点前驱的数据域
    Status priorElem(ElemType e, ElemType & prior_e);

    // 非循环单链表析构函数
    ~linkList();

    // 非循环单链表拷贝初始化构造函数
    linkList(const linkNode<ElemType> & linkNode);

    // 非循环单链表构造函数
    linkList();
