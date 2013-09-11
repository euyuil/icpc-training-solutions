class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n <= 0) {
            ret.push_back("");
            return ret;
        }
        if (n == 1) {
            ret.push_back("()");
            return ret;
        }
        for (int left = 0; left <= n - 1; ++left) {
            int right = n - 1 - left;
            vector<string> lefts = generateParenthesis(left);
            vector<string> rights = generateParenthesis(right);
            for (int i = 0; i < lefts.size(); ++i) {
                for (int j = 0; j < rights.size(); ++j) {
                    ret.push_back("(" + lefts[i] + ")" + rights[j]);
                }
            }
        }
        return ret;
    }
};
