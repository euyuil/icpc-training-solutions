class Solution {

    vector<vector<int> > ret;

    int n, k;
    vector<int> curr;

    void search(int d) {
        if (d == k) {
            ret.push_back(curr);
        } else {
            int last = 1;
            if (d > 0) last = curr[d - 1] + 1;
            for (curr[d] = last; curr[d] <= n; ++curr[d])
                search(d + 1);
        }
    }

public:

    vector<vector<int> > combine(int n, int k) {

        this->n = n;
        this->k = k;

        ret.clear();
        curr.resize(k, 0);

        search(0);

        return ret;
    }
};
