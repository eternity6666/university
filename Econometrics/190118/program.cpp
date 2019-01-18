#include <bits/stdc++.h>
using namespace std;

struct nMonth
{
    map<float, int> x;
};
struct node
{
    nMonth month[15];
    bool v[15];
};
int main()
{
    map<string, node> flag;
    int m;
    string a;
    float dr;
    node tmp;
    freopen("a.txt", "r", stdin);
    while(cin >> m >> a >> dr)
    {
        if(flag.find(a) != flag.end())
        {
            flag[a].month[m].x[dr]++;
        }
        else
        {
            tmp.month[m].x[dr] = 1;
            flag[a] = tmp; 
        }
    }
    fclose(stdin);

    freopen("out.csv", "w", stdout);
    map<string, node>::iterator it;
    for(it = flag.begin(); it != flag.end(); it++)
    {
        for(int i = 1; i <= 12; i++)
        {
            if((*it).second.v[i])
            {
                map<float, int>::iterator it2;
                for(it2 = (*it).second.month[i].x.begin(); it2 != (*it).second.month[i].x.end(); it2++)
                {
                    cout << (*it).first << "," << i << "," << (*it2).first << "," << (*it2).second << endl;
                }
            }
        }
    }
    fclose(stdout);
    return 0;
}

