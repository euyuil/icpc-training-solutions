/*
ID: 31415926
LANG: C++
TASK: milk2
*/

#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

const size_t N = 5234;

size_t n;
vector<pair<int, int> > cows;

template <typename T>
inline bool less1st(const T &a, const T &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    scanf("%u", &n);
    fprintf(stderr, "%u input size.\n", n);
    cows.reserve(n << 1);
    for (size_t i = 0; i < n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        cows.push_back(make_pair(a, 1));
        cows.push_back(make_pair(b, -1));
    }

    fprintf(stderr, "before sorting.\n");
    sort(cows.begin(), cows.end(), less1st<pair<int, int> >);
    fprintf(stderr, "after sorting.\n");
    for (size_t i = 0; i < cows.size(); ++i)
        fprintf(stderr, "%+d ", cows[i].first * cows[i].second);
    fprintf(stderr, "\n");

    int accumulator = 0;
    int longest_milking = 0, longest_idle = 0;
    int last_start = 0, last_end = cows[0].first;

    for (size_t i = 0; i < cows.size(); ++i)
    {
        if (accumulator == 0 && cows[i].second == 1)
        {
            // a milking era!
            last_start = cows[i].first;

            // calculate idle time.
            int current_idle = last_start - last_end;
            longest_idle = max(longest_idle, current_idle);
        }

        if (accumulator == 1 && cows[i].second == -1)
        {
            // a break.
            last_end = cows[i].first;

            // calculate milking time.
            int current_milking = last_end - last_start;
            longest_milking = max(longest_milking, current_milking);
        }

        accumulator += cows[i].second;
    }

    printf("%d %d\n", longest_milking, longest_idle);
    fprintf(stderr, "job done.\n");

    return EXIT_SUCCESS;
}
