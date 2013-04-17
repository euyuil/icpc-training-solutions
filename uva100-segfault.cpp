#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10000000;

int ans[3 * N + 2];

inline void init()
{
    memset(ans, 0, sizeof(ans));

    for (int i = 1; i < N; ++i)
    {
        if (ans[i] != 0)
            continue;

        int j = i;
        int k = 1;

        while (j > 1)
        {
            if (j & 1)
                j = 3 * j + 1;
            else
                j >>= 1;

            if (ans[j])
            {
                k += ans[j];
                break;
            }
            ++k;
        }

        ans[i] = k;
    }
}


inline int process(int a, int b)
{
    int x = 0;

    if (a > b)
        swap(a, b);

    for (int i = a; i <= b; ++i)
        if (x < ans[i])
            x = ans[i];

    return x;
}

int main()
{
    init();

    int a, b;

    while (cin >> a >> b)
        cout << a << ' ' << b << ' ' << process(a, b) << endl;

    return 0;
}
