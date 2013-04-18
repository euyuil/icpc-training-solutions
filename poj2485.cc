#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;
const int N = 555;

int w[N][N], cost[N], n, T, longest;
bool vst[N];

inline void init()
{
    memset(vst, false, sizeof(vst));
    fill(cost, cost + N, INF);

    vst[0] = true;
    longest = -1;
}

int prim()
{
    int ret = 0;
    for (int i = 1; i < n; ++i)
        cost[i] = w[0][i];
    for (int z = 1; z < n; ++z)
    {
        int x = -1, least = INF;
        for (int i = 0; i < n; ++i)
            if (!vst[i] && least > cost[i])
                least = cost[i], x = i;
        ret += least, vst[x] = true, longest = max(longest, least);
        for (int i = 0; i < n; ++i)
            if (!vst[i] && cost[i] > w[i][x])
                cost[i] = w[i][x];
    }
    return ret;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &w[i][j]);
        prim();
        printf("%d\n", longest);
    }
    return 0;
}
