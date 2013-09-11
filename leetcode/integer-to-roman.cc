class Solution {

    string digitToRoman(int digit, char ten, char five, char one) {
        if (0 <= digit && digit <= 3)
            return string(digit, one);
        else if (digit == 4)
            return string(1, one) + string(1, five);
        else if (digit <= 8) {
            return string(1, five) + string(digit - 5, one);
        } else if (digit == 9) {
            return string(1, one) + string(1, ten);
        }
    }

public:

    string intToRoman(int num) {
        string ret;
        if (num >= 1000) {
            ret += digitToRoman(num / 1000, ' ', ' ', 'M');
            num %= 1000;
        }
        if (num >= 100) {
            ret += digitToRoman(num / 100, 'M', 'D', 'C');
            num %= 100;
        }
        if (num >= 10) {
            ret += digitToRoman(num / 10, 'C', 'L', 'X');
            num %= 10;
        }
        if (num >= 1) {
            ret += digitToRoman(num / 1, 'X', 'V', 'I');
            num %= 1;
        }
        return ret;
    }
};
