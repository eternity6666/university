#include <bits/stdc++.h>
using namespace std;

struct node
{
    int id;
    int i;
    int time;
};

vector<node> ve0;
vector<node> ve4;
vector<node> ve5;
vector<node> ve8;

/*
map<int, node> ma0;
map<int, node> ma4;
map<int, node> ma5;
map<int, node> ma8;
*/

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
        tmp.id = a;
        tmp.i = goti(b, c);
        tmp.time = 0;
        ve0.push_back(tmp);
    }
    fclose(stdin);

    freopen("4.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        tmp.id = a;
        tmp.i = goti(b, c);
        tmp.time = 0;
        ve4.push_back(tmp);
    }
    fclose(stdin);

    freopen("5.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        tmp.id = a;
        tmp.i = goti(b, c);
        tmp.time = 0;
        ve5.push_back(tmp);
    }
    fclose(stdin);

    freopen("8.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        tmp.id = a;
        tmp.i = goti(b, c);
        tmp.time = 0;
        ve8.push_back(tmp);
    }
    fclose(stdin);

    vector<node>::iterator it;
    long long x = 0;
    freopen("171.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        cout << x++ << endl;
        tmp.id = a;
        tmp.i = goti(b, c);

        for(it = ve0.begin(); it != ve0.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve4.begin(); it != ve4.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve5.begin(); it != ve5.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve8.begin(); it != ve8.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

    }
    fclose(stdin);
    cout << 171 << endl;

    freopen("172.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        cout << x++ << endl;
        tmp.id = a;
        tmp.i = goti(b, c);

        for(it = ve0.begin(); it != ve0.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve4.begin(); it != ve4.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve5.begin(); it != ve5.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve8.begin(); it != ve8.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

    }
    fclose(stdin);
    cout << 172 << endl;

    freopen("182.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        cout << x++ << endl;
        tmp.id = a;
        tmp.i = goti(b, c);

        for(it = ve0.begin(); it != ve0.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve4.begin(); it != ve4.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve5.begin(); it != ve5.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve8.begin(); it != ve8.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

    }
    fclose(stdin);
    cout << 182 << endl;

    freopen("185.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        cout << x++ << endl;
        tmp.id = a;
        tmp.i = goti(b, c);

        for(it = ve0.begin(); it != ve0.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve4.begin(); it != ve4.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve5.begin(); it != ve5.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve8.begin(); it != ve8.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

    }
    fclose(stdin);
    cout << 185 << endl;

    freopen("187.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        cout << x++ << endl;
        tmp.id = a;
        tmp.i = goti(b, c);

        for(it = ve0.begin(); it != ve0.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve4.begin(); it != ve4.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve5.begin(); it != ve5.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve8.begin(); it != ve8.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

    }
    fclose(stdin);
    cout << 187 << endl;

    freopen("189.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &b, &c))
    {
        cout << x++ << endl;
        tmp.id = a;
        tmp.i = goti(b, c);

        for(it = ve0.begin(); it != ve0.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve4.begin(); it != ve4.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve5.begin(); it != ve5.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

        for(it = ve8.begin(); it != ve8.end(); it++)
            if((*it).id == tmp.id && (*it).i > tmp.i)
                (*it).time++;

    }
    fclose(stdin);
    cout << 189 << endl;

    freopen("0.csv", "w", stdout);
    for(it = ve0.begin(); it != ve0.end(); it++)
    {
        int x, y;
        gotDay((*it).i, &x, &y);
        cout << (*it).id << "," << x << "/" << y << "," << (*it).time << endl;
    }
    fclose(stdout);

    freopen("4.csv", "w", stdout);
    for(it = ve4.begin(); it != ve4.end(); it++)
    {
        int x, y;
        gotDay((*it).i, &x, &y);
        cout << (*it).id << "," << x << "/" << y << "," << (*it).time << endl;
    }
    fclose(stdout);

    freopen("5.csv", "w", stdout);
    for(it = ve5.begin(); it != ve5.end(); it++)
    {
        int x, y;
        gotDay((*it).i, &x, &y);
        cout << (*it).id << "," << x << "/" << y << "," << (*it).time << endl;
    }
    fclose(stdout);

    freopen("8.csv", "w", stdout);
    for(it = ve8.begin(); it != ve8.end(); it++)
    {
        int x, y;
        gotDay((*it).i, &x, &y);
        cout << (*it).id << "," << x << "/" << y << "," << (*it).time << endl;
    }
    fclose(stdout);

    return 0;
}

