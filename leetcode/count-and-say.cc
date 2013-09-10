#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {

        string ret;
        if (n <= 0) return ret;
        ret.resize(1, '1');

        while (--n) {

            string newRet;
            int start = 0;
            while (start < ret.size()) {
                int i = start, ch = ret[start];
                for ( ; i < ret.size(); ++i)
                    if (ret[i] != ch) break;
                // [start, i)
                newRet += i - start + '0';
                newRet += ch;
                start = i;
            }

            ret = newRet;
        }

        return ret;
    }
};

int main() {
    int n;
    while (cin >> n)
        cout << Solution().countAndSay(n) << endl;
    return 0;
}
