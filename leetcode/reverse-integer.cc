class Solution {
public:
    int reverse(int x) {

        if (x == 0) return x;

        int factor = x > 0 ? 1 : x < 0 ? -1 : 0;

        x = abs(x);

        int ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }

        return ret * factor;
    }
};
