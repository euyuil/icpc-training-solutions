/*
ID: 31415926
LANG: C++
TASK: numtri
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1234;
int tri[N][N], n;

int main()
{
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &tri[i][j]);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, tri[n][i]);

    printf("%d\n", ans);

    return EXIT_SUCCESS;
}
