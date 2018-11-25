#include <iostream>
#include <iomanip>
#include "setSqList.h"
#include <vector>
#include "student.h"
using namespace std;

mySqList<int> a, b;
vector<student> x, y;

void menu();
void code1();
void code2();
void code3();
void code4();
void code5();
void code6();
void code7();
void code8();
void code9();
void code10();
void code11();
void code13();
void code12();
void code14();
void code15();
void code1501();
void code1502();
void code1503();
void code1504();
void code1505();
void code1506();
void code1507();
void code1508();
void code1509();
void code1510();
void code1511();
void code1512();

int main()
{
    a.newList(1);
    while(1)
    {
        system("clear");
        menu();
        cout << " ********************************************************** " << endl;
        cout << " 当前顺序表有" << a.getLength() << "个元素,分别为:" << endl;
        a.output(); 
        cout << " ********************************************************** " << endl;

        cout << " 请选择你要操作的代码<1-15>:";
        int n;
        cin >> n;
        switch(n)
        {
        case 1:
            code1();
            break;
        case 2:
            code2();
            break;
        case 3:
            code3();
            break;
        case 4:
            code4();
            break;
        case 5:
            code5();
            break;
        case 6:
            code6();
            break;
        case 7:
            code7();
            break;
        case 8:
            code8();
            break;
        case 9:
            code9();
            break;
        case 10:
            code10();
            break;
        case 11:
            code11();
            break;
        case 12:
            code12();
            break;
        case 13:
            code13();
            break;
        case 14:
            code14();
            break;
        case 15:
            code15();
            break;
        default:
            cout << " 结束" << endl;
            return 0;
        }
        cout << " 还继续吗<Y.继续\tN.结束>? ";
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y')
            continue;
        else
            break;
    }
    return 0;
}

void code1()
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

void code2()
{
    cout << " **************** && 判断顺序表是否为空 && **************** " << endl;
    if(a.isEmpty())
        cout << " 当前顺序表为空" << endl;
    else
        cout << " 当前顺序表不为空" << endl;
    cout << " ********************************************************** " << endl;
}

void code3()
{
    cout << " ************** && 求顺序表中元素的个数 && **************** " << endl;
    cout << " 顺序表元素的个数为:" << a.getLength() << endl;
    cout << " ********************************************************** " << endl;
}

void code4()
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

void code5()
{
    cout << " *** && 查找第1个与某元素满足compare()关系元素的序号 && *** "<< endl;
    int x, e;
    cout << " 查找等于某个元素的操作 " << endl;
    cout << " 请输入你想查找的元素:";
    cin >> x;
    e = a.locateElem(x, equal);
    if(e == -1)
        cout << " 未找到 " << endl;
    else
        cout << " 你想查找第一个等于" << x << "的元素序号为" << e << endl;
    cout << endl;

    cout << " 查找大于某个元素的操作 " << endl;
    cout << " 请输入你想查找的元素:";
    cin >> x;
    e = a.locateElem(x, great);
    if(e == -1)
        cout << " 未找到 " << endl;
    else
        cout << " 你想查找第一个大于" << x << "的元素序号为" << e << endl;
    cout << endl;
    
    cout << " 查找小于某个元素的操作 " << endl;
    cout << " 请输入你想查找的元素:";
    cin >> x;
    e = a.locateElem(x, Less);
    if(e == -1)
        cout << " 未找到 " << endl;
    else
        cout << " 你想查找第一个小于" << x << "的元素序号为" << e << endl;
    cout << endl;
    cout << " ********************************************************** " << endl;
}

void code6()
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

void code7()
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

void code8()
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

void code9()
{
    cout << " ********* && 把一个顺序表赋值个另一个顺序表 && *********** " << endl;
    cout << " 另一个顺序表赋值给当前顺序表为: " << endl;
    a = b;
    a.output();
    cout << " ********************************************************** " << endl;
}

