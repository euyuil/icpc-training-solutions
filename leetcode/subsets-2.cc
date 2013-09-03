#include <map>
#include <utility>

using namespace std;

class Solution {

    map<int, int> m;
    vector<pair<int, int> > mv;
    vector<int> arr;
    vector<vector<int> > ret;

    void recursive(int d) {

        if (d == arr.size()) {
            vector<int> subset;
            for (int i = 0; i < arr.size(); ++i)
                for (int j = 0; j < arr[i]; ++j)
                    subset.push_back(mv[i].first);
            ret.push_back(subset);
        } else {
            for (arr[d] = 0; arr[d] <= mv[d].second; ++arr[d]) {
                recursive(d + 1);
            }
        }
    }

public:

    vector<vector<int> > subsetsWithDup(vector<int> &S) {

        m.clear();
        mv.clear();
        arr.clear();
        ret.clear();

        for (int i = 0; i < S.size(); ++i)
            ++m[S[i]];

        for (auto it = m.begin(); it != m.end(); ++it)
            mv.push_back(make_pair(it->first, it->second));

        arr.resize(mv.size());

        recursive(0);

        return ret;

    }
};
