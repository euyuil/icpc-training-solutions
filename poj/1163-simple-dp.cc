#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 111;

int n, tri[N][N], sum[N][N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            scanf("%d", &tri[i][j]);
    sum[0][0] = tri[0][0];
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            sum[i+1][ j ] = max(sum[i+1][ j ], sum[i][j] + tri[i+1][ j ]);
            sum[i+1][j+1] = max(sum[i+1][j+1], sum[i][j] + tri[i+1][j+1]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, sum[n-1][i]);
    printf("%d\n", ans);
    return 0;
}
