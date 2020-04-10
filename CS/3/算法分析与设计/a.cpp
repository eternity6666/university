#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> va;
int count1, count2;
set<string> sa, sb;
void swap(int x, int y)
{
    int t = va[x];
    va[x] = va[y];
    va[y] = t;
}

void perm1(int k, int n)
{
    int i;
    if (k == 1)
    {
        string s = "";
        for (i = 0; i < n; ++i)
        {
            char c = '0' + va[i];
            s = s + c;
        }
        sa.insert(s);
    }
    else
    {
        for (i = n - k; i < n; ++i)
        {
            swap(n - k, i);
            perm1(k - 1, n);
            swap(n - k, i);
        }
    }
}

void perm2(int k, int n)
{
    int i;
    if (k == 1)
    {
        string s = "";
        for (i = 0; i < n; ++i)
        {
            char c = '0' + va[i];
            s = s + c;
        }
        sb.insert(s);
    }
    else
    {
        for (i = n - k; i < n; ++i)
        {
            swap(n - k, i);
            perm2(k - 1, n);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        va.push_back(i);
    perm1(n, n);
    perm2(n, n);
    cout << sa.size() - sb.size() << endl;
    return 0;
}