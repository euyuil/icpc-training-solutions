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
                // this is really a good idea.
                if (!used[i] && (i == used.size() - 1 ||
                                 pnum->at(i) != pnum->at(i + 1) ||
                                 used[i + 1])) {
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

        sort(num.begin(), num.end());

        pnum = &num;

        search(0);

        return ret;
    }
};
