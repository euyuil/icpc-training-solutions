/*
ID: 31415926
LANG: C++
TASK: crypt1
*/

#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

vector<int> digits;
int usables[10];

inline bool is_valid(int x, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (!usables[x % 10])
            return false;
        x /= 10;
    }
    if (x) return false;
    return true;
}

int main()
{
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    int n;
    cin >> n;
    digits.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> digits[i];

    memset(usables, 0, sizeof(usables));
    for (int i = 0; i < n; ++i)
        usables[digits[i]] = true;

    int sols = 0;
    for (int a = 0; a < n; ++a)
    {
        for (int b = 0; b < n; ++b)
        {
            for (int c = 0; c < n; ++c)
            {
                int i = 100 * digits[a] + 10 * digits[b] + digits[c];
                for (int d = 0; d < n; ++d)
                {
                    for (int e = 0; e < n; ++e)
                    {
                        int j = 10 * digits[d] + digits[e];
                        int k = digits[d] * i, l = digits[e] * i, m = i * j;
                        if (is_valid(k, 3) && is_valid(l, 3) && is_valid(m, 4))
                        {
                            cerr << i << " x " << digits[d] * 10 + digits[e] << endl;
                            ++sols;
                        }
                        // if (i == 222 && j == 22)
                        // {
                        //     cerr << k << ' ' << l << ' ' << m << endl;
                        // }
                    }
                }
            }
        }
    }

    cout << sols << endl;

    return EXIT_SUCCESS;
}
