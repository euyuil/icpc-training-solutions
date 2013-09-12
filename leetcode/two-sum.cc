class Solution {

    vector<int> order;

    struct orderLessThan {
        vector<int> *pnumbers;
        orderLessThan(vector<int> *p) : pnumbers(p) { }
        bool operator()(int a, int b) {
            vector<int> &numbers = *pnumbers;
            return numbers[a] < numbers[b];
        }
    };

public:

    vector<int> twoSum(vector<int> &numbers, int target) {

        order.resize(numbers.size());
        for (int i = 0; i < numbers.size(); ++i)
            order[i] = i;
        sort(order.begin(), order.end(), orderLessThan(&numbers));

        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[order[i]] + numbers[order[j]];
            if (sum > target) --j;
            else if (sum < target) ++i;
            else break; // assume solution always exists.
        }

        vector<int> ret(2);
        ret[0] = order[i] + 1;
        ret[1] = order[j] + 1;

        if (ret[0] > ret[1])
            swap(ret[0], ret[1]);

        return ret;
    }
};
