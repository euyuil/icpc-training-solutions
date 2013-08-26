/*
ID: 31415926
LANG: C++
TASK: namenum
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const size_t N = 5234;
const size_t BUF_IDX = N - 1;

size_t dict_size;
char dict[N][16];
size_t dict_order[N];

short mapping[256];

void init_mapping()
{
    // You should notice that there might be letter Q or Z in the dict.

    fill(mapping, mapping + sizeof(mapping) / sizeof(*mapping), 10);

    char c = 'A';
    for (int i = 2; i <= 6; ++i)
        for (int j = 0; j < 3; ++j, ++c)
            mapping[c] = i;

    mapping['P'] = mapping['R'] = mapping['S'] = 7;
    mapping['T'] = mapping['U'] = mapping['V'] = 8;
    mapping['W'] = mapping['X'] = mapping['Y'] = 9;

    for (c = '0'; c <= '9'; ++c)
        mapping[c] = c - '0';

    mapping['\0'] = 0;
}

void init_order()
{
    for (size_t i = 0; i < N; ++i)
        dict_order[i] = i;
}

inline bool less_than(size_t i, size_t j)
{
    const char *a = dict[i], *b = dict[j];
    while (*a && mapping[*a] == mapping[*b])
        ++a, ++b;
    return mapping[*a] < mapping[*b];
}

inline bool less_than_stable(size_t i, size_t j)
{
    const char *a = dict[i], *b = dict[j];
    while (*a && mapping[*a] == mapping[*b])
        ++a, ++b;
    if (mapping[*a] == mapping[*b])
        return i < j;
    return mapping[*a] < mapping[*b];
}

int main()
{
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    FILE *fd = fopen("dict.txt", "r");

    init_mapping();
    init_order();

    dict_size = 0;
    while (fscanf(fd, "%s", dict[dict_size]) != EOF)
        ++dict_size;

    fprintf(stderr, "%d lines read\n", dict_size);

    sort(dict_order, dict_order + dict_size, less_than_stable);

    scanf("%s", dict[BUF_IDX]);

    size_t *lb = lower_bound(dict_order, dict_order + dict_size, BUF_IDX, less_than);
    size_t *ub = upper_bound(dict_order, dict_order + dict_size, BUF_IDX, less_than);

    fprintf(stderr, "lower bound %d\n", lb - dict_order);
    fprintf(stderr, "upper bound %d\n", ub - dict_order);

    if (lb == ub)
        printf("NONE\n");
    else for ( ; lb != ub; ++lb)
        printf("%s\n", dict[*lb]);

    fclose(fd);

    return EXIT_SUCCESS;
}
