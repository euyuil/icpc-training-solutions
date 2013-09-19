/*
ID: 31415926
LANG: C++
TASK: holstein
*/

#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

const int NV = 25 + 5;
const int NF = 15 + 5;

int nv, vita[NV], nf, feed[NF][NV], usedCount, bestCount = INT_MAX;
bool used[NF], bestUsed[NF];

inline bool enough()
{
    for (int i = 0; i < nv; ++i)
        if (vita[i] > 0)
            return false;
    return true;
}

inline void dofeed(int f)
{
    for (int i = 0; i < nv; ++i)
        vita[i] -= feed[f][i];
    used[f] = true;
    ++usedCount;
}

inline void unfeed(int f)
{
    for (int i = 0; i < nv; ++i)
        vita[i] += feed[f][i];
    used[f] = false;
    --usedCount;
}

void search(int f)
{
    if (usedCount >= bestCount)
        return;

    if (enough())
    {
        memcpy(bestUsed, used, sizeof(used));
        bestCount = usedCount;
    }

    if (f >= nf)
    {
        // don't do anything
    }
    else
    {
        // use it
        dofeed(f);
        search(f + 1);
        unfeed(f);

        // don't use it
        search(f + 1);
    }
}

int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    scanf("%d", &nv);
    for (int i = 0; i < nv; ++i)
        scanf("%d", vita + i);

    scanf("%d", &nf);
    for (int i = 0; i < nf; ++i)
        for (int j = 0; j < nv; ++j)
            scanf("%d", &feed[i][j]);

    search(0);

    printf("%d", bestCount);
    for (int i = 0; i < nf; ++i)
        if (bestUsed[i])
            printf(" %d", i + 1);
    printf("\n");

    return EXIT_SUCCESS;
}
