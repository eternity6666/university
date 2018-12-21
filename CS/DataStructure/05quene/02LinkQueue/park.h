#ifndef PARK_H
    #define PARK_H
    #include "../../04stack/01SqStack/SqStack.h"
    #include <string>
    #include <ctime>
    #include "linkQueue.h"
    const int parkFirstSize = 100;
    const int parkFirstFee = 100;

template <typename elemtype>
class parkStack:public SqStack<elemtype>
{
public:
    void setSize(int n);

    elemtype getElem(int n);
};

template <typename elemtype>
void parkStack<elemtype>::setSize(int n)
{
    this->stackSize = n;
}

template <typename elemtype>
elemtype parkStack<elemtype>::getElem(int n)
{
    return this->base + n;
}

class park
{
public:
    class carNode
    {
    public:
        string name;

        int time;

        carNode()
        {
            name = "";
            time = 0;
        }
    };

protected:
    int parkSize = parkFirstSize;

    int parkFee = parkFirstFee;

    int carInPark = 0;

    parkStack<carNode> s;

    linkQueue<string> q;

public:
    void carIn(string name);

    void carOut(int n);

    int inCarNum();

    void display(ostream& out) ;

    void getByRand(int display);

    bool isEmpty();

    bool isFull();

    void setSize(int n);

    void setFee(int n);

    int outputFee();

    int caculateFee(int time);

    void clear();
};

void park::carIn(string name)
{
    q.enQueue(name);
}

void park::carOut(int n)
{
    parkStack<carNode> tmps;
    cout << " 停车场停放在" << n << "号位置上车辆准备离开. " << endl;
    cout << " (1)";
    carNode tmp;
    if(n < carInPark)
    {
        cout << " 下列车牌号的车辆先退出停车场让路: " << endl;
        for(int i = 0; i < carInPark - n - 1; i++)
        {
            s.pop(tmp);
            tmps.push(tmp);
            cout << "          " << tmp.name << endl;
        }
        cout << " (2)";
    }
    s.pop(tmp);
    int nowTime = clock();
    cout << " 场内停放在" << n << "号位置上车牌号为" << tmp.name << "车辆离开。" << endl;
    cout << "     停车时间为: " << nowTime - tmp.time; 
    cout << "     应交纳停车费为: " << caculateFee(nowTime - tmp.time) << endl;;
    if(n < carInPark)
    {
        cout << " (3) 先前退出的车辆再进停车场. " << endl;
        while(!tmps.isEmpty())
        {
            carNode temp;
            tmps.pop(temp);
            s.push(temp);
        }
        cout << " (4)";
    }
    int qn = q.getLength();
    if(qn > 0)
    {
        if(n == carInPark)
        {
            cout << " (2)";
        }
        string newCarName;
        q.deQueue(newCarName);
        cout << " 场外车牌号为" << newCarName << "的车辆现在进停车场. " << endl;
        carNode newCar;
        newCar.time = clock();
        newCar.name = newCarName;
        s.push(newCar);
    }
    else
        cout << " (2) 由于场外并无车辆, 因此无车辆进入" << endl;
}

int park::inCarNum()
{
    return carInPark;
}

void park::display(ostream& out)
{
    int sn = s.getLength();
    if(sn == 0)
    {
        cout << " 当前停车场内停车车辆" << endl;
    }
    else
    {
        cout << "                     停车场内停车车辆信息" << endl;
        cout << "                 车牌号码            进入时间" << endl;
        if(sn == 1)
        {
            carNode tmp;
            s.getTop(tmp);
            cout << "  base/top->[ 1] " << tmp.name << "            " << tmp.time << endl;
        }
        else
        {
            parkStack<park::carNode> tmps;
            park::carNode tmp;
            fei(1, sn)
            {
                s.pop(tmp);
                tmps.push(tmp);
                char xh[] = "[ i]";
                if(i < 10)
                    xh[2] = '0' + i;
                else
                {
                    xh[1] = '0' + i / 10;
                    xh[2] = '0' + i % 10;
                }
                if(i == 1)
                {
                    cout << "      base->" << xh << " " << tmp.name << "            " << tmp.time << endl;
                }
                else if(i == sn)
                {
                    cout << "       top->" << xh << " " << tmp.name << "            " << tmp.time << endl;
                }
                else
                {
                
                    cout << "            " << xh << " " << tmp.name << "            " << tmp.time << endl;
                }
            }
            while(!tmps.isEmpty())
            {
                tmps.pop(tmp);
                s.push(tmp);
            }
        }
    }

    int qn = q.getLength();
    if(qn == 0)
    {
        cout << " 当前停车场外无候车车辆" << endl;
    }
    else
    {
        cout << "                     停车场内停车车辆信息" << endl;
        cout << "                            车牌号" << endl;
        if(qn == 1)
        {
            string tmp;
            q.getFront(tmp);
            cout << "                front/rear->" << tmp << endl;
        }
        else
        {
            linkQueue<string> tmps;
            string tmp;
            fei(1, qn)
            {
                q.deQueue(tmp);
                tmps.enQueue(tmp);
                if(i == 1)
                    cout << "                     front->" << tmp << endl;
                else if(i == qn)
                    cout << "                      rear->" << tmp << endl;
                else
                    cout << "                            " << tmp << endl;
            }
            fei(1, qn)
            {
                tmps.deQueue(tmp);
                q.enQueue(tmp);
            }
        }
    }
}

ostream& operator <<(ostream& out, park& x)
{
    x.display(out);
    return out;
}

void park::getByRand(int display)
{
    clear();
    int n1 = rand() % 23 + 1;
    int n2 = rand() % 23 + 1;

    char sname[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if(display)
    {
        cout << "                 进入停车场内停车信息" << endl;
        cout << "             车牌号码            进入时间" << endl;
    }
    fei(1, n1)
    {
        char xh[] = "[ i]";
        carNode tmp;
        tmp.name = 'A' + rand() % 26;
        tmp.time = clock();
        fei(1, 9)
            tmp.name += sname[rand() % (26 + 10)];
        s.push(tmp);
        carInPark++;
        if(i < 10)
            xh[2] = '0' + i;
        else
        {
            xh[1] = '0' + i / 10;
            xh[2] = '0' + i % 10;
        }
        if(display)
        {
            cout << "        " << xh << " " << tmp.name << "            " << tmp.time << endl;
        }
    }
    if(display)
        cout << "       停车场外候车信息" << endl;
    fei(1, n2)
    {
        string tmp;
        tmp = 'A' + rand() % 26;
        fei(1, 9)
            tmp += sname[rand() % (26 + 10)];
        q.enQueue(tmp);
        if(display)
            cout << "             " << tmp << endl;
    }
}

bool park::isEmpty()
{
    if(carInPark == 0)
        return true;
    else
        return false;
}

bool park::isFull()
{
    if(carInPark == s.getStackSize())
        return true;
    else
        return false;
}

void park::setSize(int n)
{  
    parkSize = n;
    s.setSize(n);
}

void park::setFee(int n)
{
    parkFee = n;
}

int park::outputFee()
{
    return parkFee;
}

int park::caculateFee(int time)
{
    return parkFee * time;
}

void park::clear()
{
    carInPark = 0;
    s.clear();
    q.clear();
}
#endif
