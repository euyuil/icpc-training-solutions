class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, maxSum = INT_MIN;
        for (int i = 0; i < n; ++i) {
            sum = max(A[i], sum + A[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
