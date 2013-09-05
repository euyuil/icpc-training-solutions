#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n, x = 0;
    cin >> n;

    while (n--)
    {
        string stmt;
        cin >> stmt;
        x = stmt[1] == '+' ? x + 1 : x - 1;
    }

    cout << x << endl;

    return EXIT_SUCCESS;
}
