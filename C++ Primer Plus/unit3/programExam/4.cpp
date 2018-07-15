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
    long long second, seconds, minutes, hours, days;
    cout << "Enter the number of seconds ";
    cin >> second;
    const int DayToHour = 24;
    const int HourToMinute = 60;
    const int MinuteToSecond = 60;
    minutes = second / MinuteToSecond;
    seconds = second % MinuteToSecond;
    hours = minutes / HourToMinute;
    minutes = minutes % HourToMinute;
    days = hours / DayToHour;
    hours = hours % DayToHour;
    cout << second << " seconds "
         << " = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds\n";
    return 0;
}