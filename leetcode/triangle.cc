#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {

        if (triangle.size() == 0)
            return 0;

        vector<int> state(triangle.size());

        state[0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); ++i)
        {
            for (int j = triangle[i].size() - 1; j >= 0; --j)
            {
                int minimum = INT_MAX;

                if (j < triangle[i - 1].size())
                    minimum = state[j];
                if (j > 0)
                    minimum = min(minimum, state[j - 1]);

                state[j] = minimum + triangle[i][j];
            }
        }

        int minimum = INT_MAX;

        for_each(state.begin(), state.end(), [&](int x) {
            minimum = min(minimum, x);
        });

        return minimum;
    }
};

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vs)
{
    os << "[ ";
    for (int i = 0; i < vs.size(); ++i)
        os << vs[i] << ' ';
    os << ']';
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T> > &vvs)
{
    os << "[ ";
    for (int i = 0; i < vvs.size(); ++i)
        os << vvs[i] << ' ';
    os << ']';
    return os;
}

int main()
{
    Solution sol;

    int arr[4][4] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    vector<vector<int> > tri(4);
    for (int i = 0; i < 4; ++i)
        tri[i] = vector<int>(arr[i], arr[i] + i + 1);

    cout << tri << endl;

    cout << sol.minimumTotal(tri) << endl;

    return 0;
}
