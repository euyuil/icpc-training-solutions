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
    int search(int A[], int n, int target) {

        int big = 0, small = n;
        while (big + 1 < small) {
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

        return (at(A, n, small, begin) == target) ? pos(n, small, begin) : -1;
    }
};
