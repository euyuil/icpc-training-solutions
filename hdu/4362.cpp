#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int M = 55;
const int N = 1111;
const ll INF = 999999999999999999ll;

struct ball_t
{
    ll pos, cost;

    inline bool operator<(const ball_t &b) const
    {
        return pos < b.pos;
    }
};

ll least[M][N], left[N], right[N];
ball_t balls[M][N];

int main()
{
    freopen("input.txt", "r", stdin);

    int T, m, n, x;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &m, &n, &x);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%lld", &balls[i][j].pos);
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%lld", &balls[i][j].cost);
        for (int i = 1; i <= m; ++i)
            sort(balls[i]+1, balls[i]+1 + n);

        for (int i = 1; i <= n; ++i)
            least[1][i] = balls[1][i].cost + abs(balls[1][i].pos - x);

        for (int i = 2; i <= m; ++i)
        {
            left[1] = least[i-1][1];
            for (int j = 2; j <= n; ++j)
                left[j] = min(least[i-1][j], left[j-1] -
                    balls[i-1][j-1].pos + balls[i-1][j].pos);

            right[n] = least[i-1][n];
            for (int j = n - 1; j >= 1; --j)
                right[j] = min(least[i-1][j], right[j+1] +
                    balls[i-1][j+1].pos - balls[i-1][j].pos);

            for (int j = 1; j <= n; ++j)
            {
                ball_t *l = upper_bound(balls[i-1]+1,
                    balls[i-1]+1 + n, balls[i][j]) - 1;
                ball_t *r = lower_bound(balls[i-1]+1,
                    balls[i-1]+1 + n, balls[i][j]);
                int il = l - balls[i-1], ir = r - balls[i-1];

                ll vl = INF, vr = INF;
                if (il >= 1 && il <= n &&
                        balls[i-1][il].pos <= balls[i][j].pos)
                    vl = left[il] + balls[i][j].pos - balls[i-1][il].pos;
                if (ir >= 1 && ir <= n)
                    vr = right[ir] - balls[i][j].pos + balls[i-1][ir].pos;

                least[i][j] = min(vl, vr) + balls[i][j].cost;
            }
        }

        ll result = INF;
        for (int i = 1; i <= n; ++i)
            result = min(result, least[m][i]);
        printf("%lld\n", result);
    }
    return 0;
}
