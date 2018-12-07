#ifndef MYSPORTS_H
    #define MYSPORTS_H
    #include "../../myhead.h"
    #include "mySqQueue.h"
class mySports
{
public:
    void arrangeSports();

    void displayCollusion() const;

    mySports(int a = 9, int b = 3, int c = 7, int *d = NULL, int *e = NULL);

    void read(istream& in);

    void display(ostream& out) const;

private:
    int game_num;
    int max;
    int anthelete_num;
    int *collusion;
    int *game_arrange;
};

void mySports::arrangeSports()
{
    int pre = game_num;
    int group = 0;
    int *clash;
    SqQueue<int> q;

    if(!collusion)
    {
        cout << " 没有项目冲突矩阵，比赛无法安排! " << endl;
        return ;
    }

    for(int i = 0; i < game_num; i++)
        q.enQueue(i);

    clash = new int[game_num];
    assert(clash != 0);

    while(!q.isEmpty())
    {
        int i;
        q.deQueue(i);
        if(i <= pre)
        {
            ++group;
            for(int j = 0; j < game_num; ++j)
                clash[j] = 0;
        }
        if(clash[i] == 0)
        {
            game_arrange[i] = group;
            for(int j = 0; j < game_num; ++j)
                clash[j] += *(collusion + i * game_num + j);
        }
        else
        {
            q.enQueue(i);
        }
        pre = i;
    }
}

void mySports::displayCollusion() const
{
    int i, j;

    cout << "     ";

    for(i = 0; i < game_num; i++)
    {
        char no[5] = "[ i]";
        if(i < 9)
            no[2] = i + '0';
        else
        {
            no[1] = i / 10 + '0';
            no[2] = i % 10 + '0';
        }

        cout.width(4);
        cout.fill(' ');
        cout.setf(ios::right, ios::adjustfield);
        cout << no;
    }
    cout << endl;

    for(int i = 0; i < game_num; i++)
    {
        char no[5] = "[ i]";
        cout << " ";
        if(i <= 9)
            no[2] = i + '0';
        else
        {
            no[1] = i / 10 + '0';
            no[2] = i % 10 + '0';
        }

        cout.width(4);
        cout.fill(' ');
        cout.setf(ios::right, ios::adjustfield);
        cout << no;
        for(j = 0; j < game_num; j++)
            cout << "  " << *(collusion + i * game_num + j) << " ";
        cout << endl;
    }
}

mySports::mySports(int a, int b, int c, int *d, int *e)
{
    game_num = a;
    max = b;
    anthelete_num = c;
    collusion = new int[game_num * game_num];
    assert(collusion != 0);

    *(collusion+0)=0;
    *(collusion+1)=1;
    *(collusion+2)=0;
    *(collusion+3)=0;
    *(collusion+4)=0;
    *(collusion+5)=1;
    *(collusion+6)=0;
    *(collusion+7)=0;
    *(collusion+8)=0;

    *(collusion+9)=1;
    *(collusion+10)=0;
    *(collusion+11)=0;
    *(collusion+12)=0;
    *(collusion+13)=1;
    *(collusion+14)=1;
    *(collusion+15)=0;
    *(collusion+16)=1;
    *(collusion+17)=1;

    *(collusion+18)=0;
    *(collusion+19)=0;
    *(collusion+20)=0;
    *(collusion+21)=0;
    *(collusion+22)=0;
    *(collusion+23)=1;
    *(collusion+24)=1;
    *(collusion+25)=0;
    *(collusion+26)=0;
    
    *(collusion+27)=0;
    *(collusion+28)=0;
    *(collusion+29)=0;
    *(collusion+30)=0;
    *(collusion+31)=1;
    *(collusion+32)=0;
    *(collusion+33)=0;
    *(collusion+34)=0;
    *(collusion+35)=1;
    
    *(collusion+36)=0;
    *(collusion+37)=1;
    *(collusion+38)=0;
    *(collusion+39)=1;
    *(collusion+40)=0;
    *(collusion+41)=0;
    *(collusion+42)=1;
    *(collusion+43)=0;
    *(collusion+44)=1;
    
    *(collusion+45)=1;
    *(collusion+46)=1;
    *(collusion+47)=1;
    *(collusion+48)=0;
    *(collusion+49)=0;
    *(collusion+50)=0;
    *(collusion+51)=1;
    *(collusion+52)=0;
    *(collusion+53)=0;
    
    *(collusion+54)=0;
    *(collusion+55)=0;
    *(collusion+56)=1;
    *(collusion+57)=0;
    *(collusion+58)=1;
    *(collusion+59)=1;
    *(collusion+60)=0;
    *(collusion+61)=0;
    *(collusion+62)=0;
    
    *(collusion+63)=0;
    *(collusion+64)=1;
    *(collusion+65)=0;
    *(collusion+66)=0;
    *(collusion+67)=0;
    *(collusion+68)=0;
    *(collusion+69)=0;
    *(collusion+70)=0;
    *(collusion+71)=0;
    
    *(collusion+72)=0;
    *(collusion+73)=1;
    *(collusion+74)=0;
    *(collusion+75)=1;
    *(collusion+76)=1;
    *(collusion+77)=0;
    *(collusion+78)=0;
    *(collusion+79)=0;
    *(collusion+80)=0;

    game_arrange = new int[game_num];
    assert(game_arrange != 0);

    for(int i = 0; i < game_num; i++)
        game_arrange[i] = 0;
}

