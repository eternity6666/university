#include <iostream>
using namespace std;
int main()
{
    int *arr = new int[10];
    cout << "ÊäÈë10¸öÊı×Ö" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cin >> arr[i];
    }
    int maxnum = arr[0];
    int minnum = arr[0];
    for (int i = 1; i < 10; ++i)
    {
        if (maxnum < arr[i])
            maxnum = arr[i];
        if (minnum > arr[i])
            minnum = arr[i];
    }
    cout << "max: " << maxnum << endl;
    cout << "min: " << minnum << endl;
    delete[] arr;
    return 0;
}