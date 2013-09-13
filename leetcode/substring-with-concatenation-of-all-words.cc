#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {

        vector<int> ret;

        if (L.size() == 0)
            return ret;

        int unitLength = L[0].size();

        if (S.size() < unitLength || unitLength == 0)
            return ret;

        unordered_map<string, int> target, current;

        for (int i = 0; i < L.size(); ++i)
            target[L[i]]++;

        for (int begin = 0; begin < unitLength; ++begin) {

            current.clear();
            int i = begin, j = begin;
            int validRequired = L.size(), invalidCount = 0;

            while (j <= S.size()) {

                if (validRequired == 0 && invalidCount == 0)
                    ret.push_back(i);

                if (invalidCount > 0 || validRequired == 0) {

                    string substr = S.substr(i, unitLength);

                    int &nowHave = current[substr];
                    int &shouldHave = target[substr];

                    if (nowHave > shouldHave) --invalidCount;
                    else ++validRequired;
                    --nowHave;
                    i += unitLength;

                } else {

                    if (j + unitLength > S.size()) break;

                    string substr = S.substr(j, unitLength);

                    if (target.find(substr) == target.end()) {
                        i = j = j + unitLength;
                        current.clear();
                        validRequired = L.size();
                        invalidCount = 0;
                        continue;
                    }

                    int &nowHave = current[substr];
                    int &shouldHave = target[substr];

                    if (nowHave < shouldHave) --validRequired;
                    else ++invalidCount;
                    ++nowHave;
                    j += unitLength;
                }
            }
        }

        return ret;
    }
};

int main() {
    vector<string> vec;
    vec.push_back("foo");
    vec.push_back("bar");
    Solution().findSubstring("barfoothefoobarman", vec);
    return 0;
}
