#include <iostream>
using namespace std;

char newChar()
{
    int x = rand() % 100;
    if (x < 50)
        return 'a' + (x % 26);
    return 'A' + (x % 26);
}

int main()
{
    int n = 100;
    for (int i = 0; i < n; ++i)
    {
        int x = 10;
        while (x--)
        {
            cout << newChar();
        }
        cout << endl;
    }
    return 0;
}