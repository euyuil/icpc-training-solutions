class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {

        int n = obstacleGrid.size(), m = (n ? obstacleGrid[0].size() : 0);

        vector<vector<int> > mat(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[i][0])
                break;
            mat[i][0] = 1;
        }

        for (int j = 0; j < m; ++j) {
            if (obstacleGrid[0][j])
                break;
            mat[0][j] = 1;
        }

        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (obstacleGrid[i][j] != 1)
                    mat[i][j] = mat[i - 1][j] + mat[i][j - 1];

        return mat.back().back();
    }
};
