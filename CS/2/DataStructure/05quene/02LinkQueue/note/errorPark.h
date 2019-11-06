#ifndef PARK_H
    #define PARK_H
    #include "linkQueue.h"
    #include "../../04stack/2SqStack/SqStack.h"
    #include <string>
    #include <ctime>
    const int parkFirstSize = 100;
    const int parkFirstFee = 100;


class park
{
public:
    class carNode
    {
    public:
        string name;

        int time;

        carNode(){
            name = "";
            time = 0;
        };
    };

    class parkStack:public SqStack<carNode>
    {
    public:
        void display(ostream& out) const;

        void read(istream& in);

        void setSize(int n);
    };

    class parkQueue:public linkQueue<string>
    {
    public:
        void display(ostream& out) const;

        void read(istream& in);
    };

protected:
    int parkSize = parkFirstSize;

    int parkFee = parkFirstFee;

    int carInPark = 0;

    parkStack ps;
    
    parkQueue pq;

public:
    void display(ostream& out) const;

    void read(istream& in);

    void getByRand(int display);

    bool isEmpty();

    bool isFull();

    void setSize(int n);

    void setFee(int n);

    int outputFee();

    void clear();
};

void park::clear()
{
    parkSize = parkFirstSize;
    parkFee = parkFirstFee;
    carInPark = 0;
    ps.clear();
    pq.clear();
}

void park::getByRand(int display)
{
    clear();
    int n1 = rand() % 23 + 1;
    int n2 = rand() % 23 + 1;

    char s[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if(display)
    {
        cout << "                     进入停车场内停车信息" << endl << endl;
        cout << "                 车牌号码            进入时间" << endl;
    }
    fei(1, n1)
    {
        char xh[] = "[ i]";
        carNode tmp;
        tmp.name = 'A' + rand() % 26;
        tmp.time = clock();
        fei(1, 9)
            tmp.name += s[rand() % (26 + 10)];
        ps.push(tmp);
        if(i < 10)
            xh[2] = i;
        else
        {
            xh[1] = i / 10;
            xh[2] = i % 10;
        }
        if(display)
        {
            cout << "            " << xh << " " << tmp.name << "            " << tmp.time << endl;
        }
    }
    if(display)
        cout << "           停车场外候车信息" << endl;
    fei(1, n2)
    {
        string tmp;
        tmp = 'A' + rand() % 26;
        fei(1, 9)
            tmp += s[rand() % (26 + 10)];
        pq.enQueue(tmp);
        if(display)
            cout << "             " << tmp << endl;
    }
}

void park::setSize(int n)
{  
    parkSize = n;
    ps.setSize(n);
}

void park::setFee(int n)
{
    parkFee = n;
}

int park::outputFee()
{
    return parkFee;
}

bool park::isEmpty()
{
    if(carInPark == 0)
        return true;
    else
        return false;
}

void park::display(ostream& out) const
{
    int n = ps.getLength();
    if(n == 0)
    {
        cout << "         当前没有车停在停车场内" << endl;
        return ;
    }
    else
    {
        cout << "                   停车场内停车车辆信息" << endl << endl;
        cout << "               车牌号码            进入时间" << endl;
        if(n == 1)
        {
            park::carNode tmp;
            ps.pop(tmp);
            cout << "  baps./top->[ 1] " << tmp.name << "           " << tmp.time << endl;
        }
        else
        {
            parkStack tmps;
            park::carNode tmp;
            fei(1, n)
            {
                this->pop(tmp);
                tmps.push(tmp);
                char xh[] = "[ i]";
                if(i < 10)
                    xh[2] = i;
                else
                {
                    xh[1] = i / 10;
                    xh[2] = i % 10;
                }
                if(i == 1)
                {
                    cout << "      base->" << xh << " " << tmp.name << "           " << tmp.time << endl;
                }
                else if(i == n)
                {
                    cout << "       top->" << xh << " " << tmp.name << "           " << tmp.time << endl;
                }
                else
                {
                
                    cout << "            " << xh << " " << tmp.name << "            " << tmp.time << endl;
                }
            }
            while(!tmps.isEmpty())
            {
                tmps.pop(tmp);
                ps.push(tmp);
            }
        }
    }
}

ostream& operator <<(ostream& out, const park& x)
{
    x.display(out);
    return out;
}

void park::parkStack::setSize(int n)
{
    stackSize = n;
}

#endif
