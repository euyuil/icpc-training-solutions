class Solution {
public:
    int divide(int dividend, int divisor) {
        int ret = 0, i = 1;
        do {
            if ((dividend & divisor) == divisor) {
                ret |= i;
                dividend &= ~divisor;
            }
            divisor <<= 1; i <<= 1;
        } while (divisor);
        return ret;
    }
};
