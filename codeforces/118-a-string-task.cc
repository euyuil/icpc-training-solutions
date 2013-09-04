#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

inline bool isvowel(int ch)
{
    switch (tolower(ch))
    {
    case 'a':
    case 'o':
    case 'y':
    case 'e':
    case 'u':
    case 'i':
        return true;
    default:
        return false;
    }
}

inline bool isconsonant(int ch)
{
    return (isalpha(ch) && !isvowel(ch));
}

int main()
{
    string s;
    cin >> s;

    string t;
    for (int i = 0; i < s.size(); ++i)
        if (isconsonant(s[i]))
            t += '.', t += tolower(s[i]);

    cout << t << endl;

    return 0;
}
