#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int dx[] = {1, 0};
const int dy[] = {0, 1};

class Solution {

private:

    int x, y;
    char *pBoard;
    int *pSet;

private:

    inline int pos(int i, int j) {
        if (i < 0 || i >= x || j < 0 || j >= y)
            return -1;
        return i * y + j;
    }

    void init(vector<vector<char> > &board) {

        free();

        x = board.size() + 2;
        y = board[0].size() + 2;
        int xy = x * y;

        pBoard = new char[xy];
        pSet = new int[xy];

        for (int i = 0; i < xy; ++i)
            pBoard[i] = 'O';
        for (int i = 1; i <= board.size(); ++i)
            for (int j = 1; j <= board[0].size(); ++j)
                pBoard[pos(i, j)] = board[i - 1][j - 1];

        for (int i = 0; i < xy; ++i)
            pSet[i] = i;
    }

    inline void free() {

        if (pBoard)
            delete [] pBoard;
        if (pSet)
            delete [] pSet;

        pBoard = NULL;
        pSet = NULL;
    }

    int root(int i) {
        return i == pSet[i] ? i : (pSet[i] = root(pSet[i]));
    }

    inline void join(int i, int j) {
        pSet[root(i)] = root(j);
    }

    void fill() {
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                int p = pos(i, j);
                if (p < 0) continue;
                for (int k = 0; k < 2; ++k) {
                    int q = pos(i + dx[k], j + dy[k]);
                    if (q < 0) continue;
                    if (pBoard[p] == pBoard[q])
                        join(p, q);
                }
            }
        }
        root(0);
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                int p = pos(i, j);
                // cout << root(p) << ' ';
                if (root(p) != pSet[0])
                    pBoard[p] = 'X';
            }
            // cout << endl;
        }
    }

    void write(vector<vector<char> > &board) {
        for (int i = 1; i <= board.size(); ++i)
            for (int j = 1; j <= board[0].size(); ++j)
                board[i - 1][j - 1] = pBoard[pos(i, j)];
    }

public:

    Solution() {
        pBoard = NULL;
        pSet = NULL;
    }

    virtual ~Solution() {
        free();
    }

    void solve(vector<vector<char> > &board) {
        if (board.size() != 0 && board[0].size() != 0) {
            init(board);
            fill();
            write(board);
        }
    }
};

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vs)
{
    os << "[ ";
    for (int i = 0; i < vs.size(); ++i)
        os << vs[i] << ' ';
    os << ']';
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T> > &vvs)
{
    os << "[ ";
    for (int i = 0; i < vvs.size(); ++i)
        os << vvs[i] << ' ';
    os << ']';
    return os;
}

int main_2x2()
{
    vector<vector<char> > board;

    vector<char> str;
    str.push_back('O');
    str.push_back('O');
    board.push_back(str);
    board.push_back(str);

    Solution().solve(board);

    cout << board << endl;

    return 0;
}

int main()
{
    vector<vector<char> > board;

    vector<char> str;
    str.push_back('X');
    str.push_back('X');
    str.push_back('X');
    str.push_back('X');
    board.push_back(str);

    str[1] = str[2] = 'O';
    board.push_back(str);

    str[1] = 'X';
    board.push_back(str);

    str[1] = 'O'; str[2] = 'X';
    board.push_back(str);

    Solution().solve(board);

    cout << board << endl;

    return 0;
}
