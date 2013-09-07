class Solution {
public:
    bool isMatch(const char *s, const char *p) {

        int lens = strlen(s), lenp = strlen(p);

        const char *ss = s - 1, *pp = p - 1;
        // m * n will cause memory limit exceeded.
        vector<vector<int> > f(2, vector<int>(lenp + 1, -1));

        f[0][0] = 0;
        for (int j = 1; j <= lenp; ++j)
            if (pp[j] == '*') f[0][j] = 0;
            else break;

        // next time, try to loop the pattern at outer loop...
        for (int i = 1; i <= lens; ++i) {
            bool possible = false;
            int ii = i % 2, i1 = (i + 1) % 2;
            for (int j = 1; j <= lenp; ++j) {
                if (pp[j] == '*') {
                    if (f[ii][j - 1] == i || f[i1][j - 1] == i - 1 || f[i1][j] > 0)
                        f[ii][j] = i, possible = true;
                } else if (pp[j] == '?' || pp[j] == ss[i]) {
                    if (f[i1][j - 1] == i - 1)
                        f[ii][j] = i, possible = true;
                } else {
                    f[ii][j] = -1;
                }
            }
            if (!possible) return false;
        }

        return f[lens % 2].back() == lens;
    }
};
