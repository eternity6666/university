#include <iostream>
#include "mySqQueue.h"
using namespace std;

mySqQueue<int> a, b;

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

int main()
{
    while(1)
    {
        system("clear");
        menu();
        if(a.isEmpty())
            cout << " 当前循环顺序队列为空" << endl;
        else
        {
            cout << " 当前循环顺序队列为: " << endl;
            a.display();
        }
        cout << " -------------------------------------------------------" << endl;
        cout << " 请选择你要操作的代码<1-11>: ";
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
            default:
                cout << " 结束" << endl;
                return 0;
        }
        cout << " 还继续吗<Y.继续/tN.结束>?";
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
    cout << " ------------- && 进队列(在循环顺序队列队尾插入元素) && ----------- " << endl;
    if(a.isFull())
        cout << " 当前对列已满,无法入队." << endl;
    else
    {
        cout << " 请输入你要入队的元素: ";
        int n;
        cin >> n;
        a.enQueue(n);
        cout << " 在队尾插入元素" << n << "后， 循环顺序队列为: " << endl;
        a.display();
    }
    cout << " ------------------------------------------------------------------ " << endl;
}

void code2()
{
    cout << " ------------- && 出对列(删除循环顺序队列队头元素) && ------------- " << endl;
    if(a.isEmpty())
        cout << " 当前队列为空,无法出队." << endl;
    else
    {
        int e;
        a.deQueue(e);
        cout << "删除队头的元素" << e << "后，";
        if(a.isEmpty())
            cout << "循环顺序队列为空" << endl;
        else
        {
            cout << "循环顺序队列为: " << endl;
            a.display();
        }
    }
    cout << " ------------------------------------------------------------------ " << endl;
}

void code3()
{
    cout << " ----------------- && 读取循环顺序队列队头元素 && ----------------- " << endl;
    if(a.isEmpty())
        cout << " 当前队列为空,无法读取." << endl;
    else
    {
        int e;
        a.getFront(e);
        cout << " 读队头的元素" << e << "后，循环顺序队列为: " << endl;
        a.display();
    }
    cout << " ------------------------------------------------------------------ " << endl;
}

void code4()
{
    cout << " ----------------- && 判断循环顺序队列是否为空 && ----------------- " << endl;
    if(a.isEmpty())
        cout << " 当前队列为空 " << endl;
    else
        cout << " 当前队列不为空 " << endl;
    cout << " ------------------------------------------------------------------ " << endl;
}

void code5()
{
    cout << " ----------------- && 判断循环顺序队列是否已满 && ----------------- " << endl;
    if(a.isFull())
        cout << " 当前队列已满 " << endl;
    else
        cout << " 当前队列未满 " << endl;
    cout << " ------------------------------------------------------------------ " << endl;
}

void code6()
{
    cout << " --------------- && 求循环顺序队列中元素的个数 && ----------------- " << endl;
    cout << " 循环顺序队列中元素的个数为: " << a.getLength() << endl;
    cout << " ------------------------------------------------------------------ " << endl;
}

void code7()
{
    cout << " -------- && 把一个循环顺序队列赋值给另一个循环顺序队列 && -------- " << endl;
    mySqQueue<int> c;
    c.getByRand(0);
    a = c;
    cout << " 另一个循环顺序队列赋值给当前循环顺序队列为: " << endl;
    a.display();
    cout << " ------------------------------------------------------------------ " << endl;
}

void code8()
{
    cout << " -------------------- && 把循环顺序队列置空 && -------------------- " << endl;
    a.clear();
    cout << " 当前循环顺序队列置空后,元素的个数为: " << a.getLength() << endl;
    cout << " ------------------------------------------------------------------ " << endl;
}

void code9()
{
    cout << " ----------------- && 随机生成循环顺序队列 && --------------------- " << endl;
    cout << " 用如下随机数生成循环顺序队列:\n";
    a.getByRand(1);
    cout << " 随机生成的循环顺序队列为:\n";
    a.display();
    cout << " ------------------------------------------------------------------ " << endl;
}

void code10()
{
    cout << " ------ && 用已有的循环顺序队列初始化另一个新循环顺序队列 && ------ " << endl;
    b = a;
    cout << " 当前循环顺序队列初始化另一个循环顺序队列为:\n";
    b.display();
    cout << " ------------------------------------------------------------------ " << endl;
}

void code11()
{
    cout << " ------------------------------------------------------------------ " << endl;
}

void menu()
{
    cout << " -------------------- && 测试循环顺序队列的操作 && -----------------" << endl;
    cout << "    1. 进队列(在循环顺序队列队尾插入元素)\n"
         << "    2. 出队列(删除循环顺序队列队头元素)\n"
         << "    3. 读循环顺序队列队头的元素到e\n"
         << "    4. 判断循环顺序队列是否为空\n"
         << "    5. 判断循环顺序队列是否已满\n"
         << "    6. 求循环顺序队列中元素的个数\n"
         << "    7. 把一个循环顺序队列赋值给另一个循环顺序队列\n"
         << "    8. 把循环顺序队列置空\n"
         << "    9. 随机生成循环顺序队列\n"
         << "   10. 用已有的循环顺序队列初始化另一个新循环顺序队列\n"
         << "   11. 运动会比赛安排(循环顺序队列的应用)\n"
         << " 其他. 结束 " << endl;
    cout << " ------------------------------------------------------------------ " << endl;
}

