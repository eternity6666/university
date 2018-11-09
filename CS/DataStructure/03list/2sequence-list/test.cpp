#include <iostream>
#include <iomanip>
#include "sequence.h"
using namespace std;

SqList<int> a, b;

void menu();

void insert();
void isEmpty();
void getLength();
void getElem();
void locateElem();
void priorElem();
void nextElem();
void deleteElem();
void copy();
void clear();
void newList();
void inputList();
void initList();

/*
void setWay();
void stu();
*/

int main()
{
    a.newList();
    while(1)
    {
        system("clear");
        menu();
        cout << " ********************************************************** " << endl;
        cout << " 当前顺序表有" << a.getLength() << "个元素,分别为:" << endl;
        a.output(); 
        cout << " ********************************************************** " << endl;

        cout << " 请选择你要操作的代码<1-13>:";
        int code;
        cin >> code;

        switch(code)
        {
        case 1:
            insert();
            break;
        case 2:
            isEmpty();
            break;
        case 3:
            getLength();
            break;
        case 4:
            getElem();
            break;
        case 5:
            locateElem();
            break;
        case 6:
            priorElem();
            break;
        case 7:
            nextElem();
            break;
        case 8:
            deleteElem();
            break;
        case 9:
            copy();
            break;
        case 10:
            clear();
            break;
        case 11:
            newList();
            break;
        case 12:
            initList();
            break;
        case 13:
            inputList();
            break;
        /*
        case 14:
            setWay();
            break;
        case 15:
            stu();
            break;
        */
        default:
            cout << " 请输入1-13之间的整数" << endl;
            break;
        }
        
        cout << " 输入Y继续，输入N结束:";
        char c;
        cin >> c;
        if(c == 'N' || c == 'n')
            break;
    }
    return 0;
}

void initList()
{
    cout << " ********* && 用已有的顺序表初始化另一个顺序表 && ********* " << endl;
    cout << " 当前的顺序表初始化另一个顺序表为: " << endl;
    b = a;
    b.output();
    cout << " ********************************************************** " << endl;
}

void copy()
{
    cout << " ********* && 把一个顺序表赋值个另一个顺序表 && *********** " << endl;
    cout << " 另一个顺序表赋值给当前顺序表为: " << endl;
    a = b;
    a.output();
    cout << " ********************************************************** " << endl;
}

void getElem()
{
    cout << " *************** && 求顺序表中元素的个数 && *************** " << endl;
    cout << " 请输入你想取的元素的序号(1-";
    int n = a.getLength();
    cout << n << "):";
    int i;
    cin >> i;
    if(i < 1 || i > n)
        cout << " 您输入了非法序号 " << endl;
    else
    {
        int e;
        a.getElem(i, e);
        cout << " 你想取的第" << i <<"个元素的值为:" << e << endl;
    }
    cout << " ********************************************************** " << endl;
}

void locateElem()
{
    cout << " *** && 查找第1个与某元素满足compare()关系元素的序号 && *** "<< endl;
    int x, e;
    cout << " 查找等于某个元素的操作 " << endl;
    cout << " 请输入你想查找的元素:";
    cin >> x;
    cout << " 你想查找第一个等于" << x << "的元素序号为";
    e = a.locateElem(x, equal);
    if(e == -1)
        cout << " 未找到 " << endl;
    else
        cout << e << endl;
    cout << endl;

    cout << " 查找大于某个元素的操作 " << endl;
    cout << " 请输入你想查找的元素:";
    cin >> x;
    cout << " 你想查找第一个大于" << x << "的元素序号为";
    e = a.locateElem(x, great);
    if(e == -1)
        cout << " 未找到 " << endl;
    else
        cout << e << endl;
    cout << endl;
    
    cout << " 查找小于某个元素的操作 " << endl;
    cout << " 请输入你想查找的元素:";
    cin >> x;
    cout << " 你想查找第一个小于" << x << "的元素序号为";
    e = a.locateElem(x, Less);
    if(e == -1)
        cout << " 未找到 " << endl;
    else
        cout << e << endl;
    cout << endl;
    cout << " ********************************************************** " << endl;
}

void nextElem()
{
    cout << " ****************** && 返回某元素的后继 && **************** " << endl;
    cout << " 请问你想查找哪个元素的后继:" << endl;
    int i;
    cout << " ";
    cin >> i;
    int e;
    if(a.nextElem(i, e))
    {
        cout << " 你想查找元素" << i << "的后继为";
        cout << e << endl;
    }
    else
        cout << " 请检查你的输入 " << endl;
    cout << " ********************************************************** " << endl;
}

