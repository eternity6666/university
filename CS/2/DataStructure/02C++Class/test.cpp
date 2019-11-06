#include <iostream>
#include "eg3.h"
using namespace std;

int main()
{
    myRectangle<int> a;
    //a.myNo.no = 1;    a.length = a.width = 1;
    cin >> a.myNo.no >> a.length >> a.width;
    cout << a.length << a.width << endl;
    return 0;
}
