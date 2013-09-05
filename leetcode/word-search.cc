#include <vector>
#include <iostream>

using namespace std;

const int dx[] = {  0,  1,  0, -1};
const int dy[] = { -1,  0,  1,  0};

class Solution {

    int n, m;
    string word;
    vector<vector<char> > *pboard;

    vector<vector<bool> > visited;

    inline bool onboard(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    bool search(int d, int x, int y) {

        bool ret = false;

        if (d >= word.size())
            return ret = true;

        if (!onboard(x, y))
            return ret;

        if (visited[x][y])
            return ret;

        do {

            visited[x][y] = true;

            if (pboard->at(x)[y] != word[d])
                break;

            for (int i = 0; i < 4; ++i) {
                if (search(d + 1, x + dx[i], y + dy[i])) {
                    ret = true;
                    break;
                }
            }

        } while (false);

        visited[x][y] = false;

        return ret;
    }

public:
    bool exist(vector<vector<char> > &board, string word) {

        if (word.size() == 0)
            return true;

        if (board.size() == 0)
            return false;

        n = board.size(); m = board.front().size();

        visited.clear();
        visited.resize(n, vector<bool>(m, false));

        this->word = word;
        pboard = &board;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (search(0, i, j))
                    return true;

        return false;
    }
};

int main()
{
    vector<vector<char> > mat(3, vector<char>(3, 'a'));
    string word = "aaaaaaaaaaaaa";
    cout << Solution().exist(mat, word) << endl;
    return 0;
}