void mySports::read(istream& in)
{
    int i, j, k;
    int x;
    int num;
    int temp[10];

    cout << " 请输入比赛项目数: ";
    in >> game_num;
    cout << " 请输入每个运动员最多允许参加的比赛项目数: ";
    in >> max;
    cout << " 请输入运动员人数: ";
    in >> anthelete_num;

    collusion = new int[game_num * game_num];
    assert(collusion != 0);

    for(i = 0; i < game_num; ++i)
        for(j = 0; j < game_num; ++j)
            *(collusion + i * game_num + j) = 0;

    cout << "\n 请输入每个运动员的参赛情况: \n\n";

    for(k = 1; k <= anthelete_num; ++k)
    {
        cout << " 请输入第" << k << "个运动员报名参赛情况: " << endl;
        while(1)
        {
            cout << " 请输入第" << k << "个运动员参赛数目: ";
            in >> num;
            if(num > 0 && num <= max)
                break;
            else
            {
                cout << "   每个运动员最多允许参加的比赛项目数为: " << max << "请重新输入! " << endl;
            }
        }
        j = 0;
        while(j < num)
        {
            cout << "       第" << j + 1 << "个参赛项目为: ";
            in >> x;
            if(x > -1 && x < game_num)
            {
                for(i = 0; i < j; i++)
                    if(temp[i] == x)
                        break;
                if(i == j)
                    temp[j++] = x;
                else
                    cout << "       该比赛项目已经输入" << endl;
            }
            else
            {
                cout << "       参赛项目应该在<0-" << game_num - 1;
                cout << ">，请重新输入" << endl;
            }
        }

        for(i = 0; i < num; i++)
            for(j = i + 1; j < num; j++)
            {
                *(collusion + temp[i]*game_num + temp[j]) = 1;
                *(collusion + temp[j]*game_num + temp[i]) = 1;
            }
        cout << endl;
    }
    displayCollusion();
}

istream& operator >> (istream& in, mySports& sq)
{
    sq.read(in);
    return in;
}

void mySports::display(ostream& out) const
{
    char no[5] = "[ i]";
    
    if(!game_num)
    {
        out << " 没有任何运动会信息! " << endl;
        return ;
    }

    out << " 比赛项目数: " << game_num << endl;
    out << " 每个运动员最多允许参加的比赛项目数: " << max << endl;

    if(!anthelete_num)
    {
        out << " 还没有运动员报名! " << endl;
        return ;
    }

    out << " 项目冲突矩阵: " << endl;
    displayCollusion();

    if(!game_arrange)
    {
        out << " 各项比赛分组还没有安排! " << endl;
        return ;
    }

    out << "\n 各项比赛分组安排如下: " << endl;
    
    out << " ";
    for(int i = 0; i < game_num; i++)
    {
        if(i <= 9)
            no[2] = i + '0';
        else
        {
            no[1] = i / 10 + '0';
            no[2] = i % 10 + '0';
        }

        out.width(4);
        out.fill(' ');
        out.setf(ios::right, ios::adjustfield);
        out << no; 
    }
    out << endl;

    // out << " ";
    for(int i = 0; i < game_num; i++)
    {
        out.width(4);
        out.fill(' ');
        out.setf(ios::right, ios::adjustfield);
        out << *(game_arrange + i);
    }
    out << endl;
}

ostream& operator <<(ostream& out, mySports& sq)
{
    sq.display(out);
    return out;
}

#endif

