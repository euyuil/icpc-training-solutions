const int dx[] = {  0,  1,  0, -1};
const int dy[] = { -1,  0,  1,  0};

class Solution {

    int m, n, mn;

    inline int lineLength(int dir) {
        int ret = (dir & 1) ? m : n;
        return ret - dir / 2;
    }

    inline void firstStep(int &x, int &y, int &dir, int &len) {
        x = 0; y = 0; dir = 1; len = lineLength(dir) - 1;
    }

    inline bool nextStep(int &x, int &y, int &dir, int &len) {
        if (len--) {
            x += dx[dir % 4]; y += dy[dir % 4];
            return true;
        } else {
            len = lineLength(++dir);
            if (len > 0) return nextStep(x, y, dir, len);
        }
        return false;
    }

public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {

        vector<int> ret;

        if (matrix.size() == 0) return ret;

        n = matrix.size();
        m = matrix[0].size();
        mn = m * n;

        int x, y, dir, len;
        firstStep(x, y, dir, len);
        ret.push_back(matrix[y][x]);

        while (nextStep(x, y, dir, len))
            ret.push_back(matrix[y][x]);

        return ret;
    }
};
