class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, maxSum = 0;
        for (int i = 0; i < n; ++i) {
            sum = max(0, sum + A[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};
