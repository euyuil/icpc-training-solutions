#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 11111;

int n;
int dist[N];
bool visited[N];
map<int, vector<pair<int, int> > > g; // vertex => (another vertex, edge weight)

inline void init()
{
    memset(dist, 0, sizeof(dist));
}

inline void reset_visited()
{
    memset(visited, false, sizeof(visited));
}

inline void input()
{
    int v, w;
    scanf("%d", &n);
    for (int u = 2; u <= n; ++u)
    {
        scanf("%d%d", &v, &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
}

int find_farthest_from(int s)
{
    int farthest = -1, distance = -1;

    queue<pair<int, int> > q;
    q.push(make_pair(s, 0));

    reset_visited();
    visited[s] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int u = p.first;
        int du = p.second;

        fprintf(stderr, "dist[%d] = %d\n", u, du);
        dist[u] = max(du, dist[u]); // extra step

        if (du > distance)
        {
            farthest = u;
            distance = du;
        }

        vector<pair<int, int> > &edge_list = g[u];
        for (int i = 0; i < edge_list.size(); ++i)
        {
            int v = edge_list[i].first;
            if (visited[v])
                continue;
            visited[v] = true;
            int w = edge_list[i].second;
            int dv = du + w;
            q.push(make_pair(v, dv));
        }
    }

    fprintf(stderr, "farthest from %d is %d, dist = %d\n", s, farthest, distance);

    return farthest;
}

inline pair<int, int> find_diameter()
{
    int s = find_farthest_from(1);
    int t = find_farthest_from(s);
    int z = find_farthest_from(t); // extra step
    return make_pair(s, t);
}

inline void output()
{
    for (int i = 1; i <= n; ++i)
        printf("%d\n", dist[i]);
}

int main()
{
    init();
    input();
    find_diameter();
    output();
    return EXIT_SUCCESS;
}
