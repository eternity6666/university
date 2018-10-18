#include <iostream>
using namespace std;

int longToYard(int);
int main()
{
    cout << "Enter a distance in long: ";
    int distance;
    cin >> distance;
    int ans;
    ans = longToYard(distance);
    cout << distance << " long = " << ans <<" yard"<< endl;
    return 0;
}

int longToYard(int n)
{
    return n*220;
}