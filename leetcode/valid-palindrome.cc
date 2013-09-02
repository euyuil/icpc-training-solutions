#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

class Solution {

public:

    bool isPalindrome(string s) {

        transform(s.begin(), s.end(), s.begin(), static_cast<int (*)(int)>(tolower));

        string t;
        t.reserve(s.size());
        for (int i = 0; i < s.size(); ++i)
            if (islower(s[i]) || isdigit(s[i]))
                t += s[i];

        int i = 0, j = t.size() - 1;
        while (i < j)
            if (t[i++] != t[j--])
                return false;
        return true;
    }
};
