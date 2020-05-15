#include <stdio.h>
#include "my.h"
#define MAXN 1005

int score[MAXN];
int main()
{
    printf("输入学生数: ");
    int n,i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("%d: ", i);
        scanf("%d",&score[i]);
    }
    printf("Minimum: %d\n", getMin(score, n));
    printf("Maximum: %d\n", getMax(score, n));
    printf("Sum: %d\n", getSum(score, n));
    printf("Average: %lf\n", getAver(score, n));
    return 0;
}
