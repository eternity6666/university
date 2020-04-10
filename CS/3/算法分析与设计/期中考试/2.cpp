#include <cstdio>
#include <cstring>
#define M 36000
int s[M];
int main()
{
    int n, i, j;
    while (scanf("%d", &n) != EOF)
    {
        memset(s, 0, sizeof(s));
        s[0] = 1;
        for (i = 2; i <= n; ++i)
        {
            int m = 0;
            for (j = 0; j < M; ++j)
            {
                int x = s[j] * i + m;
                s[j] = x % 10;
                m = x / 10;
            }
        }
        for (i = M - 1; i >= 0; --i)
            if (s[i] != 0)
                break;
        for (; i >= 0; --i)
            printf("%d", s[i]);
        printf("\n");
    }
    return 0;
}