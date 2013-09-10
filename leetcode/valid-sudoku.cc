#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {

    bool used[3][9][9];

    bool testused(int i, int j, int num) {
        return used[0][i][num] || used[1][j][num] ||
               used[2][i - i % 3 + j / 3][num];
    }

    void setused(int i, int j, int num, bool fl) {
        used[0][i][num] = fl;
        used[1][j][num] = fl;
        used[2][i - i % 3 + j / 3][num] = fl;
    }

public:

    bool isValidSudoku(vector<vector<char> > &board) {

        memset(used, 0, sizeof(used));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (!isdigit(board[i][j]))
                    continue;
                if (testused(i, j, board[i][j] - '1'))
                    return false;
                setused(i, j, board[i][j] - '1', true);
            }
        }

        return true;
    }
};

vector<char> psztovc(const char *p) {
    vector<char> ret;
    for ( ; *p; ++p)
        ret.push_back(*p);
    return ret;
}

int main() {
    vector<vector<char> > vvc;
    vvc.push_back(psztovc("53..7...."));
    vvc.push_back(psztovc("6..195..."));
    vvc.push_back(psztovc(".98....6."));
    vvc.push_back(psztovc("8...6...3"));
    vvc.push_back(psztovc("4..8.3..1"));
    vvc.push_back(psztovc("7...2...6"));
    vvc.push_back(psztovc(".6....28."));
    vvc.push_back(psztovc("...419..5"));
    vvc.push_back(psztovc("....8..79"));
    cout << Solution().isValidSudoku(vvc) << endl;
    return 0;
}
