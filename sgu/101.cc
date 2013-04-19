#include <list>
#include <vector>
#include <cstdio>
#include <utility>
#include <cstdlib>

using namespace std;

typedef list<int> lint;
typedef vector<int> vint;
typedef vector<lint> vlint;
typedef pair<int, int> prii;
typedef vector<prii> vprii;
typedef vector<bool> vbool;

int n;
vlint ves; // vertex to edges.
vprii es; // edges.
vbool vst; // vertex visited;
vbool est; // edge visited.
vint vstk; // vertex stack.
vint vrst; // vertex result.
vint estk; // edge stack.
vint erst; // edge result.

inline void init()
{
    ves.clear(); ves.resize(7);
    es.clear();
}

inline void insert(int u, int v)
{
    ves[u].push_back(es.size());
    ves[v].push_back(es.size());
    es.push_back(make_pair(u, v));
}

void search(int u)
{
    if (vst[u]) return; vst[u] = true;
    lint::iterator e; lint &ve = ves[u];
    for (e = ve.begin(); e != ve.end(); ++e)
    {
        int v = es[*e].first == u ? es[*e].second : es[*e].first;
        search(v);
    }
}

inline bool connected()
{
    vst.clear(); vst.resize(7, false);
    int c = 0, last_node;
    for (int i = 0; i < 7; ++i)
        if (ves[i].size() != 0)
            ++c, last_node = i;
    search(last_node);
    for (int i = 0; i < 7; ++i)
        if (vst[i])
            --c;
    return c == 0;
}

inline void tour(int u)
{
    tour_start:
    {
        lint::iterator e; lint &ve = ves[u];
        for (e = ve.begin(); e != ve.end(); ++e)
        {
            if (est[*e]) continue; est[*e] = true;
            u = es[*e].first == u ? es[*e].second : es[*e].first;
            break;
        }
        if (e == ve.end()) return;
        vstk.push_back(u);
        estk.push_back(*e);
    }
    goto tour_start;
}

inline void euler(int u)
{
    est.clear(); est.resize(es.size(), false);
    vrst.clear(); erst.clear();
    vstk.clear(); estk.clear();
    vstk.push_back(u);
    for (int i = 0; i < n; ++i)
    {
        tour(vstk.back());
        vrst.push_back(vstk.back()); vstk.pop_back();
        erst.push_back(estk.back()); estk.pop_back();
    }
    // vertices are one more than edges.
    // and there is vstk.back() == u.
    vrst.push_back(vstk.back()); vstk.pop_back();
}

inline int start()
{
    int odd_count = 0, last_odd = -1, last_node = -1;
    for (int i = 0; i < ves.size(); ++i) {
        if (ves[i].size() % 2 == 1)
            ++odd_count, last_odd = i;
        else if (ves[i].size() != 0)
            last_node = i;
    }
    if (odd_count == 0) return last_node;
    if (odd_count == 2) return last_odd;
    return -1;
}

int main()
{
    // freopen("101.domino.txt", "r", stdin);

    scanf("%d", &n); init();
    for (int i = 0; i < n; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        insert(u, v);
    }
    int s; if (!connected() || (s = start()) == -1) {
        printf("No solution\n");
    } else {
        euler(s);
        for (int i = 0; i < erst.size(); ++i)
            printf("%d %c\n", erst[i] + 1,
                vrst[i] == es[erst[i]].first ? '+' : '-');
    }
    return 0;
}
