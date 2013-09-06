class Solution {
public:
    int lengthOfLastWord(const char *s) {

        if (!*s) return 0;

        const char *p = s, *end = s;
        const char *last_space = s - 1;

        for ( ; *end; ++end);
        for (--end; end >= s && *end == ' '; --end);
        ++end;

        for (p = s; *p && p < end; ++p) {
            if (*p == ' ') last_space = p;
        }

        return p - last_space - 1;
    }
};
