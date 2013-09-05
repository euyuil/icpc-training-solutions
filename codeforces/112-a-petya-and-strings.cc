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
    string a, b;
    cin >> a >> b;

    transform(a.begin(), a.end(), a.begin(), static_cast<int (*)(int)>(tolower));
    transform(b.begin(), b.end(), b.begin(), static_cast<int (*)(int)>(tolower));

    int ret = strcmp(a.c_str(), b.c_str());

    cout << (ret > 0 ? 1 : ret < 0 ? -1 : 0) << endl;

    return EXIT_SUCCESS;
}
