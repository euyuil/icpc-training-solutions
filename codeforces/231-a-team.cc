#include <iostream>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}
