#include <cstdlib>

using namespace std;

class Solution {

    vector<string> restore(string s, int n) {

        vector<string> ret;

        if (s.size() >= n && s.size() <= 3 * n) {

            if (n == 1) {
                int num = atoi(s.c_str());
                if (num >= 0 && num <= 255 && (s[0] != '0' || s.size() == 1))
                    ret.push_back(s);
            } else {
                for (int i = 1; i <= 3 && i < s.size(); ++i) {
                    string pref = s.substr(0, i);
                    int num = atoi(pref.c_str());
                    if (num >= 0 && num <= 255 && (pref[0] != '0' || pref.size() == 1)) {
                        string rest = s.substr(i);
                        vector<string> rests = restore(rest, n - 1);
                        for (int j = 0; j < rests.size(); ++j)
                            ret.push_back(pref + "." + rests[j]);
                    }
                }
            }
        }

        return ret;
    }

public:

    vector<string> restoreIpAddresses(string s) {
        return restore(s, 4);
    }
};
