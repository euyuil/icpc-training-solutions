/*
ID: 31415926
LANG: C++
TASK: dualpal
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const char digit[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'
};

inline string convert(int a, int base)
{
    string display;

    while (a)
    {
        display += digit[a % base];
        a /= base;
    }

    reverse(display.begin(), display.end());

    return display;
}

inline bool is_palindrome(const string &str)
{
    size_t i = 0, j = str.size() - 1;
    while (i < j)
        if (str[i++] != str[j--])
            return false;
    return true;
}

inline bool is_dual_palindrome(int x)
{
    int cnt = 0;
    for (int base = 2; base <= 10; ++base)
    {
        string display = convert(x, base);
        if (is_palindrome(display))
            ++cnt;
        if (cnt >= 2)
            return true;
    }
    return false;
}

int main()
{
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int n, s;
    scanf("%d %d", &n, &s);

    for (int i = 1, j = 0; j < n; ++i)
    {
        int x = s + i;
        if (is_dual_palindrome(x))
        {
            printf("%d\n", x);
            ++j;
        }
    }

    return EXIT_SUCCESS;
}
