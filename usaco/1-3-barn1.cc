/*
ID: 31415926
LANG: C++
TASK: barn1
*/

#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const size_t N = 223;
bool arr[N];
vector<int> removable;
int m, s, c;

int main()
{
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    memset(arr, 0, sizeof(arr));

    scanf("%d%d%d", &m, &s, &c);
    fprintf(stderr, "input %d %d %d\n", m, s, c);

    for (size_t i = 0; i < c; ++i)
    {
        size_t pos;
        scanf("%lu", &pos);
        arr[pos] = true;
    }

    fprintf(stderr, "all input read\n");

    size_t first_true, last_true;
    for (first_true = 1; first_true <= s; ++first_true)
        if (arr[first_true])
            break;
    for (last_true = s; last_true >= 1; --last_true)
        if (arr[last_true])
            break;

    for (size_t i = first_true, cnt = 0; i <= s; ++i)
    {
        if (arr[i] && cnt)
        {
            removable.push_back(cnt);
            fprintf(stderr, "removable %d ~ %d = %d\n", i - cnt, i, cnt);
            cnt = 0;
        }
        if (!arr[i])
            ++cnt;
    }

    fprintf(stderr, "removables constructed\n");

    sort(removable.begin(), removable.end(), greater<int>());

    int removed = 0;
    for (size_t i = 0; i < m - 1 && i < removable.size(); ++i)
        removed += removable[i];

    printf("%d\n", last_true - first_true + 1 - removed);

    return EXIT_SUCCESS;
}
