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
    string s;
    cin >> s;

    s += ' ';

    int length = 0;
    bool dangerous = false;
    char last_digit = '\0';

    for (int i = 0; i < s.size(); ++i)
    {
        if (last_digit != s[i])
        {
            if (length >= 7)
                dangerous = true;
            length = 1;
            last_digit = s[i];
        }
        else
            ++length;
    }

    cout << (dangerous ? "YES" : "NO") << endl;

    return EXIT_SUCCESS;
}
