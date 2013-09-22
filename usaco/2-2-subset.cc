/*
ID: 31415926
LANG: C++
TASK: subset
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 44;
const int S = (1 + N) * N / 2;

unsigned dp[S];
int n, sum, half;

int main()
{
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    cin >> n;

    sum = (1 + n) * n / 2;

    if (sum % 2 == 0)
    {
        half = sum / 2;

        dp[0] = 1;

        for (int i = 1; i <= n; ++i)
            for (int j = sum; j - i >= 0; --j)
                if (dp[j - i]) dp[j] += dp[j - i];

        cout << dp[half] / 2 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return EXIT_SUCCESS;
}
