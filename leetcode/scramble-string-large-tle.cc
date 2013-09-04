class Solution {
public:
    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size())
            return false;

        if (s1.size() == 0)
            return true;

        if (s1.size() == 1)
            return s1 == s2;

        for (int i = 1; i < s1.size(); ++i) {

            string s1l = s1.substr(0, i);
            string s1r = s1.substr(i);

            string s2l1 = s2.substr(0, i);
            string s2r1 = s2.substr(i);
            string s2l2 = s2.substr(0, s1.size() - i);
            string s2r2 = s2.substr(s1.size() - i);

            if ((isScramble(s1l, s2l1) && isScramble(s1r, s2r1)) ||
                (isScramble(s1l, s2r2) && isScramble(s1r, s2l2)))
                return true;
        }

        return false;
    }
};
