#include <set>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 101111;
const int M = N / 2;

struct s
{
    set<int> ts[M];

    void operator()(int i, int j)
    {
        ts[i].insert(j);
    }

    bool operator()(int i, int j) const
    {
        if (i == 0)
            return true;
        return ts[i].find(j) != ts[i].end();
    }

} sol;

inline void reset()
{
}

inline void fill_sol(int i, int num)
{
    while ((num & 1) == 0)
    {
        sol(i, 2);
        num >>= 1;
    }
    for (int j = 3; num != 1; j += 2)
    {
        while (num % j == 0)
        {
            sol(i, j);
            num /= j;
        }
    }
}

inline bool good_prev(int i, int num)
{
    while ((num & 1) == 0)
    {
        if (((const s &)sol)(i, 2))
            return true;
        num >>= 1;
    }
    for (int j = 3; num != 1; j += 2)
    {
        while (num % j == 0)
        {
            if (((const s &)sol)(i, j))
                return true;
            num /= j;
        }
    }
    return false;
}

int main()
{
    int n, k = 0, num;
    reset();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num;
        for (int j = k; j >= 0; --j)
        {
            if (good_prev(j, num))
            {
                fill_sol(j + 1, num);
                k = max(k, j + 1);
            }
        }
    }
    cout << k << endl;
    return 0;
}
