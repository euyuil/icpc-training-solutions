#include <cstdio>
#include <cstring>

using namespace std;

typedef long long llint;

const int N = 55555;
int n, T;
llint ar[N];
char buffer[1024];

inline int lowbit(int a)
{
    return a & (-a);
}

inline void init()
{
    memset(ar, 0, sizeof(ar));
}

void increase(int i, llint v)
{
    while (i <= n)
    {
        ar[i] += v;
        i += lowbit(i);
    }
}

llint query(int i)
{
    llint ret = 0ll;
    while (i > 0)
    {
        ret += ar[i];
        i -= lowbit(i);
    }
    return ret;
}

llint query(int i, int j)
{
    if (i == 1)
        return query(j);
    return query(j) - query(i - 1);
}

int main()
{
    scanf("%d", &T);
    for (int C = 1; C <= T; ++C)
    {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            int x;
            scanf("%d", &x);
            increase(i, llint(x));
        }
        printf("Case %d:\n", C);
        while (scanf("%s", buffer) != EOF)
        {
            int a, b;
            // if (!strcmp(buffer, "End"))
            if (*buffer == 'E')
                break;
            scanf("%d%d", &a, &b);
            // if (!strcmp(buffer, "Add"))
            if (*buffer == 'A')
                increase(a, llint(b));
            // else if (!strcmp(buffer, "Sub"))
            else if (*buffer == 'S')
                increase(a, llint(-b));
            // else if (!strcmp(buffer, "Query"))
            else if (*buffer == 'Q')
                // printf("%I64d\n", query(a, b));
                printf("%lld\n", query(a, b));
        }
    }
}
