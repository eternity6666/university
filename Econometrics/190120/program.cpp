#include <bits/stdc++.h>
using namespace std;

struct node
{
    int year;
    int month;
    int z;
    double q;
};

bool comp(node a, node b)
{
    if(a.year == b.year && b.month == a.month)
        return 1;
    else
        return 0;
}

int main()
{
    // freopen("out.csv", "w", stdout);
    map<int, node> flag;
    int a;
    node tmp;
    freopen("a.txt", "r", stdin);
    while(~scanf("%d %d/%d", &a, &tmp.year, &tmp.month))
    {
        tmp.z = 0;
        tmp.q = 0;
        flag[a] = tmp;
    }
    fclose(stdin);

    //cout << 1 << endl;
    freopen("b.txt", "r", stdin);
    double b;
    while(~scanf("%d %lf %d/%d", &a, &b, &tmp.year, &tmp.month))
    {
        if(comp(flag[a], tmp))
        {
            flag[a].z++;
            flag[a].q += b;
        }
        cout << a << b << tmp.year << tmp.month << endl;
    }
    fclose(stdin);

    cout << 2 << endl;
    freopen("out.csv", "w", stdout);
    map<int, node>::iterator it;
    for(it = flag.begin(); it != flag.end(); it++)
    {
        cout << (*it).first << "," << (*it).second.z << "," <<(*it).second.q << endl;
    }
    fclose(stdout);
    return 0;
}
