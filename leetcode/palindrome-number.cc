class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;
        if (x == 0) return true;

        int firstDigit = 1;
        while (x / firstDigit >= 10)
            firstDigit *= 10;

        while (x > 9) {
            int first = x / firstDigit;
            int last =  x % 10;
            if (first != last)
                return false;
            x -= first * firstDigit;
            x /= 10;
            firstDigit /= 100;
        }

        return true;
    }
};

int main() {
    Solution().isPalindrome(1881);
    return 0;
}
