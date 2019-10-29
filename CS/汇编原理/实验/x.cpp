#include <iostream>
#include <fstream>
#include <utility>
using namespace std;
typedef pair<string, string> P;

bool isalpha(char c)
{
    if ('a' <= c && c <= 'z')
        return true;
    return 'A' <= c && c <= 'Z';
}
bool is0(char c)
{
    return c == '0';
}

bool isdigit(char c)
{
    return '1' <= c && c <= '9';
}

bool is16(char c)
{
    if ('a' <= c && c <= 'f')
        return true;
    if ('A' <= c && c <= 'F')
        return true;
    return isdigit(c) || is0(c);
}

bool is8(char c)
{
    return '1' <= c && c <= '7';
}

void scan(string s)
{
    int len = s.length();
    int x = 0;
    bool flag = 0;
    int count = 10;
    while (x < len)
    {
        count--;
        if (count == 0)
            break;
        string ans1 = "", ans2 = "";
        if (isalpha(s[x]))
        {
            ans1 += s[x];
            int tmp = x + 1;
            while (tmp < len)
            {
                if (is0(s[tmp]) || isalpha(s[tmp]) || isdigit(s[tmp]))
                    ans1 += s[tmp++];
                else
                    break;
            }
            x = tmp;
            if (ans1 == "if" || ans1 == "then" || ans1 == "while" || ans1 == "do" || ans1 == "else")
                ans2 = '-';
            else
                ans2 = ans1, ans1 = '0';
        }
        else if (is0(s[x]))
        {
            int tmp = x + 1;
            if (tmp < len)
            {
                if (s[tmp] == 'x')
                {
                    if (tmp + 1 < len)
                    {
                        ans1 = '3';
                        tmp++;
                        while (tmp < len)
                        {
                            if (is16(s[tmp]))
                                ans2 += s[tmp++];
                            else
                                break;
                        }
                    }
                    else
                        ans1 = '1', ans2 = '0';
                }
                else if (is8(s[tmp]))
                {
                    ans1 = '2', ans2 = s[tmp];
                    tmp++;
                    while (tmp < len)
                    {
                        if (is0(s[tmp]) || is8(s[tmp]))
                            ans2 = s[tmp++];
                        else
                            break;
                    }
                }
                else
                    ans1 = '1', ans2 = '0';
            }
            else
                ans1 = "1", ans2 = "0";
            x = tmp;
        }
        else if (isdigit(s[x]))
        {
            ans1 = '1', ans2 += s[x];
            int tmp = x + 1;
            while (tmp < len)
            {
                if (isdigit(s[tmp]))
                    ans2 += s[tmp++];
                else
                    break;
            }
            x = tmp;
        }
        else
        {
            ans1 = s[x++];
            ans2 = "-";
        }
        cout << "<" << ans1 << ", " << ans2 << ">\n";
    }
}

int main()
{
    freopen("program.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string s;
    while (cin >> s)
        scan(s);
}