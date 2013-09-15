/*
ID: 31415926
LANG: C++
TASK: clocks
*/

#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cctype>
#include <climits>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

inline int setClock(int clset, char cl, int val)
{
    int pos = (toupper(cl) - 'A') << 1;
    int bits = ((val / 3) & 3) << pos;
    int mask = ~(3 << pos);
    return clset & mask | bits;
}

inline int getClock(int clset, char cl)
{
    int pos = (toupper(cl) - 'A') << 1;
    int bits = ((clset >> pos) & 3) * 3;
    return bits ? bits : 12;
}

inline int tickClock(int clset, char cl)
{
    int pos = (toupper(cl) - 'A') << 1;
    int bits = (((clset >> pos) + 1) & 3) << pos;
    int mask = ~(3 << pos);
    return clset & mask | bits;
}

inline int moveClock(int clset, int move)
{
    static const char affected[][8] = {
        "", "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
    for (const char *p = affected[move]; *p; ++p)
        clset = tickClock(clset, *p);
    return clset;
}

int depthLimit;
int solution[1024];
int knownBest[1 << 18];

bool searchIterativeDeepening(int clset, int depth, int sameOpCnt)
{
    bool ret = false;

    if (sameOpCnt >= 4)
        return ret;

    if (knownBest[clset] <= depth)
        return ret;

    knownBest[clset] = depth;

    if (depth >= depthLimit)
    {
        if (clset == 0)
            ret = true;
        goto lovely;
    }
    else
    {
        int move = depth > 0 ? solution[depth - 1] : 1;

        for ( ; move <= 9; ++move)
        {
            int same = 1;

            if (depth > 0 && solution[depth - 1] == move)
                same = sameOpCnt + 1;

            solution[depth] = move;

            if (searchIterativeDeepening(moveClock(clset, move), depth + 1, same))
            {
                ret = true;
                goto lovely;
            }
        }
    }

lovely:

    return ret;
}

int main()
{
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);

    int initClset = 0;

    for (char c = 'A'; c <= 'I'; ++c)
    {
        int val;
        scanf("%d", &val);
        initClset = setClock(initClset, c, val);
    }

    fprintf(stderr, "%d\n", initClset);

    for (depthLimit = 0; depthLimit <= 100; ++depthLimit) {

        fill(knownBest, knownBest + sizeof( knownBest) /
                                    sizeof(*knownBest), INT_MAX);

        fprintf(stderr, "starting depth %d\n", depthLimit);

        if (searchIterativeDeepening(initClset, 0, 0)) break;
    }

    if (depthLimit)
        printf("%d", solution[0]);
    for (int i = 1; i < depthLimit; ++i)
        printf(" %d", solution[i]);
    printf("\n");

    return EXIT_SUCCESS;
}
