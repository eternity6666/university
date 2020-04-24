#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string ans = "";
    int len = s.length();
    for (int i = 0; i < len; ++i)
        ans += 'A' + (s[i] - 'A' + 5) % 26;
    cout << ans << endl;
    return 0;
}