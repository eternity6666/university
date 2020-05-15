#include <iostream>
#include <cstring>
using namespace std;
int num[10];
bool vis[10];
int dfs(int use, int total)
{
    int i, j;
    if (use == 4)
    {
        if (num[total - 1] == 24)
            return 1;
        else
            return 0;
    }
    for (i = 0; i < total - 1; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        for (j = i + 1; j < total; j++)
        {
            if (vis[j])
                continue;
            vis[j] = true;
            num[total] = num[i] + num[j];
            if (dfs(use + 1, total + 1))
                return 1;
            num[total] = num[i] - num[j];
            if (dfs(use + 1, total + 1))
                return 1;
            num[total] = num[j] - num[i];
            if (dfs(use + 1, total + 1))
                return 1;
            num[total] = num[i] * num[j];
            if (dfs(use + 1, total + 1))
                return 1;
            if (num[j])
                if (num[i] % num[j] == 0)
                {
                    num[total] = num[i] / num[j];
                    if (dfs(use + 1, total + 1))
                        return 1;
                }
            if (num[i])
                if (num[j] % num[i] == 0)
                {
                    num[total] = num[j] / num[i];
                    if (dfs(use + 1, total + 1))
                        return 1;
                }
            vis[j] = false;
        }
        vis[i] = false;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 4; i++)
            cin >> num[i];
        memset(vis, 0, sizeof(vis));
        if (dfs(1, 4))
            cout << "YES\n";
        else
            cout << "Oops\n";
    }
    return 0;
}