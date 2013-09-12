#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {

    vector<int> makeTriple(int a, int b, int c) {
        vector<int> ret;
        ret.push_back(a);
        ret.push_back(b);
        ret.push_back(c);
        return ret;
    }

public:

    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.size() == 0) return ret;
        sort(num.begin(), num.end());
        for (int k = 0; k < int(num.size()) - 2; ++k) {
            if (k > 0 && num[k] == num[k - 1]) continue;
            int i = k + 1, j = num.size() - 1;
            while (i < j) {
                int sum = num[k] + num[i] + num[j];
                if (sum > 0) --j;
                else if (sum < 0) ++i;
                else {
                    if (ret.empty() || num[k] != ret.back()[0] ||
                                       num[i] != ret.back()[1] ||
                                       num[j] != ret.back()[2])
                        ret.push_back(makeTriple(num[k], num[i], num[j]));
                    else {
                        --j; ++i;
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> num;
    num.push_back(0);
    Solution().threeSum(num);
    return 0;
}
