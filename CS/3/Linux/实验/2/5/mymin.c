#include "my.h"

int getMin(int nums[SIZE], int n)
{
    int i, min;
    min = nums[0];
    for (i = 1; i < n; i++)
        min = min > nums[i] ? nums[i] : min;
    return min;
}