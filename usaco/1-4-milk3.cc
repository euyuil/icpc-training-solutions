/*
ID: 31415926
LANG: C++
TASK: milk3
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int current[3];
int capacity[3];
bool used[21][21][21];
bool reached[21];

void search()
{
    if (used[current[0]][current[1]][current[2]])
        return;

    used[current[0]][current[1]][current[2]] = true;

    if (current[0] == 0)
        reached[current[2]] = true;

    for (int i = 0; i < 3; ++i)
    {
        if (current[i] == 0)
            continue;

        for (int j = 0; j < 3; ++j)
        {
            if (i == j || current[j] == capacity[j])
                continue;

            int amount = min(capacity[j] - current[j], current[i]);

            current[i] -= amount;
            current[j] += amount;

            search();

            current[j] -= amount;
            current[i] += amount;
        }
    }
}

int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    scanf("%d%d%d", capacity, capacity + 1, capacity + 2);
    current[2] = capacity[2];

    search();

    bool first = true;
    for (int i = 0; i <= 20; ++i)
        if (reached[i])
            if (first)
                printf("%d", i), first = false;
            else
                printf(" %d", i);
    printf("\n");

    return EXIT_SUCCESS;
}
