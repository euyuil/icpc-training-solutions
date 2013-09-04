#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {

    int push(vector<pair<int, int> > &st, int index, int value) {

        int ret = 0;

        while (st.size() && arr[i] <= st.back().second) {
            int height = st.back().second;
            st.pop_back();
            int width = i - st.back().first - 1;
            int area = width * height;
            ret = max(ret, area);
        }
        st.push_back(make_pair(i, arr[i]));

        return ret;
    }

    int maxRectHistogram(vector<int> &arr) {

        int ret = 0;
        vector<pair<int, int> > st;

        push(st, -1, 0);
        for (int i = 0; i < arr.size(); ++i) {
            ret = max(ret, push(st, i, arr[i]));
        }
        ret = max(ret, push(st, arr.size(), 0));

        return ret;
    }

public:

    int maximalRectangle(vector<vector<char> > &matrix) {

        if (!matrix.size()) return 0;

        vector<int> arr(matrix.front().size());

        for (int i = 0; i < matrix.front().size(); ++i)
            arr[i] = matrix.front()[i] - '0';

        int ret = maxRectHistogram(arr);

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '0') arr[j] = 0;
                else ++arr[j];
            }
            ret = max(ret, maxRectHistogram(arr));
        }

        return ret;
    }
};
