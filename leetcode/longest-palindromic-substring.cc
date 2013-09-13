class Solution {
public:
    string longestPalindrome(string s) {

        string t;
        t.reserve(s.size() * 2 + 4);
        t += "\002\001";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '\001';
        }
        t += '\003';

        vector<int> longest(t.size());

        int rightmost = 0, rightmostCentral = 0;
        for (int i = 1; i < t.size() - 1; ++i) {
            int j = 1;
            if (i <= rightmost)
                j = longest[2 * rightmostCentral - i] + 1;
            for ( ; t[i - j] == t[i + j]; ++j); --j;
            longest[i] = j;
            if (j > rightmost) {
                rightmost = j;
                rightmostCentral = i;
            }
        }

        int maxval = -1, maxpos = -1;
        for (int i = 0; i < t.size(); ++i) {
            if (longest[i] > maxval) {
                maxval = longest[i];
                maxpos = i;
            }
        }

        int position = maxpos / 2 - 1;
        int length = maxval;
        int begin = position - (length - 1) / 2;

        return s.substr(begin, length);
    }
};
