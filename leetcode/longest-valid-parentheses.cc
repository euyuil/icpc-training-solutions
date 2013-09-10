class Solution {

public:

    int longestValidParentheses(string s) {

        vector<bool> valid(s.size(), true);

        int counter = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') ++counter;
            else if (s[i] == ')') --counter;
            if (counter < 0) {
                valid[i] = false;
                counter = 0;
            }
        }

        counter = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') ++counter;
            else if (s[i] == '(') --counter;
            if (counter < 0) {
                valid[i] = false;
                counter = 0;
            }
        }

        int longest = 0, current = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (valid[i]) ++current;
            else {
                longest = max(longest, current);
                current = 0;
            }
        }

        return max(longest, current);
    }
};
