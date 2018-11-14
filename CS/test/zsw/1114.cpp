#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int n, i = 0;
    scanf("%d", &n);
    cin >> str;
    for(int i = 0; i < str.size(); i++)
    {
        str[i] = (str[i] - 'a' + n) % 26 + 'a';
    }
    cout << str << endl;
    return 0;
}
