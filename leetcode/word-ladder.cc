#include <map>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {

private:

    vector<string> ndict;
    vector<vector<int> > mdict;
    unordered_map<string, int> umdict;
    vector<int> shortest;
    vector<unordered_set<int> > previous;

    inline static bool convertable(const string &a, const string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i)
            if (a[i] != b[i]) ++diff;
        return diff == 1;
    }

    vector<vector<int> > produce_int(int e) {
        vector<vector<int> > ret;
        if (!previous[e].empty()) {
            auto it = previous[e].begin();
            for ( ; it != previous[e].end(); ++it) {
                vector<vector<int> > pref = produce_int(*it);
                for (int i = 0; i < pref.size(); ++i) {
                    pref[i].push_back(e);
                    ret.push_back(pref[i]);
                }
            }
        } else if (shortest[e] >= 0) {
            vector<int> vs;
            vs.push_back(e);
            ret.push_back(vs);
        }
        return ret;
    }

    vector<vector<string> > produce(int e) {
        vector<vector<int> > pi = produce_int(e);
        vector<vector<string> > ret(pi.size());
        for (int i = 0; i < pi.size(); ++i) {
            ret[i].reserve(pi[i].size());
            for (int j = 0; j < pi[i].size(); ++j)
                ret[i].push_back(ndict[pi[i][j]]);
        }
        return ret;
    }

public:

    struct state {
        int previous, current, steps;
        state(int p, int c, int s) : previous(p), current(c), steps(s) { }
    };

    int ladderLength(
        string start, string end, unordered_set<string> &dict) {

        int ei = 0;

        {
            ndict.clear();
            mdict.clear();
            umdict.clear();
            shortest.clear();
            previous.clear();

            ndict.reserve(dict.size() + 20);
            ndict.push_back(start);
            for (auto it = dict.begin(); it != dict.end(); ++it) {
                umdict[*it] = ndict.size();
                ndict.push_back(*it);
            }
            ei = ndict.size();
            umdict[end] = ei;
            ndict.push_back(end);

            mdict.resize(ndict.size());
            shortest.resize(ndict.size(), -1);
            previous.resize(ndict.size());

            for (int i = 0; i < ndict.size() - 1; ++i) {
                for (int j = 0; j < ndict[i].size(); ++j) {
                    string ndicti = ndict[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == ndict[i][j]) continue;
                        ndicti[j] = ch;
                        if (dict.find(ndicti) != dict.end())
                            mdict[i].push_back(umdict[ndicti]);
                    }
                }
            }
        }

        queue<state> q;
        q.push(state(-1, 0, 0));
        shortest[0] = 0;

        while (!q.empty()) {

            state obj = q.front(); q.pop();
            int steps = obj.steps, cur = obj.current, pre = obj.previous;

            // known best solution is better
            if (shortest[cur] >= 0 && shortest[cur] < steps) continue;
            if (shortest[ei] >= 0 && shortest[cur] > shortest[ei]) break;

            shortest[cur] = steps;
            if (pre >= 0) previous[cur].insert(pre);

            if (cur != ei) {
                vector<int> &mdictcur = mdict[cur];
                for (int i = 0; i < mdictcur.size(); ++i) {
                    int nxt = mdictcur[i], nxtsteps = steps + 1;
                    if (shortest[nxt] >= 0 && nxtsteps > shortest[nxt])
                        continue;
                    shortest[nxt] = nxtsteps;
                    q.push(state(cur, nxt, nxtsteps));
                }
            }
        }

        return shortest[ei] + 1;
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
    string start = "lost", end = "cost";
    unordered_set<string> dict;

    dict.insert("most");
    dict.insert("fist");
    dict.insert("lost");
    dict.insert("cost");
    dict.insert("fish");

    Solution sol;
    vector<vector<string> > ans = sol.findLadders(start, end, dict);

    cout << ans << endl;

    return 0;
}
