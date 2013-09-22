/*
ID: 31415926
LANG: C++
TASK: lamps
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int n, c, on, off;

inline int togroup(int n)
{
    return ((n & 1) | ((n % 3 == 1) << 1));
}

bool useful[0x10];

void search(int depth, int state)
{
    if (depth >= c)
    {
        if ((state & on) == on && (~state & off) == off)
            useful[state] = true;
    }
    else
    {
        // press button 1, all groups affected.
        search(depth + 1, state ^ 0xf);

        // press button 2, group 1 and 3 affected.
        search(depth + 1, state ^ 0xa);

        // press button 3, group 0 and 2 affected.
        search(depth + 1, state ^ 0x5);

        // press button 4, group 2 and 3 affected.
        search(depth + 1, state ^ 0xc);
    }
}

int main()
{
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);

    scanf("%d%d", &n, &c);

    if (c > 4) c = c % 4 + 4;

    int t;
    scanf("%d", &t);
    while (t != -1)
        on |= 1 << togroup(t), scanf("%d", &t);

    scanf("%d", &t);
    while (t != -1)
        off |= 1 << togroup(t), scanf("%d", &t);

    search(0, 0xf);

    bool possible = false;

    for (int i = 0;  i < 0x10; ++i)
    {
        int j = (i & 8) | (i & 2) | ((i & 4) >> 2) | ((i & 1) << 2);

        if (useful[j])
        {
            possible = true;

            for (int k = 1; k <= n; ++k)
                printf("%c", (j & (1 << togroup(k))) ? '1' : '0');
            printf("\n");
        }
    }

    if (!possible)
        printf("IMPOSSIBLE\n");

    return EXIT_SUCCESS;
}
