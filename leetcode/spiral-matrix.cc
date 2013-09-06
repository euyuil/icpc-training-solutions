const int dx[] = {  0,  1,  0, -1};
const int dy[] = { -1,  0,  1,  0};

class Solution {

    int m, n, mn;

    inline int line_length(int dir) {
        int ret = (dir & 1) ? m : n;
        return ret - dir / 2;
    }

public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {

        vector<int> ret;

        if (matrix.size() == 0) return ret;

        n = matrix.size();
        m = matrix[0].size();
        mn = m * n;

        int dir = 1, x = 0, y = 0;
        for (int i = 1; i < mn; ++i) {
            int nx = x + dx[dir % 4], ny = y + dy[dir % 4];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                ++dir; --i;
                continue;
            }
            ret.push_back(matrix[y][x]);
            x = nx; y = ny;
        }
        ret.push_back(matrix[y][x]);

        return ret;
    }
};
