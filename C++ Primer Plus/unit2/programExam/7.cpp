#include <iostream>
using namespace std;

void output(int, int);

int main()
{
    cout << "Enter the number of hours: ";
    int hours;
    cin >> hours;
    cout << "Enter the number of minuters: ";
    int min;
    cin >> min;
    output(hours, min);
}

void output(int a, int b)
{
    cout << "Time: " << a << ":";
    if (b < 10)
        cout << "0" << b;
    else
        cout << b;
    cout << endl;
}