void code10()
{
    cout << " **************** && 把当前的顺序表置空 && **************** " << endl;
    a.clear();
    cout << " 当前顺序表置空后，元素的个数为:" << a.getLength() << endl;
    cout << " ********************************************************** " << endl;
}

void code11()
{
    cout << " ****** && 随机生成顺序表(元素值为0到99之间的整数) && ***** "<< endl; 
    cout << " 用以下随机数作为当前顺序表的元素: " << endl;
    a.newList(1);
    cout << endl;
    cout << " 随机生成的顺序表为: " << endl;
    a.output();
    cout << " ********************************************************** " << endl;
}

void code12()
{
    cout << " ********* && 用已有的顺序表初始化另一个顺序表 && ********* " << endl;
    cout << " 当前的顺序表初始化另一个顺序表为: " << endl;
    b = a;
    b.output();
    cout << " ********************************************************** " << endl;
}

void code13()
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

void code14()
{
    cout << " ************** && 两个顺序表的并交集运算 && ************** " << endl;
    cout << " 第一个顺序表为: " << endl;
    a.output();
    cout << " 第二个顺序表为: " << endl;
    b.newList(0);
    b.output();
    cout << " 以上两顺序表的" << endl;
    cout << "     并集为:" << endl;
    mySqList<int> c;
    c = unionSet(a, b);
    c.output();
    cout << "     交集为:" << endl;
    c = intersectionSet(a, b);
    c.output();
    cout << "     差集为:" << endl;
    c = dirfferenceSet(a, b);
    c.output();
    cout << " ********************************************************** " << endl;
}

void code15()
{
    x = randStu();
    y = randStu();
    while(1)
    {
        system("clear");
        cout << " ************* && 学生信息管理(顺序表的应用) && *********** " << endl;
        cout << " 15. 1. 在第i个学生之前插入新学生\n"
             << " 15. 2. 判断学生表是否为空\n"
             << " 15. 3. 求学生表中学生的人数\n"
             << " 15. 4. 返回学生表中第i个学生\n"
             << " 15. 5. 返回某学生的前驱\n"
             << " 15. 6. 返回某学生的后继\n"
             << " 15. 7. 删除学生表的第i个学生\n"
             << " 15. 8. 把一个学生表赋值给另一个学生表\n"
             << " 15. 9. 设置学生表为空表\n"
             << " 15.10. 随机生成学生表\n"
             << " 15.11. 用已有的学生表初始化另一个学生表\n"
             << " 15.12. 输入学生表\n"
             << "  其他. 结束\n" << endl;
        cout << " ********************************************************** " << endl;
        if(x.size())
        {
            cout << " 当前学生表(采用顺序表存储)有" << "个学生, 分别为: " << endl;
            cout << " 学号\t姓名\t语文\t英语\t数学\t平均分\t总分\n";
            output(x);
        }
        else
            cout << " 当前学生表为空" << endl;
        cout << " ********************************************************** " << endl;
        cout << " 请选择你要操作的代码<1-12>: ";
        int n;
        cin >> n;
        switch(n)
        {
        case 1:
            code1501();
            break;
        case 2:
            code1502();
            break;
        case 3:
            code1503();
            break;
        case 4:
            code1504();
            break;
        case 5:
            code1505();
            break;
        case 6:
            code1506();
            break;
        case 7:
            code1507();
            break;
        case 8:
            code1508();
            break;
        case 9:
            code1509();
            break;
        case 10:
            code1510();
            break;
        case 11:
            code1511();
            break;
        case 12:
            code1512();
            break;
        default:
            cout << " 结束" << endl;
            return ;
        }
        cout << " 还继续吗<Y.继续\tN.结束>? ";
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y')
            continue;
        else
            break;
    }
}

void code1501()
{
    cout << "  " << endl;
    cout << " ********************************************************** " << endl;
}

void code1502()
{

    cout << " ********************************************************** " << endl;
}

void code1503()
{

    cout << " ********************************************************** " << endl;
}

