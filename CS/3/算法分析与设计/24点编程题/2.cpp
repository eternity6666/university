#include <iostream>
#include <cstring>
#include <map>
using namespace std;
map<string, int> ma;
int num[5];
bool vis[5];
int num2[5];
int getNum(string s){

}
bool dfs(int use)
{
    if (use == 4)
    {
    }
    for (int i = 0; i < 4; ++i)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        num2[use] = num[i];
        if (dfs(use + 1))
            return 1;
        vis[i] = false;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 4; ++i)
            cin >> num[i];
        memset(vis, false, sizeof(vis));
        int use = 0;
        cout << (dfs(use)?"YES":"Oops") << endl;
    }
    return 0;
}