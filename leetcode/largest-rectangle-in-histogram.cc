#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {

    int ret;
    vector<pair<int, int> > vp;

    inline void tell(int index, int value) {
        while (vp.size() && value <= vp.back().second) {
            int height = vp.back().second;
            vp.pop_back();
            int width = index - vp.back().first - 1;
            int area = width * height;
            ret = max(ret, area);
        }
        vp.push_back(make_pair(index, value));
    }

public:

    int largestRectangleArea(vector<int> &height) {

        ret = 0;

        vp.clear();
        vp.push_back(make_pair(-1, 0));

        for (int i = 0; i < height.size(); ++i)
            tell(i, height[i]);
        tell(height.size(), 0);

        return ret;
    }
};
