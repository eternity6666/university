#include "my.h"

int getSum(int nums[SIZE], int n)
{
    int sum = 0, i;
    for(i = 0; i < n; ++i)
        sum += nums[i];
    return sum;
}
