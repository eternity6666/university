#include <bits/stdc++.h>
using namespace std;

bool v[10000000];
struct node
{
    int year;
    int month;

    int count;
};

int comp(node a, node b)
{
    if(abs(a.month - b.month) <= 1)
        return 1;
    else
        return 0;
}

int main()
{
    fill(v, v + 10000000, 0);
    map<int, node> flag;
    long long a;
    node tmp;
    freopen("zjyf.txt", "r", stdin);
    while(~scanf("%lld %d/%d", &a, &tmp.year, &tmp.month))
    {
        tmp.month = tmp.month + (tmp.year - 1) * 12;
        tmp.count = 0;
        v[a] = 1;
        flag[a] = tmp;
    }
    fclose(stdin);
    int j = 0;
    freopen("17.txt", "r", stdin);
    // int b;
    // bool bflag = 0;
    while(~scanf("%lld %d/%d", &a, &tmp.year, &tmp.month))
    {
//        cout << a << tmp.year << tmp.month << endl;
        if(a == 0)
            break;
        if(v[a])
        {
            // b = a;
            tmp.month = tmp.month + (tmp.year - 1) * 12;
            int i = comp(flag[a], tmp);
            flag[a].count += i;
        }
    //     cout << j++ << endl;
    
    }
    fclose(stdin);
    //cout << 2 << endl;
    map<int, node>::iterator it;
    freopen("out.csv", "w", stdout);
    cout << "id,times" << endl;
    for(it = flag.begin(); it != flag.end(); it++)
    {
        cout << (*it).first << "," << (*it).second.count << endl;
    }
    fclose(stdout);
    return 0;
}
