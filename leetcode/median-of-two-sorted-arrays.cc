class Solution {

    // assume m and n are not both 0, k starts from 1.
    int findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        if (m > n) return findKthSortedArrays(B, n, A, m, k);
        if (m == 0) return B[k - 1];
        if (k == 1) return min(A[0], B[0]);
        // now m, n, k != 0.
        int a = min(m, k / 2), b = k - a;
        if (A[a - 1] > B[b - 1])
            return findKthSortedArrays(A, m, B + b, n - b, k - b);
        else if (A[a - 1] < B[b - 1])
            return findKthSortedArrays(A + a, m - a, B, n, k - a);
        return A[a - 1];
    }

public:

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int z = m + n;
        if (z % 2 == 0)
            return (findKthSortedArrays(A, m, B, n, z / 2) +
                    findKthSortedArrays(A, m, B, n, z / 2 + 1)) / 2.0;
        return double(findKthSortedArrays(A, m, B, n, z / 2 + 1));
    }
};
