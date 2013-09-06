class Solution {

    int n;
    vector<int> columnIndexAtRow;
    vector<vector<string> > ret;

    void buildSolution() {
        vector<string> sol;
        for (int i = 0; i < n; ++i) {
            string row(n, '.');
            row[columnIndexAtRow[i]] = 'Q';
            sol.push_back(row);
        }
        ret.push_back(sol);
    }

    bool safeUpperLeft(int row, int col) {
        --row; --col;
        while (row >= 0 && col >= 0) {
            if (columnIndexAtRow[row] == col)
                return false;
            --row; --col;
        }
        return true;
    }

    bool safeLeft(int row, int col) {
        --col;
        while (col >= 0) {
            if (columnIndexAtRow[row] == col)
                return false;
            --col;
        }
        return true;
    }

    bool safe(int row, int col) {
        return safeLeft(row, col) && safeUpperLeft(row, col);
    }

    void searchRow(int row) {
        if (row >= n) {
            buildSolution();
        } else {
            for (int i = 0; i < n; ++i) {
                if (safe(row, i)) {
                    columnIndexAtRow[row] = i;
                    searchRow(row + 1);
                }
            }
        }
    }

public:

    vector<vector<string> > solveNQueens(int n) {

        this->n = n;
        columnIndexAtRow.resize(n);
        ret.clear();

        searchRow(0);

        return ret;
    }
};
