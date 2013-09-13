class Solution {
public:
    bool isMatch(const char *s, const char *p) {

        if (!*p) return !*s;

        int lens = strlen(s), lenp = strlen(p);

        string pch; pch.reserve(lenp + 1);
        vector<bool> pst; pst.reserve(lenp + 1);

        // dummy byte for pattern
        pch += ' '; pst.push_back(false);

        for (int i = 0; i < lenp; ++i) {
            pch += p[i];
            if (i + 1 < lenp && p[i + 1] == '*') {
                pst.push_back(true);
                ++i;
            } else {
                pst.push_back(false);
            }
        }

        lenp = pch.size() - 1; // subtract for dummy byte
        --s; // dummy byte for string

        vector<vector<bool> > matches(lenp + 1,
                         vector<bool>(lens + 1, false));

        matches[0][0] = true;

        for (int i = 1; i <= lenp; ++i) {
            if (pst[i] && matches[i - 1][0])
                matches[i][0] = true;
            else break;
        }

        for (int i = 1; i <= lenp; ++i) {
            for (int j = 1; j <= lens; ++j) {
                if (pst[i]) {
                    if (pch[i] == s[j] || pch[i] == '.') {
                        matches[i][j] = matches[i - 1][j] ||
                                        matches[i - 1][j - 1] ||
                                        matches[i][j - 1];
                    } else {
                        matches[i][j] = matches[i - 1][j];
                    }
                } else {
                    if ((pch[i] == s[j] || pch[i] == '.'))
                        matches[i][j] = matches[i - 1][j - 1];
                }
            }
        }

        return matches.back().back();
    }
};
