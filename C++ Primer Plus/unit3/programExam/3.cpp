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
    const int DuToFen=60;
    const int FenToMiao=60;
    int degrees,minutes,seconds;
    cout<<"Enter a latitude in degrees, minutes and seconds: \n";
    cout<<"First, enter the degrees: ";
    cin>>degrees;
    cout<<"Next, enter the minutes of arc: ";
    cin>>minutes;
    cout<<"Finally, enter the seconds of arc: ";
    cin>>seconds;
    double latitude;
    latitude=degrees+(double)minutes/DuToFen+(double)seconds/(DuToFen*FenToMiao);
    cout<<degrees<<" degrees, "<<minutes<<" minutes, "<<seconds<<" seconds = "<<latitude<<" degrees";
    return 0;
}