void priorElem()
{
    cout << " **************** && 返回某元素的前驱 && ****************** " << endl;
    cout << " 请问你想查找哪个元素的前驱:" << endl;
    int i;
    cout << " ";
    cin >> i;
    int e;
    if(a.priorElem(i, e))
    {    
        cout << " 你想查找元素" << i << "的前驱为";
        cout << e << endl;
    }
    else
        cout << " 请检查你的输入 " << endl;
    cout << " ********************************************************** " << endl;
}

void deleteElem()
{
    cout << " ******************* && 删除第i个元素 && ****************** " << endl;
    int n = a.getLength();
    cout << " 请输入你想要删除元素的序号<1-" << n << ">:";
    int i;
    cin >> i;
    if(i < 1 || i > n)
        cout << " 您输入了非法序号 " << endl;
    else
    {
        cout << " 你想删除的第" << i << "个元素的值为:";
        int e;
        a.deleteElem(i, e);
        cout << e << endl;
        cout << " 删除后的顺序表为" << endl;
        a.output();
    }
    cout << " ********************************************************** " << endl;
}

void newList()
{
    cout << " ****** && 随机生成顺序表(元素值为0到99之间的整数) && ***** "<< endl; 
    cout << " 用以下随机数作为当前顺序表的元素: " << endl;
    a.newList();
    cout << endl;
    cout << " 随机生成的顺序表为: " << endl;
    a.output();
    cout << " ********************************************************** " << endl;
}

void clear()
{
    cout << " **************** && 把当前的顺序表置空 && **************** " << endl;
    a.clear();
    cout << " 当前顺序表置空后，元素的个数为:" << a.getLength() << endl;
    cout << " ********************************************************** " << endl;
}

void inputList()
{
    cout << " ******************** && 输入顺序表 && ******************** " << endl;
    cout << " 请输入顺序表中的元素个数:";
    int i;
    cin >> i;
    cout << " 请输入顺序表中的元素:" << endl;
    a.input(i);
    cout << " 新输入的顺序表如下:" << endl;
    a.output();
    cout << " ********************************************************** " << endl;
}

void insert()
{
    cout << " *********** && 在第i个元素之前插入一个元素 && ************ " << endl;
    cout << " 请输入你要在第几个元素之前插入元素:";
    int i;
    cin >> i;
    int n = a.getLength();
    if(i < 1 || i > n)
        cout << " 您输入了非法序号 " << endl;
    else
    {
        cout << " 请输入你要插入的元素的值:";            
        int e;
        cin >> e;
        cout << " 你要在第" << i << "个元素前插入元素" << e << endl;
        a.addElem(e, i);
        cout << " 插入后的顺序表为:" << endl;
        a.output();
    }
    cout << " ********************************************************** " << endl;
}

void isEmpty()
{
    cout << " **************** && 判断顺序表是否为空 && **************** " << endl;
    if(a.isEmpty())
        cout << " 当前顺序表为空" << endl;
    else
        cout << " 当前顺序表不为空" << endl;
    cout << " ********************************************************** " << endl;
}

void getLength()
{
    cout << " ************** && 求顺序表中元素的个数 && **************** " << endl;
    cout << " 顺序表元素的个数为:" << a.getLength() << endl;
    cout << " ********************************************************** " << endl;
}

void menu()
{
    cout << " ********************* 测试顺序表的操作 ******************* " << endl;
    cout << " 1.  在第i个元素之前插入一个元素" << endl;
    cout << " 2.  判断顺序表是否为空" << endl;
    cout << " 3.  求顺序表中元素的个数" << endl;
    cout << " 4.  取第i个元素" << endl;
    cout << " 5.  查找第1个与某元素满足compare()关系元素的序号" << endl;
    cout << " 6.  返回某元素的前驱" << endl;
    cout << " 7.  返回某元素的后继" << endl;
    cout << " 8.  删除第i个元素" << endl;
    cout << " 9.  把一个顺序表赋值给另一个顺序表" << endl;
    cout << " 10. 把顺序表置空" << endl;
    cout << " 11. 随机生成顺序表(元素值为0到99之间的整数)" << endl;
    cout << " 12. 用已有的顺序表初始化另一个顺序表" << endl;
    cout << " 13. 输入顺序表" << endl;
    // cout << " 14. 两个顺序表的并交集运算" << endl;
    // cout << " 15. 学生信息管理系统(顺序表的应用)" << endl;
    cout << endl;
}

