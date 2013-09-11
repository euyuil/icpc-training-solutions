class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push_back(s[i]);
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (st.size() && (st.back() == '(' && s[i] == ')' ||
                                  st.back() == '[' && s[i] == ']' ||
                                  st.back() == '{' && s[i] == '}'))
                    st.pop_back();
                else
                    return false;
            }
        }
        return st.size() == 0;
    }
};
