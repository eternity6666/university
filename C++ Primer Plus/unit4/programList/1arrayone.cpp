// arrayone.cpp -- small arrays of integers
#include <iostream>
int main()
{
    using namespace std;
    int yams[3] = {7, 8, 6};

    int yamcosts[3] = {20, 30, 5};

    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamcosts[1] << " cents per yam.\n";
    int total = 0;
    for (int i = 0; i < 3; i++)
    {
        total += yams[i] * yamcosts[i];
    }
    cout << "The total yam expense is " << total << " cents.\n";

    cout << "\nSize of yams array = " << sizeof(yams);
    cout << " bytes.\n";
    cout << "Size of one element = " << sizeof(yams[0]);
    cout << " bytes.\n";
    return 0;
}