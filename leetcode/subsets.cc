#include <algorithm>

using namespace std;

class Solution {

    vector<vector<int> > ret;
    vector<int> arr;
    vector<int> *pS;

    void recursive(int d) {
        if (d == arr.size()) {
            vector<int> vi;
            for (int i = 0; i < d; ++i)
                if (arr[i])
                    vi.push_back(pS->at(i));
            ret.push_back(vi);
        } else {
            for (arr[d] = 0; arr[d] <= 1; ++arr[d])
                recursive(d + 1);
        }
    }

public:

    vector<vector<int> > subsets(vector<int> &S) {

        ret.clear();
        arr.clear();
        sort(S.begin(), S.end());
        pS = &S;

        arr.resize(S.size());

        recursive(0);

        return ret;
    }
};
