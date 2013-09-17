/*
ID: 31415926
LANG: C++
TASK: hamming
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int countOnes(int a)
{
    a = (a & 0x55555555) + ((a >> 0x01) & 0x55555555);
    a = (a & 0x33333333) + ((a >> 0x02) & 0x33333333);
    a = (a & 0x0f0f0f0f) + ((a >> 0x04) & 0x0f0f0f0f);
    a = (a & 0x00ff00ff) + ((a >> 0x08) & 0x00ff00ff);
    a = (a & 0x0000ffff) + ((a >> 0x10) & 0x0000ffff);
    return a;
}

int hammingDistance(int a, int b)
{
    return countOnes(a ^ b);
}

int codewords[1024], codewordCount = 0;

int main()
{
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);

    int n, b, d;
    scanf("%d%d%d", &n, &b, &d);

    codewords[codewordCount++] = 0;

    for (int i = 1; i < (1 << b); ++i)
    {
        int j;

        for (j = 0; j < codewordCount; ++j)
            if (hammingDistance(i, codewords[j]) < d)
                break;

        if (j == codewordCount)
            codewords[codewordCount++] = i;
    }

    int i;

    for (i = 0; i < min(n, codewordCount); ++i)
    {
        if (i % 10 == 0)
            printf("%d", codewords[i]);
        else if (i % 10 == 9)
            printf(" %d\n", codewords[i]);
        else
            printf(" %d", codewords[i]);
    }

    if (i % 10 != 0)
        printf("\n");

    return EXIT_SUCCESS;
}
