class Solution {
public:
    int jump(int A[], int n) {

        if (n == 0) return 0;

        vector<int> f(n, 0x7fffffff);

        f[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = min(n - 1, i + A[i]); j >= i && f[i] + 1 < f[j]; --j) {
                f[j] = f[i] + 1;
            }
        }

        return f.back();
    }
};
