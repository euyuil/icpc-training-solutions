class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0 || A[0] >= target) return 0;
        if (A[n - 1] < target) return n;
        int s = 0, e = n;
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (A[m] >= target) e = m;
            else s = m;
        }
        return e;
    }
};
