#include <cassert>
#include <new>
using namespace std;

#include <time.h>

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

