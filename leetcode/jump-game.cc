class Solution {
public:
    bool canJump(int A[], int n) {
        if (n == 0) return true;
        vector<int> f(n);
        f[0] = A[0];
        for (int i = 1; i < n; ++i) {
            if (f[i - 1] >= i) {
                f[i] = max(i + A[i], f[i - 1]);
            } else {
                f[i] = f[i - 1];
            }
        }
        return f.back() >= n - 1;
    }
};
