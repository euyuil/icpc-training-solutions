/*
ID: 31415926
LANG: C++
TASK: friday
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

struct date
{
    int year, month, day, weekday;
};

inline bool isleap(int year)
{
    return (year % 100 != 0 && year % 4 == 0) || year % 400 == 0;
}

const int normonthdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int monthdays(int year,  int month)
{
    if (month == 2 && isleap(year))
        return 29;
    return normonthdays[month];
}

inline void tomorrow(date &d)
{
    d.weekday = (d.weekday + 1) % 7;
    if (++d.day > monthdays(d.year, d.month))
    {
        d.day = 1;
        if (++d.month > 12)
        {
            d.month = 1;
            ++d.year;
        }
    }
}

inline void janfirst1900mon(date &d)
{
    d.year = 1900;
    d.month = 1;
    d.day = 1;
    d.weekday = 1;
}

int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int n;
    cin >> n;
    n += 1900;

    date d;
    janfirst1900mon(d);

    int stats[7] = {0};
    while (d.year != n)
    {
        if (d.day == 13)
            ++stats[d.weekday];
        tomorrow(d);
    }

    cout << stats[6];
    for (int i = 0; i < 6; ++i)
        cout << ' ' << stats[i];
    cout << endl;

    return EXIT_SUCCESS;
}
