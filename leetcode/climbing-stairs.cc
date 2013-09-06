class Solution {
public:
    int climbStairs(int n) {
        const long double sqrt5 = sqrt((long double)5.0);
        long double a = pow((1 + sqrt5) / 2, n + 1);
        long double b = pow((1 - sqrt5) / 2, n + 1);
        long double r = (a - b) / sqrt5;
        return floor(r + 0.5);
    }
};
