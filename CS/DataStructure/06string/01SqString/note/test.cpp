#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x = "";
    do
    {
        string tmp = "";
        cin >> tmp;
        if(tmp == "")
            break;
        x = x + tmp + "\n";
    }while(1);
    cout << x << endl;
    return 0;
}

