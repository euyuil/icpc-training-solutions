class Solution {

public:

    int trap(int A[], int n) {

        if (n == 0) return 0;

        int max_value = INT_MIN, max_index = 0;

        for (int i = 0; i < n; ++i)
            if (A[i] > max_value)
                max_value = A[i], max_index = i;

        int ret = 0, minus = 0, high_value = 0, high_index = -1;
        for (int i = 0; i <= max_index; ++i) {
            if (A[i] >= high_value) {
                ret += high_value * (i - high_index - 1) - minus;
                minus = 0;
                high_value = A[i];
                high_index = i;
            } else minus += A[i];
        }

        minus = 0; high_value = 0; high_index = n;
        for (int i = n - 1; i >= max_index; --i) {
            if (A[i] >= high_value) {
                ret += high_value * (high_index - i - 1) - minus;
                minus = 0;
                high_value = A[i];
                high_index = i;
            } else minus += A[i];
        }

        return ret;
    }
};
