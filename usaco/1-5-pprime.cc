/*
ID: 31415926
LANG: C++
TASK: pprime
*/

#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int getFirstPosition(int prefix)
{
    int firstPosition = 1;

    while (prefix >= firstPosition * 10)
        firstPosition *= 10;

    return firstPosition;
}

int getPalindrome(int &prefix)
{
    {
        int fp = getFirstPosition(prefix);
        if (prefix / fp % 2 == 0)
            prefix += fp;
    }

    int ret = prefix;
    int firstPosition = 10;

    while (ret >= firstPosition)
    {
        ret = ret * 10 + ret / firstPosition % 10;
        firstPosition *= 100;
    }

    return ret;
}

bool isPrime(int a)
{
    for (int i = 3; i <= int(sqrt(a)); i += 2)
        if (a % i == 0)
            return false;
    return true;
}

int main()
{
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);

    int a, b;
    scanf("%d%d", &a, &b);

    if (a <= 5 && 5 <= b) printf("5\n");
    if (a <= 7 && 7 <= b) printf("7\n");
    if (a <= 11 && 11 <= b) printf("11\n");

    int prefix = 10;
    int palindrome = getPalindrome(prefix);

    while (palindrome <= b)
    {
        if (palindrome >= a)
            if (isPrime(palindrome))
                printf("%d\n", palindrome);

        palindrome = getPalindrome(++prefix);
    }

    return EXIT_SUCCESS;
}
