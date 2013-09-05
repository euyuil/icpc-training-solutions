#include <climits>
#include <algorithm>

using namespace std;

class Solution {

    int findLastIncreasingPair(vector<int> &num) {
        int ret = -1;
        for (int i = 1; i < num.size(); ++i)
            if (num[i - 1] < num[i])
                ret = i - 1;
        return ret;
    }

    int findClosestLarger(vector<int> &num, int start, int value) {
        int ret = num.size(), closest = INT_MAX;
        for (int i = start; i < num.size(); ++i) {
            if (num[i] > value && closest > num[i]) {
                ret = i;
                closest = num[i];
            }
        }
        return ret;
    }

public:

    void nextPermutation(vector<int> &num) {
        int toBeChanged = findLastIncreasingPair(num);
        if (toBeChanged >= 0) {
            int newValueIndex = findClosestLarger(num, toBeChanged + 1, num[toBeChanged]);
            swap(num[toBeChanged], num[newValueIndex]);
        }
        sort(num.begin() + toBeChanged + 1, num.end());
    }
};
