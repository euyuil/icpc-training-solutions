/*
ID: 31415926
LANG: C++
TASK: milk
*/

#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
inline bool less_first(const T &a, const T &b)
{
    return a.first < b.first;
}

int main()
{
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int amount, farmers;
    scanf("%d%d", &amount, &farmers);

    vector<pair<int, int> > offers(farmers);
    for (int i = 0; i < farmers; ++i)
        scanf("%d%d", &offers[i].first, &offers[i].second);

    sort(offers.begin(), offers.end(), less_first<pair<int, int> >);

    int amount_remain = amount, price = 0;
    for (int i = 0; i < farmers; ++i)
    {
        int can_buy = min(offers[i].second, amount_remain);
        int should_pay = can_buy * offers[i].first;

        amount_remain -= can_buy;
        price += should_pay;

        if (amount_remain <= 0)
            break;
    }

    printf("%d\n", price);

    return EXIT_SUCCESS;
}
