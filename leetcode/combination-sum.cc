#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

    vector<int> sol;
    int target;

    vector<vector<int> > ret;

    vector<int> cands;

    bool search(int d, int sum) {
        if (sum > target)
            return false;
        if (sum == target) {
            ret.push_back(sol);
            return false;
        }
        if (d >= cands.size())
            return true;
        bool flag = true; int i;
        for (i = 0; flag; ++i) {
            if (i) sol.push_back(cands[d]);
            // cout << cands[d] * i + sum << endl;
            flag = search(d + 1, cands[d] * i + sum);
        }
        sol.resize(sol.size() - i + 1);
        return true;
    }

public:

    vector<vector<int> > combinationSum(
        vector<int> &candidates, int target) {

        cands = candidates;
        sort(cands.begin(), cands.end());
        cands.resize(
            unique(cands.begin(), cands.end())
            - cands.begin());

        sol.clear();
        this->target = target;

        ret.clear();

        search(0, 0);

        return ret;
    }
};

int main() {
    vector<int> a(1, 1);
    Solution().combinationSum(a, 1);
    return 0;
}
