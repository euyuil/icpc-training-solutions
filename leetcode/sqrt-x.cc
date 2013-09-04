class Solution {
public:
    int sqrt(int x) {
        int a = 0, b = x > 2 ? x : 2;
        while (a + 1 < b) {
            long long m = (a + b) / 2;
            if (m * m <= x) a = m;
            else b = m;
        }
        return a;
    }
};
