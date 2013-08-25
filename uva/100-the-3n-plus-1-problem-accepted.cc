#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

inline int process(int a, int b)
{
    int ret = 0;

    if (a > b)
        swap(a, b);

    for (int i = a; i <= b; ++i)
    {
        int k = 1;
        long long j = i;

        while (j > 1)
        {
            if (j & 1)
                j = 3 * j + 1;
            else
                j >>= 1;
            ++k;
        }

        ret = max(ret, k);
    }

    return ret;
}

int main()
{
    int a, b;

    while (cin >> a >> b)
        cout << a << ' ' << b << ' ' << process(a, b) << endl;

    return 0;
}
