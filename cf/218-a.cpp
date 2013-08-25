#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[333];

int main()
{
    int n, k;
    cin >> n >> k;
    n = n * 2 + 1;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 2; i <= n; i += 2)
    {
        if (k > 0 && arr[i]-1 > arr[i-1] && arr[i]-1 > arr[i+1])
            --k, --arr[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i < n)
            printf("%d ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
    return 0;
}