void code1504()
{

    cout << " ********************************************************** " << endl;
}

void code1505()
{

    cout << " ********************************************************** " << endl;
}

void code1506()
{

    cout << " ********************************************************** " << endl;
}

void code1507()
{

    cout << " ********************************************************** " << endl;
}

void code1508()
{

    cout << " ********************************************************** " << endl;
}

void code1509()
{

    cout << " ********************************************************** " << endl;
}

void code1510()
{
    cout << " ************ && 随机生成学生表中的学生信息 && ************ " << endl;
    x = randStu();
    cout << " 学号\t姓名\t语文\t英语\t数学\t平均分\t总分\n";
    output(x);
    cout << " ********************************************************** " << endl;
}

void code1511()
{
    cout << " ********* && 用已有的学生表初始化另一个学生表 && ********* " << endl;
    cout << " 当前的学生表初始化另一个学生表为:\n";
    y = x;
    cout << " 学号\t姓名\t语文\t英语\t数学\t平均分\t总分\n";
    output(y);
    cout << " ********************************************************** " << endl;
}

void code1512()
{
    cout << " ******************** && 输入学生表 && ******************** " << endl;
    cout << " 请输入学生表中的学生人数: ";
    int n;
    cin >> n;
    if(n < 0)
        cout << " 您的输入非法" << endl;
    else
    {
        x.clear();
        fei(1, n)
        {
            system("clear");
            if(x.empty())
                cout << " 当前学生表为空." << endl;
            else
            {
                cout << " 当前学生表(采用顺序存储)有" << x.size() << "个学生, 分别为:\n";
                cout << endl;
                cout << " 学号\t姓名\t语文\t英语\t数学\t平均分\t总分\n";
                output(x);
            }
            cout << " ********************************************************** " << endl;
            cout << " 请输入学生表第" << i << "个学生的信息:\n" << endl;
            student s;
            cout << "       学号: ";
            cin >> s.num;
            cout << "       姓名: ";
            cin >> s.name;
            cout << "       语文: ";
            cin >> s.Chinese;
            cout << "       英语: ";
            cin >> s.English;
            cout << "       数学: ";
            cin >> s.math;
            s.sum = s.math + s.Chinese + s.English;
            s.average = s.sum / 3;
            x.push_back(s);
        }
        system("clear");
        cout << " **************** && 重新输入一个学生表 && **************** " << endl;
        if(x.empty())
            cout << " 当前学生表为空." << endl;
        else
        {
            cout << " 当前学生表(采用顺序存储)有" << x.size() << "个学生, 分别为:\n";
            cout << endl;
            cout << " 学号\t姓名\t语文\t英语\t数学\t平均分\t总分\n";
            output(x);
        }
    }
    cout << " ********************************************************** " << endl;
}

void menu()
{
    cout << " ********************* 测试顺序表的操作 ******************* " << endl;
    cout << "    1. 在第i个元素之前插入一个元素" << endl;
    cout << "    2. 判断顺序表是否为空" << endl;
    cout << "    3. 求顺序表中元素的个数" << endl;
    cout << "    4. 取第i个元素" << endl;
    cout << "    5. 查找第1个与某元素满足compare()关系元素的序号" << endl;
    cout << "    6. 返回某元素的前驱" << endl;
    cout << "    7. 返回某元素的后继" << endl;
    cout << "    8. 删除第i个元素" << endl;
    cout << "    9. 把一个顺序表赋值给另一个顺序表" << endl;
    cout << "   10. 把顺序表置空" << endl;
    cout << "   11. 随机生成顺序表(元素值为0到99之间的整数)" << endl;
    cout << "   12. 用已有的顺序表初始化另一个顺序表" << endl;
    cout << "   13. 输入顺序表" << endl;
    cout << "   14. 两个顺序表的并交集运算" << endl;
    cout << "   15. 学生信息管理系统(顺序表的应用)" << endl;
    cout << " 其他. 结束" << endl;
    cout << endl;
}

