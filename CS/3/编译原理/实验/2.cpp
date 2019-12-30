#include <bits/stdc++.h>
using namespace std;
map<char, set<string>> ma;
map<char, set<string>>::iterator mit;
set<string>::iterator sit;
bool isIn(char c)
{
    if (ma[c].size() == 0)
    {
        ma.erase(c);
        return false;
    }
    return true;
}
void read()
{
    string s;
    while (cin >> s)
    {
        char c = s[0];
        string value = "";
        int i = 3, len = s.length();
        while (i < len - 1)
        {
            value += s[i];
            if (s[i + 1] == '|' || s[i + 1] == ';')
            {
                ma[c].insert(value);
                i = i + 2;
                value = "";
            }
            else
                i++;
        }
    }
}
string substr(string x, int begin, int end)
{
    string ans = "";
    for (int i = begin; i < end; i++)
        ans += x[i];
    return ans == "" ? "@" : ans;
}
void remove_left_recursion()
{
    for (mit = ma.begin(); mit != ma.end(); ++mit)
    {
        char c = mit->first;
        set<string> se;
        for (sit = mit->second.begin(); sit != mit->second.end(); ++sit)
        {
            string s = *sit;
            string v = "";
            int slen = s.length();
            for (int i = 0; i < slen; ++i)
                if (isIn(s[i]))
                {
                    char cv = s[i];
                    string tmp = "";
                    for (int j = i + 1; j < slen; ++j)
                        tmp += s[j];
                    set<string>::iterator sit2;
                    for (sit2 = ma[cv].begin(); sit2 != ma[cv].end(); ++sit2)
                        se.insert(v + *sit2 + tmp);
                    break;
                }
                else
                {
                    v += s[i];
                    if (i + 1 == slen)
                        se.insert(v);
                }
        }
        mit->second = se;
    }
    for (mit = ma.begin(); mit != ma.end(); ++mit)
    {
        char c = mit->first;
        bool flag = false;
        for (sit = mit->second.begin(); sit != mit->second.end(); ++sit)
        {
            string s = *sit;
            if (s[0] == c)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            char cv;
            int x = 0;
            do
            {
                cv = 'A' + x;
                x++;
            } while (isIn(cv));
            set<string> se1, se2;
            se2.insert("@");
            for (sit = mit->second.begin(); sit != mit->second.end(); ++sit)
            {
                string s = *sit;
                if (s[0] == c)
                {
                    int slen = s.length();
                    string sub = substr(s, 1, slen);
                    se2.insert(sub + cv);
                }
                else
                    se1.insert(s + cv);
            }
            ma[c] = se1;
            ma[cv] = se2;
        }
    }
}
void remove_left_gene()
{
    bool flag;
    do
    {
        flag = false;
        for (mit = ma.begin(); mit != ma.end(); ++mit)
        {
            int count = 0;
            map<char, int> tmpMa;
            char c = mit->first;
            for (sit = mit->second.begin(); sit != mit->second.end(); ++sit)
            {
                tmpMa[(*sit)[0]]++;
                if (tmpMa[(*sit)[0]] == 2)
                    count++;
            }
            if (count != 0)
            {
                flag = true;
                map<char, int>::iterator mit2;
                set<string> se1;
                for (mit2 = tmpMa.begin(); mit2 != tmpMa.end(); ++mit2)
                {
                    if (mit2->second > 1)
                    {
                        char cv;
                        int x = 0;
                        do
                        {
                            cv = 'A' + x;
                            x++;
                        } while (isIn(cv));
                        string stmp = "";
                        stmp += mit2->first;
                        stmp += cv;
                        se1.insert(stmp);
                        set<string> se2;
                        for (sit = mit->second.begin(); sit != mit->second.end(); ++sit)
                            if ((*sit)[0] == mit2->first)
                                se2.insert(substr((*sit), 1, (*sit).length()));
                        ma[cv] = se2;
                    }
                    else if (mit2->second == 1)
                    {
                        for (sit = mit->second.begin(); sit != mit->second.end(); ++sit)
                            if ((*sit)[0] == mit2->first)
                            {
                                se1.insert((*sit));
                                break;
                            }
                    }
                }
                ma[c] = se1;
            }
        }
    } while (flag);
}
void print()
{
    for (mit = ma.begin(); mit != ma.end(); ++mit)
    {
        char c = mit->first;
        string s = "";
        for (sit = mit->second.begin(); sit != mit->second.end(); ++sit)
        {
            if (sit == mit->second.begin())
                s = *sit;
            else
                s += "|" + (*sit);
        }
        cout << c << "->" << s << ";\n";
    }
    cout << endl;
}
int main()
{
    read();
    print();
    remove_left_recursion();
    print();
    remove_left_gene();
    print();
    return 0;
}
/*
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<char, int> ma1;
map<char, int> ma2;
map<char, int>::iterator it;
vector<string> ve;
int len = 0;
bool isIn(char c)
{
    if (ma1[c] == 0)
        return false;
    return true;
}
void read()
{
    string s;
    while (cin >> s)
    {
        char c = s[0];
        ma1[c] = len + 1;
        string value = "";
        int slen = s.length(), i = 3;
        while (i < slen - 1)
        {
            value += s[i];
            if (s[i + 1] == '|' || s[i + 1] == ';')
            {
                ve.push_back(value);
                value = "";
                i += 2;
                len++;
            }
            else
                i++;
        }
        ma2[c] = len;
    }
}
void remove_left_recursion()
{
    for (it = ma1.begin(); it != ma1.end(); it++)
    {
        char c = it->first;
        int from = ma1[c], to = ma2[c];
        for (int i = from; i <= to; ++i)
        {
            string value = ve[i - 1];
            string v = "";
            int vlen = value.length();
            for (int z = 0; z < vlen; ++z)
                if (isIn(value[z]))
                {
                    char cv = value[z];
                    int cvfrom = ma1[cv], cvto = ma2[cv];
                    string tmp = "";
                    for (int j = z + 1; j < vlen; ++j)
                        tmp += value[j];
                    for (int j = cvfrom; j <= cvto; ++j)
                        cout << c << "->" << v + ve[j - 1] + tmp << endl;
                    break;
                }
                else
                {
                    v += value[z];
                    if(z+1==vlen)
                        cout << c << "->" << v << endl;
                }
        }
    }
}
void remove_left_gene()
{
    
}
void print()
{
    for (it = ma1.begin(); it != ma1.end(); it++)
    {
        char c = it->first;
        int from = ma1[c], to = ma2[c];
        for (int i = from; i <= to; ++i)
            cout << c << "->" << ve[i - 1] << endl;
    }
}
int main()
{
    read();
    // print();
    remove_left_recursion();
    return 0;
}
*/