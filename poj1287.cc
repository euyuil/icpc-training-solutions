#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;
const int N = 66;
const int M = N * N * 2;

int n, m, id[N];

struct edge_t
{
    int u, v, w;

    bool operator<(const edge_t &e) const
    {
        return w < e.w;
    }
}
edges[M * 2];

inline void init()
{
    for (int i = 0; i < N; ++i)
        id[i] = i;
}

int root(int i)
{
    return i == id[i] ? i : id[i] = root(id[i]);
}

inline void join(int i, int j)
{
    id[root(i)] = root(j);
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        if (n == 0)
            break;
        init();
        for (int i = 0; i < m; ++i)
            scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
        sort(edges, edges + m);
        int accu = 0;
        for (int i = 0, x = 1; i < m && x < n; ++i)
            if (root(edges[i].u) != root(edges[i].v))
                accu += edges[i].w, ++x, join(edges[i].u, edges[i].v);
        printf("%d\n", accu);
    }
    return 0;
}
