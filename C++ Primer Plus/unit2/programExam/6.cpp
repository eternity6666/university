#include <iostream>
using namespace std;

double aU(double);
int main()
{
    cout << "Enter the number of light years: ";
    double lY;
    cin >> lY;
    cout << lY << " light years = " << aU(lY) << " astronomical units." << endl;
    return 0;
}

double aU(double n)
{
    return 63240*n;
}