#include <iostream>
#include "sequence.h"
using namespace std;

SqList<int> a;

void menu();
void insert();
void isEmpty();
void getLength();
void getElem();
void locateElem();
void nextElem();
void priorElem();
void deleteElem();
void fuzh();
void clear();
void newList();
void inputList();
void setWay();
void stu();

int main()
{
    menu();
    while(1)
    {
        cout << " ******************************************** " << endl;
        cout << " 当前顺序表有" << a.getLength() << "个元素,分别为:" << endl;
        a.output(); 
        cout << " ******************************************** " << endl;

        cout << "请选择你要操作的代码<1-15>:" << endl;
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
        /*
        case 5:
            locateElem();
            break;
        case 6:
            nextElem();
            break;
        case 7:
            priorElem();
            break;
        case 8:
            deleteElem();
            break;
        case 9:
            fuzh();
            break;
        case 10:
            clear();
            break;
        */
        case 11:
            newList();
            break;
        /*
        case 12:
            initList();
            break;
        case 13:
            inputList();
            break;
        case 14:
            setWay();
            break;
        case 15:
            stu();
            break;
        */
        default:
            cout << "请输入1-15之间的整数" << endl;
            break;
        }
        
        cout << "输入Y继续，输入N结束:" << endl;
        char c;
        cin >> c;
        if(c == 'N' || c == 'n')
            break;
    }
    return 0;
}

void getElem()
{
    cout << " ******** && 求顺序表中元素的个数 && ******** " << endl;
    cout << "　请输入你想取的元素的序号(1-";
    int n = a.getLength();
    cout << n << "):";
    int code;
    cin >> code;
    int e;
    a.getElem(code, e);
    cout << " 你想取的第" << code <<"个元素的值为:" << e << endl;
    cout << " ******************************************** " << endl;
}

/*
void locateElem()
{

}

void nextElem()
void priorElem()
void deleteElem()
void fuzh()
void clear()
void newList()
void setWay()
void stu()
*/

void inputList()
{
    cout << " *************** && 输入顺序表 && ************ " << endl;
    cout << " 请输入顺序表中的元素个数:";
    int n;
    cin >> n;
    cout << " 请输入顺序表中的元素:";
    a.input();
    cout << " 新输入的顺序表如下:";
    a.output();
}

void insert()
{
    cout << " ***** && 在第i个元素之前插入一个元素 && ***** " << endl;
    cout << " 请输入你要在第几个元素之前插入元素:";
    int n;
    cin >> n;
    cout << " 请输入你要插入的元素的值:";            
    int e;
    cin >> e;
    cout << " 你要在第" << i << "个元素前插入元素" << e << endl;
    a.addElem(e, i);
    cout << " 插入后的顺序表为:" << endl;
    a.output(n);
    cout << " ********************************************* " << endl;
}

void isEmpty()
{
    cout << " ********* && 判断顺序表是否为空 && ********** " << endl;
    if(a.isEmpty())
        cout << "当前顺序表为空" << endl;
    else
        cout << "当前顺序表不为空" << endl;
    cout << " ********************************************* " << endl;
}

void getLength()
{
    cout << " ******** && 求顺序表中元素的个数 && ********* " << endl;
    cout << "   顺序表元素的个数为:" << a.getLength() << endl;
    cout << " ********************************************* " << endl;
}

void menu()
{
    cout << " ******** 测试顺序表的操作 ******** " << endl;
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
    cout << " 14. 两个顺序表的并交集运算" << endl;
    cout << " 15. 学生信息管理系统(顺序表的应用)" << endl;
    cout << endl;
}

