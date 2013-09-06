class Solution {

    int current_count, target_count;
    vector<int> current, target;

public:

    string minWindow(string S, string T) {

        current.clear();
        current.resize(256);
        target.clear();
        target.resize(256);

        current_count = 0;
        target_count = T.size();

        for (int i = 0; i < T.size(); ++i)
            ++target[T[i]];

        bool covered = false;
        int i = 0, j = 0, mi = 0, mj = INT_MAX;

        while (i <= j) {

            if (current_count >= target_count) {

                covered = true;

                if (mj - mi > j - i) {
                    mi = i; mj = j;
                }

                if (--current[S[i]] < target[S[i]])
                    --current_count;
                ++i;

            } else {

                if (j >= S.size())
                    break;

                if (++current[S[j]] <= target[S[j]])
                    ++current_count;
                ++j;
            }
        }

        string ret;

        if (covered) {
            ret = S.substr(mi, mj - mi);
        }

        return ret;
    }
};
