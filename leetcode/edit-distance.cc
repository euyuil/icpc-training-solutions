class Solution {
public:
    int minDistance(string word1, string word2) {

        int len1 = word1.size(), len2 = word2.size();
        word1 = " " + word1; word2 = " " + word2;

        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1));

        for (int i = 0; i <= len1; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= len2; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int least = INT_MAX;
                least = min(least, dp[i - 1][j] + 1);
                least = min(least, dp[i][j - 1] + 1);
                if (word1[i] == word2[j])
                    least = min(least, dp[i - 1][j - 1]);
                else
                    least = min(least, dp[i - 1][j - 1] + 1);
                dp[i][j] = least;
            }
        }

        return dp.back().back();
    }
};
