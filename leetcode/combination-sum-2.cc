class Solution {

    int target;
    vector<int> sol;
    vector<vector<int> > ret;

    vector<bool> used;
    vector<int> cands;

    void search(int d, int sum) {
        if (sum > target)
            return;
        if (sum == target) {
            ret.push_back(sol);
            return;
        }
        if (d >= cands.size())
            return;

        search(d + 1, sum);

        if (d == 0 || cands[d - 1] != cands[d] || used[d - 1]) {
            used[d] = true;
            sol.push_back(cands[d]);
            search(d + 1, sum + cands[d]);
            sol.pop_back();
            used[d] = false;
        }
    }

public:

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {

        this->target = target;
        ret.clear();
        sol.clear();

        used.resize(num.size());
        cands = num;
        sort(cands.begin(), cands.end());

        search(0, 0);

        return ret;
    }
};
