#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long sum = -1;
    int n, i, j = 0, h;
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> h;
        if (h < j)
        {
            sum += j - h + 2;
        }
        else
        {
            sum += h - j + 2;
        }
        j = h;
    }
    cout << sum << endl;
}
