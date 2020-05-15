#include "my.h"

double getAver(int nums[SIZE], int n)
{
    int i, sum;
    sum = nums[0];
    for (i = 1; i < n; i++)
        sum += nums[i];
    return 1.0 * sum / n;
}
