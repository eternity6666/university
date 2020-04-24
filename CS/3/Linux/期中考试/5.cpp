#include <map>
#include <iostream>
using namespace std;

map<string, int> ma;
bool isOK(char c)
{
    if ('a' <= c && c <= 'z')
        return true;
    if ('A' <= c && c <= 'Z')
        return true;
    return false;
}

int main()
{
    freopen("./wordCount.txt", "r", stdin);
    string s;
    while (cin >> s)
    {
        string s1 = "";
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            if (isOK(s[i]))
                s1 += s[i];
        }
        s = s1;
        if (s != "")
            ma[s]++;
    }
    map<string, int>::iterator mit;
    int count = 0;
    for (mit = ma.begin(); mit != ma.end(); mit++)
    {
        count ++;
        cout << mit->first << ": " << mit->second << " ";
        if(count % 5 == 0)
            cout << endl;
    }
    return 0;
}