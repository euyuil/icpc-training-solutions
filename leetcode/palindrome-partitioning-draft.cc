#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
private:
    static bool isPalindrome(const char *b, const char *e)
    {
        --e;
        while (b < e)
            if (*(b++) != *(e--))
                return false;
        return true;
    }

public:
    vector<vector<string> > fff(string s)
    {
        vector<vector<string> > ret;

        // cout << "begin " << s << endl;

        for (int i = 1; i <= s.size(); ++i)
        {
            if (isPalindrome(s.c_str(), s.c_str() + i))
            {
                string left = s.substr(0, i), right = s.substr(i);

                // cout << "select " << left << endl;

                if (right.size() > 0)
                {
                    vector<vector<string> > vvs = fff(right);

                    for (int j = 0; j < vvs.size(); ++j)
                    {
                        vector<string> vs;
                        vs.push_back(left);
                        for (int k = 0; k < vvs[j].size(); ++k)
                            vs.push_back(vvs[j][k]);
                        ret.push_back(vs);
                    }
                }
                else
                {
                    vector<string> vs;
                    vs.push_back(left);
                    ret.push_back(vs);
                }
            }
        }

        // cout << "end " << s << endl;

        return ret;
    }
};

ostream &operator<<(ostream &os, const vector<string> &vs)
{
    os << "[ ";
    for (int i = 0; i < vs.size(); ++i)
        os << vs[i] << ' ';
    os << ']';
    return os;
}

ostream &operator<<(ostream &os, const vector<vector<string> > &vvs)
{
    os << "[ ";
    for (int i = 0; i < vvs.size(); ++i)
        os << vvs[i] << ' ';
    os << ']';
    return os;
}

int main()
{
    string s = "aab";
    cout << Solution().fff(s) << endl;
    return 0;
}
