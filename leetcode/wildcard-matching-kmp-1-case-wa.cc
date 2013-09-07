#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {

        string ss("\001" + string(s) + "\002"), pp("\001" + string(p) + "\002");
        int lens = ss.size(), lenp = pp.size();

        int lastFallback = -1;
        vector<int> prev(lenp, -1);

        int si = 0, pi = 0;
        while (si < lens && pi < lenp) {
            if (pp[pi] == '*') {
                prev[pi] = pi - 1;
                lastFallback = pi;
                ++pi;
            } else if (ss[si] == pp[pi] || pp[pi] == '?') {
                if (pi > 0) {
                    int prevpi = prev[pi - 1] + 1;
                    if (pp[prevpi] == '?') {
                        prev[pi] = prevpi;
                    } else if (si == 0) {
                        if (pp[prevpi] == pp[pi]) prev[pi] = prevpi;
                        else prev[pi] = lastFallback;
                    } else if (si > 0) {
                        int prevsi = si - pi + prevpi;
                        if (ss[prevsi] == ss[si]) prev[pi] = prevpi;
                        else prev[pi] = lastFallback;
                    }
                } else prev[pi] = lastFallback;
                ++si; ++pi;
            } else {
                if (pi == 0) break;
                else pi = prev[pi - 1] + 1;
                if (pp[pi] == '*') {
                    ++si; ++pi;
                }
            }
        }

        return si == lens && pi == lenp;
    }
};

int main() {
    cout << Solution().isMatch("abb", "*??") << endl;
    return 0;
}
