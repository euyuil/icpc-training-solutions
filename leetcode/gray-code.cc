class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        int end = (1 << n);
        for (int i = 0; i < end; ++i)
            ret.push_back(i ^ (i >> 1));
        return ret;
    }
};
