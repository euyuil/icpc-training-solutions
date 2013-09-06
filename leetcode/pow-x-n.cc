class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n == 2) return x * x;
        if (n == -1) return 1.0 / x;
        if (n == -2) return 1.0 / (x * x);
        int m = n / 2;
        double powxm = pow(x, m);
        double ret = powxm * powxm;
        if (n % 2) ret *= pow(x, n % 2);
        return ret;
    }
};
