class Solution {
public:
    int divide(int dividend, int divisor) {

        unsigned ua = dividend > 0 ? dividend : -dividend;
        unsigned ub = divisor > 0 ? divisor : -divisor;

        int factor = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        int first_bit = 0;

        while (ub << first_bit < ua && (ub << first_bit & 0x80000000u) == 0)
            ++first_bit;

        unsigned ret = 0;
        for (int i = first_bit; i >= 0; --i) {
            if (ua >= ub << i) {
                ua -= ub << i;
                ret |= 1u << i;
            }
        }

        return factor > 0 ? ret : -ret;
    }
};

int main() {
    Solution().divide(-2147483648, 2);
    return 0;
}
