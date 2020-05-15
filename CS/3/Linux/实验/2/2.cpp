#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;
int main()
{
    time_t timep;
    time(&timep);
    printf("GMT:%s\n", asctime(gmtime(&timep)));
    timep += 60 * 60 * 8;
    printf("Local:%s\n", asctime(gmtime(&timep)));
    return 0;
}