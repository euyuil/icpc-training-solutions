#include <map>
#include <vector>
#include <cctype>

using namespace std;

class Solution {

public:

    bool isNumber(const char *s) {

        while (*s == ' ') ++s;

        if (*s == '+' || *s == '-') ++s;

        bool hasnum = false;
        bool hasdot = false;

        for ( ; s; ++s) {
            if (isdigit(*s)) {
                hasnum = true;
                continue;
            }
            if (*s == '.') {
                if (hasdot) return false;
                hasdot = true;
                continue;
            }
            break;
        }

        if (tolower(*s) == 'e') {

            ++s;

            if (*s == '+' || *s == '-') ++s;

            bool hasenum = false;

            for ( ; *s; ++s) {
                if (isdigit(*s)) {
                    hasenum = true;
                    continue;
                }
                break;
            }

            if (!hasenum) return false;
        }

        if (!hasnum) return false;

        while (*s == ' ') ++s;

        if (*s) return false;

        return true;
    }
};
