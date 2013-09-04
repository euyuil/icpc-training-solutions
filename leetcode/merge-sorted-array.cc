#include <cstring>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {

        int *C = new int[m + n];

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (A[i] < B[j]) C[i + j] = A[i++];
            else C[i + j] = B[j++];
        }

        for ( ; i < m; ++i)
            C[i + j] = A[i];
        for ( ; j < n; ++j)
            C[i + j] = B[j];

        memcpy(A, C, sizeof(int) * (m + n));

        delete [] C;
    }
};
