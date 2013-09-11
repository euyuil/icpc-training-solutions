#include <cctype>
#include <climits>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        int ret = 0;
        int factor = 1;
        const char *p = str;
        while (*p == ' ') ++p;
        if (*p == '-') factor = -factor, ++p;
        else if (*p == '+') ++p;
        for ( ; *p; ++p) {
            if (isdigit(*p)) {
                int newReta = ret * 10;
                int newRetb = factor * (*p - '0');
                if (factor > 0) {
                    if (ret == 214748364 && newRetb > 7 ||
                        ret > 214748364)
                        ret = INT_MAX;
                    else ret = newReta + newRetb;
                } else if (factor < 0) {
                    if (ret == -214748364 && newRetb < -8 ||
                        ret < -214748364)
                        ret = INT_MIN;
                    else ret = newReta + newRetb;
                }
            } else break;
        }
        return ret;
    }
};

int main() {
    Solution().atoi("-11919730356x");
    return 0;
}
