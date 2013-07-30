/*
ID: 31415926
LANG: C++
TASK: beads
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int checkpoint(const string &s, int x)
{
    char left_color = 'w', right_color = 'w';
    int left_value = 0, right_value = 0;

    for (right_value = 0; ; ++right_value)
    {
        if (right_value == s.size())
            return s.size(); // whole chain can be collected
        int i = (right_value + x) % s.size();
        if (right_color != 'w' && s[i] != 'w' && s[i] != right_color)
            break;
        if (right_color == 'w')
            right_color = s[i];
    }

    for (left_value = 0; ; ++left_value)
    {
        int i = (x - left_value - 1 + s.size()) % s.size();
        if (left_color != 'w' && s[i] != 'w' && s[i] != left_color)
            break;
        if (left_color == 'w')
            left_color = s[i];
    }

    clog << "pos " << x << " left " << left_value << " right " << right_value << endl;

    return min(left_value + right_value, (int)s.size()); // rrwwwwbb
}

int main()
{
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int n;
    string necklace;

    int ans = -1;
    cin >> n >> necklace;
    for (int i = 0; i < n; ++i)
        ans = max(ans, checkpoint(necklace, i));

    cout << ans << endl;

    return EXIT_SUCCESS;
}
