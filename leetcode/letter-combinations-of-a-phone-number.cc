class Solution {

    static const char keyboard[][5];

public:

    vector<string> letterCombinations(string digits) {
        int x = 0, y = 1;
        vector<string> ret[2];
        if (digits.size() == 0) {
            ret[x].push_back("");
            return ret[x];
        }
        const char *kb = keyboard[digits[0] - '0'];
        for (const char *p = kb; *p; ++p) {
            string s(1, *p);
            ret[y].push_back(s);
        }
        x ^= 1; y ^= 1; ret[y].clear();
        for (int i = 1; i < digits.size(); ++i) {
            const char *kb = keyboard[digits[i] - '0'];
            for (int j = 0; j < ret[x].size(); ++j) {
                for (const char *p = kb; *p; ++p) {
                    ret[y].push_back(ret[x][j] + *p);
                }
            }
            x ^= 1; y ^= 1; ret[y].clear();
        }
        return ret[x];
    }
};

const char Solution::keyboard[10][5] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};
