#include <cassert>
#include <new>
#include <time.h>
#define fei(a, b) for(int i = a; i <= b; i++)
#define fej(a, b) for(int j = a; j <= b; j++)
#define fek(a, b) for(int k = a; k <= b; k++)

using namespace std;

const int OK = 1;
const int ERROR = 0;
const int INFEASIBLE = -1;
const int OVERFLOW = -2;

typedef int Status;

Status equal(int a, int b)
{
    return a == b ? OK : ERROR;
}

Status great(int a, int b)
{
    return a > b ? OK : ERROR;
}

Status Less(int a, int b)
{
    return a < b ? OK : ERROR;
}

