/*
ID: 31415926
LANG: C++
TASK: castle
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

const int dx[] = { -1,  0,  1,  0};
const int dy[] = {  0, -1,  0,  1};
const char chdir[] = "WNES";

int nx, ny, castle[55][55];

inline bool accessible(int x, int y, int dir)
{
    return !((castle[y][x] >> dir) & 1);
}

inline bool inside(int x, int y)
{
    return x >= 0 && y >= 0 && x < nx && y < ny;
}

int dsu[3333], dsuSize[3333];

inline void initDsu()
{
    for (int i = 0; i < 3333; ++i)
        dsu[i] = i;
}

inline int posi(int x, int y)
{
    return y * nx + x;
}

int root(int i)
{
    return i == dsu[i] ? i : (dsu[i] = root(dsu[i]));
}

inline void join(int i, int j)
{
    dsu[root(i)] = root(j);
}

int main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    scanf("%d%d", &nx, &ny);

    initDsu();

    for (int y = 0; y < ny; ++y)
        for (int x = 0; x < nx; ++x)
            scanf("%d", &castle[y][x]);

    for (int y = 0; y < ny; ++y)
        for (int x = 0; x < nx; ++x)
            for (int dir = 2; dir <= 3; ++dir)
                if (accessible(x, y, dir))
                    join(posi(x, y), posi(x + dx[dir], y + dy[dir]));

    int roomCount = 0;

    for (int y = 0; y < ny; ++y)
    {
        for (int x = 0; x < nx; ++x)
        {
            int pos = posi(x, y);
            if (root(pos) == pos)
                ++roomCount;
            ++dsuSize[dsu[pos]];
        }
    }

    int maxSize = 0;

    for (int i = 0; i < 3333; ++i)
        maxSize = max(maxSize, dsuSize[i]);

    int maxCombine = INT_MIN, mcx, mcy, mcdir;

    for (int x = 0; x < nx; ++x)
    {
        for (int y = ny - 1; y >= 0; --y)
        {
            int pos = posi(x, y);

            for (int dir = 1; dir <= 2; ++dir)
            {
                if (!accessible(x, y, dir) && inside(x + dx[dir], y + dy[dir]))
                {
                    int pot = posi(x + dx[dir], y + dy[dir]);

                    if (root(pos) != root(pot))
                    {
                        int combine = dsuSize[root(pos)] + dsuSize[root(pot)];

                        if (maxCombine < combine)
                        {
                            maxCombine = combine;
                            mcx = x; mcy = y; mcdir = dir;
                        }
                    }
                }
            }
        }
    }

    printf("%d\n%d\n%d\n%d %d %c\n", roomCount,
                                     maxSize,
                                     maxCombine,
                                     mcy + 1, mcx + 1, chdir[mcdir]);

    for (int y = 0; y < ny; ++y)
    {
        for (int x = 0; x < nx; ++x)
            fprintf(stderr, "%d ", dsu[posi(x, y)]);
        fprintf(stderr, "\n");
    }

    return EXIT_SUCCESS;
}
