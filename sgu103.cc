#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llint;

struct node_t
{
    char init_color; // {B, P}
    int init_rem; // [1, 100]
    int blue_period; // [1, 100]
    int purple_period; // [1, 100]
};

struct edge_t
{
    int node_a;
    int node_b;
    int length; // [1, 100]
};

const int N = 333;
const int M = 15555;
const llint INF = 99999999999999999ll;
int src, dest, n, m;
node_t nodes[N];
edge_t edges[M];
vector<vector<int> > edges_of_node;

inline int first_complete_period(const node_t &node)
{
    if (node.init_color == 'B')
        return node.purple_period;
    else return node.blue_period;
}

inline char opposite_color(char c)
{
    if (c == 'B') return 'P';
    else return 'B';
}

inline char color_of_time(const node_t &node, llint now_time)
{
    if (now_time < node.init_rem)
        return node.init_color;
    now_time -= node.init_rem;
    now_time %= (node.blue_period + node.purple_period);
    if (now_time < first_complete_period(node))
        return opposite_color(node.init_color);
    return node.init_color;
}

inline llint next_change_time(const node_t &node, llint now_time)
{
    // never return now_time
    if (now_time < node.init_rem)
        return node.init_rem;
    llint t = now_time - node.init_rem;
    llint sum = node.blue_period + node.purple_period;
    llint k = t / sum, r = t % sum;
    llint fcp = first_complete_period(node);
    if (r < fcp) return llint(node.init_rem) + k * sum + fcp;
    else return llint(node.init_rem) + (k + 1ll) * sum;
}

inline bool can_pass(const edge_t &edge, llint now_time)
{
    if (color_of_time(nodes[edge.node_a], now_time) ==
        color_of_time(nodes[edge.node_b], now_time))
    {
        // printf("can_pass((%d, %d), %lld) = true\n", edge.node_a, edge.node_b, now_time);
        return true;
    }
    // printf("can_pass((%d, %d), %lld) = false\n", edge.node_a, edge.node_b, now_time);
    return false;
}

inline llint pass_time_after(const edge_t &edge, llint now_time)
{
    // might return now_time
    llint time_a, time_b, least;
    time_a = time_b = least = now_time;
    for (int i = 0; i < 5; ++i)
    {
        if (can_pass(edge, least))
            return least;
        if (time_a == least)
            time_a = next_change_time(nodes[edge.node_a], least);
        if (time_b == least)
            time_b = next_change_time(nodes[edge.node_b], least);
        least = min(time_a, time_b);
    }
    return INF;
}

queue<int> pending;
vector<int> path;
bool inqueue[N];
int prev[N];
llint dist[N];

inline int pop_pending()
{
    int ret = pending.front();
    pending.pop();
    inqueue[ret] = false;
    // printf("popped %d\n", ret);
    return ret;
}

inline void push_pending(int e)
{
    if (!inqueue[e])
    {
        inqueue[e] = true;
        pending.push(e);
        // printf("pushed %d\n", e);
    }
}

llint bellman_ford()
{
    memset(inqueue, false, sizeof(inqueue));
    memset(prev, -1, sizeof(prev));
    fill(dist, dist + N, INF);
    push_pending(src);
    dist[src] = 0;

    while (!pending.empty())
    {
        int u = pop_pending();
        for (int e = 0; e < edges_of_node[u].size(); ++e)
        {
            edge_t &edge = edges[edges_of_node[u][e]];
            // printf("%d %d\n", edge.node_a, edge.node_b);
            int v = edge.node_a == u ? edge.node_b : edge.node_a;
            llint new_dist = pass_time_after(edge, dist[u]) + edge.length;
            // printf("dist[%d] from %d could be %lld\n", v, u, new_dist);
            if (dist[v] > new_dist)
            {
                prev[v] = u;
                dist[v] = new_dist;
                push_pending(v);
                // printf("relaxed dist[%d] = %lld, from %d\n", v, new_dist, u);
            }
        }
    }

    /*
    for (int i = 1; i <= n; ++i)
        printf("%d ", dist[i]);
    puts("");
    */

    path.reserve(n);
    for (int i = dest; i != -1; i = prev[i])
        path.push_back(i);

    return dist[dest];
}

char buffer[1024];

int main()
{
    freopen("sgu103.in.txt", "r", stdin);

    scanf("%d%d%d%d", &src, &dest, &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s%d%d%d",
              buffer,
              &nodes[i].init_rem,
              &nodes[i].blue_period,
              &nodes[i].purple_period);
        nodes[i].init_color = *buffer;
    }
    edges_of_node.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d",
              &edges[i].node_a,
              &edges[i].node_b,
              &edges[i].length);
        edges_of_node[edges[i].node_a].push_back(i);
        edges_of_node[edges[i].node_b].push_back(i);
    }

    /*
    printf("next_change_time(1, 2) = %lld\n", next_change_time(nodes[1], 2));
    printf("next_change_time(2, 6) = %lld\n", next_change_time(nodes[2], 6));
    printf("next_change_time(3, 2) = %lld\n", next_change_time(nodes[3], 2));
    printf("next_change_time(4, 38) = %lld\n", next_change_time(nodes[4], 38));

    printf("pass_time_after(0, 0) = %lld\n", pass_time_after(edges[0], 0));
    printf("pass_time_after(1, 0) = %lld\n", pass_time_after(edges[1], 0));
    printf("pass_time_after(2, 0) = %lld\n", pass_time_after(edges[2], 0));
    printf("pass_time_after(3, 0) = %lld\n", pass_time_after(edges[3], 0));
    printf("pass_time_after(4, 0) = %lld\n", pass_time_after(edges[4], 0));

    printf("color_of_time(1, 0) = %c\n", color_of_time(nodes[1], 0));
    printf("color_of_time(1, 2) = %c\n", color_of_time(nodes[1], 2));
    printf("color_of_time(1, 101) = %c\n", color_of_time(nodes[1], 101));
    printf("color_of_time(3, 0) = %c\n", color_of_time(nodes[3], 0));
    printf("color_of_time(3, 2) = %c\n", color_of_time(nodes[3], 2));
    printf("color_of_time(3, 89) = %c\n", color_of_time(nodes[3], 89));
    printf("color_of_time(3, 93) = %c\n", color_of_time(nodes[3], 93));
    */

    llint ans = bellman_ford();
    if (ans >= INF)
        printf("0\n");
    else
    {
        printf("%lld\n", ans);
        if (!path.empty())
        {
            printf("%d", path.back());
            for (int i = path.size() - 2; i >= 0; --i)
                printf(" %d", path[i]);
            puts("");
        }
    }

    return 0;
}
