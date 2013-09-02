#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int dx[] = {  0,  1,  0, -1};
const int dy[] = { -1,  0,  1,  0};

class Solution {
private:
    vector<vector<bool> > visited;
    vector<vector<bool> > cache;

private:

    bool outof(vector<vector<char> > &board, int i, int j)
    {
        return (i < 0 || i >= board.size() || j < 0 || j >= board[i].size());
    }

    bool leaked(vector<vector<char> > &board, int i, int j)
    {
        if (outof(board, i, j))
            return true;

        if (visited[i][j])
            return cache[i][j];

        if (board[i][j] == 'X')
            return cache[i][j] = false;

        visited[i][j] = true;

        for (int k = 0; k < 4; ++k)
        {
            int x = i + dx[k], y = j + dy[k];
            if (leaked(board, x, y))
                return cache[i][j] = true;
        }

        return cache[i][j] = false;
    }

    void fill(vector<vector<char> > &board, int i, int j)
    {
        if (outof(board, i, j) || board[i][j] == 'X')
            return;

        board[i][j] = 'X';

        for (int k = 0; k < 4; ++k)
        {
            int x = i + dx[k], y = j + dy[k];
            fill(board, x, y);
        }
    }

public:

    void solve(vector<vector<char> > &board) {

        visited.resize(0);
        visited.resize(board.size());
        for (int i = 0; i < board.size(); ++i)
            visited[i].resize(board[i].size());

        cache.resize(0);
        cache.resize(board.size());
        for (int i = 0; i < board.size(); ++i)
            cache[i].resize(board[i].size());

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] == 'O' && !leaked(board, i, j))
                    fill(board, i, j);
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

int main()
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

int main_sample()
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
