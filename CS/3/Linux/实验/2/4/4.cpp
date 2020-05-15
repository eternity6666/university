#include <iostream>
#include <sys/time.h>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;
bool cmp(string s1, string s2)
{
    return s1 <= s2;
}
void bubble(string *str, int len)
{
    string temp;
    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (str[j] >= str[j + 1])
            {
                temp = str[j + 1];
                str[j + 1] = str[j];
                str[j] = temp;
            }
        }
    }
}
int main()
{
    string str1[105], str2[105];
    char buffer[40];
    int num = 0;
    ifstream in("A.in");
    ofstream out("out.in");
    if (!in.is_open())
        cout << "Open error" << endl;
    while (!in.eof())
    {
        in.getline(buffer, 30);
        str2[num] = buffer;
        str1[num++] = buffer;
    }
    struct timeval tv1, tv2;
    struct timezone tz;
    gettimeofday(&tv1, &tz);
    sort(str1, str1 + num - 1, cmp);
    gettimeofday(&tv2, &tz);
    cout << "¿ìÅÅ£º" << tv2.tv_usec - tv1.tv_usec << endl;
    gettimeofday(&tv1, &tz);
    bubble(str2, 100);
    gettimeofday(&tv2, &tz);
    cout << "Ã°Åİ£º" << tv2.tv_usec - tv1.tv_usec << endl;
    if (out.is_open())
    {
        for (int i = 0; i < num; ++i)
            out << str1[i] << endl;
    }
    out.close();
    in.close();
    return 0;
}