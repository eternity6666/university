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