class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {

        /** n = 6
         * 0 1 2 3 4 5
         * 1    |*  
         * 2 *  |  m
         * 3    |  *
         * 4 m *|
         * 5    |
         */

        /** n = 7
         * 0 1 2 3 4 5 6
         * 1     - *
         * 2 *   -   m
         * 3 - - - - - -
         * 4 m   -   *
         * 5   * -
         * 6     -
         */

        int n = matrix.size();
        int q1 = (n + 1) / 2, q2 = n / 2;

        for (int i1 = 0; i1 < q1; ++i1) {
            for (int j1 = 0; j1 < q2; ++j1) {
                int im = n - i1 - 1, jm = n - j1 - 1;
                int i2 = j1, j2 = im;
                int i3 = im, j3 = jm;
                int i4 = jm, j4 = i1;
                int a = matrix[i1][j1];
                matrix[i1][j1] = matrix[i4][j4];
                matrix[i4][j4] = matrix[i3][j3];
                matrix[i3][j3] = matrix[i2][j2];
                matrix[i2][j2] = a;
            }
        }
    }
};
