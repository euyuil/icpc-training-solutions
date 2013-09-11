class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

        if (strs.size() == 0)
            return "";

        int lcp = 0;
        bool flag = true;

        while (flag && lcp < strs[0].size()) {
            int i = 1;
            for ( ; i < strs.size(); ++i) {
                if (lcp >= strs[i].size() || strs[i][lcp] != strs[0][lcp])
                    break;
            }
            if (i == strs.size()) {
                flag = true;
                ++lcp;
            } else {
                flag = false;
            }
        }

        return strs[0].substr(0, lcp);
    }
};
