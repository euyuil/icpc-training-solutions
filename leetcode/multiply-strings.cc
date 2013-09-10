#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

    string normalize(string num) {
        int i;
        for (i = num.size() - 1; i >= 0; --i)
            if (num[i] != '0')
                break;
        num.resize(i + 1, '0');
        if (num.size() == 0)
            return string("0");
        return num;
    }

    string multiply(string num, char chnum, int pow10) {

        string ret;
        ret.reserve(num.size() + pow10 + 2);
        ret.resize(pow10, '0');

        int carrier = 0;
        for (int i = 0; i < num.size(); ++i) {
            int digit = carrier;
            digit += int(num[i] - '0') * int(chnum - '0');
            carrier = digit / 10;
            ret += (digit % 10 + '0');
        }

        if (carrier) ret += (carrier + '0');

        return ret;
    }

    string add(string num1, string num2) {

        string ret;
        int maxlen = max(num1.size(), num2.size());
        ret.reserve(maxlen);

        bool carrier = false;
        for (int i = 0; i < maxlen; ++i) {
            int digit = (carrier ? 1 : 0);
            if (i < num1.size()) digit += num1[i] - '0';
            if (i < num2.size()) digit += num2[i] - '0';
            if (digit >= 10) {
                carrier = true;
                digit -= 10;
            } else carrier = false;
            ret += (digit + '0');
        }

        if (carrier) ret += '1';

        return ret;
    }

public:

    string multiply(string num1, string num2) {

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        num1 = normalize(num1);
        num2 = normalize(num2);

        string sum;
        for (int i = 0; i < num2.size(); ++i) {
            string prod = multiply(num1, num2[i], i);
            cout << prod << endl;
            sum = add(sum, prod);
            cout << sum << endl;
        }

        sum = normalize(sum);
        reverse(sum.begin(), sum.end());

        return sum;
    }
};

int main() {
    string a, b;
    while (cin >> a >> b)
        cout << Solution().multiply(a, b) << endl;
    return 0;
}
