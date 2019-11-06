#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
#define usefre

int main()
{
#ifdef usefre
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    const double InchToMeter = 0.0254;
    const double FootToInch = 12;
    const double KilogramToPound = 2.2;
    double foot, inch, pound;
    cout << "Please enter you height and weight(eg:foot inch pound): \n";
    cin >> foot >> inch >> pound;
    double inches = foot * FootToInch;
    double kilograms = pound / KilogramToPound;
    double meters = inches * InchToMeter;
    double ans = kilograms / pow(meters, 2);
    cout<<"You BMI is "<<ans<<".\n";
    return 0;
}