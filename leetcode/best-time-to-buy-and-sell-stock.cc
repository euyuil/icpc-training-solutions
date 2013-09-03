#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {

        if (prices.size() == 0)
            return 0;

        vector<int> leftMin(prices.size());

        leftMin[0] = prices[0];
        for (int i = 1; i < prices.size(); ++i)
            leftMin[i]= min(leftMin[i - 1], prices[i]);

        int ret = INT_MIN;
        for (int i = 0; i < prices.size(); ++i)
            ret = max(ret, prices[i] - leftMin[i]);

        return ret;
    }
};
