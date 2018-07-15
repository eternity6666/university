#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
// #define usefre

int main()
{
#ifdef usefre
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long world, US;
    cout << "Enter the world\'s population: ";
    cin >> world;
    cout << "Enter the population of the US: ";
    cin >> US;
    cout << "The population of the US is " << (double)US / world * 100 << "\% of the world population.\n";
    return 0;
}