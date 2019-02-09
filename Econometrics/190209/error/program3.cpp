#include <bits/stdc++.h>
using namespace std;

struct node
{
    bool v[14];
    long long a[14];
};

map<int, node> ma0;
map<int, node> ma4;
map<int, node> ma5;
map<int, node> ma8;

int goti(int a, int b)
{
    if(a == 2017)
        return b - 8;
    else if(a == 2018)
        return b + 4;;
}

int gotDay(int i, int* x, int* y)
{
    if(i <= 4)
        *x = 2017, *y = i + 8;
    else
        *x = 2018, *y = i - 4;
}

int main()
{
    int a, b, c;
    node tmp;
    freopen("0.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma0.find(a) != ma0.end())
            ma0[a].v[tmpi] = 1;
        else
        {
            for(int i = 0; i < 14; i++)
            {
                tmp.v[i] = 0;
                tmp.a[i] = 0;
            }
            tmp.v[tmpi] = 1;
            tmp.a[tmpi] = 0;
            ma0[a] = tmp;
        }
    }
    fclose(stdin);
    cout << 1 << endl;
    freopen("4.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma4.find(a) != ma4.end())
            ma4[a].v[tmpi] = 1;
        else
        {
            for(int i = 0; i < 14; i++)
            {
                tmp.v[i] = 0;
                tmp.a[i] = 0;
            }
            tmp.v[tmpi] = 1;
            tmp.a[tmpi] = 0;
            ma4[a] = tmp;
        }
    }
    fclose(stdin);

    freopen("5.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma5.find(a) != ma5.end())
            ma5[a].v[tmpi] = 1;
        else
        {
            for(int i = 0; i < 15; i++)
            {
                tmp.v[i] = 0;
                tmp.a[i] = 0;
            }
            tmp.v[tmpi] = 1;
            tmp.a[tmpi] = 0;
            ma5[a] = tmp;
        }
    }
    fclose(stdin);

    freopen("5.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma5.find(a) != ma5.end())
            ma5[a].v[tmpi] = 1;
        else
        {
            for(int i = 0; i < 15; i++)
            {
                tmp.v[i] = 0;
                tmp.a[i] = 0;
            }
            tmp.v[tmpi] = 1;
            tmp.a[tmpi] = 0;
            ma5[a] = tmp;
        }
    }
    fclose(stdin);

    freopen("8.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma8.find(a) != ma8.end())
            ma8[a].v[tmpi] = 1;
        else
        {
            for(int i = 0; i < 18; i++)
            {
                tmp.v[i] = 0;
                tmp.a[i] = 0;
            }
            tmp.v[tmpi] = 1;
            tmp.a[tmpi] = 0;
            ma8[a] = tmp;
        }
    }
    fclose(stdin);

    freopen("171.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma0.find(a) != ma0.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma0[a].v[i])
                {
                    if(i > tmpi)
                        ma0[a].a[i]++;
                }
            }
        }

        if(ma4.find(a) != ma4.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma4[a].v[i])
                {
                    if(i > tmpi)
                        ma4[a].a[i]++;
                }
            }
        }

        if(ma5.find(a) != ma5.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma5[a].v[i])
                {
                    if(i > tmpi)
                        ma5[a].a[i]++;
                }
            }
        }

        if(ma8.find(a) != ma8.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma8[a].v[i])
                {
                    if(i > tmpi)
                        ma8[a].a[i]++;
                }
            }
        }

    }
    fclose(stdin);

    freopen("172.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma0.find(a) != ma0.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma0[a].v[i])
                {
                    if(i > tmpi)
                        ma0[a].a[i]++;
                }
            }
        }

        if(ma4.find(a) != ma4.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma4[a].v[i])
                {
                    if(i > tmpi)
                        ma4[a].a[i]++;
                }
            }
        }

        if(ma5.find(a) != ma5.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma5[a].v[i])
                {
                    if(i > tmpi)
                        ma5[a].a[i]++;
                }
            }
        }

        if(ma8.find(a) != ma8.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma8[a].v[i])
                {
                    if(i > tmpi)
                        ma8[a].a[i]++;
                }
            }
        }

    }
    fclose(stdin);

    freopen("182.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma0.find(a) != ma0.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma0[a].v[i])
                {
                    if(i > tmpi)
                        ma0[a].a[i]++;
                }
            }
        }

        if(ma4.find(a) != ma4.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma4[a].v[i])
                {
                    if(i > tmpi)
                        ma4[a].a[i]++;
                }
            }
        }

        if(ma5.find(a) != ma5.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma5[a].v[i])
                {
                    if(i > tmpi)
                        ma5[a].a[i]++;
                }
            }
        }

        if(ma8.find(a) != ma8.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma8[a].v[i])
                {
                    if(i > tmpi)
                        ma8[a].a[i]++;
                }
            }
        }

    }
    fclose(stdin);

    freopen("185.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma0.find(a) != ma0.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma0[a].v[i])
                {
                    if(i > tmpi)
                        ma0[a].a[i]++;
                }
            }
        }

        if(ma4.find(a) != ma4.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma4[a].v[i])
                {
                    if(i > tmpi)
                        ma4[a].a[i]++;
                }
            }
        }

        if(ma5.find(a) != ma5.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma5[a].v[i])
                {
                    if(i > tmpi)
                        ma5[a].a[i]++;
                }
            }
        }

        if(ma8.find(a) != ma8.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma8[a].v[i])
                {
                    if(i > tmpi)
                        ma8[a].a[i]++;
                }
            }
        }

    }
    fclose(stdin);

    freopen("187.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma0.find(a) != ma0.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma0[a].v[i])
                {
                    if(i > tmpi)
                        ma0[a].a[i]++;
                }
            }
        }

        if(ma4.find(a) != ma4.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma4[a].v[i])
                {
                    if(i > tmpi)
                        ma4[a].a[i]++;
                }
            }
        }

        if(ma5.find(a) != ma5.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma5[a].v[i])
                {
                    if(i > tmpi)
                        ma5[a].a[i]++;
                }
            }
        }

        if(ma8.find(a) != ma8.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma8[a].v[i])
                {
                    if(i > tmpi)
                        ma8[a].a[i]++;
                }
            }
        }

    }
    fclose(stdin);

    freopen("189.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        int tmpi = goti(b, c);
        if(ma0.find(a) != ma0.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma0[a].v[i])
                {
                    if(i > tmpi)
                        ma0[a].a[i]++;
                }
            }
        }

        if(ma4.find(a) != ma4.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma4[a].v[i])
                {
                    if(i > tmpi)
                        ma4[a].a[i]++;
                }
            }
        }

        if(ma5.find(a) != ma5.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma5[a].v[i])
                {
                    if(i > tmpi)
                        ma5[a].a[i]++;
                }
            }
        }

        if(ma8.find(a) != ma8.end())
        {
            for(int i = 1; i < 14; i++)
            {   
                if(ma8[a].v[i])
                {
                    if(i > tmpi)
                        ma8[a].a[i]++;
                }
            }
        }

    }
    fclose(stdin);

    map<int, node>::iterator it;
    freopen("0.csv", "w", stdout);
    it = ma0.begin();
    for(it = ma0.begin(); it != ma0.end(); it++)
    {
        for(int i = 1; i < 14; i++)
        {
            if((*it).second.v[i])
            {
                int x,y;
                gotDay(i, &x, &y);
                cout << (*it).first << "," << x << "/" << y << "," << (*it).second.a[i] << endl;
            }
        }
    }
    fclose(stdout);

    freopen("8.csv", "w", stdout);
    it = ma8.begin();
    for(it = ma8.begin(); it != ma8.end(); it++)
    {
        for(int i = 1; i < 18; i++)
        {
            if((*it).second.v[i])
            {
                int x,y;
                gotDay(i, &x, &y);
                cout << (*it).first << "," << x << "/" << y << "," << (*it).second.a[i] << endl;
            }
        }
    }
    fclose(stdout);

    freopen("5.csv", "w", stdout);
    it = ma5.begin();
    for(it = ma5.begin(); it != ma5.end(); it++)
    {
        for(int i = 1; i < 15; i++)
        {
            if((*it).second.v[i])
            {
                int x,y;
                gotDay(i, &x, &y);
                cout << (*it).first << "," << x << "/" << y << "," << (*it).second.a[i] << endl;
            }
        }
    }
    fclose(stdout);

    freopen("4.csv", "w", stdout);
    it = ma4.begin();
    for(it = ma4.begin(); it != ma4.end(); it++)
    {
        for(int i = 1; i < 14; i++)
        {
            if((*it).second.v[i])
            {
                int x,y;
                gotDay(i, &x, &y);
                cout << (*it).first << "," << x << "/" << y << "," << (*it).second.a[i] << endl;
            }
        }
    }
    fclose(stdout);

    return 0;
}

