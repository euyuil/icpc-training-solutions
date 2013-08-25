#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int id[111], xs[1111], ys[1111];
bool has[111];

inline void init()
{
    for (int i = 0; i < 111; ++i)
        id[i] = i;
    memset(xs, -1, sizeof xs);
    memset(ys, -1, sizeof ys);
    memset(has, false, sizeof has);
}

inline int find(int i)
{
    return i == id[i] ? i : (i = find(id[i]));
}

inline void join(int i, int j)
{
    id[find(i)] = find(j);
}

int main()
{
    int n; cin >> n;
    init();
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (xs[x] != -1)
            join(i, xs[x]);
        if (ys[y] != -1)
            join(i, ys[y]);
        xs[x] = i;
        ys[y] = i;
    }
    int cnt = -1;
    for (int i = 1; i <= n; ++i)
        has[find(i)] = true;
    for (int i = 1; i <= n; ++i)
        if (has[i])
            ++cnt;
    cout << cnt << endl;
    return 0;
}
