class Solution {

    int n, ret;
    vector<int> columnIndexAtRow;

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
            ++ret;
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

    int totalNQueens(int n) {

        this->n = n;
        columnIndexAtRow.resize(n);
        ret = 0;

        searchRow(0);

        return ret;
    }
};
