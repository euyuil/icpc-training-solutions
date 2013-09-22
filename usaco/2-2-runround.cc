/*
ID: 31415926
LANG: C++
TASK: runround
*/

#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

inline bool isuniq(const string &s)
{
    static bool used[10];
    memset(used, 0, sizeof(used));
    for (int i = 0; i < s.size(); ++i)
    {
        int d = s[i] - '0';
        if (used[d]) return false;
        used[d] = true;
    }
    return true;
}

inline bool iscyc(const string &s)
{
    static bool visited[10];
    memset(visited, 0, sizeof(visited));
    int pos = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (visited[pos]) return false;
        visited[pos] = true;
        pos -= s[pos] - '0';
        while (pos < 0) pos += s.size();
    }
    return pos == 0;
}

inline bool isra(int n)
{
    if (n == 0) return false;

    string s;
    while (n)
    {
        s += n % 10 + '0';
        n /= 10;
    }

    if (!isuniq(s)) return false;
    return iscyc(s);
}

int main()
{
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    int n, i;

    cin >> n;

    for (i = n + 1; !isra(i); ++i);

    cout << i << endl;

    return EXIT_SUCCESS;
}
