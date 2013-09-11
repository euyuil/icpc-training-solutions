class Solution {
public:
    string convert(string s, int nRows) {

        string ret;
        if (nRows <= 0) return ret;
        if (nRows == 1) return s;

        ret.reserve(s.size());
        int groupSize = 2 * nRows - 2;
        for (int i = 0; i < nRows; ++i) {
            if (i == 0 || i == nRows - 1) {
                for (int j = i; j < s.size(); j += groupSize)
                    ret += s[j];
            } else {
                int delta = groupSize - 2 * i;
                for (int j = i; j < s.size(); j += groupSize) {
                    ret += s[j];
                    if (j + delta < s.size())
                        ret += s[j + delta];
                }
            }
        }
        return ret;
    }
};
