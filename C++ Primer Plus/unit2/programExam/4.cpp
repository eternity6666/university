#include <iostream>
using namespace std;
int ageToMonth(int);
int main()
{
    cout<<"Please enter your age: "<<endl;
    int age;
    cin>>age;
    cout<<"It includes "<<ageToMonth(age)<<" months."<<endl;
    return 0;
}

int ageToMonth(int n)
{
    return 12*n;
}