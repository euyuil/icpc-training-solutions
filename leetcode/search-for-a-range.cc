class Solution {

    int lower(int A[], int n, int target) {
        if (A[0] >= target) return 0;
        int b = 0, e = n;
        while (b + 1 < e) {
            int m = (b + e) / 2;
            if (A[m] >= target) e = m;
            else b = m;
        }
        return e;
    }

    int upper(int A[], int n, int target) {
        if (A[0] > target) return 0;
        int b = 0, e = n;
        while (b + 1 < e) {
            int m = (b + e) / 2;
            if (A[m] <= target) b = m;
            else e = m;
        }
        return e;
    }

public:

    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret(2, -1);
        if (n == 0) return ret;
        int b = lower(A, n, target);
        int e = upper(A, n, target);
        if (b >= e) return ret;
        ret[0] = b;
        ret[1] = e - 1;
        return ret;
    }
};
