class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        map<string, vector<string> > groups;
        for (int i = 0; i < strs.size(); ++i) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            groups[sorted].push_back(strs[i]);
        }
        for (auto it = groups.begin(); it != groups.end(); ++it) {
            vector<string> &group = it->second;
            if (group.size() >= 2)
                for (int i = 0; i < group.size(); ++i)
                    ret.push_back(group[i]);
        }
        return ret;
    }
};
