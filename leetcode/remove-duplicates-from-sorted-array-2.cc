class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int k = 0;
        for (int i = 2; i < n; ++i) {
            if (A[i - k - 2] == A[i - k - 1] &&
                A[i - k - 1] == A[i]) ++k;
            else A[i - k] = A[i];
        }
        return n - k;
    }
};
