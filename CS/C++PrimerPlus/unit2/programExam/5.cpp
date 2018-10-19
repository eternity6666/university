#include <iostream>
using namespace std;
double CF(double);
int main()
{
    cout<<"Please enter a Celsius Value: ";
    double CV;
    cin>>CV;
    cout<<CV<<" degrees Celsius is "<<CF(CV)<<" degrees Fahrenheit."<<endl;
    return 0;
}

double CF(double CV)
{
    return CV*1.8+32.0;
}