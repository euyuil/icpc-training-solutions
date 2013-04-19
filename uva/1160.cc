#include <cstdio>

using namespace std;

const int N = 111111;
int id[N], accu;

void reset()
{
    for (int i = 0; i < N; ++i)
        id[i] = i;
    accu = 0;
}

int find(int i)
{
    return i == id[i] ? i : find(id[i]);
}

void join(int a, int b)
{
    id[find(a)] = find(b);
}

inline int readline(int &a, int &b)
{
    // 1 for succ, 2 for case ends, 3 for eof
    int r = scanf("%d", &a);
    if (r == EOF)
        return 3;
    if (a == -1)
        return 2;
    scanf("%d", &b);
    return 1;
}

int main()
{
    int a, b, r;

    reset();

    while (true)
    {
        r = readline(a, b);
        if (r == 3)
            break;
        if (r == 2)
        {
            printf("%d\n", accu);
            reset();
            continue;
        }
        if (find(a) == find(b))
            ++accu;
        else
            join(a, b);
    }
    return 0;
}
