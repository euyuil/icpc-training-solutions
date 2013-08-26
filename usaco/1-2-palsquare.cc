/*
ID: 31415926
LANG: C++
TASK: palsquare
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

int main()
{
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);

    int base;
    scanf("%d", &base);

    for (int i = 1; i <= 300; ++i)
    {
        string display = convert(i * i, base);
        if (is_palindrome(display))
            printf("%s %s\n", convert(i, base).c_str(), display.c_str());
    }

    return EXIT_SUCCESS;
}
