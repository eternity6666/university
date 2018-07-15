#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
#define usefre

int main()
{
#ifdef usefre
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a;
    const int InchToFoot = 12;
    while (cout << "Please enter your height in inch: \n" && cin >> a)
    {
        // cout << "Please enter your height in inch: ";
        // cin >> a;
        int inch, foot;
        inch = a % InchToFoot;
        foot = a / InchToFoot;
        if (a > 1)
        {
            if (foot > 1)
            {
                if (inch > 1)
                {
                    // cout<<"case 1\n";
                    cout << a << " inches = " << foot << " feet + " << inch << " inches.\n";
                }
                else
                {
                    // cout<<"case 2\n";
                    cout << a << " inches = " << foot << " feet + " << inch << " inch.\n";
                }
            }
            else
            {
                if (inch > 1)
                {
                    // cout<<"case 3\n";
                    cout << a << " inches = " << foot << " foot + " << inch << " inches.\n";
                }
                else
                {
                    // cout<<"case 4\n";
                    cout << a << " inches = " << foot << " foot + " << inch << " inch.\n";
                }
            }
        }
        else
        {
            // cout<<"case 5\n";
            cout << a << " inch = " << foot << " foot + " << inch << " inch.\n";
        }
    }
    return 0;
}