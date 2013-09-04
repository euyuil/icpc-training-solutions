#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    int a[2], n;
    cin >> a[0] >> a[1] >> n;

    int ans = 0, numpick = 0;
    while (numpick <= n)
    {
        n -= numpick;
        numpick = gcd(a[ans], n);
        ans = ans ^ 1;
    }
    cout << ans << endl;

    return 0;
}
