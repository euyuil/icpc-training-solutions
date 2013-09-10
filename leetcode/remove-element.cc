#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {

        int newlen = n;

        for (int i = 0; i < newlen; ++i)
            if (A[i] == elem)
                swap(A[i--], A[--newlen]);

        return newlen;
    }
};

int main() {
    int a[] = {2, 2, 2};
    Solution().removeElement(a, 3, 2);
}
