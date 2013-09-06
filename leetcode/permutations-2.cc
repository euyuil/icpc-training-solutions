class Solution {

    vector<int> *pnum;
    vector<bool> used;
    vector<int> current;
    vector<vector<int> > ret;

    void search(int d) {
        if (d >= used.size()) {
            vector<int> ans(pnum->size());
            for (int i = 0; i < ans.size(); ++i)
                ans[i] = pnum->at(current[i]);
            ret.push_back(ans);
        } else {
            for (int i = 0; i < used.size(); ++i) {
                if (!used[i]) {
                    current[d] = i;
                    used[i] = true;
                    search(d + 1);
                    used[i] = false;
                }
            }
        }
    }

public:

    vector<vector<int> > permuteUnique(vector<int> &num) {

        ret.clear();
        used.clear();
        used.resize(num.size());
        current.clear();
        current.resize(num.size());

        pnum = &num;

        search(0);

        sort(ret.begin(), ret.end(), [](const vector<int> &a, const vector<int> &b) {
            for (int i = 0; i < a.size() && i < b.size(); ++i)
                if (a[i] != b[i])
                    return a[i] < b[i];
            return a.size() < b.size();
        });

        ret.resize(unique(ret.begin(), ret.end()) - ret.begin());

        return ret;
    }
};
