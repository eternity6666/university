#include <bits/stdc++.h>
using namespace std;

struct node
{
   // int user;
    int year;
    int month;
    int day;
    int hour;
    int min;
    int second;

    int count1;
    int count2;
};

int comp(node a, node b)
{
    if(a.year > b.year)
        return 1;
    else if(a.year == b.year)
    {
        if(a.month > b.month)
            return 1;
        else if(a.month == b.month)
        {
            if(a.day > b.day)
                return 1;
            else if(a.day == b.day)
            {
                if(a.hour > b.hour)
                    return 1;
                else if(a.hour == b.hour)
                {
                    if(a.min > b.min)
                        return 1;
                    else if(a.min == b.min)
                    {
                        if(a.second > b.second)
                            return 1;
                        else if(a.second == b.second)
                            return -1;
                        else
                            return 0;
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    map<int, node> flag;
    freopen("a.txt", "r", stdin);
    int a;
    node tmp;
    while(~scanf("%d %d/%d/%d %d:%d:%d", &a, &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.min, &tmp.second))
    {
        tmp.count1 = 0;
        tmp.count2 = 0;
        flag[a] = tmp;
    }
    fclose(stdin);

    freopen("171.csv", "r", stdin);
    while(~scanf("%d,%d/%d/%d %d:%d", &a, &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.min))
    {
        tmp.second = 0;
        int i = comp(flag[a], tmp);
        if(i == 1)
        {
            flag[a].count2 += 1;
            flag[a].count1 += 1; 
        }
        else if(i == -1)
            flag[a].count2 += 1;
    }
    fclose(stdin);
    freopen("172.csv", "r", stdin);
    while(~scanf("%d,%d/%d/%d %d:%d", &a, &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.min))
    {
        tmp.second = 0;
        int i = comp(flag[a], tmp);
        if(i == 1)
        {
            flag[a].count2 += 1;
            flag[a].count1 += 1; 
        }
        else if(i == -1)
            flag[a].count2 += 1;
    }
    fclose(stdin);

    freopen("182.csv", "r", stdin);
    while(~scanf("%d,%d/%d/%d %d:%d:%d", &a, &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.min, &tmp.second))
    {
        int i = comp(flag[a], tmp);
        if(i == 1)
        {
            flag[a].count2 += 1;
            flag[a].count1 += 1; 
        }
        else if(i == -1)
            flag[a].count2 += 1;
    }
    fclose(stdin);

    freopen("185.csv", "r", stdin);
    while(~scanf("%d,%d/%d/%d %d:%d:%d", &a, &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.min, &tmp.second))
    {
        int i = comp(flag[a], tmp);
        if(i == 1)
        {
            flag[a].count2 += 1;
            flag[a].count1 += 1; 
        }
        else if(i == -1)
            flag[a].count2 += 1;
    }
    fclose(stdin);

    freopen("187.csv", "r", stdin);
    while(~scanf("%d,%d/%d/%d %d:%d:%d", &a, &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.min, &tmp.second))
    {
        int i = comp(flag[a], tmp);
        if(i == 1)
        {
            flag[a].count2 += 1;
            flag[a].count1 += 1; 
        }
        else if(i == -1)
            flag[a].count2 += 1;
    }
    fclose(stdin);
    
    freopen("189.csv", "r", stdin);
    while(~scanf("%d,%d/%d/%d %d:%d:%d", &a, &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.min, &tmp.second))
    {
        int i = comp(flag[a], tmp);
        if(i == 1)
        {
            flag[a].count2 += 1;
            flag[a].count1 += 1; 
        }
        else if(i == -1)
            flag[a].count2 += 1;
    }
    fclose(stdin);

    map<int, node>::iterator it;
    freopen("out1.csv", "w", stdout);
    cout << "t3.user_no,t3.login_time" << endl;
    for(it = flag.begin(); it != flag.end(); it++)
    {
        cout << (*it).first << "," << (*it).second.count1 << endl;
    }
    fclose(stdout);

    freopen("out2.csv", "w", stdout);
    cout << "t3.user_no,t3.login_time" << endl;
    for(it = flag.begin(); it != flag.end(); it++)
    {
        cout << (*it).first << "," << (*it).second.count2 << endl;
    }
    fclose(stdout);
    return 0;
}

