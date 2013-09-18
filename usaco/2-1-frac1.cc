/*
ID: 31415926
LANG: C++
TASK: frac1
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

struct frac
{
    int upper, lower;

    bool operator<(const frac &b) const
    {
        int diff = upper * b.lower - b.upper * lower;
        if (diff == 0) return lower < b.lower;
        return diff < 0;
    }

    bool operator==(const frac &b) const
    {
        return upper * b.lower == b.upper * lower;
    }
};

int main()
{
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);

    int n, size, pos = 0;

    scanf("%d", &n);
    size = (n + 3) * n / 2;

    frac *p = new frac[size];

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= i; ++j)
            p[pos].lower = i,
            p[pos].upper = j,
            ++pos;

    sort(p, p + size);

    size = unique(p, p + size) - p;

    for (int i = 0; i < size; ++i)
        printf("%d/%d\n", p[i].upper, p[i].lower);

    delete [] p;

    return EXIT_SUCCESS;
}
