#include <bits/stdc++.h>
using namespace std;

struct noo
{
    int id;
    int year;
    int month;
};

struct ndd
{
    int id;
    int year;
    int month;
    char c;
};

int main()
{
    map<noo, int> m;
    map<ndd, int> md;
    int id, year, month;
    noo tmp;
    freopen("0.txt", "r", stdin);
    while(~scanf("%d %d/%d", &id, &year, &month))
    {
        tmp.id = id;
        tmp.year = year;
        tmp.month = month;
        m[tmp] = 0;
    }
    fclose(stdin);
    
    freopen("4.txt", "r", stdin);
}
