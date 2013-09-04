class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {

        vector<vector<int> > dp(grid);

        for (int i = 1; i < dp.size(); ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        for (int j = 1; j < dp[0].size(); ++j)
            dp[0][j] = dp[0][j - 1] + grid[0][j];

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size(); ++j) {
                dp[i][j] = min(dp[i - 1][  j  ],
                               dp[  i  ][j - 1]) + grid[i][j];
            }
        }

        return dp.back().back();
    }
};
