#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAXN = 0x3f3f3f3f;
const int MAX = 110;
int point[MAX][MAX];
int dist[MAX];
bool visit[MAX];
int Prim(int N)
{
    int i, j, pos, minx;
    int shortx = 0;
    memset(visit, false, sizeof(visit));
    visit[1] = true;
    pos = 1;
    for (i = 1; i <= N; ++i)
        if (i != pos)
            dist[i] = point[1][i];

    for (i = 1; i < N; ++i)
    {
        minx = MAXN;
        for (j = 1; j <= N; ++j)
        {
            if (!visit[j] && dist[j] < minx)
            {
                minx = dist[j];
                pos = j;
            }
        }

        if (minx == MAXN)
            return -1;
        visit[pos] = true;
        shortx += minx;
        for (j = 1; j <= N; ++j)
        {
            if (!visit[j] && dist[j] > point[pos][j])
                dist[j] = point[pos][j];
        }
    }
    return shortx;
}
int main(void)
{
    int i, j;
    int x, y;
    int ans;
    int N, M, V;
    while (2 == scanf("%d %d", &N, &M))
    {
        if (0 == N)
            break;
        memset(point, MAXN, sizeof(point));
        for (i = 1; i <= N; ++i)
        {
            scanf("%d%d%d", &x, &y, &V);
            point[x][y] = point[y][x] = V;
        }
        ans = Prim(M);
        if (-1 == ans)
            printf("?\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}