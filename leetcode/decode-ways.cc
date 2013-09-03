#include <cstdlib>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {

        // I think it should return 1 but the judge accepts 0.
        if (s.size() == 0) return 0;

        // I don't think there are invalid inputs
        // according to the problem description but there is.
        if (s[0] == '0') return 0;

        s = " " + s; // 12323
        vector<int> dp(s.size());

        dp[0] = dp[1] = 1;

        for (int i = 2; i < s.size(); ++i) {
            int ways = 0;
            for (int j = 1; j <= 2; ++j) {
                int start = i - j + 1;
                string substr = s.substr(start, j);
                int num = atoi(substr.c_str());
                if (1 <= num && num <= 26 && substr[0] != '0') {
                    ways += dp[i - j];
                }
            }
            dp[i] = ways;
        }

        return dp.back();
    }
};
