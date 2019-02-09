#include <bits/stdc++.h>
using namespace std;

struct n1
{
    int year;
    int month;
};

struct n2
{
    int year;
    int month;
    char c;
};

struct node1
{
    n1 tmp;
    map<n1, int> m1;
};

struct node2
{
    n2 tmp;
    map<n2, int> m2;
};

int main()
{
    map<int, node1> m0;
    map<int, node2> m4;
    map<int, node2> m5;
    map<int, node2> m8;
    map<int, node1>::iterator it1;
    node1 tmp1;
    int a;
    freopen("0.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &tmp1.tmp.year, &tmp1.tmp.month))
    {
        if(m0.find(a) != m0.end())
        {
            m0[a].m1[m0[a].tmp] = 0;
        }
        else
        {
            tmp1.m1[tmp1.tmp] = 0;
            m0[a] = tmp1;
        }
    }
    fclose(stdin);
    return 0;
}

