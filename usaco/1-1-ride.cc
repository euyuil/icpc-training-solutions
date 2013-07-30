/*
ID: 31415926
LANG: C++
TASK: ride
*/

#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

long prodmod47(const string &str)
{
    long prod = 1;
    for (size_t i = 0; i < str.size(); ++i)
        prod *= (str[i] - 'A' + 1);
    return prod % 47;
}

int main()
{
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    string a, b;
    cin >> a >> b;
    if (prodmod47(a) == prodmod47(b))
        cout << "GO" << endl;
    else
        cout << "STAY" << endl;

    return EXIT_SUCCESS;
}
