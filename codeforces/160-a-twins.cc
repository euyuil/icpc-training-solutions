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
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int total = 0;
    for (int i = 0; i < n; ++i)
        total += arr[i];

    int taken = 0, ans = n;
    for (int i = n - 1; i >= 0; --i)
    {
        taken += arr[i];
        if (taken * 2 > total)
        {
            ans = n - i;
            break;
        }
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}
