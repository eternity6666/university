#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x = "";
    string tmp = "";
    while(cin >> tmp, !cin.eof())
    {
        tmp = "";
        x = x + tmp;
    }
    /*
    do
    {
        string tmp = "";
        cin >> tmp;
        if(tmp == "")
            break;
        x = x + tmp + "\n";
    }while(1);
    */
    cin.clear();
    cout << x << endl;
    return 0;
}

