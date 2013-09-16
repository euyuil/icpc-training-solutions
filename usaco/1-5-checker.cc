/*
ID: 31415926
LANG: C++
TASK: checker
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int maxDepth = 0;
int solutionCount = 0;
int currentSolution[20];

void search(int depth, int left, int down, int right)
{
    if (depth >= maxDepth)
    {
        if (solutionCount < 3)
        {
            printf("%d", currentSolution[0] + 1);
            for (int i = 1; i < maxDepth; ++i)
                printf(" %d", currentSolution[i] + 1);
            printf("\n");
        }
        ++solutionCount;
    }
    else
    {
        left <<= 1; right >>= 1;
        int mask = left | down | right;

        for (int i = 0; i < maxDepth; ++i)
        {
            int bit = 1 << i;

            if (bit & mask)
                continue;

            currentSolution[depth] = i;

            search(depth + 1, left | bit, down | bit, right | bit);
        }
    }
}

int main()
{
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);

    scanf("%d", &maxDepth);

    search(0, 0, 0, 0);

    printf("%d\n", solutionCount);

    return EXIT_SUCCESS;
}
