#include <cmath>
#include <cstdio>

using namespace std;

int pow_mod(int a, int b, int mod)
{
    int t = a % mod, ret = 1;
    while (b)
    {
        if (b & 1)
        {
            ret *= t;
            ret %= mod;
        }
        t *= t;
        t %= mod;
        b >>= 1;
    }
    return ret;
}

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        if (a == 0 && b == 0)
            break;
        printf("%d\n", pow_mod(a, b, 1000));
    }
    return 0;
}
