#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {

    bool canPointNext(const char *pat, int i, char cp, char cs) {
        return pat[i + 1] == '?' || pat[i + 1] == cp ||
                      (cp == '?' && pat[i + 1] == cs);
    }

    /**
     * Matches string with pattern contains question mark.
     * @param sb  the begin position of the string
     * @param se  the end position of the string
     * @param pb  the begin position of the pattern
     * @param pe  the end position of the pattern
     * @param b  (out) the begin position of the matching
     * @param e  (out) the end position of the matching
     * @return  whether it's matched or not
     */

    bool match(
        const char *sb, const char *se,
        const char *pb, const char *pe,
        const char *&b, const char *&e)
    {
        vector<int> prev(pe - pb, -1);

        const char *s = sb, *p = pb; b = e = sb;

        while (s < se && p < pe) {

            int si = s - sb, pi = p - pb;

            // update prev array of the pattern
            if (pi > 0) { // si must > 0
                int prevpi = prev[pi - 1];
                while (true) {
                    if (canPointNext(pb, prevpi, *p, *s)) {
                        prev[pi] = prevpi + 1;
                        break;
                    } else if (prevpi == -1) {
                        prev[pi] = -1;
                        break;
                    }
                    prevpi = prev[prevpi];
                }
            }

            // match the string with the pattern
            if (*s == *p || *p == '?') {
                ++s; ++p;
            } else {
                if (pi == 0) b = ++s;
                else pi = prev[pi - 1] + 1;
                p = pb + pi;
            }
        }

        e = s;

        return p == pe;
    }

public:

    bool isMatch(const char *s, const char *p) {

        string strs = "\001" + string(s) + "\002";
        string strp = "\001" + string(p) + "\002";

        const char *ss = strs.c_str(), *pp = strp.c_str();

        const char *sb = ss, *se = ss + strlen(ss), *pb = pp, *pe, *b, *e;

        while (true) {
            for (pe = pb; *pe != '\0' && *pe != '*'; ++pe);
            if (!match(sb, se, pb, pe, b, e)) return false;
            sb = e;
            if (*pe == '\0') break;
            for (pb = pe; pb != '\0' && *pb == '*'; ++pb);
        }

        return true;
    }
};

int main()
{
    //           "*                          babbbb*  aab**b* bb*aa*"
    char str[] = "aaabaaabaabababbabababaababbabbbbaaaaababbaabbbaab";
    char pat[] = "*babbbb*aab**b*bb*aa*";
    cout << Solution().isMatch(str, pat) << endl;
}
