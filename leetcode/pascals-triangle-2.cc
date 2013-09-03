#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> ret;
        ret.resize(rowIndex + 1);
        ret.front() = 1;

        if (rowIndex > 0) {

            long long ni = 1, mi = 1;

            for (int i = 1; i <= (rowIndex / 2); ++i) {
                ni *= (long long)(rowIndex - i + 1);
                mi *= (long long)(i);
                ret[i] = (int)(ni / mi);
            }

            int i = 0, j = rowIndex;
            while (i < j)
                ret[j--] = ret[i++];

        }

        return ret;
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

int main() {
    cout << Solution().getRow(3) << endl;
    return 0;
}
