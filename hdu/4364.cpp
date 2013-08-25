#include <cstdio>
#include <cstring>

using namespace std;

typedef int elem;

elem plus(elem a, elem b)
{
    return a ^ b;
}

elem mult(elem a, elem b)
{
    elem result = b;
    if (a == 1)
        return result;
    if (a == 2)
        result <<= 1;
    if (a == 3)
        result = (b << 1) ^ b;
    if (result > 0xff)
        result = (0x1b ^ result) % 0x100;
    return result;
}

struct matrix
{
    elem w[4][4];

    inline matrix()
    {
        memset(w, 0, sizeof w);
    }

    inline matrix operator*(const matrix &b) const
    {
        matrix r;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                for (int k = 0; k < 4; ++k)
                    r.w[i][j] = plus(r.w[i][j], mult(w[i][k], b.w[k][j]));
        return r;
    }

    inline void read()
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                scanf("%x", &w[i][j]);
    }

    inline void write() const
    {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (j == 3)
                    printf("%02X\n", w[i][j] % 0x100);
                else
                    printf("%02X ", w[i][j] % 0x100);
    }
};

matrix fact, user;

inline void init()
{
    elem w[4][4] = {
        {2, 3, 1, 1},
        {1, 2, 3, 1},
        {1, 1, 2, 3},
        {3, 1, 1, 2}};

    memcpy(fact.w, w, sizeof w);
}

int main()
{
    freopen("input.txt", "r", stdin);

    init();
    int T;
    scanf("%d", &T);

    while (T--)
    {
        user.read();
        (fact * user).write();
        if (T)
            puts("");
    }

    return 0;
}
