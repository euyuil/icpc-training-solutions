#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {

    bool used[3][9][9];

    bool isUsed(int i, int j, char v) {
        return used[0][i][v - '1'] ||
               used[1][j][v - '1'] ||
               used[2][i - i % 3 + j / 3][v - '1'];
    }

    void setUsed(int i, int j, char v, bool b) {
        used[0][i][v - '1'] = b;
        used[1][j][v - '1'] = b;
        used[2][i - i % 3 + j / 3][v - '1'] = b;
    }

    vector<vector<char> > *pboard;

    bool next(int &x, int &y) {
        ++y;
        if (y >= 9) {
            ++x;
            y = 0;
        }
        if (x >= 9)
            return false;
        return true;
    }

    bool isValid(int x, int y) {
        if (x >= 9 || y >= 9)
            return false;
        return true;
    }

    bool search(int x, int y) {

        // cout << " - " << x << ", " << y << endl;

        do {
            if (!isValid(x, y)) return true;
            if (pboard->at(x)[y] == '.') break;
            // cout << " # " << x << ", " << y << " -> " << pboard->at(x)[y] << endl;
            if (!next(x, y)) return true;
        } while (true);

        // cout << " + " << x << ", " << y << endl;

        int nx = x, ny = y; next(nx, ny);
        for (char v = '1'; v <= '9'; ++v) {
            if (isUsed(x, y, v)) continue;
            setUsed(x, y, v, true);
            pboard->at(x)[y] = v;
            // cout << x << ", " << y << " -> " << v << endl;
            if (search(nx, ny)) return true;
            // cout << x << ", " << y << " -> " << '.' << endl;
            pboard->at(x)[y] = '.';
            setUsed(x, y, v, false);
        }

        return false;
    }

public:

    void solveSudoku(vector<vector<char> > &board) {
        memset(used, 0, sizeof(used));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                    setUsed(i, j, board[i][j], true);
        pboard = &board;
        search(0, 0);
    }
};

int main() {

    vector<vector<char> > sudoku(9, vector<char>(9, '.'));

    char sudstr[] = "..9748...7.........2.1.9.....7...24..64.1.59..98...3.....8.3.2.........6...2759..";

    int cnt = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku[i][j] = sudstr[cnt++];
        }
    }

    Solution().solveSudoku(sudoku);

    return 0;
}
