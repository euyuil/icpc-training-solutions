class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret = INT_MAX, retAbs = INT_MAX;
        sort(num.begin(), num.end());
        for (int k = 0; k < int(num.size()) - 2; ++k) {
            int i = k + 1, j = num.size() - 1;
            while (i < j) {
                int sum = num[k] + num[i] + num[j];
                if (sum > target) --j;
                else if (sum < target) ++i;
                else --j, ++i;
                if (abs(target - sum) < retAbs) {
                    retAbs = abs(target - sum);
                    ret = sum;
                }
            }
        }
        return ret;
    }
};
