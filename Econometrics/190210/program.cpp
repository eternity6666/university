#include <bits/stdc++.h>
using namespace std;

struct time
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

struct node 
{
    struct time first;
    struct time second;
};

bool deal(struct node a, struct node b);
bool equalOrSmaller(struct time a, struct time b);

vector<int> ve1;
vector<int> ve2;
vector<int> ve3;

struct node a1;
struct node a2;
struct node a3;

int main()
{
    int a;
    struct time b;
    struct time c;
    freopen("x.txt", "r", stdin);
    scanf("%d/%d/%d %d:%d %d/%d/%d %d:%d", &b.year, &b.month, &b.day, &b.hour, &b.minute, &c.year, &c.month, &c.day, &c.hour, &c.minute);
    a1.first = b;
    a1.second = c;
    cout << b.year << "," << b.month << "," << b.day << "," << b.hour << "," << b.minute << endl;
    cout << c.year << "," << c.month << "," << c.day << "," << c.hour << "," << c.minute << endl;

    scanf("%d/%d/%d %d:%d %d/%d/%d %d:%d", &b.year, &b.month, &b.day, &b.hour, &b.minute, &c.year, &c.month, &c.day, &c.hour, &c.minute);
    a2.first = b;
    a2.second = c;
    cout << b.year << "," << b.month << "," << b.day << "," << b.hour << "," << b.minute << endl;
    cout << c.year << "," << c.month << "," << c.day << "," << c.hour << "," << c.minute << endl;

    scanf("%d/%d/%d %d:%d %d/%d/%d %d:%d", &b.year, &b.month, &b.day, &b.hour, &b.minute, &c.year, &c.month, &c.day, &c.hour, &c.minute);
    a3.first = b;
    a3.second = c;
    cout << b.year << "," << b.month << "," << b.day << "," << b.hour << "," << b.minute << endl;
    cout << c.year << "," << c.month << "," << c.day << "," << c.hour << "," << c.minute << endl;
    fclose(stdin);

    freopen("o.txt", "w", stdout);
    freopen("1.txt", "r", stdin);
    while(~scanf("%d %d/%d/%d %d:%d %d/%d/%d %d:%d", &a, &b.year, &b.month, &b.day, &b.hour, &b.minute, &c.year, &c.month, &c.day, &c.hour, &c.minute))
    {
        struct node tmp;
        tmp.first = b;
        tmp.second = c;
        // cout << b.year << "," << b.month << "," << b.day << "," << b.hour << "," << b.minute << endl;
        // cout << c.year << "," << c.month << "," << c.day << "," << c.hour << "," << c.minute << endl;
        if(deal(tmp, a1))
            ve1.push_back(a);

        if(deal(tmp, a2))
            ve2.push_back(a);

        if(deal(tmp, a3))
            ve3.push_back(a);

    }
    fclose(stdin);
    fclose(stdout);

    freopen("out.csv", "w", stdout);
    vector<int>::iterator it;
    for(it = ve1.begin(); it != ve1.end(); it++)
        if(it == ve1.begin())
            cout << (*it);
        else
            cout << "," << (*it);
    cout << endl;
    
    for(it = ve2.begin(); it != ve2.end(); it++)
        if(it == ve2.begin())
            cout << (*it);
        else
            cout << "," << (*it);
    cout << endl;

    for(it = ve3.begin(); it != ve3.end(); it++)
        if(it == ve3.begin())
            cout << (*it);
        else
            cout << "," << (*it);
    cout << endl;
    fclose(stdout);
    return 0;
}

bool deal(struct node a, struct node b)
{
    cout << endl;
    if(equalOrSmaller(a.first, b.first) && equalOrSmaller(b.second, a.second))
        return true;
    else
        return false;
}

bool equalOrSmaller(struct time a, struct time b)
{
    cout << 1 << "  ";
    cout << a.year << "," << a.month << "," << a.day << "," << a.hour << "," << a.minute << endl;
    cout << 2 << "  ";
    cout << b.year << "," << b.month << "," << b.day << "," << b.hour << "," << b.minute << endl;
    if(a.year < b.year)
        return true;
    else if(a.year > b.year)
        return false;
    else
    {
        if(a.month < b.month)
            return true;
        else if(a.month > b.month)
            return false;
        else
        {
            if(a.day < b.day)
                return true;
            else if(a.day > b.day)
                return false;
            else
            {
                if(a.hour < b.hour)
                    return true;
                else if(a.hour > b.hour)
                    return false;
                else
                {
                    if(a.hour <= b.hour)
                        return true;
                    else
                        return false;
                }
            }
        }
    }
}

