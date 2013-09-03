#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() == 0 && s2.size() == 0 && s3.size() == 0)
            return true;

        if (s1.size() + s2.size() != s3.size())
            return false;

        if (s1.size() == 0 || s2.size() == 0)
            return s1 + s2 == s3;

        s1 = " " + s1; s2 = " " + s2; s3 = " " + s3;

        vector<vector<int> > dp(s1.size(), vector<int>(s2.size()));

        for (int i = 1; i < s1.size(); ++i)
            if (s1[i] == s3[i] && dp[i - 1][0] == i - 1)
                dp[i][0] = i;

        for (int j = 1; j < s2.size(); ++j)
            if (s2[j] == s3[j] && dp[0][j - 1] == j - 1)
                dp[0][j] = j;

        for (int i = 1; i < s1.size(); ++i) {
            for (int j = 1; j < s2.size(); ++j) {
                int k = i + j;
                if (s1[i] == s3[k] && dp[i - 1][j] == k - 1)
                    dp[i][j] = k;
                else if (s2[j] == s3[k] && dp[i][j - 1] == k - 1)
                    dp[i][j] = k;
            }
        }

        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[i].size(); ++j)
                cout << dp[i][j] << ' ';
            cout << endl;
        }

        return dp.back().back() == s3.size() - 1;
    }
};

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    cout << Solution().isInterleave(s1, s2, s3) << endl;
    return 0;
}
