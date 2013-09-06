class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {

        if (matrix.size() == 0) return false;

        int n = matrix.size(), m = matrix.front().size();

        int t = 0, b = n;
        while (t + 1 < b) {
            int mid = (t + b) / 2;
            if (matrix[mid][0] <= target) t = mid;
            else b = mid;
        }

        int l = 0, r = m;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (matrix[t][mid] <= target) l = mid;
            else r = mid;
        }

        return matrix[t][l] == target;
    }
};
