#include <cstdio>
#include <functional>

using namespace std;

const int N = 55555;
const int LOGN = 18;

int n, q;
int log2[N];
int pow2[LOGN];

void init()
{
    for (int k = 1; k < 17; ++k)
        for (int i = (1 << (k - 1)); i < (1 << k) && i < N; ++i)
            log2[i] = k - 1;
    for (int i = 0; i < LOGN; ++i)
        pow2[i] = (1 << i);
}

template <class cmp>
struct stab
{
    cmp lt;
    int f[N][LOGN];
    stab(cmp lt) : lt(lt) { }
    void prep() {
        // invoker should fill f[i][0] first
        for (int j = 1; j <= log2[n]; ++j) {
            for (int i = 0; i < n; ++i) {
                int j2 = j - 1;
                int i2 = i + pow2[j2];
                if (i2 >= n)
                    f[i][j] = f[i][j2];
                else if (lt(f[i][j2], f[i2][j2]))
                    f[i][j] = f[i][j2];
                else
                    f[i][j] = f[i2][j2];
            }
        }
    }
    int query(int a, int b) {
        int i1 = a;
        int j1 = log2[b - a + 1];
        int i2 = b - pow2[j1] + 1;
        int j2 = j1;
        if (lt(f[i1][j1], f[i2][j2]))
            return f[i1][j1];
        else
            return f[i2][j2];
    }
};

stab<greater<int> > larg = stab<greater<int> >(greater<int>());
stab<less<int> > smal = stab<less<int> >(less<int>());

int main()
{
    init();

    while (scanf("%d%d", &n, &q) != EOF)
    {
        for (int i = 0; i < n; ++i)
        {
            int h;
            scanf("%d", &h);
            larg.f[i][0] = smal.f[i][0] = h;
        }

        larg.prep();
        smal.prep();

        /*
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= log2[n]; ++j)
                printf("%d ", larg.f[i][j]);
            puts("");
        }
        */

        for (int i = 0; i < q; ++i)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            --a, --b;
            int l = larg.query(a, b);
            int s = smal.query(a, b);
            printf("%d\n", l - s);
        }
    }

    return 0;
}
