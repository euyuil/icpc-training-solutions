#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 0, curr = 0;
    cin >> n;
    while (n--)
    {
        int numexit, numenter;
        cin >> numexit >> numenter;
        curr = curr - numexit + numenter;
        ans = max(ans, curr);
    }
    cout << ans << endl;
    return 0;
}
