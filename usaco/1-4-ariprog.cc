/*
ID: 31415926
LANG: C++
TASK: ariprog
*/

#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 125666;

vector<int> squares;
bool bisquares[N];
int biscount[N];

int main()
{
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0; i <= m; ++i)
        squares.push_back(i * i);

    memset(bisquares, 0, sizeof(bisquares));

    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            bisquares[squares[i] + squares[j]] = true;

    bool flag = false;
    int maxStep = squares[m] * 2 / n + 5;

    for (int step = 1; step <= maxStep; ++step)
    {
        // fprintf(stderr, "step %d / %d\n", step, maxStep);
        for (int i = 0; i < N; ++i)
        {
            if (bisquares[i])
            {
                if (i - step < 0 || !bisquares[i - step])
                    biscount[i] = 1;
                else
                    biscount[i] = 1 + biscount[i - step];

                if (biscount[i] >= n)
                {
                    printf("%d %d\n", i - step * (n - 1), step);
                    flag = true;
                }
            }
        }
    }

    if (!flag)
        printf("NONE\n");

    return EXIT_SUCCESS;
}
