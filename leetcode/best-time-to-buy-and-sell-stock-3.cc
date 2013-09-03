#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {

        if (prices.size() < 2)
            return 0;

        vector<int> delta(prices.size() - 1);
        vector<int> leftMax(prices.size() - 1);
        vector<int> rightMax(prices.size() - 1);

        for (int i = 1; i < prices.size(); ++i)
            delta[i - 1] = prices[i] - prices[i - 1];

        int leftCurr = max(0, delta[0]);
        leftMax[0] = leftCurr;
        for (int i = 1; i < delta.size(); ++i) {
            leftCurr = max(0, leftCurr + delta[i]);
            leftMax[i] = max(leftMax[i - 1], leftCurr);
        }

        int rightCurr = max(0, delta.back());
        rightMax.back() = rightCurr;
        for (int i = delta.size() - 2; i >= 0; --i) {
            rightCurr = max(0, rightCurr + delta[i]);
            rightMax[i] = max(rightMax[i + 1], rightCurr);
        }

        int ret = leftMax[0];
        for (int i = 1; i < delta.size(); ++i)
            ret = max(ret, leftMax[i - 1] + rightMax[i]);

        return ret;
    }
};
