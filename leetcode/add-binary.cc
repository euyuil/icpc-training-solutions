class Solution {
public:
    string addBinary(string a, string b) {

        string r(max(a.size(), b.size()) + 1, '0');

        bool carrier = false;
        for (int ai = a.size() - 1, bi = b.size() - 1, ri = r.size() - 1;
             ri >= 0; --ai, --bi, --ri) {

            int sum = (carrier ? 1 : 0);
            carrier = false;

            if (ai >= 0 && a[ai] == '1') ++sum;
            if (bi >= 0 && b[bi] == '1') ++sum;

            if (sum == 1 || sum == 3) r[ri] = '1';
            if (sum >= 2) carrier = true;
        }

        if (r[0] == '0') r = r.substr(1);
        return r;
    }
};
