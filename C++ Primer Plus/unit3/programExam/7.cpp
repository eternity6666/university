#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
#define usefre

int main()
{
#ifdef usefre
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    return 0;
}