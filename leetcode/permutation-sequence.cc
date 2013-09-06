class Solution {

    template <typename Iterator>
    void fillPermutation(Iterator begin, int n, int k) {

        if (n <= 0) return;

        int ni = 1;
        for (int i = 2; i <= n; ++i) ni *= i;

        int group_size = ni / n;

        *begin = (k / group_size) + '1';

        fillPermutation(begin + 1, n - 1, k % group_size);
    }

public:

    string getPermutation(int n, int k) {

        string ret(n, ' ');

        fillPermutation(ret.begin(), n, k - 1);

        for (int i = ret.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j < ret.size(); ++j)
                if (ret[j] >= ret[i])
                    ++ret[j];
        }

        return ret;
    }
};
