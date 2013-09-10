#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

    struct elem {
        int index, value;
        elem(int i, int v) : index(i), value(v) { }
    };

    int *A, n, ret;
    vector<elem> st;

    void push_stack(int index, int value) {

        int last_height = 0;

        while (st.size() && st.back().value <= value) {

            int width = index - st.back().index - 1;
            int this_height = st.back().value;
            int height = this_height - last_height;

            ret += width * height;

            st.pop_back();

            last_height = this_height;
        }

        if (st.size()) {

            int width = index - st.back().index - 1;
            int height = value - last_height;

            ret += width * height;
        }

        st.push_back(elem(index, value));
    }

public:

    int trap(int A[], int n) {

        this->A = A;
        this->n = n;

        ret = 0;
        st.clear();

        for (int i = 0; i < n; ++i)
            push_stack(i, A[i]);

        return ret;
    }
};

int main() {
    int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(A) / sizeof(int);
    cout << Solution().trap(A, n) << endl;
    return 0;
}
