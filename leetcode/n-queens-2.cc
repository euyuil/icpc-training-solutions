#include <vector>
#include <iostream>

using namespace std;

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

    bool safeUpperRight(int row, int col) {
        --row; ++col;
        while (row >= 0 && col < n) {
            if (columnIndexAtRow[row] == col)
                return false;
            --row; ++col;
        }
        return true;
    }

    bool safeUp(int row, int col) {
        --row;
        while (row >= 0) {
            if (columnIndexAtRow[row] == col)
                return false;
            --row;
        }
        return true;
    }

    bool safe(int row, int col) {
        return safeUp(row, col) && safeUpperLeft(row, col) && safeUpperRight(row, col);
    }

    void searchRow(int row) {
        if (row >= n) {
            // for (int i = 0; i < n; ++i) cout << columnIndexAtRow[i];
            // cout << endl;
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

int main()
{
    cout << Solution().totalNQueens(3) << endl;
    return 0;
}
