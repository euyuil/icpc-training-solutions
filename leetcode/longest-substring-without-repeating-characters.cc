class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size() == 0) return 0;

        int numberOfChar[256], repeatedCount = 0, maxLength = 1;
        memset(numberOfChar, 0, sizeof(numberOfChar));

        int i = 0, j = 0;
        numberOfChar[s[0]] = 1;

        while (i < s.size() && j < s.size()) {

            if (repeatedCount == 0) {

                maxLength = max(maxLength, j - i + 1);

                ++j;

                if (numberOfChar[s[j]] == 0) {
                    numberOfChar[s[j]] = 1;
                } else {
                    numberOfChar[s[j]]++;
                    repeatedCount++;
                }

            } else {

                if (numberOfChar[s[i]] == 1) {
                    numberOfChar[s[i]] = 0;
                } else {
                    numberOfChar[s[i]]--;
                    repeatedCount--;
                }

                ++i;
            }
        }

        return maxLength;
    }
};
