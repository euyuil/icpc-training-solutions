#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

#define OUT_INT(x) \
{ if (is1st) printf("%d", x), is1st = false; \
  else printf(" %d", x); }

int main()
{
    bool is1st;
    int T, n, sqn, fg, gc, dt;
    scanf("%d", &T);
    while (T--)
    {
        is1st = true;
        scanf("%d", &n);
        if (n != 2)
        {
            sqn = int(ceil(sqrt(double(n))));
            gc = n / sqn;
            fg = n % sqn;
            if (n != sqn * sqn && fg == 0)
                fg = sqn, --gc;
            if (gc == sqn - 1)
            {
                for (int i = fg; i >= 1; --i)
                    OUT_INT(i);
            }
            else if (gc == sqn - 2)
            {
                OUT_INT(1);
                for (int i = fg; i > 1; --i)
                    OUT_INT(i);
            }
            for (int i = 1; i <= gc; ++i)
                for (int j = 1, k = i * sqn + fg; j <= sqn; ++j, --k)
                    OUT_INT(k);
            puts("");
        }
        else
        {
            puts("1 2");
        }
    }
    return 0;
}
