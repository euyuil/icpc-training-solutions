/*
ID: 31415926
LANG: C++
TASK: nocows
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 223;
const int K = 123;
const int MOD = 9901;

int n, k;
int dp[N][K]; // sol for n nodes and k depth
int sum[N][K]; // sol for n nodes and depth <= k

int main()
{
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);

    cin >> n >> k;

    dp[1][1] = sum[1][1] = 1;

    for (int i = 2; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int l = 1; l <= j - 2; ++l)
            {
                int r = j - 1 - l;

                dp[j][i] = (dp[j][i] + dp[l][i-1] * sum[r][i-1]) % MOD;
                dp[j][i] = (dp[j][i] + sum[l][i-1] * dp[r][i-1]) % MOD;
                dp[j][i] = (dp[j][i] - dp[l][i-1] * dp[r][i-1] + MOD) % MOD;
            }

            sum[j][i] = (sum[j][i-1] + dp[j][i]) % MOD;
        }
    }

    cout << dp[n][k] << endl;

    return EXIT_SUCCESS;
}
