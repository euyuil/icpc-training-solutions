class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int lens = strlen(haystack);
        int lenp = strlen(needle);
        vector<int> prev(lenp, -1);
        for (int i = 1; i < lenp; ++i) {
            int pr = prev[i - 1];
            while (pr >= 0 && needle[pr + 1] != needle[i])
                pr = prev[pr];
            if (pr == -1) {
                if (needle[0] != needle[i]) prev[i] = -1;
                else prev[i] = 0;
            } else prev[i] = pr + 1;
        }
        int i = 0, j = 0;
        while (i < lens && j < lenp) {
            if (haystack[i] == needle[j]) {
                ++i; ++j;
            } else {
                if (j > 0) {
                    int pr = prev[j - 1];
                    j = pr + 1;
                } else if (j == 0) {
                    ++i;
                }
            }
        }
        if (j == lenp) {
            return haystack + i - j;
        } else {
            return NULL;
        }
    }
};
