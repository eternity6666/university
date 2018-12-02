#ifndef IOMANIP_H
    #define IOMANIP_H
    #include <iomanip>
#endif

#ifndef SQSTACK_H
    #define SQSTACK_H
    #include "SqStack.h"
#endif

const int maxm = 100 + 5;
class mg{
public:
    void display(ostream& out);
   
    void input(istream& in);
    
    void getByRand(bool see);

    void clear();

    int getx();

    int gety();

    bool isEmpty();

    bool findRoad(int sx, int sy, int ex, int ey);

    mg operator = (mg omg);

    mg();

    mg(const mg& omg);

    ~mg();

private:
    int x, y;
    int g[maxm][maxm];
};

int mg::getx()
{
    return x;
}

int mg::gety()
{
    return y;
}

bool mg::findRoad(int sx, int sy, int ex, int ey)
{
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    struct node
    {
        int x, y;
    };
    bool v[maxm][maxm];
    fei(0, x)
        fej(0, y)
            v[i][j] = 0;
    SqStack<node> s;
    
    node t;
    t.x = sx;
    t.y = sy;
    s.push(t);

    bool flag = 0;

    while(!s.isEmpty())
    {
        s.pop(t);
        if(g[t.x][t.y] == 1)
            continue;
        if(t.x == ex && t.y == ey)
        {
            flag = 1;
            break;
        }
        fei(0, 3)
        {
            node tmp;
            tmp.x = t.x + dx[i];
            tmp.y = t.y + dy[i];

            if(tmp.x >= 0 && tmp.x <= x)
                if(tmp.y >= 0 && tmp.y <= y)
                {
                    if(v[tmp.x][tmp.y] == 0)
                    {
                        v[tmp.x][tmp.y] = 1;
                        s.push(tmp);
                    }
                }
        }
    }
    if(flag)
        return true;
    else
        return false;
}

void mg::clear()
{
    x = y = -1;
}

void mg::getByRand(bool see)
{
    x = rand() % 10;
    y = rand() % 10;
    fei(0, x)
        fej(0, y)
            g[i][j] = rand() % 2;

    if(see)
        cout << this;
}

bool mg::isEmpty()
{
    if(x == -1 || y == -1)
        return true;
    else
        return false;
}

void mg::display(ostream& out)
{
    out << setw(6) << " ";
    fei(0, x)
        out << "[" << setw(3) << i << "]";
    out << endl;
    fei(0, y)
    {
        out << " [" << setw(3) << i << "]";
        fej(0, x)
        {
            out << " " << setw(3) << g[i][j] << " ";
        }
        out << endl;
    }
}
ostream& operator <<(ostream& out, mg& s)
{
    s.display(out);
    return out;
}

void mg::input(istream& in)
{
    clear();

    cout << " 请输入迷宫的行列数: ";
    int n;
    while(in >> n)
    {
        if(n < 0)
            cout << " 你的输入非法，请输入不小于0的数字: ";
        else
            break;
    }
    x = y = n - 1;
    fei(0, x)
        fej(0, y)
            in >> g[i][j];
}

istream& operator >>(istream& in, mg& s)
{
    s.input(in);
    return in;
}

mg mg::operator = (mg omg)
{
    if(this != &omg)
    {
        clear();
        
        x = omg.x;
        y = omg.y;

        fei(0,x)
            fej(0,y)
                g[i][j] = omg.g[i][j];
    }
    return *this;
}

mg::mg()
{
    getByRand(false);
}

mg::mg(const mg& omg)
{
    clear();
    
    x = omg.x;
    y = omg.y;

    fei(0,x)
        fej(0,y)
            g[i][j] = omg.g[i][j];
}

mg::~mg()
{
    clear();
}

