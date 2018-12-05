#ifndef IOMANIP_H
    #define IOMANIP_H
    #include <iomanip>
#endif

#ifndef SQSTACK_H
    #define SQSTACK_H
    #include "SqStack.h"
#endif

const int maxm = 100 + 5;
bool v[maxm][maxm];
class mg{
public:
    void display(ostream& out);
   
    void input(istream& in);
    
    void getByRand(bool see);

    void clear();

    int getx();

    int gety();

    bool isEmpty();

    void findRoad(int sx, int sy, int ex, int ey);

    void dfs(int sx, int sy, bool* flag, int ex, int ey);

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

void mg::dfs(int sx, int sy, bool* flag, int ex, int ey)
{
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    if(v[sx][sy] == 1)
        return ;
    v[sx][sy] = 1;

    if(g[sx][sy] == 1)
        return ;
    if(sx == ex && sy == ey)
    {
        *flag = 1;
        g[sx][sy] = 2;
        return ;
    }
    fei(0, 3)
    {
        int tx = sx + dx[i];
        int ty = sy + dy[i];
        if(tx >= 0 && tx <= x && ty >= 0 && ty <= y)
        {
            dfs(tx, ty, flag, ex, ey);
        }

        if(*flag)
            break;
    }
    if(*flag)
    {
        g[sx][sy] = 2;
        return ;
    }
}

void mg::findRoad(int sx, int sy, int ex, int ey)
{
    fei(0, x)
        fej(0, y)
            v[i][j] = 0;
    bool flag = 0;
    dfs(sx, sy, &flag, ex, ey);
    if(flag)
    {
        cout << "有通路, 现用2标注如下: " << endl;
        display(cout);

        fei(0, x)
            fej(0, y)
                if(g[i][j] == 2)
                    g[i][j] = 0;
    }
    else
        cout << "无通路" << endl;
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
    {
        display(cout);
    }
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
    fei(0, y)
        out << "[" << setw(3) << i << "]";
    out << endl;
    fei(0, x)
    {
        out << " [" << setw(3) << i << "]";
        fej(0, y)
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

