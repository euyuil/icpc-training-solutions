template <typename T>
bool vecLess(const vector<T> &a, const vector<T> &b) {
    int minLength = min(a.size(), b.size());
    for (int i = 0; i < minLength; ++i)
        if (a[i] != b[i])
            return a[i] < b[i];
    return a.size() < b.size();
}

template <typename T>
bool vecEqual(const vector<T> &a, const vector<T> &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i])
            return false;
    return true;
}

class Solution {

    vector<int> makeQuad(pair<int, int> &a, pair<int, int> &b) {
        vector<int> ret;
        ret.push_back(a.first);
        ret.push_back(a.second);
        ret.push_back(b.first);
        ret.push_back(b.second);
        return ret;
    }

public:

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int, int> > > hash;
        for (int i = 0; i < num.size(); ++i)
            for (int j = i + 1; j < num.size(); ++j)
                hash[num[i] + num[j]].push_back(make_pair(i, j));
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            int remain = target - it->first;
            auto jt = hash.find(remain);
            if (jt == hash.end()) continue;
            for (int i = 0; i < it->second.size(); ++i) {
                for (int j = 0; j < jt->second.size(); ++j) {
                    vector<int> quad = makeQuad(it->second[i], jt->second[j]);
                    sort(quad.begin(), quad.end());
                    for (int i = 1; i < quad.size(); ++i)
                        if (quad[i - 1] == quad[i])
                            goto lovely;
                    ret.push_back(quad);
                }
                lovely:;
            }
        }
        for (int i = 0; i < ret.size(); ++i)
            for (int j = 0; j < ret[i].size(); ++j)
                ret[i][j] = num[ret[i][j]];
        sort(ret.begin(), ret.end(), vecLess<int>);
        ret.resize(unique(ret.begin(), ret.end(), vecEqual<int>) - ret.begin());
        return ret;
    }
};
