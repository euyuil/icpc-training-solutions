#include <cstdio>
#include <cstring>

using namespace std;

const int N = 11111;
const int M = 11;

int dfa[N*M][M], sz, T, n;
bool dead[N*M];
char buffer[M];

void init()
{
    sz = 1;
    memset(dfa, 0, sizeof(dfa));
    memset(dead, false, sizeof(dead));
}

bool insert(const char *str)
{
    int x = 0, osz = sz;
    while (*str)
    {
        int m = *str - '0' + 1;
        int nx = dfa[x][m];
        if (nx == 0)
            dfa[x][m] = nx = sz++;
        if (dead[nx])
            return false;
        x = nx, ++str;
    }
    dead[x] = true;
    return osz != sz;
}

int main()
{
    scanf("%d", &T);
    for (int C = 1; C <= T; ++C)
    {
        bool flag = true;

        init();
        scanf("%d", &n);

        while (n--)
        {
            scanf("%s", buffer);
            flag = flag && insert(buffer);
        }

        if (flag)
            printf("Case %d: YES\n", C);
        else
            printf("Case %d: NO\n", C);
    }
    return 0;
}
