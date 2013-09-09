#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

    struct elem {
        int index, value, minus;
        elem(int i, int v, int m) : index(i), value(v), minus(m) { }
    };

    int *A, n, ret, minus;
    vector<elem> st;

    void push_stack(int index, int value) {

        if (st.back().value > value) {

            st.back().minus += value;

        } else if (st.back().value <= value) {

            int width = index - st.back().index - 1;
            int height = st.back().value;
            int minus = st.back().minus;

            st.pop_back();

            ret += width * height - minus;

            st.push_back(elem(index, value, 0));
        }
    }

public:

    int trap(int A[], int n) {

        this->A = A;
        this->n = n;

        ret = 0;
        minus = 0;
        st.clear();
        st.push_back(elem(-1, 0, 0));

        for (int i = 0; i < n; ++i)
            push_stack(i, A[i]);

        push_stack(n, 0);

        return ret;
    }
};

int main() {
    int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(A) / sizeof(int);
    cout << Solution().trap(A, n) << endl;
    return 0;
}
