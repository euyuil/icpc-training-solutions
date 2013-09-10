class Solution {

public:

    int trap(int A[], int n) {

        vector<int> left(n), right(n);

        int maxi = 0;
        for (int i = 0; i < n; ++i)
            maxi = left[i] = max(maxi, A[i]);
        maxi = 0;
        for (int i = n - 1; i >= 0; --i)
            maxi = right[i] = max(maxi, A[i]);

        int ret = 0;
        for (int i = 0; i < n; ++i)
            ret += max(0, min(left[i], right[i]) - A[i]);

        return ret;
    }
};
