#include "my.h"

int getMax(int nums[SIZE], int n)
{
    int i, max;
    max = nums[0];
    for (i = 1; i < n; i++)
        max = max < nums[i] ? nums[i] : max;
    return max;
}