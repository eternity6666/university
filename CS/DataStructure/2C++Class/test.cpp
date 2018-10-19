#include <iostream>
#include "testh.h"
using namespace std;

int main()
{
    myRectangle<int> a;

    cin >> a.width >> a.length;
    cout << a.width << a.length << endl;
    return 0;

}
