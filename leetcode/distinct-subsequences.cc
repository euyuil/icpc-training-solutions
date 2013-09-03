#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

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

class Solution {
public:
    int numDistinct(string S, string T) {

        if (T.size() == 0) return S.size() + 1;
        if (S.size() == 0) return 0;

        S = " " + S, T = " " + T;
        vector<vector<int> > f(T.size());
        for (int i = 0; i < f.size(); ++i)
            f[i].resize(S.size());

        for (int i = 1; i < T.size(); ++i) {
            for (int j = 1; j < S.size(); ++j) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (T[i] == S[j])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }

        // cout << f << endl;

        vector<vector<int> > g(f.size());
        for (int i = 0; i < f.size(); ++i)
            g[i].resize(S.size());

        for (int j = 1; j < S.size(); ++j)
            if (T[T.size() - 1] == S[j] && f.back()[j] == T.size() - 1)
                g.back()[j] = 1;

        for (int i = T.size() - 2; i > 0; --i) {
            for (int j = S.size() - 1; j > 0; --j) {
                if (T[i] == S[j] && f[i][j] == i) {
                    int routes = 0;
                    for (int k = j + 1; k < S.size(); ++k) {
                        if (T[i + 1] == S[k] && f[i + 1][k] == i + 1) {
                            routes += g[i + 1][k];
                        }
                        if (g[i][k] > 0) {
                            routes += g[i][k];
                            break;
                        }
                    }
                    g[i][j] = routes;
                }
            }
        }

        // cout << g << endl;

        int ret = 0;
        for (int j = 1; j < S.size(); ++j)
            ret += g[1][j];
        return ret;
    }
};

int main() {
    string S = "rabbbit", T = "rabbit";
    cout << Solution().numDistinct(S, T) << endl;
    return 0;
}
