#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int n, l, a, b, m, l2, l2lt, l2gt, cnt;
    while (scanf("%d%d%d%d%d", &n, &l, &a, &b, &m) != EOF)
    {
        cnt = 0;
        l2 = (l >> 1);
        l2lt = INT_MIN;
        l2gt = INT_MAX;
        while (n--)
        {
            b += a;
            b %= m;
            if (b <= l2)
            {
                ++cnt;
                if (l2lt < b)
                    l2lt = b;
            }
            else if (l2gt > b)
                l2gt = b;
        }
        if (l2gt != INT_MAX && l2lt + l2gt <= l)
            ++cnt;
        printf("%d\n", cnt);
    }
    return 0;
}
