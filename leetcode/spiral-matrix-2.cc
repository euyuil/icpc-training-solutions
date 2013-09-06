const int dx[] = {  0,  1,  0, -1};
const int dy[] = { -1,  0,  1,  0};

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {

        vector<vector<int> > mat(n, vector<int>(n, -1));

        if (n == 0) return mat;

        int dir = 1, x = 0, y = 0, n2 = n * n;
        for (int i = 1; i < n2; ++i) {
            mat[y][x] = i;
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n ||
                mat[ny][nx] != -1) {

                dir = (dir + 1) % 4;
                --i;

                continue;
            }
            x = nx; y = ny;
        }
        mat[y][x] = n2;

        return mat;
    }
};
