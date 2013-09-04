#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

inline string to_string(int i)
{
    string ret;
    if (i == 0) ret += '0';
    while (i)
        ret += '0' + i % 10, i /= 10;
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        if (s.size() > 10)
        {
            string t;
            t = s[0] + to_string(s.size() - 2) + s[s.size() - 1];
            cout << t << endl;
        }
        else
        {
            cout << s << endl;
        }
    }

    return 0;
}
