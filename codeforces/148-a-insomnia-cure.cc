#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int a[4], n;
    vector<bool> sieve(n + 1);

    for (int i = 0; i < 4; ++i)
        cin >> a[i];

    cin >> n;

    for (int i = 0; i < 4; ++i)
        for (int j = a[i]; j <= n; j += a[i])
            sieve[j] = true;

    int cnt = 0;
    for (int i = 0; i < sieve.size(); ++i)
        if (sieve[i])
            ++cnt;

    cout << cnt << endl;

    return EXIT_SUCCESS;
}
