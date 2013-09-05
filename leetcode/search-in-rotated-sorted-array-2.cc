#include <iostream>

// Although the solution was accepted, it's not written that straight forward.
// Can be implemented using only one binary search.

using namespace std;

class Solution {

    inline static int pos(int n, int offset, int i) {
        int actual = (offset + i) % n;
        if (actual < 0) actual += n;
        return actual;
    }

    inline static int &at(int A[], int n, int offset, int i) {
        return A[pos(n, offset, i)];
    }

public:
    bool search(int A[], int n, int target) {

        int big = 0, small = n;

        for ( ; big + 1 < n; ++big)
            if (A[big] != A[n - 1])
                break;

        int *p = lower_bound(A + big, A + n, target);
        if (p != A + n && *p == target) return true;

        while (big + 1 < small) {

            if (A[big] == A[big + 1]) {
                ++big;
                continue;
            }

            int mid = (big + small) / 2;

            if (A[mid] > A[big]) big = mid;
            else small = mid;
        }

        int begin = 0, end = n;

        while (begin + 1 < end) {

            int mid = (begin + end) / 2;
            int &midnum = at(A, n, small, mid);

            if (midnum <= target) begin = mid;
            else end = mid;
        }

        return (at(A, n, small, begin) == target);
    }
};

int main()
{
    int arr[] = {2, 2, 2, 0, 2, 2};
    cout << Solution().search(arr, 6, 0) << endl;
    return 0;
}
