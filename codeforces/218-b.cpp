#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr, work;

inline int find_max()
{
    int id = -1, x = INT_MIN;
    for (int i = 0; i < work.size(); ++i)
        if (x < work[i] && work[i] > 0)
            x = work[i], id = i;
    return id;
}

inline int find_min()
{
    int id = -1, x = INT_MAX;
    for (int i = 0; i < work.size(); ++i)
        if (x > work[i] && work[i] > 0)
            x = work[i], id = i;
    return id;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int t; cin >> t;
        arr.push_back(t);
    }
    work = arr;
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
        int id = find_max();
        x += work[id];
        --work[id];
    }
    work = arr;
    int y = 0;
    for (int i = 0; i < n; ++i)
    {
        int id = find_min();
        y += work[id];
        --work[id];
    }
    cout << x << ' ' << y << endl;
    return 0;
}
