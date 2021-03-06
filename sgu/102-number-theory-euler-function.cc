#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        if (gcd(n, i) == 1)
            ++cnt;
    cout << cnt << endl;
    return 0;
}
