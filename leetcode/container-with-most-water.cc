class Solution {
public:
    int maxArea(vector<int> &height) {
        int ret = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            int a = h * w;
            if (ret < a)
                ret = a;
            if (height[i] > height[j]) --j;
            else ++i;
        }
        return ret;
    }
};
