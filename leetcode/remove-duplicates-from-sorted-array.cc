class Solution {
public:
    int removeDuplicates(int A[], int n) {

        int k = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] == A[i - 1]) ++k;
            else A[i - k] = A[i];
        }

        return n - k;
    }
};
