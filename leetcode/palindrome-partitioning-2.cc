#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        if (s.size() == 0)
            return 0;

        vector<int> dp(s.size());
        vector<int> lens; // possible lengths for palindrome trailings.

        dp[0] = 0;
        lens.push_back(0);
        lens.push_back(1);

        for (int i = 1; i < s.size(); ++i)
        {
            vector<int> new_lens;
            int min_dp = dp[i - 1] + 1;

            for (int j = 0; j < lens.size(); ++j)
            {
                int pos = i - lens[j] - 1;

                if (pos < 0)
                    continue;

                if (s[pos] == s[i])
                {
                    new_lens.push_back(lens[j] + 2);

                    if (pos == 0)
                        min_dp = min(min_dp, 0);
                    else
                        min_dp = min(min_dp, dp[pos - 1] + 1);
                }
            }

            dp[i] = min_dp;

            new_lens.push_back(0);
            new_lens.push_back(1);

            lens.swap(new_lens);
        }

        // for (int i = 0; i < dp.size(); ++i)
        //     cout << dp[i] << ' ';
        // cout << endl;

        return dp[s.size() - 1];
    }
};

int main()
{
    string s = "aab";
    cout << Solution().minCut(s) << endl;
    return 0;
}
