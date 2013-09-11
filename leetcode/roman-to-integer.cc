class Solution {

    int romanCharToInt(char c) {
        switch (toupper(c)) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        }
        return 0;
    }

public:

    int romanToInt(string s) {
        vector<int> arr;
        int begin = 0, end = 0;
        for ( ; begin < s.size(); begin = end) {
            for (end = begin + 1; end < s.size(); ++end)
                if (s[end] != s[begin]) break;
            int num = romanCharToInt(s[begin]) * (end - begin);
            arr.push_back(num);
        }
        int ret = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (i + 1 < arr.size() && arr[i] < arr[i + 1]) {
                ret += arr[i + 1] - arr[i];
                ++i;
            } else {
                ret += arr[i];
            }
        }
        return ret;
    }
};
