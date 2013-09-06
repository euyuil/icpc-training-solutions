class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {

        if (matrix.size() == 0) return;

        vector<bool> cols(matrix.front().size());
        vector<bool> rows(matrix.size());

        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix.front().size(); ++j)
                if (matrix[i][j] == 0)
                    cols[j] = rows[i] = true;

        for (int j = 0; j < cols.size(); ++j)
            if (cols[j])
                for (int i = 0; i < rows.size(); ++i)
                    matrix[i][j] = 0;

        for (int i = 0; i < rows.size(); ++i)
            if (rows[i])
                for (int j = 0; j < cols.size(); ++j)
                    matrix[i][j] = 0;
    }
};
