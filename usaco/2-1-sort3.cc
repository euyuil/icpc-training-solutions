/*
ID: 31415926
LANG: C++
TASK: sort3
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

    int n, cnt[4] = {0}, mismat[4][4] = {{0}};

    scanf("%d", &n);

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", arr + i);
        cnt[arr[i]]++;
    }

    int pos = 0;

    for (int k = 1; k <= 3; ++k)
    {
        for (int j = 0; j < cnt[k]; ++j)
        {
            if (arr[pos] != k)
                mismat[k][arr[pos]]++;

            ++pos;
        }
    }

    int exchanges = 0, cycles = 0;

    for (int i = 1; i <= 3; ++i)
    {
        for (int j = i + 1; j <= 3; ++j)
        {
            int steps = min(mismat[i][j], mismat[j][i]);

            mismat[i][j] -= steps;
            mismat[j][i] -= steps;

            exchanges += steps;

            cycles += mismat[i][j];
            cycles += mismat[j][i];

            mismat[i][j] = 0;
            mismat[j][i] = 0;
        }
    }

    printf("%d\n", exchanges + cycles / 3 * 2);

    delete [] arr;

    return EXIT_SUCCESS;
}
