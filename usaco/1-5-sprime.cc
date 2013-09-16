/*
ID: 31415926
LANG: C++
TASK: sprime
*/

#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int maxDepth;

bool isPrime(int a)
{
    if (a <= 1)
        return false;
    if (a == 2)
        return true;
    if (a % 2 == 0)
        return false;
    for (int i = 3; i <= int(sqrt(a)); i += 2)
        if (a % i == 0)
            return false;
    return true;
}

void search(int depth, int number)
{
    if (depth >= maxDepth)
    {
        if (isPrime(number))
            printf("%d\n", number);
    }
    else
    {
        for (int i = 1; i <= 9; ++i)
        {
            int newNumber = number * 10 + i;
            if (isPrime(newNumber))
                search(depth + 1, newNumber);
        }
    }
}

int main()
{
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    scanf("%d", &maxDepth);

    search(0, 0);

    return EXIT_SUCCESS;
}
